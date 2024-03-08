#include <iostream>
using namespace std;

void ersteAufgabe() {
    string firstName, lastName;
    cout << "Vorname: ";
    cin >> firstName;
    cout << "Nachname: ";
    cin >> lastName;
    int length = firstName.length() + lastName.length();
    cout << "Hallo, " << firstName << " " << lastName << "!" << endl;
    cout << "Anzahl der Zeichen: " << length << endl;
}

void dritteAufgabe() {
    int lines, columns, sum=0, matrix[51][51];
    cout << "Lines: ";
    cin >> lines;
    cout << "Columns: ";
    cin >> columns;
    cout << "Matrix: ";
    for(int i = 1; i<=lines; i++)
        for(int j = 1; j<=columns; j++) {
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    cout << sum;
}

struct client{
    int number, postcode;
    string name, place;
}client[10];

class bankAccount {
public:
    bankAccount(int account_number, string name, double balance)
            : account_number_(account_number), name_(name), balance_(balance) {}

    void deposit(double amount) {
        balance_ += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance_ << endl;
    }

    bool withdraw(double amount) {
        if (balance_ >= amount) {
            balance_ -= amount;
            cout << "Withdrew: " << amount << ". New balance: " << balance_ << endl;
            return true;
        } else {
            cout << "Insufficient funds" << endl;
            return false;
        }
    }

    double get_balance() const {
        return balance_;
    }

private:
    int account_number_;
    string name_;
    double balance_;
};

int main() {
    //ersteAufgabe();
    /*
    cout << "Number: ";
    cin >> client[0].number;
    cout << "Name: ";
    cin >> client[0].name;
    cout << "Postcode: ";
    cin >> client[0].postcode;
    cout << "Place: ";
    cin >> client[0].place;
    cout << client[0].number << "\n";
    cout << client[0].name << "\n";
    cout << client[0].postcode << "\n";
    cout << client[0].place;
    */
    //dritteAufgabe();
    bankAccount my_account(12345, "John Doe", 1000.00);
    my_account.deposit(500.00);
    my_account.withdraw(200.00);
    double balance = my_account.get_balance();
    cout << "Balance: " << balance << endl;
}