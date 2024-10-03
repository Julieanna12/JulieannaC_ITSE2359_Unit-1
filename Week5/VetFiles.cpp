#include <iostream>
#include "PetDog.h"
#include "PetCat.h"
using namespace std;

int main()
{
    PetDog JuliesPet("Schnauzer", "Charcoal", 2021);
    PetDog FernsPet("Maltese", "White", 2021);
    PetCat ItaleesPet("Calico", "Tri-color(White,Orange,Black)", 2016);
    PetDog LivsPet("Terrier", "Brown", 2020);

    JuliesPet.displayInfo();
    FernsPet.displayInfo();
    ItaleesPet.displayInfo();
    LivsPet.displayInfo();

    return 0;
}