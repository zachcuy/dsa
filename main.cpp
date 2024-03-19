#include "dump.hpp"
#include "solution.h"

int main(int argc, char* argv[])
{
    std::vector<char> v1 {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C'};

    Solution obj;

    obj.leastInterval(v1, 2);
    return 0;
}
