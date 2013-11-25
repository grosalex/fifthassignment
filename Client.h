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
#include "Withdrawal.h"
#include "Deposit.h"
#include "Transfer.h"
#define maxAccount 10
#define maxRecord 10
class Client {
public:
	Client();
	virtual ~Client();
	//bool addAccount();
	void print();///todo on affiche les comptes et les records?
	bool addTransactionInRecord(Transaction*);
	Account* findAccountById(int);
	const string& getAddress() const;
	void setAddress(const string& address);
	const Date*& getBirhdate() const;
	void setBirhdate(const Date*& birhdate);
	int getClientid() const;
	void setClientid(int clientid);
	const string& getName() const;
	void setName(const string& name);
	int getNumberOfClients();
	void setNumberOfClients(int numberOfClients);
	const string& getPhonenb() const;
	void setPhonenb(const string& phonenb);
	const Transaction**& getRecords() const;
	const string& getSocialnb() const;
	void setSocialnb(const string& socialnb);
	bool openAccount();
	void showTransactions();
	Transaction * findTransactionById(int id);

private:
	int clientid;
	static int number_of_clients;
	Date* birhdate;
	string name;
	string address;
	string phonenb;
	string socialnb;
	Account* accounts[10];///TODO Combien d'account ? Vector ? Mettre plutot id client dans classe account ?
	Transaction* records[100];
};

#endif /* CLIENT_H_ */
