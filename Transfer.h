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

private:
	int accountsource;
	int branchsource;
	int branchtarget;
	int accounttarget;
};

#endif /* TRANSFER_H_ */
