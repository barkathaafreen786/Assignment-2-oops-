// Q9_BankAccount.cpp
#include <iostream>
#include <string>
#include <stdexcept> // for std::invalid_argument
using namespace std;

class BankAccount {
private:
    string accountNumber;   // kept private — encapsulated
    string ownerName;       // kept private
    double balance;         // private: only modified via methods

public:
    // Constructor using member initializer list to set immutable starting state
    BankAccount(const string &acctNo, const string &owner, double initialBalance = 0.0)
        : accountNumber(acctNo), ownerName(owner), balance(initialBalance)
    {
        // Basic validation in constructor
        if (initialBalance < 0.0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
    }

    // Deposit: only positive amounts allowed
    void deposit(double amount) {
        if (amount <= 0.0) {
            cout << "Deposit failed: amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << '\n';
    }

    // Withdraw: check for positive amount and sufficient funds
    bool withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "Withdrawal failed: amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Withdrawal failed: insufficient funds.\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << '\n';
        return true;
    }

    // Display account summary (read-only access to sensitive info)
    void display() const {
        cout << "Account: " << accountNumber << "\nOwner: " << ownerName
             << "\nBalance: " << balance << '\n';
    }

    // Read-only getter for balance (if external code needs to read balance safely)
    double getBalance() const { return balance; }

    // No public setter for balance -> prevents arbitrary external modification
};

int main() {
    try {
        BankAccount acct("ACC123456", "Asha Kumar", 1000.0);

        acct.display();

        acct.deposit(500.0);     // valid deposit
        acct.withdraw(200.0);    // valid withdrawal
  
       acct.withdraw(2000.0);   // fails: insufficient funds
        acct.deposit(-50.0);     // fails: negative deposit

        cout << "Final balance (via getter): " << acct.getBalance() << '\n';

        // The following line would be a compile-time error because balance is private:
        // acct.balance = 1000000.0; // ERROR: 'double BankAccount::balance' is private
        // (kept commented to show intentional encapsulation)
    }
    catch (const exception &ex) {
        cerr << "Error creating account: " << ex.what() << '\n';
    }
    return 0;
}
