/*
 * Deposit.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Deposit.h"

Deposit::Deposit(int inAccountBranch, int inAccount, int inDepositBranch)
	:Transaction(inDepositBranch){
	accountBranch = inAccountBranch;
	account = inAccount;
}

Deposit::~Deposit() {
	// TODO Auto-generated destructor stub
}

