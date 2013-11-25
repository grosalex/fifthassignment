/*
 * Transfer.h
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#ifndef TRANSFER_H_
#define TRANSFER_H_

#include "Transaction.h"

class Transfer: public Transaction {
public:
	Transfer(int, Account*, int, Account*, int);
	virtual ~Transfer();
	void cancel();

private:
	Account* accountsource;
	int branchsource;
	int branchtarget;
	Account* accounttarget;
	virtual void print();
};

#endif /* TRANSFER_H_ */
