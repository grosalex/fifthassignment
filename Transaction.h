/*
 * Transaction.h
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
using namespace std;
#include <string>
#include "Date.h"

class Transaction {
public:
	Transaction(int);
	virtual ~Transaction();

private:
	static int nb_of_transactions;
	int transactionID;
	string transactionType; //Deposit/Withdrawal/transfer
	int amount;
	Date* transactionDate;
	int transactionBranch;
};

#endif /* TRANSACTION_H_ */
