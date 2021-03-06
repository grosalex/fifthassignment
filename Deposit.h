/*
 * Deposit.h
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#ifndef DEPOSIT_H_
#define DEPOSIT_H_

#include "Transaction.h"

class Deposit: public Transaction {
public:
	Deposit(int, Account*, int,char);
	virtual ~Deposit();
	virtual void print();
	void cancel();

private:
	Account* account;
	int accountBranch;
};

#endif /* DEPOSIT_H_ */
