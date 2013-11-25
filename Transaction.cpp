/*
 * Transaction.cpp
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#include "Transaction.h"

int Transaction::nb_of_transactions = 0;

Transaction::Transaction(int inTransactionBranch) {
	string inTransactionType;
	int inAmount;

	nb_of_transactions++;
	transactionID = nb_of_transactions;
	transactionType = inTransactionType;
	cout << "How much money ?" << endl;
	cin >> inAmount;
	amount = inAmount;
	cout << "Transaction date :" << endl;
	transactionDate = new Date;
	transactionBranch = inTransactionBranch;
	amount = inAmount;
}

Transaction::~Transaction() {
	delete transactionDate;
}

int Transaction::getAmount() const {
	return amount;
}

void Transaction::setAmount(int amount) {
	this->amount = amount;
}

int Transaction::getTransactionBranch() const {
	return transactionBranch;
}

void Transaction::setTransactionBranch(int transactionBranch) {
	this->transactionBranch = transactionBranch;
}
int Transaction::getTransactionId() const {
	return transactionID;
}

void Transaction::setTransactionId(int transactionId) {
	transactionID = transactionId;
}

const char Transaction::getTransactionType() const {
	return transactionType;
}

void Transaction::setTransactionType(const string& transactionType) {
	this->transactionType = transactionType;
}
