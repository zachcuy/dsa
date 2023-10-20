#include "includes.h"

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
    void pop()
    {
        /*
        get the first (smallest value) value, return it, and delete the value
        */
    }

    void print()
    {
        for (auto &i : this->heap)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

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

    return 0;
}