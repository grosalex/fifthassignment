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
	for(i=0;i<maxclient;i++){
		clientArray[i]=NULL;
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

void BankManagerSystem::showBranches() {
	int i=0;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]!=NULL) branchArray[i]->print();
	}
}

bool BankManagerSystem::addClientInBranch(int branchId) {
	bool results=false;
	int i=0;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]->getBranchid()==branchId && branchArray[i]!=NULL){
			results=branchArray[i]->addClient();
			i=maxbranch;
			results =true;
		}
	}
	return results;
}

void BankManagerSystem::showClientFromBranch(int branchId) {
	int i=0;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]->getBranchid()==branchId && branchArray[i]!=NULL){
			branchArray[i]->showClients();
			i=maxbranch;
		}
	}
}

bool BankManagerSystem::doDeposit() {
	bool ok = false;
	int accountsource, amount, branch;
	cout << "Enter account number :";
	cin >> accountsource;
	cout << "Enter amount";
	cin >> amount;
	cout << "In which branch are you doing this operation ?";
	cin >> branch;
	if(checkBranch(branch))
		for(int i=0; i<maxaccount;i++) {
			if(bankAccounts[i]!=NULL && bankAccounts[i]->getAccountnb() == accountsource) {
				cout << "account found at " << i << endl;
				i = maxaccount;
				amount += amount*bankAccounts[i]->getInterest() + bankAccounts[i]->getMoney();
				bankAccounts[i]->setMoney(amount);
				ok = true;
			}
			else cout << "Account not found." << endl;
		}
	else cout << "Branch not found" << endl;
	return ok;
}

bool BankManagerSystem::doTransfer() {
	bool ok = false;
	int accountsource, accounttarget, amount, branch;
	cout << "Enter source account number :";
	cin >> accountsource;
	cout << "enter target account number :";
	cin >> accounttarget;
	cout << "Enter amount";
	cin >> amount;
	cout << "In which branch are you doing this operation ?";
	cin >> branch;
	if(checkBranch(branch))
		for(int i=0; i<maxaccount;i++) {
			if(bankAccounts[i]!=NULL && bankAccounts[i]->getAccountnb() == accounttarget) {
				cout << "target account found at " << i << endl;
				i = maxaccount;
				if(bankAccounts[i]->getMoney()-amount>0) {
					for(int j=0; j<maxaccount;j++) {
						if(bankAccounts[j]!=NULL && bankAccounts[j]->getAccountnb() == accountsource) {
							cout << "source account found at " << j << endl;
							j=maxaccount;
							ok = true;
							bankAccounts[j]->setMoney(bankAccounts[j]->getMoney()-amount);
							bankAccounts[i]->setMoney(amount + amount*bankAccounts[i]->getInterest() + bankAccounts[i]->getMoney());
							cout << "Source account has now : $" << bankAccounts[j]->getMoney() << endl;
							cout << "Target account has now : $" << bankAccounts[i]->getMoney() << endl;
						}
						else cout << "Source account not found" << endl;

					}
				}
				else cout << "Not enough money in source account" << endl;
			}
			else cout << "Target account not found." << endl;
		}
	else cout << "Branch not found." << endl;
	return ok;
}

bool BankManagerSystem::doWithdrawal() {
	bool ok = false;
	int accountsource, amount, branch;
	cout << "Enter account number :";
	cin >> accountsource;
	cout << "Enter amount";
	cin >> amount;
	cout << "In which branch are you doing this operation ?";
	cin >> branch;
	if(checkBranch(branch))
		for(int i=0; i<maxaccount;i++) {
			if(bankAccounts[i]!=NULL && bankAccounts[i]->getAccountnb() == accountsource) {
				cout << "account found at " << i << endl;
				i = maxaccount;
				if(bankAccounts[i]->getMoney()-amount>0) {
					bankAccounts[i]->setMoney(bankAccounts[i]->getMoney()-amount);
					ok = true;
				}
			}
		}
	else cout << "Branch not found." << endl;
	return ok;
}

bool BankManagerSystem::checkBranch(int branchID) {
	bool ok = false;
	for(int i=0;i<maxbranch;i++) {
		if(branchID == branchArray[i]->getBranchid()) {
			cout << "Branch found at " << i << endl;
			i = maxbranch;
			ok =true;
		}
	}
	return ok;
}
