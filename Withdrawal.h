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
	Withdrawal(int,int);
	virtual ~Withdrawal();

private:
	int account;
	int branch;
};

#endif /* WITHDRAWAL_H_ */