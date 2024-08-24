#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("student_data.txt");

    

    if (!inFile.is_open()){
        cout << "File was not found" << endl;
    }
    int size = 53
    string name[size];
    int age[size];
    double GPA[size];

    int firstindex = 0;
    while (!inFile.eof())
    {
        inFile >> name[firstindex];
        inFile >> age[firstindex];
        inFile >> GPA[firstindex];  
    }
    
    cout << name << " " << age << " " << GPA << endl;

    

        
    
    
}