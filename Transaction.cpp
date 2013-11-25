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
	// TODO Auto-generated destructor stub
}

int Transaction::getAmount() const {
	return amount;
}

void Transaction::setAmount(int amount) {
	this->amount = amount;
}

static int Transaction::getNbOfTransactions() const {
	return nb_of_transactions;
}

void Transaction::setNbOfTransactions(static int nbOfTransactions) {
	nb_of_transactions = nbOfTransactions;
}

int Transaction::getTransactionBranch() const {
	return transactionBranch;
}

void Transaction::setTransactionBranch(int transactionBranch) {
	this->transactionBranch = transactionBranch;
}

const Date*& Transaction::getTransactionDate() const {
	return transactionDate;
}

void Transaction::setTransactionDate(const Date*& transactionDate) {
	this->transactionDate = transactionDate;
}

int Transaction::getTransactionId() const {
	return transactionID;
}

void Transaction::setTransactionId(int transactionId) {
	transactionID = transactionId;
}

const string& Transaction::getTransactionType() const {
	return transactionType;
}

void Transaction::setTransactionType(const string& transactionType) {
	this->transactionType = transactionType;
}
