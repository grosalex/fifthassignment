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
	//int getClientid() const;
	//void setClientid(int clientid);
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
	int interest;
};

#endif /* ACCOUNT_H_ */
