
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "consoleUI.h"

class Account {
public:
    string accountNumber;
    int accountBalance;
    bool accountType;
    string accountUserName;
    int accountPassword;
    Account* next;
    Account* prev;

    Account(string accountUserName, int accountPassword, bool accountType, int accountBalance = 0) {
        accountNumber = ""; //static
        this->accountBalance = accountBalance;
        this->accountType = accountType;
        this->accountUserName = accountUserName;
        this->accountPassword = accountPassword;
        this->next = 0; this->prev = 0;
    }
};

class AccountDataList {
public:
    Account* head;
    AccountDataList() { head = 0; }

    void createNewAccount() {
        Account* newAccount = new Account(getAccountUserName(), getAccountPassword(), getAccountType());
        if (head == 0) {
            head = newAccount;
            cout << "\n\nYour Account Has Been Created" << endl;
        }
        else {
            newAccount->next = head;
            head->prev = newAccount;
            head = newAccount;
            cout << "\n\nYour Account Has Been Created" << endl;
        }
    }

    Account* searchAccount(string accNum) {
        Account* temp = head;
        while (temp != 0) {
            if (temp->accountNumber == accNum) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    void deleteAccount() {
        Account* accToDelete = searchAccount(getAccountNumber());
        Account* temp = accToDelete;
        if (temp->prev == 0) {
            head->prev = 0;
            temp->next = 0;
            temp = 0;
            cout << "\n\nAccount Has Been Deleted" << endl;
        }
        else if (temp->next == 0) {
            temp->prev->next = 0;
            temp->prev = 0;
            temp = 0;
            cout << "\n\nAccount Has Been Deleted" << endl;
        }
        else {
            temp = accToDelete->prev;
            temp->next = accToDelete->next;
            temp->next->prev = temp;
            cout << "\n\nAccount Has Been Deleted" << endl;
        }
    }

    void dispalyAccountData() {
        Account* temp = head;
        if (temp == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            cout << setw(17) << "Account Number | "
                << setw(15) << "Account Name | "
                << setw(15) << "Account Type | "
                << setw(15) << "Account Balance" << endl;
            while (temp != 0) {
                cout << "\t" << temp->accountNumber
                    << "\t" << temp->accountUserName
                    << "\t" << temp->accountType
                    << "\t" << temp->accountBalance << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    AccountDataList ADL;
    ADL.createNewAccount();
    ADL.dispalyAccountData();
}