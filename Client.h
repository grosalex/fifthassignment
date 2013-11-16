/*
 * Client.h
 *
 *  Created on: 16 nov. 2013
 *      Author: William
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "Date.h"
#include "Account.h"
#include <string>
class Client {
public:
	Client();
	virtual ~Client();

private:
	Date birhdate;
	string name;
	string address;
	string phonenb;
	string socialnb;
	Account* accounts[10];///TODO Combien d'account ? Vector ? Mettre plutot id client dans classe account ?
};

#endif /* CLIENT_H_ */
