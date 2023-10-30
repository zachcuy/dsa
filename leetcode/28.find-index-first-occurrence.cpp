#include "includes.h"

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int len = needle.size();

        int idx = 0;
        int R = 0;

        if (haystack == needle)
        {
            return 0;
        }
        else if (haystack.size() < needle.size())
        {
            return -1;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
        {
            if (haystack[i] == needle[0])
            {
                idx = i;

                while (R < needle.size())
                {
                    if (haystack[R + i] != needle[R])
                    {
                        break;
                    }
                    R++;
                }

                if (R == needle.size())
                {
                    return idx;
                }
                else
                {
                    R = 0;
                    i += R;
                }
            }
        }
        return -1;
    }
};

int main()
{

    Solution obj;
    std::string s = "abc";
    std::string ss = "c";
    obj.strStr(s, ss);
}