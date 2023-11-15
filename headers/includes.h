#ifndef __INCLUDES_H__
#define __INCLUDES_H__

// STL
#include <algorithm>
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

// bool print
void boolPrint(bool x) { cout << (x ? "True" : "False") << "\n"; }

// 1D vector print
void vecPrint(std::vector<int> &v)
{
    for (auto &el : v)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

// 2D vector print
void vecPrint2D(std::vector<std::vector<int>> &v)
{
    for (auto &row : v)
    {
        for (auto &cell : row)
        {
            std::cout << cell << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// key:value pair print
template <typename A, typename B>
void mapPrint(std::unordered_map<A, B> &m)
{
    for (auto &e : m)
    {
        std::cout << e.first << " " << e.second << "\n";
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

// usage: TreeNode* root =
// build("[7,1,4,6,null,5,3,null,null,null,null,null,2]");
TreeNode *build(string serialized)
{
    serialized = serialized.substr(1, serialized.size() - 2);
    istringstream iss(serialized);
    string s;
    vector<int> nums;
    while (getline(iss, s, ',')) nums.push_back(s == "null" ? -1 : stoi(s));
    if (nums.empty()) return nullptr;
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

// LEETCODE LIST
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode* root = populate("[7,1,4,6,null,5,3,null,null,null,null,null,2]");
ListNode *populate(string serialized)
{
    serialized = serialized.substr(1, serialized.size() - 2);
    istringstream iss(serialized);
    string s;
    vector<int> nums;
    while (getline(iss, s, ',')) nums.push_back(s == "null" ? -1 : stoi(s));
    if (nums.empty()) return nullptr;
    ListNode *root = new ListNode(nums[0]);
    ListNode *cur = root;
    for (int i = 1; i < nums.size(); ++i)
    {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return root;
}

// linked list print
void listPrint(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n\n";
}

#endif  // __INCLUDES_H__
