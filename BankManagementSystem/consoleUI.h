string getAccountUserName() {
	string accName = " ";
	cout << setfill(' ');
	cout << "\n\n" << setw(25) << "[User Name] >> ";
	getline(cin >> ws, accName);
	return accName;
}

int getAccountPassword() {
	int accPass = 0;
	cout << setfill(' ');
	cout << "\n" << setw(25) << "[Password] >> ";
	cin >> accPass;
	return accPass;
}

bool getAccountType() {
	bool pickAccount = false;
	cout << setfill(' ');
	cout << "\n" << setw(80) << "Note: Enter \"0\" for Current Account & \"1\" for Saving Account" << endl;
	cout << "\n" << setw(25) << "[Account Type] >> ";
	cin >> pickAccount;
	return pickAccount;
}

string getAccountNumber() {
	string accNum = "";
	cout << setfill(' ');
	cout << setw(25) << "\n[Account Number] >> ";
	getline(cin >> ws, accNum);
	return accNum;
}

string generateCustomerAccountNumber() {
	const string CACN = "CACN";
	static int num = 0;
	string accNum = CACN;
	accNum = accNum + to_string(++num);
	return accNum;
}

string generateEmployeeAccountNumber() {
	const string EACN = "EACN";
	const string MACN = "Manager";
	string accNum = "";
	static int num1 = 0;
	static int num2 = 0;
	int choice = 0;

	cout << "[0] Employee | [1] Manager >> ";
	cin >> choice;

	switch (choice) {
		case 0: {
			accNum = EACN;
			accNum = accNum + to_string(++num1);
			break;
		}

		case 1: {
			accNum = MACN;
			accNum = accNum + to_string(++num2);
			break;
		}
	}
	return accNum;
}

int getAmount() {
	int ammount;
	cout << "\n" << setw(20) << "[Amount] >> ";
	cin >> ammount;
	return ammount;
}