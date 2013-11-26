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
	Transaction(int,char);
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
	char getTransactionType() const;
	void setTransactionType(char transactionType);

private:
	static int nb_of_transactions;
	int transactionID;
	char transactionType; //Deposit/Withdrawal/transfer
	int amount;
	Date* transactionDate;
	int transactionBranch;
};

#endif /* TRANSACTION_H_ */
