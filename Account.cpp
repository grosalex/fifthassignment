/*
 * Account.cpp
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#include "Account.h"
int Account::number_of_accounts=0;
Account::Account() {
	int inMoney;
	int inInterest;
	number_of_accounts++;
	accountnb = number_of_accounts;
	cout << "Enter the money : ";
	cin >> inMoney;
	//cout << "Enter the client id : ";
	//cin >> inClientid;
	cout << "Enter the interest : (divided by 100)";
	cin >> inInterest;
	money=inMoney;
	//clientid=inClientid;
	interest=inInterest;
}

Account::~Account() {
	// TODO Auto-generated destructor stub
}

void Account::print() {
	cout << "Account N°" << accountnb << endl;
	cout << "Money : $" << money << endl;
	cout << "Interest : " << interest*100 << "%" << endl;
}

int Account::getAccountnb() const {
	return accountnb;
}

void Account::setAccountnb(int accountnb) {
	this->accountnb = accountnb;
}

int Account::getInterest() const {
	return interest;
}

void Account::setInterest(int interest) {
	this->interest = interest;
}

int Account::getMoney() const {
	return money;
}

void Account::setMoney(int money) {
	this->money = money;
}
