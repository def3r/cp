#include "dbg.h"
#include <vector>

// TC -> O(m^n * E)
// E-> edges
// improvement => form adjacency list, =->TC : m^n

bool recFun(int vertex, int color, vector<int> &colors,
            vector<vector<int>> &edges, int m, int n) {
  if (vertex >= n) {
    return true;
  }

  int adjacentVertex = -1;
  for (vector<int> &edge : edges) {
    if (edge[0] == vertex) {
      adjacentVertex = edge[1];
    } else if (edge[1] == vertex) {
      adjacentVertex = edge[0];
    } else {
      adjacentVertex = -1;
    }

    if (adjacentVertex != -1 && colors[adjacentVertex] == color) {
      return false;
    }
  }

  colors[vertex] = color;
  for (int i = 0; i < m; i++) {
    if (recFun(vertex + 1, i, colors, edges, m, n)) {
      return true;
    }
  }
  colors[vertex] = -1;
  return false;
}

bool graphColoring(vector<vector<int>> &edges, int m, int n) {
  vector<int> colors(n, -1);
  return recFun(0, 0, colors, edges, m, n);
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> edges;
  int m;
  int n;

#define dbg_test_fun graphColoring(edges, m, n)
  dbg_test_with(false, n = 3, m = 2, edges = {{0, 1}, {1, 2}, {0, 2}});
  dbg_test_with(true, n = 4, m = 3,
                edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}});

  return EXIT_SUCCESS;
}
