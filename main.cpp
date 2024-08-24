#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("student_data.txt");

    if (!inFile){
        std::cout << "File was not found" << endl;
    }
    int size = 53;
    string name[size];
    int age[size];
    double GPA[size];
    double sum = 0;
    double gpa_average = 0;
    double highest_gpa = 0;
    int location;
    int oldest_age = 0;
    int youngest_age = 0;
    
   for (int i = 0; i < size; ++i) // sorts the file's data into arrays
   {
    inFile >> name[i];
    inFile >> age[i];
    inFile >> GPA[i];
    }
    
    
    for (int i = 0; i < size; ++i) // finds gpa average
        sum += GPA[i];
    gpa_average = (double)(sum / size);

    std::cout << "GPA Average: " << gpa_average << endl; //prints the gpa average

    for (int i = 1; i < size; ++i) //finds the highest gpa
    {
        if(GPA[0] < GPA[i])
            GPA[0] = GPA[i];
    highest_gpa = GPA[0];
    }
    std::cout << "Highest GPA " << highest_gpa << endl;
    std::cout << "These students have the highest GPA: ";
    for (int i = 1; i < size; ++i) //finds who has the highest gpa
        if (GPA[i] == highest_gpa)
            std::cout << name[i] << ", ";
    

     for (int i = 1; i < size; ++i) // finds the oldest age
        if(age[0] < age[i])
            age[0] = age[i];
     oldest_age = age[0]; 

     for (int i = 1; i < size; ++i) // finds the youngest age
        if(age[0] > age[i])
            age[0] = age[i];
    youngest_age = age[0]; 
    
    std::cout << endl << "Oldest age: " << oldest_age << endl << "These students are the oldest: ";
    for (int i = 1; i < size; ++i) // finds who is the oldest
        if (age[i] == oldest_age)
            std::cout << name[i] << ", ";

std::cout << endl << "Youngest age: " << youngest_age << endl << "These students are the younguest: ";
    for (int i = 1; i < size; ++i) // finds who is the youngest
        if (age[i] == youngest_age)
            std::cout << name[i] << ",";

   inFile.close();

    
}