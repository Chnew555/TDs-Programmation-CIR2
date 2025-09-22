#include <string>
#include <iostream>
using namespace std;

class BankAccount {
protected:
    int number;
    string owner;
    float balance;
public:
    BankAccount(int n, string o, float b = 0.0)
        : number(n), owner(o), balance(b) {}

    virtual void deposit(float amount) {
        balance += amount;
    }

    virtual bool withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    float getBalance() const { return balance; }
};

class CheckingAccount : public BankAccount {
    float overdraftLimit;
public:
    CheckingAccount(int n, string o, float b, float limit)
        : BankAccount(n, o, b), overdraftLimit(limit) {}

    bool withdraw(float amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    bool transfer(float amount, BankAccount& other) {
        if (withdraw(amount)) {
            other.deposit(amount);
            return true;
        }
        return false;
    }
};

class SavingsAccount : public BankAccount {
    float annualInterestRate;
public:
    SavingsAccount(int n, string o, float b, float rate)
        : BankAccount(n, o, b), annualInterestRate(rate) {}

    void depositAnnualInterest() {
        balance += balance * annualInterestRate;
    }
};
int main() {
    CheckingAccount cc(1001, "Alice", 500.0, 200.0);   // solde = 500, découvert autorisé = 200
    SavingsAccount sc(2001, "Bob", 1000.0, 0.05);      // solde = 1000, taux = 5%

    cout << "Solde initial compte courant (Alice) : " << cc.getBalance() << endl;
    cout << "Solde initial compte epargne (Bob) : " << sc.getBalance() << endl;

    // Dépôt
    cc.deposit(200);
    cout << "Alice depose 200 -> solde = " << cc.getBalance() << endl;

    // Retrait
    if (cc.withdraw(800)) {
        cout << "Alice retire 800 -> solde = " << cc.getBalance() << endl;
    }
    else {
        cout << "Retrait refuse (fonds insuffisants)" << endl;
    }

    // Transfert
    if (cc.transfer(100, sc)) {
        cout << "Alice transfere 100 a Bob" << endl;
    }
    cout << "Solde Alice = " << cc.getBalance() << endl;
    cout << "Solde Bob = " << sc.getBalance() << endl;

    // Ajout d'interets
    sc.depositAnnualInterest();
    cout << "Bob recoit interets annuels -> solde = " << sc.getBalance() << endl;

    return 0;
}
