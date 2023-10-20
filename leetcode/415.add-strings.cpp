#include "includes.h"

std::string reverseString(std::string str)
{
    std::string out;

    for (auto it = str.rbegin(); it != str.rend(); ++it)
    {
        out.push_back(*it);
    }

    return out;
}

std::string addStrings(std::string num1, std::string num2)
{
    // output string
    std::string out;

    // reverse iterators for both strings
    std::string::reverse_iterator it1 = num1.rbegin();
    std::string::reverse_iterator it2 = num2.rbegin();

    // go through the numbers together (both numbers have a value)
    int carry = 0;
    while (it1 != num1.rend() or it2 != num2.rend())
    {
        // default value if there are no longer digits for a given string
        // This will happen if either num1 or num2 are larger than the other
        int a = 0;
        int b = 0;
        if (it1 == num1.rend())
        {
            a = 0;
        }
        else
        {
            a = (*it1 - '0');
        }
        if (it2 == num2.rend())
        {
            b = 0;
        }
        else
        {
            b = (*it2 - '0');
        }
        // get carry digit and base
        // std::cout << "a: " << a << " b: " << b << " c: " << carry << "\n";
        int sum = a + b + carry;
        carry = sum / 10;
        sum %= 10;

        // append the base to the out string
        out.push_back(sum + '0');

        // go next
        if (it1 != num1.rend())
        {
            it1++;
        }
        if (it2 != num2.rend())
        {
            it2++;
        }
    }
    out.push_back(carry + '0');

    return reverseString(out);
}

int main()
{
    std::string a{"456"};
    std::string b{"77"};
    std::string res = addStrings(a, b);

    std::cout << res << "\n";

    return 0;
}