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
	Deposit();
	virtual ~Deposit();

private:
	int account;
	int branch;
};

#endif /* DEPOSIT_H_ */
