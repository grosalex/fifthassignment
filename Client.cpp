/*
 * Client.cpp
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#include "Client.h"
int Client::number_of_clients=1;
Client::Client() {
	int i=0;
	cout << "Enter his birthdate : ";
	birhdate=new Date;
	string inName;
	string inAddress;
	string inPhonenb;
	string inSocialnb;
	clientid=number_of_clients;
	number_of_clients++;
	cout << "Enter his name : ";
	cin >> inName;
	cout << "Enter his address : ";
	cin >> inAddress;
	cout << "Enter his phone : ";
	cin >> inPhonenb;
	cout << "Enter his social number : ";
	cin >> inSocialnb;
	name=inName;
	address=inName;
	phonenb=inPhonenb;
	socialnb=inSocialnb;
	for(i=0;i<maxAccount;i++){
		accounts[i]=NULL;
	}
	for(i=0;i<maxRecord;i++){
		records[i]=NULL;
	}
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

bool Client::addAccount() {
}
