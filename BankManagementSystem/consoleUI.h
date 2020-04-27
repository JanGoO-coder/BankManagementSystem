string getAccountUserName() {
	string accName = "";
	cout << "\n[User Name] ";
	cin.ignore();
	getline(cin, accName);
	return accName;
}

int getAccountPassword() {
	int accPass = 0;
	cout << "\n[Password] ";
	cin >> accPass;
	return accPass;
}

bool getAccountType() {
	bool pickAccount = false;
	cout << "\n[0 for Current Account] [1 for Saving Account]" << endl;
	cout << "[Account Type] ";
	cin >> pickAccount;
	return pickAccount;
}

string getAccountNumber() {
	string accNum = "";
	cout << "\n[Account Number] ";
	cin.ignore();
	getline(cin, accNum);
	return accNum;
}