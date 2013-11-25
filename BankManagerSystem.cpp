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

/*bool BankManagerSystem::doDeposit() {
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
				Deposit* = new Deposit(returnBranchId(accountsource),accountsource,branch,amount,"d");

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
}*/

bool BankManagerSystem::checkBranch(int branchID) {
	bool ok = false;
	for(int i=0;i<maxbranch;i++) {
		if(branchID == branchArray[i]->getBranchid() && branchArray[i]!=NULL) {
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
			i=maxbranch;
		}
	}

	cout << "Select account target branch";
	cin >> targetBranch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==targetBranch) {
			cout << "Branch Target found" << endl;
			i=maxbranch;
			cout << "Enter client target id";
			cin >> clientTargetId;
			clientTarget = branchArray[i]->findClientById(clientTargetId);
			cout << "Enter account nb";
			cin >> targetAccountid;
			targetAccount = clientTarget->findAccountById(targetAccountid);
		}
	}
	cout << "Select account source branch";
	cin >> sourceBranch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==sourceBranch) {
			cout << "Branch Source found" << endl;
			i=maxbranch;
			cout << "Enter client source id";
			cin >> clientSourceId;
			clientTarget = branchArray[i]->findClientById(clientSourceId);
			cout << "Enter account nb";
			cin >> sourceAccountid;
			targetAccount = clientTarget->findAccountById(sourceAccountid);
		}
	}
	Transfer *t = new Transfer(sourceBranch,sourceAccount,targetBranch,targetAccount,transactionBranch);
	sourceAccount->setMoney(sourceAccount->getMoney()-t->getAmount());
	targetAccount->setMoney(targetAccount->getMoney()+t->getAmount());
	if(clientSource->addTransactionInRecord(t) && clientTarget->addTransactionInRecord(t)) ok =true;

	return ok;
}

bool BankManagerSystem::clientDepositWithdrawal() {
	bool ok=false;
	int branch;
	int transactionBranch;
	int clientId;
	int accountid;
	Client* client;
	Account* account;
	string type;

	cout << "Select where you are doing the transaction";
	cin >> transactionBranch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==transactionBranch) {
			cout << "Transaction Branch found" << endl;
			i=maxbranch;
		}
	}

	cout << "Select account branch";
	cin >> branch;
	for(int i=0;i<maxbranch;i++) {
		if(branchArray[i]!=NULL && branchArray[i]->getBranchid()==branch) {
			cout << "Branch found" << endl;
			i=maxbranch;
			cout << "Enter client id";
			cin >> clientId;
			client = branchArray[i]->findClientById(clientId);
			cout << "Enter account nb";
			cin >> accountid;
			account = client->findAccountById(accountid);
		}
	}
	do {
		cout << "Type d for Deposit, w for Withdrawal";
		cin >> type;
	}while(type!="d" || type!="w");
	if(type == "d") {
		Deposit *d = new Deposit(branch,account,transactionBranch);
		account->setMoney(account->getMoney()+d->getAmount()*account->getInterest()+d->getAmount());
		ok = client->addTransactionInRecord(d);
	}
	else {
		Withdrawal *w = new Withdrawal(branch,account,transactionBranch);
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
				return true;
			}
		}
	}
	return false;
}
