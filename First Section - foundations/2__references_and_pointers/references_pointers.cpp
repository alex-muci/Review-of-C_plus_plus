#include <iostream>
using std::cout;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

#include <iostream>
using std::cout;

int* AddOnePointer(int& j) 
{
    // Increment the referenced int and return the
    // address of j. This is safer since reference exists outside the scope of the function
    j++;
    return &j;
}


int main() 
{
    int i = 1;
    
    // Declare a reference to i
    int& j = i;
    cout << "The value of j is: " << j << "\n";
    
    // Change the value of i
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";
    
    // Change the value of the reference
    // Since reference is just another name for the variable,
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";

    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    // cout << "The address of j is: " << &j << "\n"; // memory address would be the same in this case

    // POINTERS
    int a = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_a = &a;
    // Print the memory addresses of i and j
    cout << "The address of a is:          " << &a << "\n";
    cout << "The variable pointer_to_a is: " << pointer_to_a << "\n";
    cout << "The value of the variable pointed to by pointer_to_a is: " << *pointer_to_a << "\n";

    AddOne(pointer_to_a);
    cout << "The value of a is now: " << a << " (correct if 6)\n";

    int* my_pointer = AddOnePointer(a);    
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << " (correct if 7)\n";


}