# Stress testing scripts

> [!NOTE]
> Understanding how [Polygon](https://polygon.codeforces.com) works will help you understand these scripts.

Here are scripts for different use cases and scenarios.

1. Simulate interactions using pipe without writing to files
 (`interact*` files).
1. Run a stress test without a checker (`diff` will be used by default for identical comparison) or a validator.
1. Or if you want you can add a checker or a validator or both.
1. You can use these scripts to author a problem on Polygon or just to stress test your invalid solution.
1. `testlib.h` library is used extensively because of its power and flexibility.


Run `stress-files --help` for help. You should also check `setup.sh` in the root directory of the repo.

## Examples

I got WA and can't find the edge-case. Here are some steps:

1. Open your terminal on the directory that contains the solution (`main.cpp`).
1. Run `stress-files` to get `stress.cpp` and `gen.cpp` files
1. Write the generator and another solution (maybe brute-force) in `stress.cpp`
1. Run `stress` and enjoy

