#ifndef PETDOG_H
#define PETDOG_H
#include "Pets.h"
#include <iostream>

class PetDog : public Pets
{
    public:
        PetDog(string breed, string color, int birthYear) : Pets(breed, color, birthYear) 
        {
            cout << "Pet dog constructed " << endl;
        }
        ~PetDog()
        {
            cout << "Pet dog deconstructed" << endl;
        }

    void displayInfo() const override
    {
        cout << "Pet Dog - Breed: " << breed << ", Color: " << color << ", Birth Year: " << birthYear << endl;
    }
};



#endif