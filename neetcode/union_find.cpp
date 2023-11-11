#include "includes.h"

class DisjointSet {
 public:
  std::vector<int> nodes;
  std::vector<int> size;

  DisjointSet(int n) {
    nodes.resize(n);
    size.resize(n);
    for (int i = 0; i < n; ++i) {
      nodes[i] = i;
      size[i] = 1;
    }
  }

  int find(int id) {
    // using PATH COMPRESSION
    // get parent node, the parent is the one that points to itself
    if (nodes[id] == id) {
      return id;
    }
    return nodes[id] = find(nodes[id]);
  }

  void uni(int a, int b) {
    // combine two nodes by getting the parents of both nodes
    // then pointing one node to the other

    // get parents of both nodes
    a = find(a);
    b = find(b);

    // only combine if they aren't the same set already
    // using UNION BY SIZE
    if (a != b) {
      if (size[a] < size[b]) {
        swap(a, b);
      }
      nodes[b] = a;
      size[a] += size[b];
    }
  }
};

int main() {
  DisjointSet obj(3);

  std::vector<std::vector<int>> vec{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < vec[i].size(); ++j) {
      if (vec[i][j] == 1) {
        obj.uni(i, j);
      }
    }
  }

  std::cout << obj.find(4) << " " << obj.find(0) << "\n";
  if (obj.find(4) == obj.find(0))
    cout << "Yes\n";
  else
    cout << "No\n";

  std::cout << obj.find(1) << " " << obj.find(0) << "\n";
  if (obj.find(1) == obj.find(0))
    cout << "Yes\n";
  else
    cout << "No\n";

  for (auto &i : obj.nodes) {
    std::cout << i << " ";
  }
  std::cout << "\n\n";
}