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
		branchArray[i]=NULL;//setting to null the array
	}
}

BankManagerSystem::~BankManagerSystem() {
	delete []branchArray;
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

bool BankManagerSystem::checkBranch(int branchID) {
	bool ok = false;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchID == branchArray[i]->getBranchid()) {
			cout << "Branch found at " << i << endl;
			i = maxbranch;
			ok =true;
		}
	}
	return ok;
}

bool BankManagerSystem::addAccount() {
	bool result=false;
	Client * target=NULL;
	int id;
	this->showAllClients();
	cout << "Enter the id of the client who is creating an accout :";
	cin >> id;
	target=this->findClientById(id);
	if(target!=NULL){
		result=target->openAccount();
		result=true;
		return result;
	}
	else return result;
}

bool BankManagerSystem::clientTransfer() {
	bool ok=false;
	bool branchok=false;
	int targetBranch;
	int sourceBranch;
	int transactionBranch;
	int clientTargetId;
	int clientSourceId;
	int targetAccountid;
	int sourceAccountid;
	Client* clientTarget;
	Client* clientSource;
	Account* targetAccount;
	Account* sourceAccount;

	cout << "Select where you are doing the transaction";
	cin >> transactionBranch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==targetBranch) {
			cout << "Transaction Branch found" << endl;
			branchok=true;
			i=maxbranch;
		}
	}

	if(branchok) {
		cout << "Select account target branch";
		cin >> targetBranch;
		if(checkBranch(targetBranch)) {
			for(int i=0;i<maxbranch;i++) {
				if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==targetBranch) {
					cout << "Branch Target found" << endl;
					cout << "Enter client target id";
					cin >> clientTargetId;
					clientTarget = branchArray[i]->findClientById(clientTargetId);
					if(clientTarget==NULL) return false;
					cout << "Enter account nb";
					cin >> targetAccountid;
					targetAccount = clientTarget->findAccountById(targetAccountid);
					if(targetAccount==NULL) return false;
					i=maxbranch;
				}
			}
			cout << "Select account source branch";
			cin >> sourceBranch;
			if(checkBranch(sourceBranch)) {
				for(int i=0;i<maxbranch;i++) {
					if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==sourceBranch) {
						cout << "Branch Source found" << endl;
						cout << "Enter client source id";
						cin >> clientSourceId;
						clientSource = branchArray[i]->findClientById(clientSourceId);
						if(clientSource==NULL) return false;
						cout << "Enter account nb";
						cin >> sourceAccountid;
						sourceAccount = clientTarget->findAccountById(sourceAccountid);
						if(sourceAccount==NULL) return false;
						i=maxbranch;
					}
				}
				Transfer *t = new Transfer(sourceBranch,sourceAccount,targetBranch,targetAccount,transactionBranch,'t');
				int newAmount = sourceAccount->getMoney()-t->getAmount();
				try {
					if(newAmount<0) throw sourceAccount->getMoney()-t->getAmount();
					else {
						sourceAccount->setMoney(sourceAccount->getMoney()-t->getAmount());
						targetAccount->setMoney(targetAccount->getMoney()+t->getAmount());
						clientSource->addTransactionInRecord(t);
						clientTarget->addTransactionInRecord(t);
					}
				}
				catch(int) /*ou catch (...)*/ {
					cerr << "Not enough money" << endl;
				}
			}
			else cout << "Source branch not found" << endl;
		}
		else cout << "Target branch not found" << endl;
	}
	else cout << "Transaction Branch not found" << endl;


	return ok;
}

bool BankManagerSystem::clientDepositWithdrawal() {
	bool ok=false;
	bool branchok=false;
	int branch;
	int transactionBranch;
	int clientId;
	int accountid;
	Client* client = NULL;
	Account* account = NULL;
	char type;

	cout << "Select where you are doing the transaction (type branch id)";
	cin >> transactionBranch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==transactionBranch) {
			cout << "Transaction Branch found" << endl;
			branchok=true;
			i=maxbranch;
		}
	}

	if(branchok) {
		cout << "Select account branch";
		cin >> branch;
		if(checkBranch(branch)) {
			for(int i=0;i<maxbranch;i++) {
				if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==branch) {
					cout << "Branch found" << endl;
					cout << "Enter client id";
					cin >> clientId;
					client = branchArray[i]->findClientById(clientId);
					if(client==NULL) return false;
					cout << "Enter account nb";
					cin >> accountid;
					account = client->findAccountById(accountid);
					if(account==NULL) return false;
					i=maxbranch;
				}
			}
			do {
				cout << "Type d for Deposit, w for Withdrawal";
				cin >> type;
			}while(type!='d' && type!='w');
			if(type == 'd') {
				Deposit *d = new Deposit(branch,account,transactionBranch,type);
				account->setMoney(account->getMoney()+d->getAmount()*account->getInterest()+d->getAmount());
				ok = client->addTransactionInRecord(d);
			}
			else {
				Withdrawal *w = new Withdrawal(branch,account,transactionBranch,type);
				int newAmount = account->getMoney()-w->getAmount();
				try {
					if(newAmount<0) throw account->getMoney()-w->getAmount();
					else {
						account->setMoney(account->getMoney()-w->getAmount());
						ok = client->addTransactionInRecord(w);
					}
				}
				catch(int) /*ou catch (...)*/ {
					cerr << "Not enough money" << endl;
				}
			}
		}
	}
	else cout << "invalid branch id" << endl;

	return ok;
}

void BankManagerSystem::showAllClients() {
	int i=0;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]!=NULL){
			branchArray[i]->showClients();
		}
	}
}

Client* BankManagerSystem::findClientById(int id) {
	int i=0;
	Client * target=NULL;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]!=NULL){
			target=branchArray[i]->findClientById(id);
			return target;
		}
	}
	return NULL;
}

Branch* BankManagerSystem::findBranchById(int id) {
	Branch* target=NULL;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==id) {
			target=branchArray[i];
			return target;
		}
	}
	return NULL;
}

void BankManagerSystem::findClientByName(string name) {
	int i=0;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]!=NULL){
			branchArray[i]->findClientByName(name);
		}
	}
}

bool BankManagerSystem::closeBranch() {
	int id=0;
	int i=0;
	this->showBranches();
	cout << "Enter the id of the branch you want to delete : ";
	cin >> id;
	for(i=0;i<maxbranch;i++){
		if(branchArray[i]!=NULL){
			if(branchArray[i]->getBranchid()==id){
				delete branchArray[i];
				branchArray[i]=NULL;
				return true;
			}
		}
	}
	return false;
}
