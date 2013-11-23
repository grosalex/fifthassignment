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
	///TODO Faire le addaccount et addclient dans bankmanager
	switch(choice){
	case '1'://
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
		break;
	case '4':
		break;
	case '5':
		myManager->showBranches();
		cout << "Enter the branch id in wich you want to show clients : ";
		cin >> id;
		myManager->showClientFromBranch(id);
		break;
	case '6':
		break;
	}
	return 0;
}
