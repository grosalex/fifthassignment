/*
 * Account.h
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account {
public:
	Account();
	virtual ~Account();

private:
	int accountnb;
	int money;
	int clientid;
	string type; //checking/saving
	int interest;
};

#endif /* ACCOUNT_H_ */
