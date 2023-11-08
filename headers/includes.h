#ifndef __INCLUDES_H__
#define __INCLUDES_H__

// STL
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// CP MACROS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define LSOne(S) ((S) & -(S))

// vector print
void vPrint(std::vector<int> &v)
{
    for (auto &el : v)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

// LEETCODE BINTREE
// Definition for a bin tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// usage: TreeNode* root = build("[7,1,4,6,null,5,3,null,null,null,null,null,2]");
TreeNode *build(string serialized)
{
    serialized = serialized.substr(1, serialized.size() - 2);
    istringstream iss(serialized);
    string s;
    vector<int> nums;
    while (getline(iss, s, ','))
        nums.push_back(s == "null" ? -1 : stoi(s));
    if (nums.empty())
        return nullptr;
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 0;
    int n = nums.size();
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (++i < n && nums[i] != -1)
        {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        if (++i < n && nums[i] != -1)
        {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
    }
    return root;
}

#endif // __INCLUDES_H__
