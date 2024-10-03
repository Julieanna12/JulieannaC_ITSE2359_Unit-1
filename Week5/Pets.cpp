#include <iostream>
#include "Pets.h"
using namespace std;

Pets::Pets(string breedName, string colorName, int birthYearNum)
{
    breed = breedName;
    color = colorName;
    birthYear = birthYearNum;
    cout << "Pet constructor called for " << breed << endl;
}
Pets::~Pets()
{
    cout << "Pets destructor called for " << breed << endl;
}
 
