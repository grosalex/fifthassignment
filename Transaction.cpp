/*
 * Transaction.cpp
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#include "Transaction.h"

int Transaction::nb_of_transactions = 0;

Transaction::Transaction() {
	int inAmount;
	string inTransactionType;

	nb_of_transactions++;
	transactionID = nb_of_transactions;
	do {
		cout << "Which type ? w for withdrawal, t for transfer, d for deposit" << endl;
		cin >> inTransactionType;
	}while(inTransactionType!="w" || inTransactionType!="t" || inTransactionType!="d");
	transactionType = inTransactionType;
	cout << "How much money ?" << endl;
	cin >> inAmount;
	amount = inAmount;
	cout << "Transaction date :" << endl;
	transactionDate = new Date;
}

Transaction::~Transaction() {
	// TODO Auto-generated destructor stub
}

