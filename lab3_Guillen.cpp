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
};

int Account::totalAccounts = 0;

int main() {
    Account c1("Juan", 1000);
    return 0;
}