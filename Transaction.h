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
#include "Account.h"

class Transaction {
public:
	Transaction(int);
	virtual ~Transaction();
	virtual void print();
	int getAmount() const;
	void setAmount(int amount);
	int getTransactionBranch() const;
	void setTransactionBranch(int transactionBranch);
	const Date*& getTransactionDate() const;
	void setTransactionDate(const Date*& transactionDate);
	int getTransactionId() const;
	void setTransactionId(int transactionId);
	const string& getTransactionType() const;
	void setTransactionType(const string& transactionType);

private:
	static int nb_of_transactions;
	int transactionID;
	string transactionType; //Deposit/Withdrawal/transfer
	int amount;
	Date* transactionDate;
	int transactionBranch;
};

#endif /* TRANSACTION_H_ */
