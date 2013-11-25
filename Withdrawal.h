/*
 * Withdrawal.h
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#ifndef WITHDRAWAL_H_
#define WITHDRAWAL_H_

#include "Transaction.h"

class Withdrawal: public Transaction {
public:
	Withdrawal(int,Account*,int,char);
	virtual ~Withdrawal();
	virtual void print();
	void cancel();

private:
	Account* account;
	int branch;
};

#endif /* WITHDRAWAL_H_ */
