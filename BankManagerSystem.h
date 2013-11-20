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
#include <iostream>

class BankManagerSystem {
public:
	BankManagerSystem();
	virtual ~BankManagerSystem();
	bool addBranch();
private:
	Branch * branchArray[maxbranch];
	Account* bankAccounts[maxaccount];
};

#endif /* BANKMANAGERSYSTEM_H_ */
