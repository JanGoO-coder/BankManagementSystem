//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <cstdlib>
//
//using namespace std;

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

	gotoXY(18, 5); cout << "Sub Menu";
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

				accNumber = getAccountNumber();

				user.EADL.updateCustomerAccountUserName(accNumber, getAccountUserName());
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);

				accNumber = getAccountNumber();

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

	gotoXY(18, 5); cout << "Sub Menu";
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

				accNumber = getAccountNumber();

				user.CADL.updateCustomerAccountUserName(accNumber, getAccountUserName());
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);

				accNumber = getAccountNumber();

				user.CADL.updateCustomerAccountPassword(accNumber, getAccountPassword());
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

int updateMenu()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool running = true;
	string accNumber = "";

	gotoXY(18, 5); cout << "Sub Menu";
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

				accNumber = getAccountNumber();

				user.CADL.updateCustomerAccountUserName(accNumber, getAccountUserName());
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);

				accNumber = getAccountNumber();

				user.CADL.updateCustomerAccountPassword(accNumber, getAccountPassword());
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

int managerMiniMenu_0()
{
	system("cls");
	int menu_item = 0, x = 7;
	bool runningManagerMiniMenu = true;

	gotoXY(18, 5); cout << "Sub Menu";
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
					user.EADL.createNewEmployeeAccount(
						generateEmployeeAccountNumber(), 
						getAccountUserName(), 
						getAccountPassword()
					);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);
					user.CADL.createNewCustomerAccount(
						generateCustomerAccountNumber(),
						0 ,
						getAccountUserName(), 
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

	gotoXY(18, 5); cout << "Sub Menu";
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

				accNumber = getAccountNumber();

				user.EADL.removeEmployeeAccount(accNumber);
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);

				accNumber = getAccountNumber();

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

	gotoXY(18, 5); cout << "Sub Menu";
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

	gotoXY(18, 5); cout << "Sub Menu";
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

	gotoXY(18, 5); cout << "Sub Menu";
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

				accNumber = getAccountNumber();

				user.EADL.displayEmployeeAccountData(accNumber);
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);
				accNumber = getAccountNumber();

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

	gotoXY(18, 5); cout << "Sub Menu";
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
				//
				break;
			}

			case 1: {
				system("cls");
				gotoXY(20, 16);
				//
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

	gotoXY(18, 5); cout << "Sub Menu";
	gotoXY(18, 7); cout << "> ";

	while (runningManagerSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Add Account";
		gotoXY(20, 8);  cout << "[1] Remove Account";
		gotoXY(20, 9);  cout << "[2] Modify Account";
		gotoXY(20, 10); cout << "[3] Record Inquiry";
		gotoXY(20, 11); cout << "[4] Account Inquiry";
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

	gotoXY(18, 5); cout << "Sub Menu";
	gotoXY(18, 7); cout << "> ";

	while (runningSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Add Account";
		gotoXY(20, 8);  cout << "[1] Remove Account";
		gotoXY(20, 9);  cout << "[2] Modify Account";
		gotoXY(20, 10); cout << "[3] Record Inquiry";
		gotoXY(20, 11); cout << "[4] Account Inquiry";
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
					user.CADL.createNewCustomerAccount(
						generateCustomerAccountNumber(), 
						0, 
						getAccountUserName(), 
						getAccountPassword(), 
						getAccountType()
					);
					break;
				}

				case 1: {
					system("cls");
					gotoXY(20, 16);

					accNumber = getAccountNumber();

					user.CADL.removeCustomerAccount(accNumber);
					break;
				}
				
				case 2: {
					system("cls");
					gotoXY(20, 16);
					updateMenu();
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

					accNumber = getAccountNumber();

					user.CADL.displayCustomerAccountData(accNumber);
					break;
				}

				case 5: {
					system("cls");
					gotoXY(20, 16);
					
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

	gotoXY(18, 5); cout << "Sub Menu";
	gotoXY(18, 7); cout << "> ";

	while (runningSubMenu)
	{
		gotoXY(20, 7);  cout << "[0] Deposite Money";
		gotoXY(20, 8);  cout << "[1] Withdraw Money";
		gotoXY(20, 9);  cout << "[2] Transfer MOney";
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
				user.moneyMachine.depositMoney(
					getAmount()
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
				cout << "Enter Sender and Reciever Account Number respectivley" << endl;
				user.moneyMachine.transferMoney(
					user.CADL.searchCustomerAccount(getAccountNumber()),
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

	gotoXY(18, 5); cout << "Main Menu";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] LOG IN";
		gotoXY(20, 8);  cout << "[1] SIGN UP";
		gotoXY(20, 9);  cout << "[2] QUIT";

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
					user.EADL.createNewEmployeeAccount(
						generateEmployeeAccountNumber(), 
						getAccountUserName(), 
						getAccountPassword()
					);
					break;
				}

				case 2: {
					gotoXY(20, 16);
					cout << "The program has now terminated!!";
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

	gotoXY(18, 5); cout << "Main Menu";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] LOG IN";
		gotoXY(20, 8);  cout << "[1] QUIT";

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
				accNumber = getAccountNumber();
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
				cout << "The program has now terminated!!";
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

	gotoXY(18, 5); cout << "Main Menu";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[0] BANK";
		gotoXY(20, 8);  cout << "[1] ATM";
		gotoXY(20, 9);  cout << "[2] QUIT";

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
				cout << "The program has now terminated!!";
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