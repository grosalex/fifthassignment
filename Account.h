/*
 * Account.h
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
using namespace std;

class Account {
public:
	Account();
	virtual ~Account();
	int getAccountnb() const;
	void setAccountnb(int accountnb);
	int getInterest() const;
	void setInterest(int interest);
	int getMoney() const;
	void setMoney(int money);
	void print();

private:
	static int number_of_accounts;
	int accountnb;
	int money;
	//int clientid;
	int interest;// not in percentage but divided by 100 so for 1% enter 0.01
};

#endif /* ACCOUNT_H_ */
