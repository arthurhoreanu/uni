#include "BankAccount.h"
#include <iostream>
#include <fstream>

BankAccount::BankAccount()
        : accountNumber(0), name(""), balance(0.0) {}

BankAccount::BankAccount(int accountNumber, const std::string& name, double balance)
        : accountNumber(accountNumber), name(name), balance(balance) {}

void BankAccount::deposit(double amount) {
    balance += amount;
    std::cout << "Deposited: " << amount << ". New balance: " << balance << std::endl;
}

bool BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrew: " << amount << ". New balance: " << balance << std::endl;
        return true;
    } else {
        std::cout << "Insufficient funds" << std::endl;
        return false;
    }
}

double BankAccount::getBalance() const {
    return balance;
}