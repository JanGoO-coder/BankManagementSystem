// Labraries Are Handled in the "BankManagementSyetem.cpp" File

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int, int);
int mainPage();

Bank user;

int employeeUpdateMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = "";
	string userName = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Change What?";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] Change Account User Name";
		gotoXY(20, 8);  cout << "[1] Change Account Password";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'E');

					userName = getAccountUserName();
					toupper(userName[0]);

					user.EADL.updateCustomerAccountUserName(accNumber, userName);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'E');

					user.EADL.updateCustomerAccountPassword(accNumber, getAccountPassword());
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					running = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int customerUpdateMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = "";
	int amount = 0;
	string userName = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Change What?";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] Change Account User Name";
		gotoXY(20, 8);  cout << "[1] Change Account Password";
		gotoXY(20, 9);  cout << "[2] Change Account Balance";
		gotoXY(20, 10);  cout << "[3] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 10) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					userName = getAccountUserName();
					toupper(userName[0]);

					user.CADL.updateCustomerAccountUserName(accNumber, userName);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					user.CADL.updateCustomerAccountPassword(accNumber, getAccountPassword());
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					do {
						amount = getAmount();
					} while (amount <= 0);

					user.CADL.updateCustomerAccountBalance(accNumber, amount);
					break;
				}

				case 3: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					running = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int managerMiniMenu_0()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;
	string userName = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					userName = getAccountUserName();
					userName[0] = toupper(userName[0]);

					user.EADL.createNewEmployeeAccount(
						generateEmployeeAccountNumber(), 
						userName, 
						getAccountPassword()
					);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					userName = getAccountUserName();
					userName[0] = toupper(userName[0]);

					user.CADL.createNewCustomerAccount(
						generateCustomerAccountNumber(),
						0 ,
						userName, 
						getAccountPassword(), 
						getAccountType()
					);
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
int managerMiniMenu_1()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";
	string accNumber = "";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'E');

					user.EADL.removeEmployeeAccount(accNumber);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					user.CADL.removeCustomerAccount(accNumber);
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
int managerMiniMenu_2()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);
					employeeUpdateMenu();
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);
					customerUpdateMenu();
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
int managerMiniMenu_3()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);
					user.EADL.displayEmployeeAccountsData();
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);
					user.CADL.displayCustomerAccountsData();
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
int managerMiniMenu_4()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;
	string accNumber = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'E');

					user.EADL.displayEmployeeAccountData(accNumber);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					user.CADL.displayCustomerAccountData(accNumber);
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}
int managerMiniMenu_5()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;
	char firstLetter;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Select Catagory";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerMiniMenu)
	{
		gotoXY(20, 7);  cout << "[0] Employee";
		gotoXY(20, 8);  cout << "[1] Customer";
		gotoXY(20, 9);  cout << "[2] Quit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					firstLetter = getFirstLetter();
					firstLetter = toupper(firstLetter);

					user.EADL.searchEmployeeAccountsWithFirstLetter(firstLetter);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					firstLetter = getFirstLetter();
					firstLetter = toupper(firstLetter);

					user.CADL.searchCustomerAccountsWithFirstLetter(firstLetter);
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerMiniMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int managerSubMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerSubMenu = true;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Manager Logged In";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Add Account";
		gotoXY(20, 8);  cout << "[1] Remove Account";
		gotoXY(20, 9);  cout << "[2] Modify Account";
		gotoXY(20, 10); cout << "[3] Record Inquiry";
		gotoXY(20, 11); cout << "[4] Account Inquiry";
		gotoXY(20, 12); cout << "[5] Search Account";
		gotoXY(20, 13); cout << "[6] LOG OUT";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 13) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_0();
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_1();
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_2();
					break;
				}

				case 3: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_3();
					break;
				}

				case 4: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_4();
					break;
				}

				case 5: {
					system("cls");
					gotoXY(20, 16);
					managerMiniMenu_5();
					break;
				}

				case 6: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningManagerSubMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int bankSubMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningSubMenu = true;
	string accNumber = "";
	char firstLetter;
	string userName = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Employee Logged In";
	gotoXY(18, 7); cout << "> ";

	while (runningSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Add Account";
		gotoXY(20, 8);  cout << "[1] Remove Account";
		gotoXY(20, 9);  cout << "[2] Modify Account";
		gotoXY(20, 10); cout << "[3] Record Inquiry";
		gotoXY(20, 11); cout << "[4] Account Inquiry";
		gotoXY(20, 12); cout << "[5] Search Accounts";
		gotoXY(20, 13); cout << "[6] LOG OUT";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 13) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					userName = getAccountUserName();
					userName[0] = toupper(userName[0]);

					user.CADL.createNewCustomerAccount(
						generateCustomerAccountNumber(), 
						0, 
						userName, 
						getAccountPassword(), 
						getAccountType()
					);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					user.CADL.removeCustomerAccount(accNumber);
					break;
				}
				
				case 2: {
					system("cls");
					gotoXY(20, 16);
					customerUpdateMenu();
					break;
				}

				case 3: {
					system("cls");
					gotoXY(20, 16);
					user.CADL.displayCustomerAccountsData();
					break;
				}

				case 4: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					user.CADL.displayCustomerAccountData(accNumber);
					break;
				}

				case 5: {
					system("cls");
					gotoXY(20, 16);

					firstLetter = getFirstLetter();
					firstLetter = toupper(firstLetter);

					user.CADL.searchCustomerAccountsWithFirstLetter(firstLetter);
					break;
				}

				case 6: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningSubMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int atmSubMenu(CustomerAccount* loggedInAccountNumber)
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningSubMenu = true;
	string accNumber = "";
	int amount = 0;

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Now " 
		<< loggedInAccountNumber->customerAccountUserName 
		<< " with Account Number " 
		<< loggedInAccountNumber->customerAccountNumber 
		<< " is Logged In";
	gotoXY(18, 7); cout << "> ";

	while (runningSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Deposite Money";
		gotoXY(20, 8);  cout << "[1] Withdraw Money";
		gotoXY(20, 9);  cout << "[2] Transfer Money";
		gotoXY(20, 10); cout << "[3] Change Password";
		gotoXY(20, 11); cout << "[4] Banlance Inquiry";
		gotoXY(20, 12); cout << "[5] Account Statement";
		gotoXY(20, 13); cout << "[6] LOG OUT";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 13) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						amount = getAmount();
					} while (amount <= 0);

					user.moneyMachine.depositMoney(
						amount
					);
					user.CADL.updateFullFile();
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);
					user.moneyMachine.withdrawMoney(
						getAmount()
					);
					user.CADL.updateFullFile();
					break;
				}

				case 2: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					cout << "Enter Reciever Account Number and Amount respectivley" << endl;
					user.moneyMachine.transferMoney(
						user.CADL.searchCustomerAccount(accNumber),
						getAmount()
					);
					user.CADL.updateFullFile();
					break;
				}

				case 3: {
					system("cls");
					gotoXY(20, 16);
					cout << "\nEnter User Name and New Password" << endl;
					user.moneyMachine.changePassword(
						getAccountPassword()
					);
					user.CADL.updateFullFile();
					break;
				}

				case 4: {
					system("cls");
					gotoXY(20, 16);
					cout << "Your Account Balance is : ";
					cout << loggedInAccountNumber->customerAccountBalance;
					break;
				}

				case 5: {
					system("cls");
					gotoXY(20, 16);
					cout << endl;
					user.moneyMachine.transactionHistory();
					break;
				}

				case 6: {
					system("cls");
					gotoXY(20, 16);
					cout << "You are now loged out" << endl;
					runningSubMenu = false;
					break;
				}
			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int bankMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = " ";
	string userName = "";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Staff Inside Bank";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] LOG IN";
		gotoXY(20, 8);  cout << "[1] SIGN UP";
		gotoXY(20, 9);  cout << "[2] Go Back";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			system("cls");

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					accNumber = getAccountNumber();
					if (accNumber[0] == 'M' || accNumber[0] == 'm') {
						accNumber[0] = toupper(accNumber[0]);
					}
					else {
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					}
					
					if (user.EADL.logIn(user.EADL.searchEmployeeAccount(accNumber), getAccountPassword())) {
						if (accNumber[0] == 'M') {
							managerSubMenu();
						}
						else {
							bankSubMenu();
						}
					}
					else {
						cout << "\n" << setw(80) << "Your Password or Account Number is incorrect" << endl;
					}
					break;
				}


				case 1: {
					gotoXY(20, 16);

					userName = getAccountUserName();
					userName[0] = toupper(userName[0]);

					user.EADL.createNewEmployeeAccount(
						generateEmployeeAccountNumber(), 
						userName, 
						getAccountPassword()
					);
					break;
				}

				case 2: {
					gotoXY(20, 16);
					cout << "Back To the Entry Point ...";
					running = false;
					break;
				}

			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int atmMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = " ";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Standing In Front of ATM Machine";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] LOG IN";
		gotoXY(20, 8);  cout << "[1] Get Out of the ATM Room";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 8) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			system("cls");

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);

					do {
						accNumber = getAccountNumber();
						accNumber[0] = toupper(accNumber[0]);
						accNumber[1] = toupper(accNumber[1]);
						accNumber[2] = toupper(accNumber[2]);
						accNumber[3] = toupper(accNumber[3]);
					} while (accNumber[0] != 'C');

					CustomerAccount* loggedInAccount = user.moneyMachine.atmLogIn(user.CADL.searchCustomerAccount(accNumber), getAccountPassword());
					if (loggedInAccount) {
						atmSubMenu(loggedInAccount);
					}
					else {
						cout << "\n" << setw(80) << "Your Password or Account Number is incorrect" << endl;
					}
					break;
				}


				case 1: {
					gotoXY(20, 16);
					cout << "Your are now back on street ...";
					running = false;
					break;
				}

			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

int entryPoint()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = " ";

	cout << user.branchName << endl;
	cout << "Branch Code: " << user.branchCode << endl;

	gotoXY(18, 5); cout << "Standing Outside Bank";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] Get Inside BANK";
		gotoXY(20, 8);  cout << "[1] Get Inside ATM";
		gotoXY(20, 9);  cout << "[2] Go Back Home";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
		{
			gotoXY(18, x); cout << "  ";
			x++;
			gotoXY(18, x); cout << "> ";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(18, x); cout << "  ";
			x--;
			gotoXY(18, x); cout << "> ";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			system("cls");

			switch (menu_item) {

				case 0: {
					system("cls");
					gotoXY(20, 16);
					bankMenu();
					break;
				}


				case 1: {
					gotoXY(20, 16);
					atmMenu();
					break;
				}

				case 2: {
					gotoXY(20, 16);
					cout << "Your Safely Reached Home ...";
					running = false;
					break;
				}

			}

		}

	}

	gotoXY(20, 21);
	return 0;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}