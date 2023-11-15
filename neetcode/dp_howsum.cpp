#include "includes.h"

/*

similar to howSum, except we want to return a vector of the numbers that
contribute to a total sum of the target

*/

vector<int> howSum(vector<int> v, int target, unordered_map<int, vector<int>>& m)
{
    if (m.count(target))
    {
        return m[target];
    }
    else if (target == 0)
    {
        return {0};
    }
    else if (target < 0)
    {
        return {};
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        const int remainder = target - v[i];

        vector<int> remainderResult = howSum(v, remainder, m);
        if (remainderResult.size())
        {
            remainderResult.push_back(v[i]);
            m[target] = remainderResult;
            return m[target];
        }
    }

    return m[target] = {};
}

int main(int argc, char const* argv[])
{
    vector<int> v1{5, 3, 4, 7};
    vector<int> v2{2, 4};
    vector<int> v3{2, 3};
    vector<int> v4{2, 3, 5};
    vector<int> v5{7, 14};

    std::unordered_map<int, vector<int>> m;
    vector<int> out;
    out = howSum(v1, 7, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }

    m = {};
    out = howSum(v2, 7, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }

    m = {};
    out = howSum(v3, 7, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }

    m = {};
    out = howSum(v4, 8, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }

    m = {};
    out = howSum(v5, 300, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }
}