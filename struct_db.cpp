#include<iostream>

using namespace std;

struct StudentIdentifiers
{
    string FirstName;
    string LastName;
    int ID_Num;
};

struct GPA
{
    double GPA;
};

struct Major
{
    string DegreeType;
    string DegreeField;
};



int main()
{
    StudentIdentifiers student1;
    cout << "Enter Student First name: ";
    getline(cin, student1.FirstName);
    cout << "Enter Student Last name: ";
    getline(cin,student1.LastName);
    cout << "Enter Student ID number: ";
    cin >> student1.ID_Num;
    cout << student1.FirstName << " "<< student1.LastName << endl; 
    cout << student1.ID_Num << endl;
}