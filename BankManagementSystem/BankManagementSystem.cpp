
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
        this->accountNumber = generateAccountNumber(); // auto generated account number
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
        if (temp == 0) {
            cout << "There is No Account Data" << endl;
        }
        else {
            while (temp != 0) {
                if (temp->accountNumber == accNum) {
                    break;
                }
                if (temp == 0) {
                    cout << "There is no Account Data" << endl;
                    break;
                }
                temp = temp->next;
            }
        }
        return temp;
    }

    void displayAccountData(string accNum) {
        Account* accountToDispay = searchAccount(accNum);
        Account* temp = accountToDispay;
        if (temp != 0) {
            cout << setw(17) << "Account Number | "
                << setw(15) << "Account Name | "
                << setw(15) << "Account Type | "
                << setw(15) << "Account Balance" << endl;
            cout << setw(14) << temp->accountNumber << " | "
                << setw(12) << temp->accountUserName << " | "
                << setw(12) << temp->accountType << " | "
                << setw(15) << temp->accountBalance << endl;
        }
    }

    void dispalyAccountsData() {
        Account* temp = head;
        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            cout << setw(17) << "Account Number | "
                << setw(15) << "Account Name | "
                << setw(15) << "Account Type | "
                << setw(15) << "Account Balance" << endl;
            while (temp != 0) {
                cout << setw(14) << temp->accountNumber << " | "
                    << setw(12) << temp->accountUserName << " | "
                    << setw(12) << temp->accountType << " | "
                    << setw(15) << temp->accountBalance << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    AccountDataList ADL;
    ADL.createNewAccount();
    ADL.dispalyAccountsData();
}