//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
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

    CustomerAccount(
        string customerAccountUserName, 
        int customerAccountPassword, 
        bool customerAccountType, 
        int customerAccountBalance = 0
    ) {
        this->customerAccountNumber = "CACN";
        this->customerAccountBalance = customerAccountBalance;
        this->customerAccountType = customerAccountType;
        this->customerAccountUserName = customerAccountUserName;
        this->customerAccountPassword = customerAccountPassword;
        this->nextCustomer = 0; this->prevCustomer = 0;
    }

    ~CustomerAccount() {}
};

class CustomerAccountDataList {
public:
    CustomerAccount* head;
    CustomerAccountDataList() { head = 0; }
    ~CustomerAccountDataList() {}
    friend class ATM;

    void writeDataOnFile(
        const string accNum,
        int accBal,
        string accName,
        int accPass,
        bool accT
    ) {
        ofstream customerDataWRITE;
        customerDataWRITE.open("database/customerData.csv", ios::app);

        if (customerDataWRITE.is_open()) {
            customerDataWRITE
                << accNum << ","
                << accBal << ","
                << accName << ","
                << accPass << ","
                << accT << "," << endl;
        }
        else { cout << "\n\nFile Not Open" << endl; }

        customerDataWRITE.close();
    }

    void updateFullFile() {
        CustomerAccount* temp = head;
        ofstream customerDataWRITE;
        customerDataWRITE.open("database/customerData.csv", ios::trunc);

        if (customerDataWRITE.is_open()) {
            while (temp != 0) {
                customerDataWRITE 
                    << temp->customerAccountNumber << ","
                    << temp->customerAccountBalance << ","
                    << temp->customerAccountUserName << ","
                    << temp->customerAccountPassword << ","
                    << temp->customerAccountType << "," << endl;
                temp = temp->nextCustomer;
            }
        }
        else { cout << "\n\nFile Not Open" << endl; }

        customerDataWRITE.close();
    }

    void createNewCustomerAccount(
        const string accNumber,
        int accBalance,
        string accUserName,
        int accPassword,
        bool accType
    ) {
        CustomerAccount* newAccount = new CustomerAccount(accUserName, accPassword, accType);
        newAccount->customerAccountNumber = accNumber;
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

        writeDataOnFile(
            accNumber,
            accBalance,
            accUserName,
            accPassword,
            accType
        );
    }

