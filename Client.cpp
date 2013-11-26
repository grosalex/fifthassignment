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
	birhdate=new Date();
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
	for(i=0;i<maxRecord;i++){
		records[i]=NULL;
	}
}

Client::~Client() {
	delete birhdate;
	delete [] accounts;
	delete [] records;
}

/*bool Client::addAccount() {
	bool result=false;
	int i=0;
	for(i=0;i<maxAccount;i++){
		if(accounts[i]==NULL){
			accounts[i]=new Account();
			i=maxAccount;
		}
	}
	return result;
}
*/
void Client::print() {
	cout << "Client's id : " << clientid<< endl;
	cout << "Client's name : " << name << endl;
	cout << "Client's address is : " << address << endl;
	cout << "Client's phone number is " << phonenb << endl;
	cout << "Client's social number is : "<< socialnb<<endl;
}

Account* Client::findAccountById(int id) {
	int i=0;
	for(i=0;i<10;i++){
		if(accounts[i]!=NULL){
			if(accounts[i]->getAccountnb()==id){
				return accounts[i];
			}
		}
	}
	return NULL;
}

bool Client::addTransactionInRecord(Transaction* t) {
	bool ok=false;

	for(int j=0;j<100;j++){
		if(records[j]==NULL) {
			records[j] = t;
			ok =true;
			j=100;
		}
	}
	return ok;
}

const string& Client::getAddress() const {
	return address;
}

void Client::setAddress(const string& address) {
	this->address = address;
}

int Client::getClientid() const {
	return clientid;
}

void Client::setClientid(int clientid) {
	this->clientid = clientid;
}

const string& Client::getName() const {
	return name;
}

void Client::setName(const string& name) {
	this->name = name;
}

int Client::getNumberOfClients(){
	return number_of_clients;
}

const string& Client::getPhonenb() const {
	return phonenb;
}

void Client::setPhonenb(const string& phonenb) {
	this->phonenb = phonenb;
}

const string& Client::getSocialnb() const {
	return socialnb;
}

void Client::setSocialnb(const string& socialnb) {
	this->socialnb = socialnb;
}

bool Client::openAccount() {
	int i=0;
	for(i=0;i<maxAccount;i++){
		if(accounts[i]==NULL){
			accounts[i]=new Account();
			return true;
		}
	}
	return false;
}

void Client::showTransactions() {
	int i =0;
	for(i=0;i<maxRecord;i++){
		if(records[i]!=NULL){
			switch(records[i]->getTransactionType()) {
				case 'd':
					dynamic_cast<Deposit*>(records[i])->print();
					break;
				case 'w':
					dynamic_cast<Withdrawal*>(records[i])->print();
					break;
				case 't':
					dynamic_cast<Transfer*>(records[i])->print();
					break;
			}
		}
	}
}

Transaction* Client::findTransactionById(int id) {
	int i=0;
	for(i=0;i<maxRecord;i++){
		if(records[i]!=NULL){
			if(records[i]->getTransactionId()==id){
				return records[i];
			}
		}
	}
	return NULL;
}

void Client::showAllAccounts() {
	int i=0;
	for(i=0;i<maxAccount;i++){
		if(accounts[i]!=NULL){
			accounts[i]->print();
		}
	}
}

void Client::showAllRecords() {
	int i=0;
	for(i=0;i<maxRecord;i++){
		if(records[i]!=NULL){
			records[i]->print();
		}
	}
}
