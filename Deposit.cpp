/*
 * Deposit.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Deposit.h"

Deposit::Deposit(int inBranch, int inAccount)
	:Transaction(){
	branch = inBranch;
	account = inAccount;
}

Deposit::~Deposit() {
	// TODO Auto-generated destructor stub
}

