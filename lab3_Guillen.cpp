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
};

int Account::totalAccounts = 0;

int main() {
    Account c1("Juan", 1000);
    c1.deposit(200);

    if (c1.withdraw(500)) {
        cout << "Retiro exitoso. Saldo: " << c1.getBalance() << endl;
    }

    return 0;
}