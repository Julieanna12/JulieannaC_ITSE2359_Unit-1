#ifndef PETCAT_H
#define PETCAT_H
#include "Pets.h"
#include <iostream>

class PetCat : public Pets
{
    public:
        PetCat(string breed, string color, int birthYear) : Pets(breed, color, birthYear) 
        {
            cout << "Pet Cat constructed" << endl;
        }
        ~PetCat()
        {
            cout << "Pet Cat destructed " << endl;
        }

    void displayInfo() const override
    {
        cout << "Pet Cat - Breed: " << breed << ", Color: " << color << ", Birth Year: " << birthYear << endl;
    }
};



#endif