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
	Transfer(int, Account*, int, Account*, int,char);
	virtual ~Transfer();
	void cancel();
	virtual void print();

private:
	Account* accountsource;
	int branchsource;
	int branchtarget;
	Account* accounttarget;

};

#endif /* TRANSFER_H_ */
