#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
// using std::vector;

/* recall enum in Python
import enum
class Colour(enum.Enum):
   white = 1;  black = 2; blue = 3

my_colour = Colour.blue
*/
enum class Colour{white, black, blue};
// Colour my_colour = Colour::blue;
// if(my_colour == Colour::black) {  cout << "The colour is not blue.";    }

enum class State {kEmpty, kObstacle};
string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

// Function declared and defined here.
void ReadBoardFile_cout(string path) {
  // ifstream myfile; myfile.open(path); // or in one-line as per below
  ifstream myfile(path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
    }
  }
}


vector<int> ParseLine(string my_string) {
  int n; char cr;
  vector<int> v;
  std::istringstream my_stream(my_string);
  while (my_stream >> n >> cr) {    // (my_stream >> n >> cr && cr == ',') 
    v.push_back(n);
    }
  return v;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> vv;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> row = ParseLine(line);
      vv.push_back(row);
    }
  }
  return vv;
}

void PrintBoard(const vector<vector<int>> board) {
  // index-based (first rows, then columns)
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
  /* range-based    
  for (auto i: board) {
    for (int j: i) {
      cout << j;
        }
    } 
  */

}


int AdditionFunction(int i, int j) 
{
    return i + j;
}

int AdditionFunctionVec(vector<int> &v)
{
    int sum = 0;
    for(int &i : v)
        sum += i;
    return sum;

    /* 2. oppure:
    int sum = 0;
    for(int i = 0; i < v.size(); ++i)
        sum += v[i];
    return sum;

    3. oppure using iterator (and dereferencing in sum)
    int sum = 0;
    for(auto i = v.begin(); i != v.end(); ++i)
        sum += *i;  
    return sum;

    4. oppure in one-line
    return std::accumulate(v.begin(), v.end(), 0);
    */
}


int main() 
{
    // Three ways of declaring and initializing vectors.
    vector<int> v_1{0, 1, 2};
    vector<int> v_2 = {3, 4, 5};
    vector<int> v_3;
    v_3 = {6};

    /*
    vector<int> a = {0, 1, 2, 3, 4};
    for(int i : a)
        cout << a[i] << " ";    
    cout << "\n";

    // simple loop
    for (int i=0; i < 5; i++) {
      cout << i << "\n";
    }
    */

    /* Loop  */
    // Post-increment assigns i to c and then increments i (MOST USED)
    auto i = 1;
    auto c = i++;
    cout << "Post-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";  // =1 (assign first, then increment)
    cout << "The value of i is: " << i << "\n";  // =2    
    // Pre-increment increments i, then assigns to c.    
    i = 1;    // Reset i to 1.
    c = ++i;
    cout << "Pre-increment example:" << "\n";
    cout << "The value of c is: " << c << "\n";  // =2  (assing and increment)
    cout << "The value of i is: " << i << "\n";  // =2
    // Decrement i;
    i--;
    cout << "Decrement example:" << "\n";
    cout << "The value of i is: " << i << "\n";  // = 1

    /* Loop a 2-dim vect  */
    vector<vector<int>> b {{1, 2}, {3, 4}, {5, 6}};
    // 1. index-based
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            cout << b[i][j] << "\n";
        }
    }    
    // 1. bis index-based (2-dim: first rows, then cols)
    for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[i].size(); j++) {
            cout << b[i][j];
        }
        cout << "\n";
    }

    // 2. range-based    
    for (auto i: b) {
        for (int j: i) {
            cout << j << "\n";
        }
    }
   
    // Creating a 2D vector.
    vector<vector<int>> v{{1,2}, {3,4}};    
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)  // NB: for container "range-based loop" (as here) or index-based
    {   cout << word << " ";
    }
    cout << endl;

    // call a function
    auto ii = 3;
    int j = 5;
    cout << AdditionFunction(ii, j) << "\n";


    // reading a file (if successful is true, else false)
    // std::ifstream my_file; my_file.open("1.board"); // or in one-line below
    std::ifstream my_file("1.board");
    if (my_file) {
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << "\n";
        }
    }    
    else {
        std::cout << "The file stream does not exist!" << "\n";
    }
    
    // store line into variables
    string a("1 2 3");
    std::istringstream my_stream(a);  // initialised with string a
    int n;
    /*
    my_stream >> n;  // stream first element into n (i.e. 1) (>> is the extractor operator)
    cout << n << "\n";
    */
    while(my_stream){
        my_stream >> n;
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";
        }
    }
    // >> writes the stream to the variable on the right and returns the istringstream object, so it can be a bool
    my_stream.clear();  // otherwise eof will prevent any operation
    my_stream.seekg(0, std::istringstream::beg);
    while (my_stream >> n) {
      cout << "That stream (again) was successful: " << n << "\n";
    }
    cout << "The stream (again) has failed." << "\n";

    // string with mixed types (i.e. not just int and whitespaces as above) 
    string bb("1,2,3");  // NB: 3 not printed if not followed by ,
    istringstream my_stream2(bb);
    char cr;
    // int n;
    while (my_stream2 >> n >> cr) {
      cout << "That stream was successful:" << n << " " << cr << "\n";
    }
    cout << "The stream has failed." << "\n";

}
