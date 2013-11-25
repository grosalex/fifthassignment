/*
 * Transfer.cpp
 *
 *  Created on: 20 nov. 2013
 *      Author: William
 */

#include "Transfer.h"

Transfer::Transfer(int inBranchSource, Account* accountSource,int inBranchTarget, Account* accountTarget, int inTransactionBranch,char type)
	:Transaction(inTransactionBranch,type){
	accountsource = accountSource;
	branchsource = inBranchSource;
	branchtarget = inBranchTarget;
	accounttarget = accountTarget;
}

Transfer::~Transfer() {
	// TODO Auto-generated destructor stub
}


void Transfer::print() {
	Transaction::print();
	cout << "Source Account" << endl;
	accountsource->print();
	cout << "Account Source is in branch N°" << branchsource << endl;
	cout << "Target Account" << endl;
	accounttarget->print();
	cout << "Account Target is in branch N°" << branchtarget << endl;
}

void Transfer::cancel() {
	accountsource->setMoney(accountsource->getMoney()+this->getAmount());
	accounttarget->setMoney(accounttarget->getMoney()-this->getAmount());
}