    void pushCustomerAccount(
        const string accNumber, 
        int accBalance, 
        string accUserName, 
        int accPassword, 
        bool accType
    ) {
        CustomerAccount* newAccount = new CustomerAccount(accUserName, accPassword, accType);
        newAccount->customerAccountNumber = accNumber;
        newAccount->customerAccountBalance = accBalance;
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

    void readDataFromFile() {
        CustomerAccount* temp = head; string line;
        string accountTypeString = "";
        string accountBalanceString = "";
        string accountPasswordString = "";
        string accountNameString = "";
        string accountNumberString = "";
        bool accountType = false;

        ifstream customerDataREAD;
        customerDataREAD.open("database/customerData.csv", ios::in | ios::app);
        
        if (customerDataREAD.is_open()) {
            while (getline(customerDataREAD, line)) {
                stringstream ss(line);
                getline(ss, accountNumberString, ',');
                getline(ss, accountBalanceString, ',');
                getline(ss, accountNameString, ',');
                getline(ss, accountPasswordString, ',');
                getline(ss, accountTypeString, ',');

                if (accountTypeString == "true") { accountType = true; }
                else { accountType = false; }


                if (line != "") {
                    pushCustomerAccount(
                        accountNumberString,
                        stoi(accountBalanceString),
                        accountNameString,
                        stoi(accountPasswordString),
                        accountType
                    );
                }
            }
        }
        else { cout << "\n\nFile Not Open" << endl; }

        customerDataREAD.close();
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

                updateFullFile();
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

        updateFullFile();
    }

    void updateCustomerAccountPassword(string accNum, int password) {
        CustomerAccount* accToUpdate = searchCustomerAccount(accNum);
        accToUpdate->customerAccountPassword = password;

        updateFullFile();
    }

    void updateCustomerAccountBalance(string accNum, int balance) {
        CustomerAccount* accToUpdate = searchCustomerAccount(accNum);
        accToUpdate->customerAccountBalance += balance;

        updateFullFile();
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

    void searchCustomerAccountsWithFirstLetter(char firstLetter) {
        CustomerAccount* temp = head;
        string accType = "";
        bool isFound = false;
        cout << setw(20) << "Account Number | "
            << setw(20) << "Account Name | "
            << setw(20) << "Account Type | "
            << setw(20) << "Account Balance" << endl;
        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            while (temp != 0) {
                if (firstLetter == temp->customerAccountUserName[0]) {
                    if (temp->customerAccountType)
                        accType = "Saving Account";
                    else
                        accType = "Current Account";

                    cout << setw(17) << temp->customerAccountNumber << " | "
                        << setw(17) << temp->customerAccountUserName << " | "
                        << setw(17) << accType << " | "
                        << setw(20) << temp->customerAccountBalance << endl;
                    temp = temp->nextCustomer;
                    isFound = true;
                }
                temp = temp->nextCustomer;
            }

            if (!isFound)
                cout << "\nNo User Found with Name starting with " << firstLetter << endl;
            else
                cout << "\nAll Userers with Name starting with " << firstLetter << " has been diplayed" << endl;
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

    ~EmployeeAccount() {}
};

class EmployeeAccountDataList {
public:
    EmployeeAccount* head;
    EmployeeAccountDataList() { head = 0; }
    ~EmployeeAccountDataList() {}

    void writeDataOnFile(
        string accNum,
        string accName,
        int accPass
    ) {
        ofstream employeeDataWRITE;
        employeeDataWRITE.open("database/employeeData.csv", ios::app);

        if (employeeDataWRITE.is_open()) {
            employeeDataWRITE
                << accNum << ","
                << accName << ","
                << accPass << "," << endl;
        }
        else { cout << "\n\nFile Not Open" << endl; }

        employeeDataWRITE.close();
    }

    void updateFullFile() {
        EmployeeAccount* temp = head;
        ofstream employeeDataWRITE;
        employeeDataWRITE.open("database/employeeData.csv", ios::trunc);

        if (employeeDataWRITE.is_open()) {
            while (temp != 0) {
                employeeDataWRITE
                    << temp->employeeAccountNumber << ","
                    << temp->employeeAccountName << ","
                    << temp->employeeAccountPassword << "," << endl;
                temp = temp->nextEmployee;
            }
        }
        else { cout << "\n\nFile Not Open" << endl; }

        employeeDataWRITE.close();
    }

    void createNewEmployeeAccount(
        string accNumber,
        string accUserName,
        int accPassword
    ) {
        EmployeeAccount* newAccount = new EmployeeAccount(
            accUserName,
            accNumber,
            accPassword
        );

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

        writeDataOnFile(
            accNumber,
            accUserName,
            accPassword
        );

    }

    void pushEmployeeAccount(
        string accNumber,
        string accUserName,
        int accPassword
    ) {
        EmployeeAccount* newAccount = new EmployeeAccount(
            accUserName,
            accNumber,
            accPassword
        );

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

    void readDataFromFile() {
        EmployeeAccount* temp = head; string line;
        string accountPasswordString = "";
        string accountNameString = "";
        string accountNumberString = "";

        ifstream employeeDataREAD;
        employeeDataREAD.open("database/employeeData.csv", ios::app);

        if (employeeDataREAD.is_open()) {
            while (getline(employeeDataREAD, line)) {

                stringstream ss(line);
                getline(ss, accountNumberString, ',');
                getline(ss, accountNameString, ',');
                getline(ss, accountPasswordString, ',');

                if (line != "") {
                    pushEmployeeAccount(
                        accountNumberString,
                        accountNameString,
                        stoi(accountPasswordString)
                    );
                }
            }
        }
        else { cout << "\n\nFile Not Open" << endl; }

        employeeDataREAD.close();
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

                updateFullFile();
            }
        }
    }

    

    void updateCustomerAccountUserName(string accNum, string userName) {
        EmployeeAccount* accToUpdate = searchEmployeeAccount(accNum);
        accToUpdate->employeeAccountName = userName;

        updateFullFile();
    }

    void updateCustomerAccountPassword(string accNum, int password) {
        EmployeeAccount* accToUpdate = searchEmployeeAccount(accNum);
        accToUpdate->employeeAccountPassword = password;

        updateFullFile();
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

    void searchEmployeeAccountsWithFirstLetter(char firstLetter) {
        EmployeeAccount* temp = head;
        bool isFound = false;

        cout << setw(20) << "Account Number | "
            << setw(20) << "Account Name | "
            << setw(17) << "Account Type" << endl;
        
        if (head == 0) {
            cout << "\nThere is no Account Data" << endl;
        }
        else {
            while (temp != 0) {
                if (firstLetter == temp->employeeAccountName[0]) {
                    cout << setw(17) << temp->employeeAccountNumber << " | "
                        << setw(17) << temp->employeeAccountName << " | "
                        << setw(17) << "Employee" << endl;
                    isFound = true;
                }
                temp = temp->nextEmployee;
            }

            if (!isFound)
                cout << "\nNo User Found with Name starting with " << firstLetter << endl;
            else
                cout << "\nAll Userers with Name starting with " << firstLetter << " has been diplayed" << endl;
        }
    }
};

class ATM{
    CustomerAccount* loggedInAccount;
    stack<string> atmHistory;
    stack<string> sessions;
    string currSession;
    string queueSession;
    CustomerAccount* head;
public:
    ATM() {
        loggedInAccount = 0; 
        head = 0;
    }

    void setHead(CustomerAccount* temp) {
        head = temp;
    }

    void updateFullFile(CustomerAccount* temp) {
        ofstream customerDataWRITE;
        customerDataWRITE.open("database/customerData.csv", ios::trunc);

        if (customerDataWRITE.is_open()) {
            while (temp != 0) {
                customerDataWRITE
                    << temp->customerAccountNumber << ","
                    << temp->customerAccountBalance << ","
                    << temp->customerAccountUserName << ","
                    << temp->customerAccountPassword << ","
                    << temp->customerAccountType << "," << endl;
                temp = temp->nextCustomer;
            }
        }
        else { cout << "\n\nFile Not Open" << endl; }

        customerDataWRITE.close();
    }

    void saveSessionName() {
        ofstream writeFile;
        writeFile.open("database/atmRecords/historySessionsNames.csv", ios::app);
        if (writeFile.is_open()) {
            writeFile << loggedInAccount->customerAccountNumber + currSession << endl;
        }
        else {
            cout << "File Not Open" << endl;
        }
        writeFile.close();
    }

    void readSessionName() {
        string line;
        ifstream readFile;
        readFile.open("database/atmRecords/historySessionsNames.csv");
        if (readFile.is_open()) {
            while (getline(readFile, line)) {
                sessions.push(line);
            }
        }
        else {
            cout << "File Not Open" << endl;
        }
        readFile.close();
    }

    void saveSession() {
        ofstream writeFile;
        writeFile.open("database/atmRecords/historySessions/" + loggedInAccount->customerAccountNumber + currSession + ".csv", ios::app);
        if (writeFile.is_open()) {
            while (!atmHistory.empty()) {
                writeFile << atmHistory.top() << endl;
                atmHistory.pop();
            }
        }
        else {
            cout << "File Not Open" << endl;
        }
        writeFile.close();
    }

    void readSession() {
        string line;
        while (!sessions.empty()) {
            queueSession = sessions.top();
            sessions.pop();
            if (queueSession[4] == loggedInAccount->customerAccountNumber[4]) {
                cout << "----------------------------------------" << endl;
                ifstream readFile;
                readFile.open("database/atmRecords/historySessions/" + queueSession + ".csv");
                if (readFile.is_open()) {
                    while (getline(readFile, line)) {
                        cout << line << endl;
                    }
                }
                else {
                    cout << "File Not Open" << endl;
                }
                readFile.close();
            }
        }
    }

    CustomerAccount* atmLogIn(
        CustomerAccount* accNumber, 
        int passW
    ) {
        bool isLogedIn = false;
        if (accNumber != NULL) {
            if (accNumber->customerAccountPassword == passW) {
                loggedInAccount = accNumber;
                atmHistory.push(loggedInAccount->customerAccountNumber + " logged in to the Account");
                isLogedIn = true;
            }
        }

        if (isLogedIn) {
            readAccSeries();
            currSession = "session" + to_string(++num3);
            writeAccSeries();
            return accNumber;
        }
        else {
            return NULL;
        }
    }

    void depositMoney(
        int depAmount
    ) {
        loggedInAccount->customerAccountBalance += depAmount;
        atmHistory.push(
            "Deposited Money " 
            + to_string(depAmount) 
            + " to Account " 
            + loggedInAccount->customerAccountNumber
        );
        updateFullFile(head);
    }

    void withdrawMoney(
        int witAmount
    ) {
        loggedInAccount->customerAccountBalance -= witAmount;
        atmHistory.push(
            "Withdraw Money " 
            + to_string(witAmount) 
            + " from Account " 
            + loggedInAccount->customerAccountNumber
        );
        updateFullFile(head);
    }

    void transferMoney( 
        CustomerAccount* recieverAccNum, 
        int amount
    ) {
        loggedInAccount->customerAccountBalance -= amount;
        recieverAccNum->customerAccountBalance += amount;
        atmHistory.push(
            "Transfered Money " 
            + to_string(amount) 
            + " from Account " 
            + loggedInAccount->customerAccountNumber 
            + " to Account " 
            + recieverAccNum->customerAccountNumber
        );
        updateFullFile(head);
    }

    void changePassword(
        int passW
    ) {
        loggedInAccount->customerAccountPassword = passW;
        atmHistory.push("Changed Password of Account " + loggedInAccount->customerAccountNumber );
        updateFullFile(head);
    }

    void displayBalance() { cout << loggedInAccount->customerAccountBalance; }

    void transactionHistory() {
        readSessionName();
        readSession();
    }

    ~ATM() {
        atmHistory.push(loggedInAccount->customerAccountNumber + " Logged Out");
        saveSessionName();
        saveSession();
    }
};

class Bank{
public:
    string branchName;
    int branchCode;

    ATM moneyMachine;
    CustomerAccountDataList CADL;
    EmployeeAccountDataList EADL;

    Bank() {
        branchName = "JanGoO Bank, Pakpattan Road, Pakpattan Sharif";
        branchCode = 60205;

        CADL.readDataFromFile();
        EADL.readDataFromFile();
        moneyMachine.setHead(CADL.head);
    }

    ~Bank() {}
};