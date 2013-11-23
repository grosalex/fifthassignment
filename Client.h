/*
 * Client.h
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "Date.h"
//#include "Date.cpp"

#include "Account.h"
//#include "Account.cpp"
#include <string>
#include "Transaction.h"
#define maxAccount 10
#define maxRecord 10
class Client {
public:
	Client();
	virtual ~Client();
	bool addAccount();
	void print();///todo on affiche les comptes et les records?

private:
	int clientid;
	static int number_of_clients;
	Date* birhdate;
	string name;
	string address;
	string phonenb;
	string socialnb;
	int branchid;
	//Account* accounts[10];///TODO Combien d'account ? Vector ? Mettre plutot id client dans classe account ?
	Transaction* records[10];
};

#endif /* CLIENT_H_ */
