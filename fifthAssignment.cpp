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
#include "BankManagerSystem.cpp"
using namespace std;

int main(void) {
	char choice=' ';
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
	switch(choice){
	case '1'://
		myManager->addBranch();
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	}
	return 0;
}
