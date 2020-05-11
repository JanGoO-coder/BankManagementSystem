//#include <iostream>
//#include <string>
//#include <iomanip>
//using namespace std;

class CustomerAccount {
public:
    string customerAccountNumber;
    int customerAccountBalance;
    bool customerAccountType;
    string customerAccountUserName;
    int customerAccountPassword;
    CustomerAccount* nextCustomer;
    CustomerAccount* prevCustomer;

    CustomerAccount(string customerAccountUserName, int customerAccountPassword, bool customerAccountType, int customerAccountBalance = 0) {
        this->customerAccountNumber = generateCustomerAccountNumber(); // auto generated account number
        this->customerAccountBalance = customerAccountBalance;
        this->customerAccountType = customerAccountType;
        this->customerAccountUserName = customerAccountUserName;
        this->customerAccountPassword = customerAccountPassword;
        this->nextCustomer = 0; this->prevCustomer = 0;
    }
};

class CustomerAccountDataList {
public:
    CustomerAccount* head;
    CustomerAccountDataList() { head = 0; }

    void createNewCustomerAccount() {
        CustomerAccount* newAccount = new CustomerAccount(getAccountUserName(), getAccountPassword(), getAccountType());
        if (head == 0) {
            head = newAccount;
            cout << "\n\n" << setw(80) << "Your Account Has Been Created\n" << endl;
        }
        else {
            newAccount->nextCustomer = head;
            head->prevCustomer = newAccount;
            head = newAccount;
            cout << "\n\n" << setw(80) << "Your Account Has Been Created\n" << endl;
        }
    }

    CustomerAccount* searchCustomerAccount(string accNum) {
        bool check = false;
        CustomerAccount* temp = head;
        if (head == 0) {
            cout << "There is No Account Data" << endl;
        }
        else {
            while (temp != 0) {
                if (temp->customerAccountNumber == accNum) {
                    check = true;
                    break;
                }
                temp = temp->nextCustomer;
            }
        }

        if (!check) {
            temp = NULL;
        }

        return temp;
    }

    void removeCustomerAccount(string accNum) {
        CustomerAccount* accountTodelete = searchCustomerAccount(accNum);
        CustomerAccount* temp = accountTodelete->prevCustomer;
        if (accountTodelete == NULL) {
            cout << "\n" << setw(80) << "Account Not Found" << endl;
        }
        else {
            if (head == 0) {
                cout << "\n" << setw(80) << "No Account to Delete" << endl;
            }
            else {
                if (head == accountTodelete) { // firs node in the list
                    if (accountTodelete->nextCustomer == 0) {
                        head = 0;
                    }
                    else {
                        accountTodelete->nextCustomer->prevCustomer = 0;
                        head = accountTodelete->nextCustomer;
                    }
                }
                else if (accountTodelete->nextCustomer == 0) { // last node in the list
                    accountTodelete->prevCustomer = 0;
                    temp->nextCustomer = 0;
                }
                else { // in-between the list
                    temp->nextCustomer = accountTodelete->nextCustomer;
                    temp->nextCustomer->prevCustomer = accountTodelete->prevCustomer;
                }
            }
        }
    }

    void displayCustomerAccountData(string accNum) {
        CustomerAccount* accountToDispay = searchCustomerAccount(accNum);
        CustomerAccount* temp = accountToDispay;

        cout << "\n" << setw(80) << "Account Data of your search is in the table bellow\n" << endl;

        if (temp != NULL) {
            string accType = "";
            if (temp->customerAccountType) 
                accType = "Saving Account";
            else 
                accType = "Current Account";

            cout << setw(20) << "Account Number | "
                << setw(20) << "Account Name | "
                << setw(20) << "Account Type | "
                << setw(20) << "Account Balance" << endl;
            cout << setw(17) << temp->customerAccountNumber << " | "
                << setw(17) << temp->customerAccountUserName << " | "
                << setw(17) << accType << " | "
                << setw(20) << temp->customerAccountBalance << endl;
        }
        else {
            cout << "\nAccount Data Not Found" << endl;
        }
    }

    bool logIn(CustomerAccount* logInAccount, int passW) {
        bool isLogedIn = false;
        if (logInAccount->customerAccountPassword == passW) {
            isLogedIn = true;
        }
        return isLogedIn;
    }

    void updateCustomerAccountUserName(string accNum, string userName) {
        CustomerAccount* accToUpdate = searchCustomerAccount(accNum);
        accToUpdate->customerAccountUserName = userName;
    }

    void updateCustomerAccountPassword(string accNum, int password) {
        CustomerAccount* accToUpdate = searchCustomerAccount(accNum);
        accToUpdate->customerAccountPassword = password;
    }

    void updateCustomerAccountBalance(string accNum, int balance) {
        CustomerAccount* accToUpdate = searchCustomerAccount(accNum);
        accToUpdate->customerAccountBalance = balance;
    }

