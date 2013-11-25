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
	account = inAccount->getAccountnb();
}

Deposit::~Deposit() {
	// TODO Auto-generated destructor stub
}

