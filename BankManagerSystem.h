/*
 * BankManagerSystem.h
 *
 *  Created on: 18 nov. 2013
 *      Author: William
 */

#ifndef BANKMANAGERSYSTEM_H_
#define BANKMANAGERSYSTEM_H_
#define maxbranch 100
class BankManagerSystem {
public:
	BankManagerSystem();
	virtual ~BankManagerSystem();
	bool addBranch();
private:
	Branch * branchArray[maxbranch];
	Account* bankaccounts[100];
	Client* clientsarray[100];
};

#endif /* BANKMANAGERSYSTEM_H_ */
