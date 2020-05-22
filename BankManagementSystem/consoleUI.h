

void readAccSeries() {
	string line;
	string numString, num1String, num2String, num3String;

	ifstream readFile;
	readFile.open("database/accountSeriesNumber.csv");
	if (readFile.is_open()) {
		while (getline(readFile, line)) {
			stringstream ss(line);
			getline(ss, numString, ',');
			num = stoi(numString);
			getline(ss, num1String, ',');
			num1 = stoi(num1String);
			getline(ss, num2String, ',');
			num2 = stoi(num2String);
			getline(ss, num3String, ',');
			num3 = stoi(num3String);
		}
	}
	else { cout << "File not open" << endl; }
	readFile.close();
}

void writeAccSeries() {
	ofstream writeFile;
	writeFile.open("database/accountSeriesNumber.csv");
	if (writeFile.is_open()) {
		writeFile << num << "," << num1 << "," << num2 << "," << num3 << ",";
	}
	else { cout << "File not open" << endl; }
	writeFile.close();
}

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
	readAccSeries();
	const string CACN = "CACN";
	string accNum = CACN;
	accNum = accNum + to_string(++num);
	writeAccSeries();
	return accNum;
}

string generateEmployeeAccountNumber() {
	readAccSeries();
	const string EACN = "EACN";
	const string MACN = "Manager";
	string accNum = "";
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
	writeAccSeries();
	return accNum;
}

int getAmount() {
	int ammount;
	cout << "\n" << setw(20) << "[Amount] >> ";
	cin >> ammount;
	return ammount;
}