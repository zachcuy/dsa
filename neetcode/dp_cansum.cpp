#include "includes.h"

int canSum(vector<int> v, int target, std::unordered_map<int, int>& m)
{
    if (target == 0)
    {
        return true;
    }
    if (target < 0)
    {
        return false;
    }
    if (m.count(target))
    {
        return m[target];
    }

    for (int i = 0; i < v.size(); ++i)
    {
        const int remainder = target - v[i];
        m[target] = canSum(v, remainder, m);
        if (m[target])
        {
            return true;
        }
    }

    return m[target] = false;
}

int main()
{
    vector<int> v1{5, 3, 4, 7};
    vector<int> v2{2, 4};
    vector<int> v3{2, 3};
    vector<int> v4{2, 3, 5};
    vector<int> v5{7, 14};

    std::unordered_map<int, int> m;
    std::cout << (canSum(v1, 7, m) ? "true" : "false") << "\n";  // true
    m = {};
    std::cout << (canSum(v2, 7, m) ? "true" : "false") << "\n";  // false
    m = {};
    std::cout << (canSum(v3, 7, m) ? "true" : "false") << "\n";  // true
    m = {};
    std::cout << (canSum(v4, 8, m) ? "true" : "false") << "\n";  // true
    m = {};
    std::cout << (canSum(v5, 300, m) ? "true" : "false") << "\n";  // false
}