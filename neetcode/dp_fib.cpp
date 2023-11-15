#include "includes.h"

int fib(int n)
{
    if (n <= 2) {
        return 1;
    }
    std::cout << "calculating: " << n << "\n";

    return fib(n - 1) + fib(n - 2);
}

int fib_dp(int n, std::unordered_map<int, int>& m)
{
    if (n <= 2) {
        return 1;
    }
    if (m.count(n)) {
        return m[n];
    }
    std::cout << "calculating: " << n << "\n";

    m[n] = fib_dp(n - 1, m) + fib_dp(n - 2, m);
    return m[n];
}

int main()
{
    // std::cout << fib(6) << "\n";  // 8
    // std::cout << fib(7) << "\n";  // 13
    // std::cout << fib(8) << "\n";  // 21

    std::unordered_map<int, int> m;
    // std::cout << fib_dp(6, m) << "\n";  // 8
    // std::cout << fib_dp(7, m) << "\n";   // 13
    // std::cout << fib_dp(8, m) << "\n";  // 21
    std::cout << fib_dp(30, m) << "\n";  // 832040
}