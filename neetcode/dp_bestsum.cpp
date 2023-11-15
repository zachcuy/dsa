#include "includes.h"

vector<int> bestSum(vector<int> v, int target, unordered_map<int, vector<int>>& m)
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

    vector<int> shortestCombo;

    for (size_t i = 0; i < v.size(); i++)
    {
        const int remainder = target - v[i];
        vector<int> remainderResult = bestSum(v, remainder, m);

        if (remainderResult.size())
        {
            remainderResult.push_back(v[i]);

            if (!shortestCombo.size() or remainderResult.size() < shortestCombo.size())
            {
                shortestCombo = remainderResult;
            }
        }
    }

    return m[target] = shortestCombo;
}

int main(int argc, char const* argv[])
{
    vector<int> v1{5, 7, 3, 4, 2};
    vector<int> v2{2, 4};
    vector<int> v3{2, 3};
    vector<int> v4{2, 3, 5};
    vector<int> v5{7, 14};

    std::unordered_map<int, vector<int>> m;
    vector<int> out;
    out = bestSum(v1, 7, m);
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
    out = bestSum(v2, 7, m);
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
    out = bestSum(v3, 7, m);
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
    out = bestSum(v4, 8, m);
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
    out = bestSum(v5, 300, m);
    if (out.size())
    {
        vecPrint(out);
    }
    else
    {
        std::cout << "{}"
                  << "\n";
    }
    return 0;
}
