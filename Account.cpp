/*
 * Account.cpp
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#include "Account.h"

Account::Account() {
	int inAccountnb;
	int inMoney;
	int inClientid;
	int inInterest;

	cout << "Enter the account number : ";
	cin >> inAccountnb;
	cout << "Enter the money : ";
	cin >> inMoney;
	cout << "Enter the client id : ";
	cin >> inClientid;
	cout << "Enter the interest : ";
	cin >> inInterest;
	accountnb=inAccountnb;
	money=inMoney;
	clientid=inClientid;
	interest=inInterest;
}

Account::~Account() {
	// TODO Auto-generated destructor stub
}

