/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

/*
    ["aba","bcb","ece","aa","e"]
    [[0,2],[1,4],[1,1]]

    prefix:
    0 1 2 3 4
    1 1 2 3 4


    [0,2] -> 2 - 1 = 1
    [1,4] -> 4 - 1 = 3
    [1,1] -> 1 - 1 = 0

    --------------


    ["a","e","i"]
    [[0,2],[0,1],[2,2]]

    prefix:
    0 1 2
    1 2 3

    [0,2] -> 3 - 1 = 2
    [0,1] -> 2 - 1 = 1
    [2,2] -> 3 - 3 =
*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        vector<int> prefix(words.size(), 0);
        for (int i = 0; i < words.size(); ++i)
        {
            // check if first and last chars are vowels
            if (vowels.count(words[i][0]) and vowels.count(words[i][words[i].size() - 1]))
            {
                if (i == 0)
                {
                    prefix[i] = 1;
                }
                else
                {
                    prefix[i] = prefix[i - 1] + 1;
                }
            }
            else
            {
                if (i == 0)
                {
                    prefix[i] = 0;
                }
                else
                {
                    prefix[i] = prefix[i - 1];
                }
            }
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i)
        {
            int lower = queries[i][0];
            int upper = queries[i][1];
            if (lower == 0)
            {
                ans[i] = prefix[upper];
            }
            else
            {
                ans[i] = prefix[upper] - prefix[lower - 1];
            }
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<string> v1{"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> q1{{0, 2}, {1, 4}, {1, 1}};

    vector<string> v2{"a", "e", "i"};
    vector<vector<int>> q2{{0, 2}, {0, 1}, {2, 2}};

    vector<string> v3{"bzmxvzjxfddcuznspdcbwiojiqf",
                      "mwguoaskvramwgiweogzulcinycosovozppl",
                      "uigevazgbrddbcsvrvnngfrvkhmqszjicpieahs",
                      "uivcdsboxnraqpokjzaayedf",
                      "yalc",
                      "bbhlbmpskgxmxosft",
                      "vigplemkoni",
                      "krdrlctodtmprpxwditvcps",
                      "gqjwokkskrb",
                      "bslxxpabivbvzkozzvdaykaatzrpe",
                      "qwhzcwkchluwdnqjwhabroyyxbtsrsxqjnfpadi",
                      "siqbezhkohmgbenbkikcxmvz",
                      "ddmaireeouzcvffkcohxus",
                      "kjzguljbwsxlrd",
                      "gqzuqcljvcpmoqlnrxvzqwoyas",
                      "vadguvpsubcwbfbaviedr",
                      "nxnorutztxfnpvmukpwuraen",
                      "imgvujjeygsiymdxp",
                      "rdzkpk",
                      "cuap",
                      "qcojjumwp",
                      "pyqzshwykhtyzdwzakjejqyxbganow",
                      "cvxuskhcloxykcu",
                      "ul",
                      "axzscbjajazvbxffrydajapweci"};
    vector<vector<int>> q3{{4, 4},  {6, 17},  {10, 17}, {9, 18}, {17, 22}, {5, 23},
                           {2, 5},  {17, 21}, {5, 17},  {4, 8},  {7, 17},  {16, 19},
                           {7, 12}, {9, 20},  {13, 23}, {1, 5},  {19, 19}};

    dump(obj.vowelStrings(v1, q1));  // [2, 3, 0]
    dump(obj.vowelStrings(v2, q2));  // [3, 2, 1]
    dump(obj.vowelStrings(v3, q3));  // [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    return 0;
}