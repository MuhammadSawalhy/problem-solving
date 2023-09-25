#!python

import sys
import os
import argparse
import pyperclip

current_dir = os.getcwd()
downloads_dir = "/mnt/c/Users/ms205/Downloads"


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-x", "--executable", help="Executable program to run", default="./main"
    )
    parser.add_argument(
        "-v", "--validation", action="store_true", help="Run validation", default=True
    )
    parser.add_argument("-m", "--main", action="store_true", help="Run main")
    parser.add_argument(
        "-q", "--quiet", action="store_true", help="Quiet mode", default=False
    )
    args = parser.parse_args()

    return args


args = parse_args()


def debug(msg: str):
    if args.quiet:
        return
    print(f"=====> {msg}")


def debug_err(msg: str):
    print(f"ERROR => {msg}")


def get_validation_input(dir: str) -> list[str]:
    files = os.listdir(dir)
    return [
        os.path.join(dir, file)
        for file in files
        if file.endswith("validation_input.txt")
    ]


def get_main_input(dir: str) -> list[str]:
    files = os.listdir(dir)
    return [
        os.path.join(dir, file)
        for file in files
        if file.endswith("_input.txt") and not file.endswith("validation_input.txt")
    ]


def get_7z_file(dir: str):
    files = os.listdir(dir)
    return [os.path.join(dir, file) for file in files if file.endswith("_input.zip")]


def extract_7z(file: str, target_dir: str):
    # use password from the clipboard
    debug(f"Extracting {os.path.basename(file)}")
    debug(f"Password: {pyperclip.paste()}")
    return os.system(f"7z x '{file}' -o'{target_dir}' -p'{pyperclip.paste()}' -y")


def try_to_extract_7z() -> bool:
    files = get_7z_file(downloads_dir)
    debug("Trying to extract 7z file")
    if len(files) == 0:
        debug_err("no input file or 7z archive found")
        return False
    elif len(files) > 1:
        debug_err("more than one input.zip file in the downloads directory")
        return False
    print(f"Extracting {os.path.basename(files[0])}, continue? [y]/n: ", end="")
    ans = input().lower()
    if ans not in ["y", "yes", ""]:
        return False
    if extract_7z(files[0], current_dir) == 0:
        os.remove(files[0])
        return True
    else:
        for f in get_main_input(current_dir):
            os.remove(f)
        debug_err("extraction failed")
        return False


def run(get_input):
    files = get_input(current_dir)

    if len(files) == 0:
        files = get_input(downloads_dir)
        if len(files) == 0:
            if args.main:
                if not try_to_extract_7z():
                    sys.exit(1)
            else:
                debug_err("no validation input file")
                sys.exit(1)
        elif len(files) > 1:
            debug_err("more than one input file")
            sys.exit(1)
        else:
            # move input file to the current_dir
            debug(f"Copying the input file from Downloads directory: {files[0]}")
            os.system(f"mv '{files[0]}' '{current_dir}'")

        files = get_input(current_dir)
    elif len(files) > 1:
        debug_err("more than one input file")
        sys.exit(1)

    assert len(files) == 1
    output = files[0].replace("_input.txt", "_output.txt")
    debug(f"Input:  {os.path.relpath(files[0])}")
    debug(f"Output: {os.path.relpath(output)}")
    os.system(f"{args.executable} < '{files[0]}' > '{output}'")


def main():
    if not os.path.exists(args.executable):
        debug_err(f"{args.executable} does not exist")
        sys.exit(1)
    if args.main:
        run(get_main_input)
    elif args.validation:
        run(get_validation_input)


if __name__ == "__main__":
    main()
