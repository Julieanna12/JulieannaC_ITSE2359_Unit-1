#include<iostream>
using namespace std;

class Country 
{
    public:
        virtual void displayInfo() = 0;
    
        virtual ~Country()
        {
            cout << endl << "Country has been destructored." << endl;
        }
};

class USA : public Country
{
    public:
        void displayInfo() override 
        {
            cout << "Country Name: USA" << endl;
            cout << "Capital: Washington, D.C. " <<endl;
            cout << "Population: 331 million " <<endl;
        }
};

class Japan : public Country
{
    public :
        void displayInfo() override 
        {
            cout << endl << "Country Name: Japan" <<endl;
            cout << "Capital: Tokyo " <<endl;
            cout << "Population: 126 million " <<endl;
        }
};

class Germany : public Country
{
    public :
        void displayInfo() override 
        {
            cout << endl << "Country Name: Germany" <<endl;
            cout << "Capital: Berlin " <<endl;
            cout << "Population: 83 million " <<endl;
        }
};

class India : public Country
{
    public :
        void displayInfo() override 
        {
            cout << endl << "Country Name: India" <<endl;
            cout << "Capital: New Delhi " <<endl;
            cout << "Population: 1.366 billion " <<endl;
        }
};

int main()
{   
    int numCountries;
    cout << "What is the number of countries? " << endl;
    cin >> numCountries;

    Country** CountryArray = new Country*[numCountries];

    for (int i = 0; i < numCountries; i++)
    {
        switch (i) 
        { 
            case 0:
                CountryArray[i] = new USA();
                break;

            case 1:
                CountryArray[i] = new Japan();
                break;
            
            case 2:
                CountryArray[i] = new Germany();
                break;

            case 3:
                CountryArray[i] = new India();
                break;
            
    
        }
    }
    for (int i = 0; i < numCountries; i++)
    {
        CountryArray[i] -> displayInfo();
    }

    for (int i=0; i < numCountries; i++)
    {
        delete CountryArray[i];
    }
    delete[] CountryArray;



    return 0;
}