#include "includes.h"

bool canConstruct(vector<string> wordBank, string target, unordered_map<string, bool>& m)
{
    if (target == "")
    {
        return true;
    }
    if (m.count(target))
    {
        return m[target];
    }

    for (size_t i = 0; i < wordBank.size(); i++)
    {
        string remainder = target;
        if (target.find(wordBank[i]) == 0)
        {
            // remove the word
            remainder.erase(0, wordBank[i].size());
            m[target] = canConstruct(wordBank, remainder, m);
            if (m[target])
            {
                return true;
            }
        }
    }

    return m[target] = false;
}

int main(int argc, char const* argv[])
{
    unordered_map<string, bool> m;
    vector<string> v1{"ab", "abc", "cd", "def", "abcd"};
    vector<string> v2{"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    vector<string> v3{"a", "p", "ent", "enter", "ot", "o", "t"};
    vector<string> v4{"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};

    boolPrint(canConstruct(v1, "abcdef", m));  // true
    m.clear();
    boolPrint(canConstruct(v2, "skateboard", m));  // false
    m.clear();
    boolPrint(canConstruct(v3, "enterapotentpot", m));  // true
    m.clear();
    boolPrint(canConstruct(v4, "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", m));  // false
    m.clear();

    return 0;
}
