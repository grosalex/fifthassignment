/*
 ============================================================================
 Name        : fifthAssignment.cpp
 Author      : grosalex
 Version     :
 Copyright   : do what you want with it
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include "BankManagerSystem.h"
//#include "BankManagerSystem.cpp"
using namespace std;

int main(void) {
	char choice=' ';
	int id=0;
	int transtype;
	int idBis=0;
	string name;
	Client * target=NULL;
	Branch* branchTarget=NULL;
	Transaction * targetTransaction=NULL;
	bool results=false;
	BankManagerSystem * myManager= new BankManagerSystem();
	cout << "This is the fifth Assignment" << endl; /* prints This is the fifth Assignment */
	/*
	 * TODO
	 * client method => withdrawal, deposite, transfertmoney(acount source, account target, value)
	 *
	 * 1) add/closing branch
	 * 2) add/remove clients dans une branche
	 * 3) open account for a client
	 * 4) recherche client
	 * 5) show clients from a branch
	 * 6) transaction between two date
	 */
	///TODO Faire le addaccount et addclient dans bankmanager, ou revenir � version pr�c�dente (tableau accounts dans client)
	///TODO G�rer le tableau Records dans m�thodes transaction (je le ferai)
	do {
		cin >> choice;
		switch(choice){
		case '1':
			myManager->addBranch();
			break;
		case '2':
			myManager->showBranches();
			cout << "Enter the branch id in wich you want to create the client : ";
			cin >> id;
			results=myManager->addClientInBranch(id);
			if(results){
				cout << "Success" << endl;
			}
			else{
				cout << "failure" << endl;
			}
			break;
		case '3':
			results=myManager->addAccount();
			if(results==true){
				cout << "Account succesfully created" << endl;
			}
			else cout << "Failure" << endl;
			break;
		case '4':
			cout << "Enter the client's name : ";
			cin >> name;
			myManager->findClientByName(name);
			break;
		case '5':
			myManager->showBranches();
			cout << "Enter the branch id in wich you want to show clients : ";
			cin >> id;
			myManager->showClientFromBranch(id);
			break;
		case '6'://close a branch
			results=myManager->closeBranch();
			if(results==true){
				cout << "Branch succesfully closed" << endl;
			}
			else cout << "Failure" << endl;
			break;
		case '7'://destroy a client
			myManager->showBranches();
			cout << "What is the id of the client's branch : ";
			cin >> id;
			branchTarget = myManager->findBranchById(id);
			myManager->showClientFromBranch(id);
			cout << "What is the id of the client you want to destroy : ";
			cin >> id;
			branchTarget->deleteclient(id);
			break;
		case '8'://cancel a transaction
			myManager->showAllClients();
			cout << "What is the id of the client who wants to cancel a transaction : ";
			cin >> id;
			target=myManager->findClientById(id);
			target->showTransactions();
			cout << "Enter the transaction id you want :";
			cin >> idBis;
			targetTransaction=target->findTransactionById(idBis);
			switch(targetTransaction->getTransactionType()) {
			case 'd':
				dynamic_cast<Deposit*>(targetTransaction)->cancel();
				break;
			case 'w':
				dynamic_cast<Withdrawal*>(targetTransaction)->cancel();
				break;
			case 't':
				dynamic_cast<Transfer*>(targetTransaction)->cancel();
				break;
			}
			target->setTransactionToNull(targetTransaction->getTransactionId());
			cout << "Succesfully cancelled" << endl;
			break;

			case '9':
				do {
					cout << "Type 1 to do a deposit or withdrawal, 2 for transfer";
					cin >> transtype;
				}while(transtype!=1 && transtype!=2);
				if(transtype==1) myManager->clientDepositWithdrawal();
				if(transtype==2) myManager->clientTransfer();
				break;
		}
	}while(choice!='q');
	return 0;
}
