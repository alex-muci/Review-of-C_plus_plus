// The #include is a preprocessor command which is executed before the code is compiled. 
// e.g. it searches for the iostream header file and pastes its contents into the program. 
#include <iostream>   // iostream contains the declarations for the input/output stream objects.
#include <vector>
#include <string>
#include <fstream>  // file streaming classes
#include <sstream>  // contains istringstream object

// Namespaces are a way in C++ to group identifiers (names) together. They provide context for identifiers to avoid naming collisions. 
// using std::vector;

// The std namespace is the namespace used for the standard library. The using command adds std::cout to the global scope of the program. 
// this way you can use cout in your code instead of having to write std::cout.
using namespace std;  

/* recall enum in Python
import enum
class Colour(enum.Enum):
   white = 1  
   black = 2; blue = 3

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
      // The << operator is the stream insertion operator, and it writes what's on the right side of the operator to the left side.
      cout << line << "\n";
    }
  }
}

vector<int> ParseLine(string my_string) {
  int n; char cr;
  vector<int> v;
  std::istringstream my_stream(my_string);  // istringstream can be use as a boolen, i.e. false when nothing left to stream
  // extraction operator >> writes the stream to the variable on the right of the operator and returns the istringstream object, 
  // so the entire expression my_stream >> n is an istringstream object and can be used as a boolean!  (char used to contain ',') 
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

// ****************************************************************
/*  pass-by-value: 
      when the function is called on some data, a copy of that data is made, and the function operates on a copy of the data instead of the original data. 
      This is referred to as pass by value, since only a copy of the values of an object are passed to the function, and not the actual objects itself.

    pass-by-reference:
      it is possible to modify a variable from within the function. To do this, you must pass a reference to the variable a, instead of the value. 
      In C++, a reference is just an alternative name for the same variable. 
      To pass by reference, you simply need to add an ampersand & before the variable in the function declaration.

    see also explanations about pointers and references in the "references_and_pointers" folder
  */
// ****************************************************************


/*
C++ supports two notions of immutability:
- const: meaning roughly " I promise not to change this value."...The compiler enforces the promise made by const....
- constexpr: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants...

  const int j = i * 2;  // "j can only be evaluated at run time."
                        // "But I promise not to change it after it is initialized."
      
  constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."

But the compiler will catch a const variable that changes too.
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."

The major difference between const and constexpr, though, is that constexpr must be evaluated at compile time.
The compiler will catch a constexpr variable that cannot be evaluated at compile time.
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."

A common usage of const is to guard against accidentally changing a variable, especially when it is passed-by-reference as a function argument.
  e.g. 
  int sum(const std::vector<int> &v) {...}
  
*/

/* NB: init and goal in Search function below are arrays.

  vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {...}


  An array is a C++ container much like a vector, although without the ability to change size after initialization. 
  Arrays can be accessed and iterated over just as vectors. There are less flexible (no size change), but more memory efficient.
  Almost alwats is better to avoid arrays and prefer vectors (to avoid issue with memory management, whilst vectors are safer)

  https://www.programiz.com/cpp-programming/arrays  
  int x[6] = {19, 10, 8, 17, 9, 15};      // declare and initialize and array  
  double numbers[] = {7, 5, 6, 12, 35};  // initialize an array without specifying size, implied though

*/

int AdditionFunction(int i, int j) 
{
    return i + j;
}

int AdditionFunctionVec(vector<int> &v)
{
    int sum = 0;
    for(int &i : v)  // NB difference--> for(int i : v): sum += v[i]
        sum += i;
    return sum;

    /* 2. oppure:
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
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
    vector<int> aaa = {0, 1, 2, 3, 4};
    for(int i : aaa)
        cout << aaa[i] << " ";    
    cout << "\n";

    vector<int> bbb = {0, 1, 2, 3, 4};
    for(int &i : bbb)
        cout << i << " ";    
    cout << "\n";

    // simple loop
    for (int i=0; i < 5; i++) {
      cout << i << "\n";
    }
    */

    auto v_6 = {1, 2, 3};  // NB: auto is for automatic type inference

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
            cout << b[i][j] << "\n";
        }        
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
