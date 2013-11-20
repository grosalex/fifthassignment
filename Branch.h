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
class Branch {
public:
	Branch();
	virtual ~Branch();

private:
	int branchid;
	string address;
	string phonenb;
	static int number_of_branches;
};

#endif /* BRANCH_H_ */
