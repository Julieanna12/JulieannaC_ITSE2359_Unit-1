#include <iostream>
#include <fstream>
using namespace std;


struct Student
{
    string FullName;
    int Age;
    float GPA;
};

void printStudent(Student s)
{
    cout << "Student Information:\n";
    cout << "Name: " << s.FullName << endl;
    cout << "Age: " << s.Age << endl;
    cout << "GPA: " << s.GPA << endl;

}
 //int myFunction(Student x)

        /*int ArrayLocation;
        if (x.FullName = )
        {
             ++ArrayLocation;
             return ArrayLocation
        }
             else 
             {
                return std::cout << "Name not found" << endl;
            }*/

        




int main()
{
    ifstream inFile("student_data.txt");

    if (!inFile)
    {
        cout << "File was not found" << endl;
    }
    
    int size = 0;
    string line;
    while(getline(inFile, line))
    {
      ++size;
    }
    inFile.close(); 
    // closed inFile and opened the file again in a different variable to 
    //read the file from the beginning again
    

    ifstream StudentFile("student_data.txt");

    if (!StudentFile)
    {
        cout << "File was not found" << endl;
    }

    Student students[size];
    
  
   for (int i = 0; i < size; ++i) // sorts the file's data into arrays
   {
    StudentFile >> students[i].FullName;
    StudentFile >> students[i].Age;
    StudentFile >> students[i].GPA;
    
    }
    for(int i = 0; i < size; ++i)
    {
        printStudent(students[i]);
    }
    int counter = 0;

    string SearchName;
    cout << "\nEnter student's name that you are looking for:\n";
    cin >> SearchName;
    for (int i = 0; i < size; ++i)
        if (SearchName == students[i].FullName )
        {
            //cout << SearchName << " is in the array at position " << i << endl;
             printStudent(students[i]);
             
        }
        else 
        {
            counter++;
        }
    if (counter >= size)
    {
        cout << "Name not found" << endl;
    }
 
    
    StudentFile.close();

    return 0;
}