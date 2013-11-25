/*
 * Transfer.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Transfer.h"

Transfer::Transfer(int inBranchSource, Account* accountSource,int inBranchTarget, Account* accountTarget, int inTransactionBranch)
	:Transaction(inTransactionBranch){
	accountsource = accountSource;
	branchsource = inBranchSource;
	branchtarget = inBranchTarget;
	accounttarget = accountTarget;
}

Transfer::~Transfer() {
	// TODO Auto-generated destructor stub
}

