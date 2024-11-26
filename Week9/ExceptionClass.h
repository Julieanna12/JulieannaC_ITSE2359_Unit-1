// Exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

// Custom Exception for Insufficient Funds
class InsufficientFunds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient funds for withdrawal!";
    }
};

// Custom Exception for Negative Deposit
class NegativeDeposit : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot deposit a negative amount!";
    }
};

#endif // EXCEPTIONS_H
