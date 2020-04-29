string getAccountUserName() {
	string accName = "";
	cout << setfill(' ');
	cout << "\n\n" << setw(25) << "[User Name] >> ";
	cin.ignore();
	getline(cin, accName);
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
	cin.ignore();
	getline(cin, accNum);
	return accNum;
}

string generateAccountNumber() {
	const string ACN = "ACN";
	static int num = 0;
	string accNum = ACN;
	accNum = accNum + to_string(++num);
	return accNum;
}