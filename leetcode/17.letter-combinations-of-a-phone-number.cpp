/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.71%)
 * Likes:    17497
 * Dislikes: 915
 * Total Accepted:    1.8M
 * Total Submissions: 3.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

/*

in: string
out: vec<string>

from the input string, we convert into its associated string
we create our combinations by choosing a single value for each one

ex:
in: 23

-> abc , def

we choose one letter from the first string, then choose the second letter from the second string
so for each number we get in the input, we can create around 3^n possibilities



*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    void generate(vector<string>& candidates, vector<string>& res, string& tmp, int cdx)
    {
        // base case 1: already chose
        if (tmp.size() == candidates.size())
        {
            res.push_back(tmp);
            return;
        }
        // base case 2: out of bounds
        if (cdx >= candidates.size())
        {
            return;
        }

        for (int i = cdx; i < candidates.size(); ++i)
        {
            for (int j = 0; j < candidates[i].size(); ++j)
            {
                // choose a letter in current
                tmp += candidates[i][j];
                generate(candidates, res, tmp, i + 1);

                // move to next letter of current level
                tmp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
        {
            return {};
        }
        // map for the digit -> string
        unordered_map<char, string> m;
        // m['1'] = "";
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        // generate the vector of strings that we can choose from:
        vector<string> candidates;
        for (auto& el : digits)
        {
            candidates.push_back(m[el]);
        }

        vector<string> res;
        string tmp;
        generate(candidates, res, tmp, 0);

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    string s1{"23"};
    string s2{""};
    string s3{"2"};
    string s4{"234"};

    obj.letterCombinations(s1);
    obj.letterCombinations(s4);

    return 0;
}
