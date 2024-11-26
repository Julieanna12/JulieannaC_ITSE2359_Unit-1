// BankAccount.cpp
#include "BankAccountClass.h"
#include "ExceptionClass.h"
#include <iostream>
using namespace std;

// Constructor to initialize balance and account number
BankAccount::BankAccount(const std::string& accNumber, double initialBalance) 
    : accountNumber(accNumber), balance(initialBalance) {}

// Method to withdraw money
void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        throw InsufficientFunds();  // Throw InsufficientFunds exception
    }
    balance -= amount;
    std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
}

// Method to deposit money
void BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw NegativeDeposit();  // Throw NegativeDeposit exception
    }
    balance += amount;
    std::cout << "Deposit successful. New balance: " << balance << std::endl;
}

// Getter for balance
double BankAccount::getBalance() const {
    return balance;
}
