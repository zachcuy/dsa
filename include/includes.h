#ifndef __INCLUDES_H__
#define __INCLUDES_H__

// STL
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// CP MACROS
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define LSOne(S) ((S) & -(S))

// DUMPER
#include "dump.hpp"
CPP_DUMP_SET_OPTION_IN_GLOBAL(max_line_width, 100);
CPP_DUMP_SET_OPTION_IN_GLOBAL(log_label_func, cpp_dump::log_label::filename(true));
CPP_DUMP_SET_OPTION_IN_GLOBAL(es_value,
                              (cpp_dump::es_value_t {
                                  "\e[02m",  // log: dark
                                  "\e[34m",  // expression: blue
                                  "\e[36m",  // reserved: cyan
                                  "\e[36m",  // number: cyan
                                  "\e[36m",  // character: cyan
                                  "\e[02m",  // op: dark
                                  "\e[32m",  // identifier:  green
                                  "\e[36m",  // member: cyan
                                  "",  // unsupported: default
                                  {
                                      "\e[33m",  // bracket_by_depth[0]: yellow
                                      "\e[35m",  // bracket_by_depth[1]: magenta
                                      "\e[36m",  // bracket_by_depth[2]: cyan
                                  },
                              }));

// LEETCODE BINARY TREE DEFINITION
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

// LEETCODE BINARY TREE BUILDER
TreeNode* build(string serialized)
{
    // usage:
    // TreeNode* root = build("[7,1,4,6,null,5,3,null,null,null,null,null,2]");

    serialized = serialized.substr(1, serialized.size() - 2);
    istringstream iss(serialized);
    string s;
    vector<int> nums;
    while (getline(iss, s, ','))
        nums.push_back(s == "null" ? -INT_MAX : stoi(s));
    if (nums.empty())
        return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    int n = nums.size();
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (++i < n && nums[i] != -INT_MAX)
        {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        if (++i < n && nums[i] != -INT_MAX)
        {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
    }
    return root;
}

// LEETCODE LINKED LIST DEFINITION
struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

ListNode* populate(string serialized)
{
    // usage:
    // ListNode* root = populate("[7,1,4,6,null,5,3,null,null,null,null,null,2]");

    serialized = serialized.substr(1, serialized.size() - 2);
    istringstream iss(serialized);
    string s;
    vector<int> nums;
    while (getline(iss, s, ','))
        nums.push_back(s == "null" ? -1 : stoi(s));
    if (nums.empty())
        return nullptr;
    ListNode* root = new ListNode(nums[0]);
    ListNode* cur  = root;
    for (int i = 1; i < nums.size(); ++i)
    {
        cur->next = new ListNode(nums[i]);
        cur       = cur->next;
    }
    return root;
}

#endif  // __INCLUDES_H__
