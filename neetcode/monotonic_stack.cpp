#include "includes.h"

/*

monotonic stack is a specific use of a regular stack.

Given an array, like {10, 5, 3, 8, 0, 9, 15, 20, 40, 33, 1};

if we have an increasing mono stack, then the values in the stack must be strictly increasing such
that the top is the largest element (of the stack elements). when we are putting a new value into
the stack, we pop until either the stack is empty or the top of the stack is smaller than the value
we are trying to insert.

*/

// increasing mono stack
class MonoStack
{
   public:
    MonoStack()
    {
    }

    MonoStack(vector<int> v)
    {
        for (auto& el : v)
        {
            push(el);
        }
    }

    ~MonoStack()
    {
    }

    void push(int x)
    {
        cout << "inserting: " << x << "\n";
        while (data.size() and data.top() < x)
        {
            cout << "\t\t" << this->pop() << " < " << x << "\n";
        }
        data.push(x);
    }

    int pop()
    {
        int x = data.top();
        data.pop();

        return x;
    }

    stack<int> data;
};

vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2)
{
    stack<int> s;
    vector<int> res;
    unordered_map<int, int> m;

    for (int i = 0; i < nums2.size(); ++i)
    {
        // increasing mono stack
        while (s.size() and nums2[s.top()] < nums2[i])
        {
            m[nums2[s.top()]] = nums2[i];
            s.pop();
        }
        s.push(i);
    }

    while (s.size())
    {
        m[nums2[s.top()]] = -1;
        s.pop();
    }

    for (auto& num : nums1)
    {
        res.push_back(m[num]);
    }

    return res;
}

int main(int argc, char const* argv[])
{
    vector<int> v1{6, 2, 4, 5, 3, 7};
    vector<int> a1{4, 2, 6};
    vector<int> v2{1, 3, 4, 2};
    vector<int> a2{4, 1, 2};
    vector<int> v3{1, 2, 3, 4};
    vector<int> a3{2, 4};

    vector<int> o1 = nextGreaterElement(a1, v1);
    // cout << "\n==============================\n";
    vecPrint(o1);
    cout << "\n==============================\n";

    vector<int> o2 = nextGreaterElement(a2, v2);
    // cout << "\n==============================\n";
    vecPrint(o2);
    cout << "\n==============================\n";

    vector<int> o3 = nextGreaterElement(a3, v3);
    // cout << "\n==============================\n";
    vecPrint(o3);
    cout << "\n==============================\n";

    return 0;
}
