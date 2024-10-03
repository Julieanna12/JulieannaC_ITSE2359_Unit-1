#ifndef PETS_H
#define PETS_H

#include<string>
using namespace std;

class Pets
{

    public:
        virtual void displayInfo() const=0;

    protected:  
        string breed;
        string color;
        int birthYear;
        Pets(string breedName, string colorName, int birthYearNum);

        ~Pets();
};






#endif