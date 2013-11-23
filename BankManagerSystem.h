/*
 * BankManagerSystem.h
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#ifndef BANKMANAGERSYSTEM_H_
#define BANKMANAGERSYSTEM_H_
#define maxbranch 100
#define maxaccount 100
#define maxclient 100
#include <iostream>
#include "Branch.h"
//#include "Branch.cpp"

#include "Account.h"
#include "Client.h"
class BankManagerSystem {
public:
	BankManagerSystem();
	virtual ~BankManagerSystem();
	bool addBranch();
	void showBranches();
	bool addClientInBranch(int branchId);
	void showClientFromBranch(int branchId);
	bool doDeposit();
	bool doTransfer();
	bool doWithdrawal();
	bool addAccount();
	bool checkBranch(int); //Given a branchid, check if branch exists.

private:
	Branch * branchArray[maxbranch];
	Account* bankAccounts[maxaccount];
	Client* clientArray[maxclient];
};

#endif /* BANKMANAGERSYSTEM_H_ */
