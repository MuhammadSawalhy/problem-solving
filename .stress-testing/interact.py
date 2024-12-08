#!/usr/bin/env python3
# SOURCE: https://codeforces.com/blog/entry/99821

import sys, time
import argparse
import random
import subprocess as sp
import threading
from queue import Queue, Empty


def intercept(out, q):
    for line in iter(out.readline, b""):
        q.put(line)
    out.close()


class ProcessThread:
    def __init__(self, cmd, args=[]):
        self.cmd = cmd
        self.process = sp.Popen(
            [cmd, *args],
            stdin=sp.PIPE,
            stdout=sp.PIPE,
            stderr=sp.PIPE,
            close_fds=("posix" in sys.builtin_module_names),
        )
        self.lines = dict()
        self.listen = dict()
        for stream, name in zip(
            [self.process.stdout, self.process.stderr], ["out", "err"]
        ):
            self.lines[name] = Queue()
            self.listen[name] = threading.Thread(
                target=intercept, args=(stream, self.lines[name])
            )
            self.listen[name].daemon = True
            self.listen[name].start()

    def feed_input(self, inp):
        if self.poll() is not None or not self.process.stdin:
            return
        try:
            self.process.stdin.write((inp + "\n").encode())
            self.process.stdin.flush()
        except IOError as e:
            print(f"can't feed this string to the stdin of {self.cmd}:")
            print(inp)
            print()
            print(e)
            exit(1)

    def get_stream(self, stream) -> str:
        # if self.poll() is not None:
        # 	return None
        lines = []
        while True:
            try:
                line = self.lines[stream].get_nowait()
                lines.append(line)
            except Empty:
                break
        return "\n".join(map(lambda x: x.decode().strip(), lines))

    def get_out(self):
        return self.get_stream("out")

    def get_err(self):
        return self.get_stream("err")

    def poll(self):
        return self.process.poll()


class Echo:
    simple = False
    enabled = True
    colors_enabled = True
    color_codes = {
        "Reset": 0,
        "Bold": 1,
        "Underline": 2,
        "Inverse": 7,
        "Black": 30,
        "Red": 31,
        "Green": 32,
        "Yellow": 33,
        "Blue": 34,
        "Magenta": 35,
        "Cyan": 36,
        "White": 37,
    }

    @staticmethod
    def colored(text, color):
        if not Echo.colors_enabled or color not in Echo.color_codes:
            return text
        return f"\033[{Echo.color_codes[color]}m{text}\033[0m"

    @staticmethod
    def print_framed(text, title, dir, color="normal"):
        if not Echo.enabled:
            return

        lines = text.strip().split("\n")

        if Echo.simple:
            print(Echo.colored(f"{title}:", color))
            print("\n".join(lines))
            return

        left_appendix = f"{title}: " if dir == "left" else ""
        right_appendix = f" :{title}" if dir == "right" else ""
        left_padding = " " * max(10, len(left_appendix))
        left_appendix = " " * (len(left_padding) - len(left_appendix)) + left_appendix
        color = color.capitalize()
        width = max(map(len, lines)) + 2

        print(Echo.colored(left_padding + "+" + "-" * width + "+", color))
        for line in lines:
            print(
                Echo.colored(left_padding + "| ", color)
                + line.ljust(width - 2, " ")
                + Echo.colored(" |", color)
            )
        print(
            Echo.colored(
                left_appendix + "+" + "-" * width + "+" + right_appendix, color
            )
        )

    @staticmethod
    def error(*args, **kwargs):
        print(*args, **kwargs)

    @staticmethod
    def print(*args, **kwargs):
        if not Echo.enabled:
            return
        print(*args, **kwargs)

    @staticmethod
    def solution_out(text):
        Echo.print_framed(text, "solution", "left", "green")

    @staticmethod
    def solution_err(text):
        Echo.print_framed(text, "error", "left", "yellow")

    @staticmethod
    def interactor_out(text):
        Echo.print_framed(text, "interactor", "right", "cyan")

    @staticmethod
    def interactor_err(text):
        Echo.print_framed(text, "error", "right", "red")


def interact(config, test_number=0):
    solution = ProcessThread(config.solution)
    interactor = ProcessThread(config.interactor, [str(test_number)])

    solution_running = True
    interactor_running = True

    solution_time = time.time()
    interactor_time = time.time()
    HANG_TIMEOUT = config.timeout

    while True:
        soln_out = solution.get_out()
        inter_out = interactor.get_out()
        soln_err = solution.get_err()
        inter_err = interactor.get_err()

        if soln_out:
            Echo.solution_out(soln_out)
            interactor.feed_input(soln_out)
            solution_time = time.time()

        if soln_err and not args.no_stderr:
            Echo.solution_err(soln_err)

        if inter_out:
            Echo.interactor_out(inter_out)
            solution.feed_input(inter_out)
            interactor_time = time.time()

        if inter_err and not args.no_stderr:
            Echo.interactor_err(inter_err)

        if solution_running and solution.poll() != None:
            solution_running = False
            if solution.poll() != 0:
                Echo.error(f"Solution exited with error code {solution.poll()}")
                return False
            else:
                Echo.print("Solution exited successfully")

        if interactor_running and interactor.poll() != None:
            interactor_running = False
            if interactor.poll() != 0:
                Echo.error(f"Interactor exited with error code {interactor.poll()}")
                return False
            else:
                Echo.print("Interactor exited successfully")

        if not solution_running and not interactor_running:
            return True

        if time.time() - solution_time >= HANG_TIMEOUT:
            Echo.error(
                f"Solution has been forced to shut down due to timeout ({HANG_TIMEOUT} seconds)"
            )
            return False

        if time.time() - interactor_time >= HANG_TIMEOUT:
            Echo.error(
                f"Interactor has been forced to shut down due to timeout ({HANG_TIMEOUT} seconds)"
            )
            return False


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Make two programs interact with each other."
    )
    parser.add_argument(
        "solution",
        metavar="<solution exec>",
        help="Executable file of the solution to test",
    )
    parser.add_argument(
        "interactor",
        metavar="<interactor exec>",
        help="Executable file of the interactor to test your solution against.",
    )
    parser.add_argument("--no-color", action="store_true", help="Colored frames")
    parser.add_argument(
        "--no-stderr", action="store_true", help="Disable stderr printing"
    )
    parser.add_argument(
        "--simple", action="store_true", default=False, help="Disable stderr printing"
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=1,
        help="The number of seconds to wait for the solution to exit after the interactor has finished",
    )
    parser.add_argument(
        "-t", "--test-case", type=int, help="a test case to feed to the interactor"
    )
    parser.add_argument(
        "-m",
        "--many",
        action="store_true",
        help="keep trying until we find any test case that fails the solution",
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="to get verbose interactions when doing many test cases, see --many option",
    )
    args = parser.parse_args()

    Echo.simple = args.simple
    Echo.enabled = not args.many or args.verbose
    Echo.colors_enabled = not args.no_color

    if args.test_case != None:
        interact(args, args.test_case)
    elif args.many:
        t = 1
        while True:
            print(f"(=---------- test {t} ----------=)")
            if not interact(args, t):
                break
            t += 1
    else:
        interact(args, random.randint(0, 1000000))
