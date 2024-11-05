#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
using namespace std;

class FractionClass
{
private:
    int numerator;
    int denominator;

    void simplify() {
        int aNumerator =abs(numerator);
        int aDenominator = abs(denominator);

        while (aDenominator != 0) 
        {
            int placeHolder = aDenominator;
            aDenominator = aNumerator % aDenominator;
            aNumerator = placeHolder;
        }

        numerator = numerator/aNumerator;
        denominator = denominator/aNumerator;
    }



public:
    FractionClass(int num=0, int denom = 1) : numerator(num), denominator(denom) 
    {
        if (denominator == 0) 
        {
            cout << "Error: Denominator can not be zero." << endl;
            numerator = 0;
            denominator = 1;
        } 
        simplify();
    }

    FractionClass operator+(const FractionClass& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator =  denominator * other.denominator;

        FractionClass result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }

    bool operator == (const FractionClass& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator < (const FractionClass& other) const {
    return numerator * other.denominator < other.numerator * denominator;
    }


    friend ostream& operator << (ostream& os, const FractionClass& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    friend istream& operator >> (istream& is, FractionClass& fraction) {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        if (fraction.denominator == 0) {
            cerr << "Error: Denominator can not be zero." << endl;
            fraction.numerator = 0 ;
            fraction.denominator = 1;
        }
        fraction.simplify();
        return is;
    }
    
};


template <class Type>
Type findMax(Type num1, Type num2) 
{
    if (num1 < num2) 
    {
        return num2;
    } 
    else
    {
        return num1;  
    }
}

int main() {
    ifstream inputFile("fractions.txt");
    ofstream outputFile("results.txt");

    if (!inputFile) {
        cerr << "Failed to open input file" << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Failed to open output file" << endl;
        return 1;
    }


    FractionClass fraction1, fraction2;

    while (inputFile >> fraction1 >> fraction2) 
    {
        FractionClass sum = fraction1 + fraction2;
        outputFile << fraction1 << " + " << fraction2 << " = " << sum << endl;

        if (fraction1 == fraction2) 
        {
            outputFile << fraction1 << " is equeal to " << fraction2 << endl;
        } else 
        {
            outputFile <<fraction1 << " is not equal to " << fraction2 << endl;
        }

        FractionClass maxFraction = findMax(fraction1, fraction2);
        outputFile << "Max Fraction: " << maxFraction << endl;
    }

    inputFile.close();
    outputFile.close();


    return 0;
}


