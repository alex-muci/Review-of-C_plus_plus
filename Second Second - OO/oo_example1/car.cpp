#include <iostream>
#include "car.h"

// Method definitions for the Car class.
void Car::PrintCarData() 
{
    cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
}

void Car::IncrementDistance() 
{
    distance++;  // or: this->distance++;  // this is a 'pointer' to the current class instance.
}