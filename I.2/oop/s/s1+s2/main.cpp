#include <iostream>
#include "BankAccount.h"
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
    BankAccount account1(123456, "John Doe", 1000.00);
    account1.deposit(500.00);
    account1.withdraw(200.00);
    std::cout << "Current balance: " << account1.getBalance() << std::endl;
}