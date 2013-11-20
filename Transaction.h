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

class Transaction {
public:
	Transaction();
	virtual ~Transaction();

private:
	static int nb_of_transactions;
	int transactionID;
	int branchid;
	string transactiontype; //Deposit/Withdrawal/transfer
	int accountsource;
	int branchsource;
	int branchtarget;
	int accounttarget;
	int amount;
	Date* transacationDate;

};

#endif /* TRANSACTION_H_ */
