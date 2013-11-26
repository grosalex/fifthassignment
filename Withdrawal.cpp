/*
 * Withdrawal.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Withdrawal.h"

Withdrawal::Withdrawal(int inBranch, Account* inAccount, int inWithdrawalBranch,char type)
:Transaction(inWithdrawalBranch,type) {
	account = inAccount;
	branch = inBranch;
}

Withdrawal::~Withdrawal() {
	// TODO Auto-generated destructor stub
}


void Withdrawal::print() {
	Transaction::print();
	this->account->print();
	cout << "Account is in branch N°" << branch << endl;
}

void Withdrawal::cancel() {
	account->setMoney(account->getMoney()+this->getAmount());
}
