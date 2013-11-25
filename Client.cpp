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
	// TODO Auto-generated destructor stub
}

bool Client::addAccount() {
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

void Client::print() {
	cout << "Client's id : " << clientid<< endl;
	cout << "Client's name : " << name << endl;
	cout << "Client's address is : " << address << endl;
	cout << "Client's phone number is " << phonenb << endl;
	cout << "Client's social number is : "<< socialnb<<endl;
}

bool Client::doTransaction() {
	bool ok=false;
	int accountnb;
	cout << "Select the account (enter account ID)" << endl;
	for(int i=0; i<10;i++) {
		accounts[i]->print();
	}
	cin >> accountnb;
}

const string& Client::getAddress() const {
	return address;
}

void Client::setAddress(const string& address) {
	this->address = address;
}

const Date*& Client::getBirhdate() const {
	return birhdate;
}

void Client::setBirhdate(const Date*& birhdate) {
	this->birhdate = birhdate;
}

int Client::getBranchid() const {
	return branchid;
}

void Client::setBranchid(int branchid) {
	this->branchid = branchid;
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

static int Client::getNumberOfClients() const {
	return number_of_clients;
}

void Client::setNumberOfClients(static int numberOfClients) {
	number_of_clients = numberOfClients;
}

const string& Client::getPhonenb() const {
	return phonenb;
}

void Client::setPhonenb(const string& phonenb) {
	this->phonenb = phonenb;
}

const Transaction**& Client::getRecords() const {
	return records;
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
