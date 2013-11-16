/*
 * Date.cpp
 *
 *  Created on: 28 oct. 2013
 *      Author: grosalex
 */

#include "Date.h"

Date::Date() {
	int inDay,inMonth,inYear;
	cout << "Enter the day : ";
	cin >> inDay;
	cout << "Enter the month : ";
	cin >> inMonth;
	cout << "Enter the year : ";
	cin >> inYear;
	day=inDay;
	month=inMonth;
	year=inYear;
}

Date::Date(int inDay, int inMonth, int inYear){
	day=inDay;
	month=inMonth;
	year=inYear;
}
Date::~Date() {

}

void Date::print() {
	cout << day << "/" << month << "/" << year;
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() const {
	return year;
}


void Date::setYear(int year) {
	this->year = year;
}
