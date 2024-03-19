#ifndef S1_S2_BANKACCOUNT_H
#define S1_S2_BANKACCOUNT_H
#include <string>

class BankAccount {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    BankAccount();
    BankAccount(int accountNumber, const std::string& name, double balance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif