//#include <iostream>
//#include <string>
//#include <iomanip>
//using namespace std;

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
            cout << "\n\n" << setw(80) << "Your Account Has Been Created\n" << endl;
        }
        else {
            newAccount->next = head;
            head->prev = newAccount;
            head = newAccount;
            cout << "\n\n" << setw(80) << "Your Account Has Been Created\n" << endl;
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
        string accType = "";

        if (temp->accountType) accType = "Saving Account";
        else accType = "Current Account";

        cout << "\n" << setw(80) << "Account Data of your seach is in the table bellow\n" << endl;

        if (temp != 0) {
            cout << setw(20) << "Account Number | "
                << setw(20) << "Account Name | "
                << setw(20) << "Account Type | "
                << setw(20) << "Account Balance" << endl;
            cout << setw(17) << temp->accountNumber << " | "
                << setw(17) << temp->accountUserName << " | "
                << setw(17) << accType << " | "
                << setw(20) << temp->accountBalance << endl;
        }
        else {
            cout << "\nAccount Data Not Found" << endl;
        }
    }

    bool logIn(Account* logInAccount, int passW) {
        bool isLogedIn = false;
        if (logInAccount->accountPassword == passW) {
            isLogedIn = true;
        }
        return isLogedIn;
    }

    void displayAccountsData() {
        Account* temp = head;
        string accType = "";

        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            if (temp->accountType) accType = "Saving Account";
            else accType = "Current Account";

            cout << "\n" << setw(80) << "Account Data of All the Account is in the Table bellow\n" << endl;

            cout << setw(20) << "Account Number | "
                << setw(20) << "Account Name | "
                << setw(20) << "Account Type | "
                << setw(20) << "Account Balance" << endl;
            while (temp != 0) {
                cout << setw(17) << temp->accountNumber << " | "
                    << setw(17) << temp->accountUserName << " | "
                    << setw(17) << accType << " | "
                    << setw(20) << temp->accountBalance << endl;
                temp = temp->next;
            }
        }
    }
};