/*
 * Branch.h
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#ifndef BRANCH_H_
#define BRANCH_H_
#include <iostream>
using namespace std;
#include <string>
#include "Client.h"
//#include "Client.cpp"
#define maxClient 100
class Branch {
public:
	Branch();
	bool addClient();
	virtual ~Branch();
	void print();
	int getBranchid() const;
	void setBranchid(int branchid);
	void showClients();
	Client * findClientById(int id);
	void findClientByName(string name);

private:
	int branchid;
	string address;
	string phonenb;
	static int number_of_branches;
	Client* clientsArray[maxClient];
};

#endif /* BRANCH_H_ */
