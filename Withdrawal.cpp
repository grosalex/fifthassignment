/*
 * Withdrawal.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Withdrawal.h"

Withdrawal::Withdrawal(int inBranch, Account* inAccount, int inWithdrawalBranch)
	:Transaction(inWithdrawalBranch) {
	account = inAccount->getAccountnb();
	inAccount->setMoney(inAccount->getMoney()-amount);
	branch = inBranch;
}

Withdrawal::~Withdrawal() {
	// TODO Auto-generated destructor stub
}

