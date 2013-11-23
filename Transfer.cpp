/*
 * Transfer.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Transfer.h"

Transfer::Transfer(int inBranchSource, int inAccountSource,int inBranchTarget, int inAccountTarget, int inTransactionBranch)
	:Transaction(inTransactionBranch){
	accountsource = inAccountSource;
	branchsource = inBranchSource;
	branchtarget = inBranchTarget;
	accounttarget = inAccountTarget;
}

Transfer::~Transfer() {
	// TODO Auto-generated destructor stub
}

