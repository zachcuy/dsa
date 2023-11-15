#include "includes.h"

int countConstruct(vector<string> wordBank, string target, unordered_map<string, int>& m)
{
    if (m.count(target))
    {
        return m[target];
    }
    else if (target == "")
    {
        return 1;
    }

    int count = 0;
    for (size_t i = 0; i < wordBank.size(); i++)
    {
        if (target.find(wordBank[i]) == 0)
        {
            // slice
            string tmp = target;
            tmp.erase(0, wordBank[i].size());

            count += countConstruct(wordBank, tmp, m);
        }
    }

    return m[target] = count;
}

int main(int argc, char const* argv[])
{
    unordered_map<string, int> m;
    vector<string> v1{"ab", "abc", "cd", "def", "abcd"};
    vector<string> v2{"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    vector<string> v3{"a", "p", "ent", "enter", "ot", "o", "t"};
    vector<string> v4{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    vector<string> v5{"purp", "p", "ur", "le", "purpl"};

    cout << countConstruct(v1, "abcdef", m) << "\n";  // 1
    m.clear();
    cout << countConstruct(v2, "skateboard", m) << "\n";  // 0
    m.clear();
    cout << countConstruct(v3, "enterapotentpot", m) << "\n";  // 4
    m.clear();
    cout << countConstruct(v4, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", m) << "\n";  // 0
    m.clear();
    cout << countConstruct(v5, "purple", m) << "\n";  // 2

    return 0;
}