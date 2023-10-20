#include "includes.h"

/*
Study of HEAP data structure
*/

struct Heap
{
    // MIN HEAP IMPLEMENTATION
    Heap()
    {
    }

    ~Heap()
    {
    }

    void push(int val)
    {
        /*
        add a value to the heap
        */

        // put value at end
        heap.push_back(val);

        // swap val with parent until it's in correct spot
        // get parent index
        int parent_idx = (heap.size() - 1) / 2;
        int child_idx = heap.size() - 1;

        while (parent_idx > 0 and heap[parent_idx] > heap[child_idx])
        {
            std::cout << "swapping...\n";
            // swap
            int tmp = heap[parent_idx];
            heap[parent_idx] = heap[child_idx];
            heap[child_idx] = tmp;

            // update indices
            child_idx = parent_idx;
            parent_idx /= 2;
        }
    }
    int pop()
    {
        /*
        Move last value in vector to the top and replace the last value
        Make sure to delete the last node

        Percolate downwards by replacing the first value with its min(children)
        Keep doing this as long as the children are available
        */

        // move last value to first node
        int top = heap[1];
        heap[1] = heap[heap.size() - 1];

        // pop last node
        heap.pop_back();

        // percolate downwards
        int idx = 1;
        int len = heap.size();

        while (2 * idx < len or 2 * idx + 1 < len)
        {
            // get min of children
            int jdx = idx;

            if (2 * idx < len and 2 * idx + 1 < len)
            {
                // case where we need to find the minimum between two of them

                // update jdx
                if (heap[2 * idx] < heap[2 * idx + 1])
                {
                    jdx = 2 * idx;
                }
                else
                {
                    jdx = 2 * idx + 1;
                }
            }
            else
            {
                // case where we only need have the left node
                // can never hace a case where it's only the right node because of the complete structure property
                jdx = 2 * idx;
            }

            if (heap[idx] < heap[jdx]) // if we are already following order property
            {
                break;
            }

            // swap idx and jdx
            int tmp = heap[idx];
            heap[idx] = heap[jdx];
            heap[jdx] = tmp;

            // update idx
            idx = jdx;
        }

        return top;
    }

    void print()
    {
        for (auto &i : heap)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    int peek()
    {
        return heap[1];
    }

    // Base data structure is a vector
    std::vector<int> heap{0};
};

int main()
{
    Heap myHeap;

    std::vector<int> vals{14, 19, 16, 21, 26, 19, 68, 65, 30};

    myHeap.print();

    for (auto &i : vals)
    {
        myHeap.push(i);
    }
    myHeap.print();

    // push 17
    myHeap.push(17);
    myHeap.print();

    // push 10
    myHeap.push(10);
    myHeap.print();

    // pop
    myHeap.pop();
    myHeap.print();

    myHeap.pop();
    myHeap.print();

    myHeap.pop();
    myHeap.print();

    myHeap.pop();
    myHeap.print();

    return 0;
}
