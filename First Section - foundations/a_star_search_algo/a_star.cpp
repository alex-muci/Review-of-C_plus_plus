#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle};


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

//  Implementation of A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  cout << "No path found!" << "\n";
  return std::vector<vector<State>> {};
}