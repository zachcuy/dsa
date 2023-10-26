#include "includes.h"

// Add edge list to adjList (hashmap)
void addEdges(std::vector<std::pair<std::string, std::string>> &edges, std::unordered_map<std::string, std::vector<std::string>> &adjList)
{
    for (auto &pair : edges)
    {
        // pairs
        // first -> key
        // second -> value
        std::string key = pair.first;
        std::string val = pair.second;

        // add to hashmap
        // consider when we have a key already there and when we don't
        // the default constructor on each key value is an empty vector

        // if we don't have a key, create empty
        if (!adjList.count(key))
        {
            adjList[key] = {};
        }
        // if we don't have a val, create empty
        if (!adjList.count(val))
        {
            adjList[val] = {};
        }
        adjList[key].push_back(val);
    }
}

void printAdjList(const std::unordered_map<std::string, std::vector<std::string>> &adjList)
{
    for (auto i = adjList.begin(); i != adjList.end(); ++i)
    {
        std::cout << i->first << ": ";
        for (auto &el : i->second)
        {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}

int countPaths(std::pair<std::string, std::string> verts, std::unordered_map<std::string, std::vector<std::string>> &adjList, std::unordered_set<std::string> visited)
{
    /*
    purpose: count number of paths from a starting point to an ending point

    logic:
        this is done by backtracking and dfs
        at any given node, go through each neighbor and perform DFS
        keep track of visited nodes using a set

    */

    std::string start = verts.first;
    std::string end = verts.second;

    // edge case that the start/end are NOT in the adjacency list
    if (adjList.count(start) == 0 or adjList.count(end) == 0 or visited.count(start))
    {
        return 0;
    }
    // base case
    else if (start == end)
    {
        return 1;
    }

    // add current node to visited (so we don't get stuck in an infinite loop if there is a cycle)
    visited.insert(start);

    // perform dfs on all neighbors of our current node denoted by "start"
    int count = 0;
    for (auto &neighbor : adjList[start])
    {
        count += countPaths({neighbor, end}, adjList, visited);
    }

    return count;
}

int shortestPath(std::pair<std::string, std::string> verts, std::unordered_map<std::string, std::vector<std::string>> &adjList)
{
    /*
        purpose: return the shortest number of moves needed to get from start to end

        logic:
            this is done by using bfs and checking neighbors at each vertex
    */

    std::string start = verts.first;
    std::string end = verts.second;

    // bfs containers (initialize with the start value)
    std::queue<std::string> q;
    q.push(start);
    std::unordered_set<std::string> visited{start};

    // check if start is in

    // main bfs loop
    int length = 0;
    while (q.size())
    {
        for (int i = 0; i < q.size(); ++i)
        {
            // get top
            std::string cur = q.front();
            q.pop();

            if (cur == end)
            {
                return length;
            }

            // go through neighbors and add to q if we haven't visited it yet
            for (auto &neighbor : adjList[cur])
            {
                // check if we haven't visited it
                if (!visited.count(neighbor))
                {
                    // add cur to visited
                    visited.insert(neighbor);

                    // add to Q
                    q.push(neighbor);
                }
            }
        }

        length++;
    }

    return 0;
}

int main()
{
    std::vector<std::pair<std::string, std::string>> edges = {{"A", "B"}, {"B", "C"}, {"B", "E"}, {"C", "B"}, {"C", "E"}, {"E", "D"}};

    std::unordered_map<std::string, std::vector<std::string>> adjList;

    addEdges(edges, adjList);
    printAdjList(adjList);

    std::string start = "A";
    std::string end = "E";
    std::cout << "Number of paths from " << start << " to " << end << ": " << countPaths({start, end}, adjList, {}) << "\n\n";

    std::cout << "Shortest path from " << start << " to " << end << ": " << shortestPath({start, end}, adjList) << "\n\n";

    return 0;
}