#include <algorithm>
#include <string>

#include "includes.h"

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i     = a.length() - 1;
        int j     = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};

int main()
{
    Solution obj;

    dump(obj.addBinary("11", "1"));  // 100
    dump(obj.addBinary("1010", "1011"));  // 10101
}
