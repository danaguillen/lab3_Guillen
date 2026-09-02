#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string owner;
    double balance;
    static int totalAccounts;

public:
    Account(string owner, double balance) {
        this->owner = owner;
        this->balance = balance;
        totalAccounts = totalAccounts + 1;
    }

    Account(const Account& other) {
        this->owner = other.owner + " copia";
        this->balance = other.balance;
        totalAccounts = totalAccounts + 1;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
        }
        else {
            cout << "Error en deposito" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance = balance - amount;
            return true;
        }
        else {
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }

    bool operator==(const Account& other) const {
        return (this->balance == other.balance);
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void transfer(Account& other, double amount) {
        bool ok = this->withdraw(amount);
        if (ok == true) {
            other.deposit(amount);
            cout << "Transferencia lista" << endl;
        }
        else {
            cout << "No hay dinero para transferir" << endl;
        }
    }
};

int Account::totalAccounts = 0;

int main() {
    Account c1("Juan", 1000);
    Account c2("Maria", 500);
    Account c3("Pedro", 1000);

    cout << "Total de cuentas: " << Account::getTotalAccounts() << endl;

    if (c1 == c3) {
        cout << "Las cuentas son iguales" << endl;
    }
    else {
        cout << "Las cuentas son diferentes" << endl;
    }

    c1.deposit(200);

    bool pude = c2.withdraw(2000);
    if (pude == false) {
        cout << "No se pudo retirar" << endl;
    }

    c1.transfer(c2, 100);

    return 0;
}