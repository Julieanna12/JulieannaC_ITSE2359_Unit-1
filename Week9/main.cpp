// main.cpp
#include <iostream>
#include "BankAccountClass.h"
#include "ExceptionClass.h"
using namespace std;


void performWithdrawal(BankAccount& account, double amount) {
    account.withdraw(amount);  // This may throw an exception if funds are insufficient
}

int main() {
    try {
        // Creates a BankAccount object with an initial balance of 1000
        BankAccount account("123456789", 1000.0);

        // Deposit 500
        account.deposit(500);

        // Try withdrawing 2000 should trigger the InsufficientFunds exception
        performWithdrawal(account, 2000);

    } catch (const InsufficientFunds& e) {
        cerr << e.what() << endl;  // Handle InsufficientFunds exception
    } catch (const NegativeDeposit& e) {
        cerr << e.what() << endl;  // Handle NegativeDeposit exception
    } catch (const std::exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;  // Catch any other exceptions
    }

    return 0;
}
