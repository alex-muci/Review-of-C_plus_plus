#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed};


void AddToOpen(int x, int y, int g, int h,
               vector<vector<int>> &openvect, 
               vector<vector<State>> &grid) {
  vector<int> s{x, y, g, h};
  openvect.push_back(s);  // or .push_back(vector<int>{x, y, g, h});  
  grid[x][y] = State::kClosed;    
}

bool Compare(const vector<int> a, const vector<int> b) {
  int f1 = a[2] + a[3]; 
  int f2 = b[2] + b[3]; 
  return f1 > f2; 
}

// Sort the two-dimensional vector of ints in descending order.
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


// manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

bool Compare(const vector<int> &first, const vector<int> &second){
  int first_res = first[2] + first[3];
  int second_res = second[2] + second[3];
  return first_res > second_res;
}

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};




// Implementation of A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
  
  // Initialize the starting node.
  int x = init[0];   int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    // Get the next node
    CellSort(&open);
    auto current = open.back();
    open.pop_back();
    x = current[0]; y = current[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      return grid;
    }    
    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  }
  
  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}
