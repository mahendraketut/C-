/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>
using namespace std;

//default constructor
User::User() {
    setUserName("null");
    setPassword("null");
    setName("null");
}

//constructor with argument
User::User(string inUname, string inPass, string inName) {
    setUserName(inUname);
    setPassword(inPass);
    setName(inName);
}

//mutator
void User::setUserName(string inUn) {username = inUn;}
void User::setPassword(string inPs) {password = inPs;}
void User::setName(string inNm) {name = inNm;}

//accessor
string User::getUserName() {return username;}
string User::getPassword() {return password;}
string User::getName() {return name;}

//destructor
User::~User() {}

