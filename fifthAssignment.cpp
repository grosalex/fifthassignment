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
	///Initialize some variable
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
	cout << "This is the fifth Assignment" << endl;
	///Main Loop
	do {
		cout << "Enter 1 to create a branch" << endl << "Enter 2 to create a client in a branch" << endl;
		cout << "Enter 3 to open an account for a client " << endl << "Enter 4 to look for a client " << endl;
		cout << "Enter 5 to show all client in a branch" << endl << "Enter 6 to close a branch" << endl;
		cout << "Enter 7 to destroy a client" << endl << "Enter 8 to cancel a transaction "<<endl;
		cout << "Enter 9 to add a transaction " << endl;
		cout << "Enter q to quit" << endl;
		cin >> choice;
		switch(choice){
		case '1':
			myManager->addBranch();//Add branch method
			break;
		case '2':
			/*
			 * We first show all branches and then ask in which one
			 * you want to create the new client
			 */
			myManager->showBranches();
			cout << "Enter the branch id in wich you want to create the client : ";
			cin >> id;
			if(myManager->checkBranch(id)) {
				results=myManager->addClientInBranch(id);
				if(results){
					cout << "Success" << endl;
				}
				else{
					cout << "failure" << endl;
				}
			}
			else cout << "Invalid branch id" << endl;
			break;
		case '3'://call the add Account method and study its result
			results=myManager->addAccount();
			if(results==true){
				cout << "Account succesfully created" << endl;
			}
			else cout << "Failure" << endl;
			break;
		case '4':// finding a client by his name
			cout << "Enter the client's name : ";
			cin >> name;
			myManager->findClientByName(name);
			break;
		case '5':// show all clients in a branch
			myManager->showBranches();
			cout << "Enter the branch id in which you want to show clients : ";
			cin >> id;
			if(myManager->checkBranch(id)) myManager->showClientFromBranch(id);
			else cout << "Invalid branch id" << endl;
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
			if(myManager->checkBranch(id)) {
				myManager->showClientFromBranch(id);
				cout << "What is the id of the client you want to destroy : ";
				cin >> id;
				branchTarget->deleteclient(id);
			}
			else cout << "Invalid branch id" << endl;
			break;
		case '8'://cancel a transaction
			myManager->showAllClients();
			cout << "What is the id of the client who wants to cancel a transaction : ";
			cin >> id;
			target=myManager->findClientById(id);
			if(target!=NULL){
				target->showTransactions();
				cout << "Enter the transaction id you want :";
				cin >> idBis;
				targetTransaction=target->findTransactionById(idBis);
				if(targetTransaction!=NULL){
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
				}
				else{
					cout << "Invalid transaction id" << endl;
				}

			}
			else{
				cout << "Invalid Client id "<< endl;
			}
			break;

		case '9':// adding a new transaction
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
