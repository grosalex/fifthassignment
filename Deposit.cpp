/*
 * Deposit.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Deposit.h"

Deposit::Deposit(int inAccountBranch, Account* inAccount, int inDepositBranch)
	:Transaction(inDepositBranch){
	accountBranch = inAccountBranch;
	account = inAccount;
}

Deposit::~Deposit() {
	// TODO Auto-generated destructor stub
}


void Deposit::print() {
	Transaction:print();
	account->print();
	cout << "Account is in branch N°" << accountBranch << endl;
}


void Deposit::cancel() {
	account->setMoney(account->getMoney()-amount);
}

