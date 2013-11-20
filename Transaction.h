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
	string transactiontype; //Deposit/Withdrawal/transfer
	int amount;
	Date* transactionDate;

};

#endif /* TRANSACTION_H_ */
