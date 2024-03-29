#!/usr/bin/env python3
# SOURCE: https://codeforces.com/blog/entry/99821

import sys, time
import argparse
import random
import subprocess as sp
import threading
from queue import Queue, Empty


def intercept(out, q):
    for line in iter(out.readline, b''):
        q.put(line)
    out.close()


class ProcessThread:
    def __init__(self, cmd, args = []):
        self.cmd = cmd
        self.p = sp.Popen([cmd, *args], stdin=sp.PIPE, stdout=sp.PIPE, stderr=sp.PIPE,
                          close_fds=("posix" in sys.builtin_module_names))
        self.q = dict()
        self.listen = dict()
        for stream, name in zip([self.p.stdout, self.p.stderr], ["out", "err"]):
            self.q[name] = Queue()
            self.listen[name] = threading.Thread(
                target=intercept, args=(stream, self.q[name]))
            self.listen[name].daemon = True
            self.listen[name].start()

    def feed_input(self, inp):
        if self.poll() is not None or not self.p.stdin:
            return
        try:
            self.p.stdin.write((inp + "\n").encode())
            self.p.stdin.flush()
        except IOError as e:
            print(f"can't feed this string to the stdin of {self.cmd}:")
            print(inp)
            print()
            print(e)
            exit(1)

    def get_stream(self, stream):
        # if self.poll() is not None:
        # 	return None
        lines = []
        while True:
            try:
                line = self.q[stream].get_nowait()
                lines.append(line)
            except Empty:
                break
        return None if lines == [] else "\n".join(map(lambda x: x.decode().strip(), lines))

    def get_out(self):
        return self.get_stream("out")

    def get_err(self):
        return self.get_stream("err")

    def poll(self):
        return self.p.poll()


class Echo:
    enabled = True
    colors_enabled = True
    color_codes = {
        "Reset": 0,    "Bold": 1,    "Underline": 2,
        "Inverse": 7,  "Black": 30,  "Red": 31,
        "Green": 32,   "Yellow": 33, "Blue": 34,
        "Magenta": 35, "Cyan": 36,   "White": 37,
    }

    @staticmethod
    def colored(text, color):
        if not Echo.colors_enabled or color not in Echo.color_codes:
            return text
        return f"\033[{Echo.color_codes[color]}m{text}\033[0m"

    @staticmethod
    def print_framed(text, left_appendix="", right_appendix="", color="normal"):
        if not Echo.enabled:
            return
        left_padding = " " * 10
        left_appendix = " " * (10 - len(left_appendix) - 1) + left_appendix + " "
        color = color.capitalize()
        lines = text.strip().split('\n')
        width = max(map(len, lines)) + 2
        print(Echo.colored(left_padding + "+" + "-" * width + "+", color))
        for line in lines:
            print(Echo.colored(left_padding + "| ", color) +
                  line.ljust(width - 2, ' ') + Echo.colored(" |", color))
        print(Echo.colored(left_appendix + "+" + "-" *
              width + "+" + right_appendix, color))

    @staticmethod
    def print(*args, **kwargs):
        if not Echo.enabled:
            return
        print(*args, **kwargs)

    @staticmethod
    def solution_out(text):
        Echo.print_framed(text, "solution:", "", "green")

    @staticmethod
    def solution_err(text):
        Echo.print_framed(text, "stderr:", "", "yellow")

    @staticmethod
    def interactor_out(text):
        Echo.print_framed(text, "", " :interactor", "cyan")

    @staticmethod
    def interactor_err(text):
        Echo.print_framed(text, "", " :interactor", "red")


def interact(config, test_number = 0):
    solution = ProcessThread(config.solution)
    interactor = ProcessThread(config.interactor, [str(test_number)])

    solution_running = True
    interactor_running = True

    hanging_start = None
    HANG_TIMEOUT = config.hang_timeout

    while True:
        soln_out = solution.get_out()
        inter_out = interactor.get_out()
        soln_err = solution.get_err()
        inter_err = interactor.get_err()

        if soln_out is not None:
            Echo.solution_out(soln_out)
            interactor.feed_input(soln_out)
            hanging_start = time.time()

        if soln_err is not None and not args.no_stderr:
            Echo.solution_err(soln_err)
            hanging_start = time.time()

        if inter_out is not None:
            Echo.interactor_out(inter_out)
            solution.feed_input(inter_out)
            hanging_start = time.time()

        if inter_err is not None and not args.no_stderr:
            Echo.interactor_err(inter_err)
            hanging_start = time.time()

        if solution_running and solution.poll() != None:
            Echo.print(f"Solution process exited with error code {solution.poll()}")
            solution_running = False
            if solution.poll() != 0:
                return False

        if interactor_running and interactor.poll() != None:
            Echo.print(
                f"Interactor process exited with error code {interactor.poll()}")
            interactor_running = False
            if interactor.poll() != 0:
                return False

        if not solution_running and not interactor_running:
            return True

        if hanging_start and time.time() - hanging_start >= HANG_TIMEOUT:
            Echo.print(f"Solution process has been forced to shut down due to timeout")
            return False


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Make two programs interact with each other.")
    parser.add_argument("solution", metavar="<solution exec>",
                        help="Executable file of the solution to test")
    parser.add_argument("interactor", metavar="<interactor exec>",
                        help="Executable file of the interactor to test your solution against.")
    parser.add_argument("--no-color", action="store_true",
                        help="Colored frames")
    parser.add_argument("--no-stderr", action="store_true",
                        help="Disable stderr printing")
    parser.add_argument("--hang-timeout", type=float, default=1,
                        help="The number of seconds to wait for the solution to exit after the interactor has finished")
    parser.add_argument("-m", "--many", action="store_true",
                        help="keep trying until we find any test case that fails the solution")
    parser.add_argument("-t", "--test-case", type=int,
                        help="a test case to feed to the interactor")
    parser.add_argument("--verbose", action="store_true",
                        help="to get verbose interactions when doint many test cases, see --many option")
    args = parser.parse_args()

    Echo.enabled = not args.many or args.verbose
    Echo.colors_enabled = not args.no_color

    if args.test_case != None:
        interact(args, args.test_case)
    elif args.many:
        t = 0
        while interact(args, t):
            t += 1
            print(f"(=---------- test {t} ----------=)")
    else:
        interact(args, random.randint(0, 1000000))

