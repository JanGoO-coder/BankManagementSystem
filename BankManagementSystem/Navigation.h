//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <cstdlib>
//
//using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int, int); // function defined below if this is new to you.

AccountDataList ADL;

int subMenu()
{
	//system("cls");
	//int menu_item = 0, run, x = 7;
	//bool running = true;

	//gotoXY(18, 5); cout << "Main Menu";
	//gotoXY(18, 7); cout << "> ";

	//while (running)
	//{
	//	gotoXY(20, 7);  cout << "[1] ";
	//	gotoXY(20, 8);  cout << "[2] SIGN UP";
	//	gotoXY(20, 9);  cout << "[3] QUIT";

	//	system("pause>nul"); // the >nul bit causes it the print no message

	//	if (GetAsyncKeyState(VK_DOWN) && x != 9) //down button pressed
	//	{
	//		gotoXY(18, x); cout << "  ";
	//		x++;
	//		gotoXY(18, x); cout << "> ";
	//		menu_item++;
	//		continue;
	//	}

	//	if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
	//	{
	//		gotoXY(18, x); cout << "  ";
	//		x--;
	//		gotoXY(18, x); cout << "> ";
	//		menu_item--;
	//		continue;
	//	}

	//	if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

	//		switch (menu_item) {

	//		case 0: {
	//			system("cls");
	//			gotoXY(20, 16);
	//			
	//			break;
	//		}


	//		case 1: {
	//			gotoXY(20, 16);
	//			ADL.createNewAccount();
	//			break;
	//		}

	//		case 2: {
	//			gotoXY(20, 16);
	//			cout << "The program has now terminated!!";
	//			running = false;
	//		}

	//		}

	//	}

	//}

	//gotoXY(20, 21);
	return 0;
}

int mainPage()
{
	system("cls");
	int menu_item = 0, run, x = 7;
	bool running = true;

	gotoXY(18, 5); cout << "Main Menu";
	gotoXY(18, 7); cout << "> ";

	while (running)
	{
		gotoXY(20, 7);  cout << "[1] LOG IN";
		gotoXY(20, 8);  cout << "[2] SIGN UP";
		gotoXY(20, 9);  cout << "[3] QUIT";

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
					if (ADL.logIn(ADL.searchAccount(getAccountNumber()), getAccountPassword()))
						subMenu();
					break;
				}


				case 1: {
					gotoXY(20, 16);
					ADL.createNewAccount();
					break;
				}

				case 2: {
					gotoXY(20, 16);
					cout << "The program has now terminated!!";
					running = false;
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