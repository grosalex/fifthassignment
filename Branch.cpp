/*
 * Branch.cpp
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#include "Branch.h"
int Branch::number_of_branches=1;

Branch::Branch() {
	string inAddress, inPhone;
	int i=0;
	cout << "Enter the address : ";
	cin >> inAddress;
	cout << "Enter the phone number : ";
	cin >> inPhone;
	branchid=number_of_branches;
	number_of_branches++;
	for(i=0;i<maxClient;i++){
		clientsArray[i]=NULL;
	}
	address = inAddress;
	phonenb = inPhone;
}

bool Branch::addClient() {
	bool results=false;
	int i=0;
	for(i=0;i<maxClient;i++){
		if(clientsArray[i]==NULL){
			clientsArray[i]=new Client();
			i=maxClient;
			results=true;
		}
	}
	return results;
}

Branch::~Branch() {
	// TODO Auto-generated destructor stub
	delete[] clientsArray;
}

void Branch::print() {
	cout << "Branch id : " <<branchid<< endl;
	cout << "Address : " << address << endl;
	cout << "Phone number : " << phonenb << endl;
}

int Branch::getBranchid() const {
	return branchid;
}

void Branch::setBranchid(int branchid) {
	this->branchid = branchid;
}

void Branch::showClients() {
	int i=0;
	for(i=0;i<maxClient;i++){
		if(clientsArray[i]!=NULL){
			clientsArray[i]->print();
		}
	}
}

Client* Branch::findClientById(int id) {
	int i=0;
	for(i=0;i<maxClient;i++){
		if(clientsArray[i]!=NULL){
			if(clientsArray[i]->getClientid()==id){
				return clientsArray[i];
			}
		}
	}
	return NULL;
}

void Branch::findClientByName(string name) {
	int i=0;
	for(i=0;i<maxClient;i++){
		if(clientsArray[i]!=NULL){
			if (clientsArray[i]->getName()==name) {
				clientsArray[i]->print();
			}
		}
	}
}