    void displayCustomerAccountsData() {
        CustomerAccount* temp = head;
        string accType = "";

        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {

            cout << "\n" << setw(80) << "Account Data of All the Account is in the Table bellow\n" << endl;

            cout << setw(20) << "Account Number | "
                << setw(20) << "Account Name | "
                << setw(20) << "Account Type | "
                << setw(20) << "Account Balance" << endl;
            while (temp != 0) {
                if (temp->customerAccountType)
                    accType = "Saving Account";
                else
                    accType = "Current Account";

                cout << setw(17) << temp->customerAccountNumber << " | "
                    << setw(17) << temp->customerAccountUserName << " | "
                    << setw(17) << accType << " | "
                    << setw(20) << temp->customerAccountBalance << endl;
                temp = temp->nextCustomer;
            }
        }
    }
};

class EmployeeAccount {
public:
    string employeeAccountNumber;
    string employeeAccountName;
    int employeeAccountPassword;
    EmployeeAccount* nextEmployee;
    EmployeeAccount* prevEmployee;

    EmployeeAccount(string employeeAccountName, string employeeAccountNumber, int employeeAccountPassword) {
        this->employeeAccountNumber = employeeAccountNumber;
        this->employeeAccountName = employeeAccountName;
        this->employeeAccountPassword = employeeAccountPassword;
    }
};

class EmployeeAccountDataList {
public:
    EmployeeAccount* head;
    EmployeeAccountDataList() { head = 0; }

    void createNewEmployeeAccount() {
        EmployeeAccount* newAccount = new EmployeeAccount(getAccountUserName(), generateEmployeeAccountNumber(), getAccountPassword());
        if (head == 0) {
            head = newAccount;
            cout << "\n\n" << setw(80) << "Your Employee Account Has Been Created\n" << endl;
        }
        else {
            newAccount->nextEmployee = head;
            head->prevEmployee = newAccount;
            head = newAccount;
            cout << "\n\n" << setw(80) << "Your Employee Account Has Been Created\n" << endl;
        }
    }

    EmployeeAccount* searchEmployeeAccount(string accNum) {
        bool check = false;
        EmployeeAccount* temp = head;
        if (head == 0) {
            cout << "There is No Account Data" << endl;
        }
        else {
            while (temp != 0) {
                if (temp->employeeAccountNumber == accNum) {
                    check = true;
                    break;
                }
                temp = temp->nextEmployee;
            }
        }

        if (!check) {
            temp = NULL;
        }

        return temp;
    }

    void removeEmployeeAccount(string accNum) {
        EmployeeAccount* accountTodelete = searchEmployeeAccount(accNum);
        EmployeeAccount* temp = accountTodelete->prevEmployee;
        if (accountTodelete == NULL) {
            cout << "\n" << setw(80) << "Account Not Found" << endl;
        }
        else {
            if (head == 0) {
                cout << "\n" << setw(80) << "No Account to Delete" << endl;
            }
            else {
                if (head == accountTodelete) { // firs node in the list
                    if (accountTodelete->nextEmployee == 0) {
                        head = 0;
                    }
                    else {
                        accountTodelete->nextEmployee->prevEmployee = 0;
                        head = accountTodelete->nextEmployee;
                    }
                }
                else if (accountTodelete->nextEmployee == 0) { // last node in the list
                    accountTodelete->prevEmployee = 0;
                    temp->nextEmployee = 0;
                }
                else { // in-between the list
                    temp->nextEmployee = accountTodelete->nextEmployee;
                    temp->nextEmployee->prevEmployee = accountTodelete->prevEmployee;
                }
            }
        }
    }

    bool logIn(EmployeeAccount* logInAccount, int passW) {
        bool isLogedIn = false;
        if (logInAccount != NULL) {
            if (logInAccount->employeeAccountPassword == passW) {
                isLogedIn = true;
            }
        }
        return isLogedIn;
    }

    void displayEmployeeAccountData(string accNum) {
        EmployeeAccount* accountToDispay = searchEmployeeAccount(accNum);
        EmployeeAccount* temp = accountToDispay;

        cout << "\n" << setw(80) << "Account Data of your search is in the table bellow\n" << endl;

        if (temp != 0) {
            cout << setw(20) << "Account Number | "
                << setw(17) << "Account Name" << endl;
            cout << setw(17) << temp->employeeAccountNumber << " | "
                << setw(20) << temp->employeeAccountName << endl;
        }
        else {
            cout << "\nAccount Data Not Found" << endl;
        }
    }

    void displayEmployeeAccountsData() {
        EmployeeAccount* temp = head;

        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            cout << "\n" << setw(80) << "Account Data of All the Account is in the Table bellow\n" << endl;

            cout << setw(20) << "Account Number | "
                << setw(20) << "Account Name | "
                << setw(17) << "Account Type"<< endl;
            while (temp != 0) {
                cout << setw(17) << temp->employeeAccountNumber << " | "
                    << setw(17) << temp->employeeAccountName << " | "
                    << setw(17) << "Employee" << endl;
                temp = temp->nextEmployee;
            }
        }
    }
};

//class ATM {
//    
//public:
//    ATM() {
//        
//    }
//
//    bool depositMoney() {
//
//    }
//
//    bool depositMoney() {
//
//    }
//
//    bool transferMoney() {
//
//    }
//
//    bool changePassword() {
//
//    }
//
//    bool transactionHistory() {
//
//    }
//};

class Bank: public CustomerAccountDataList, public EmployeeAccountDataList {
public:
    /*ATM moneyMachine;*/
    CustomerAccountDataList CADL;
    EmployeeAccountDataList EADL;

    Bank() {}
};