// BankAccount.h
#ifndef BANKACCOUNTCLASS_H
#define BANKACCOUNTCLASS_H

#include <string>

// Forward declaration of custom exceptions
class InsufficientFunds;
class NegativeDeposit;

class BankAccount {
private:
    double balance;
    std::string accountNumber;

public:
    // Constructor to initialize balance and account number
    BankAccount(const std::string& accNumber, double initialBalance);

    // Methods for deposit and withdrawal
    void withdraw(double amount);
    void deposit(double amount);

    // Getter for balance
    double getBalance() const;
};

#endif // BANKACCOUNT_H
