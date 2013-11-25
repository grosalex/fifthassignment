/*
 * Transaction.cpp
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#include "Transaction.h"

int Transaction::nb_of_transactions = 0;

Transaction::Transaction(int inTransactionBranch, char type) {
	int inAmount;

	nb_of_transactions++;
	transactionID = nb_of_transactions;
	transactionType = type;
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

void Transaction::print() {
	cout << "Transaction N°" << transactionID << endl;
	cout << "Type : ";
	if(transactionType=='w') cout << "Withdrawal" << endl;
	else if (transactionType=='d') cout << "Deposit" << endl;
	else cout << "Transfer" << endl;
	cout << "Amount : $" << amount << endl;
	cout << "Operation done in branch N°" << transactionBranch << endl;
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

char Transaction::getTransactionType() const {
	return transactionType;
}

void Transaction::setTransactionType(char transactionType) {
	this->transactionType = transactionType;
}
