# Stress testing scripts

> [!NOTE]
> Understanding how [Polygon](https://polygon.codeforces.com) works will help you understand these scripts.

Here are scripts for different use cases and scenarios.

1. Simulate interactions using pipe without writing to files
 (`interact*` files).
1. Run a stress test without a checker (`diff` will be used by default for identical comparison) or a validator.
1. If you want, you can add a checker, a validator, or both.
1. You can use these scripts to author a problem on Polygon or stress test your invalid solution.
1. `testlib.h` library is used extensively because of its power and flexibility.


Run `stress-files --help` for help. You should also check `setup.sh` in the repo's root directory.

## Examples

**You got WA and can't find the edge case. Here are some steps:**

1. Open your terminal on the directory that contains the solution (`main.cpp`).
1. Run `stress-files` to get `stress.cpp` and `gen.cpp` files
1. Write the generator and another solution (maybe brute-force) in `stress.cpp`
1. Run `stress` and enjoy

**You have an idea for a problem and want to create one on Polygon:**

1. Open your terminal on an empty directory for the problem.
1. Run `stress-files --check --validate --script` to get `stress.cpp`, `gen.cpp`, `check.cpp`, `validate.cpp` and `stress.sh` files
1. Fill your files
1. Run `stress`, so the following will happen:
  1. Validate the generated test case using the validator
  1. Run the solution and store the result
  1. Check it using the checker

## Future work

1. Add commonly used checkers like that in Polygon.
2. Add commonly used generator utilities like generating a star graph or BST.
