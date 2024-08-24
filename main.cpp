#include <iostream>
using namespace std;
int main() {
    ifstream inFile("student_data.txt");
    int size = 53;
    string names[size];
    string line;
    int age[size];
    float GPA[size];

    if (!inFile) {
        cerr << "File could not be found" << endl;

    }
    for (int i = 0; i < size; i++) {
        inFile >> names[i];
        getline(inFile, line);
    }
}