#include "includes.h"

template <typename T>
T dp(vector<vector<T>>& v, int i, int j, T m, T n)
{
    if (i == m - 1 and j == n - 1) {  // check if we're at goal
        return 1;
    }
    else if (i == m or j == n) {  // checking if we're out of bounds
        return 0;
    }
    else if (v[i][j] != 0) {  // check if we've already solved the cells around
        return v[i][j];
    }

    v[i][j] = dp(v, i + 1, j, m, n) +  // move down by one
              dp(v, i, j + 1, m, n);   // move right by one

    return v[i][j];
}

template <typename T>
T caller(T m, T n)
{
    vector<vector<T>> v(m, vector<T>(n, 0));

    for (auto& row : v) {
        for (auto& cell : row) {
            cout << cell << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    T x = dp(v, 0, 0, m, n);

    for (auto& row : v) {
        for (auto& cell : row) {
            cout << cell << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    return x;
}

int main()
{
    long long m = 18;
    long long n = 18;

    std::cout << caller(m, n) << "\n\n";
}