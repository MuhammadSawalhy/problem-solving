#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int test_count = opt<int>("tests");
    int sum_n = opt<int>("sum-n");
    int min_n = opt<int>("min-n", 1);

    int min_value = opt<int>("min", -1000 * 1000 * 1000);
    int max_value = opt<int>("max", 1000 * 1000 * 1000);
    int value_bias = opt<int>("bias", 0);

    vector<int> n_list = rnd.partition(test_count, sum_n, min_n);

    println(test_count);
    for (int test_case = 0; test_case < test_count; ++test_case) {
        int n = n_list[test_case];
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = rnd.wnext(min_value, max_value, value_bias);
        }
        println(n);
        println(arr);
    }
}
