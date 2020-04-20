#include<iostream>
using namespace std;
//ATM
class ATM {
public:

	int atmLocation; int atmManagedBy;
	void depositMoney() {

	}
	void withdrawMoney() {

	}
	void checkBalance() {

	}
};
//account class aggregation of main class
class Account {
public:
	//making data type object of customer class
	Customer* objectC;
	int accountNumber; float accountBalance; int accountDescription;
	void addAccount() {

	}
	void deleteAccount() {

	}
	void editAccount() {

	}
	void searchAccount() {

	}
};
class Bank {
public:
	//making object of ATM Class because of aggregation
	//ATMis used as a datatype
	//making object of ACCOUNT Class because of aggregation
	//ACCOUNT is used as a datatype
	ATM* objectAM;
	Account* objectAC;
	int code; int address; string name;
	void getAccount() {

	}
};
//customer class
class Customer : public Atm {
public:
	//object of class account bcz of simple association
	Account* object1;
	int customerId; string customerName; string customerEmail;
	string customerPhoneNumber; int customerPassword; string customerUserName;
	string customerAddress; int customerCardNumber;
	void addCustomer() {

	}
	void deleteCustomer() {

	}
	void editCustomer() {

	}
	void searchCustomer() {

	}
	void verifyPassword() {

	}
};
//making class of ATM Transaction
class AtmTransaction {
public:
	//making object data type of Account
	Account* object2;
	int transactionId; int transactionDate; int transactionType;
	float transactionAmount; float postBalance;
	void modifies() {

	}
};
//making class of saving account
class SavingAccount : public Account {
public:
	char accountTitle;
	void viewAccount() {

	}
};
//making class of Current Account
class currentAccount {
public:
	SavingAccount* objectSA;
	void viewAccount() {

	}
};