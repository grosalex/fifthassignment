/*
 * BankManagerSystem.cpp
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#include "BankManagerSystem.h"

BankManagerSystem::BankManagerSystem() {
	int i=0;
	for(i=0;i<maxbranch;i++){
		branchArray[i]=NULL;
	}
	for(i=0;i<maxaccount;i++){
		bankAccounts[i]=NULL;
	}
}

BankManagerSystem::~BankManagerSystem() {
	// TODO Auto-generated destructor stub
}

bool BankManagerSystem::addBranch() {
	int i=0;
	bool result=false;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]==NULL){
			branchArray[i]=new Branch;
			i=maxbranch;
			result=true;
		}
	}
	return result;
}