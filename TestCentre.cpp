/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>
using namespace std;

//constructor
TestCentre::TestCentre(){
    setCentreID("null");
    setCentreName("null");
    setCentreManager("null");
}

TestCentre::TestCentre(string inCentreID, string inCentreName, string inManager){
    setCentreID(inCentreID);
    setCentreName(inCentreName);
    setCentreManager(inManager);
}

//mutator
void TestCentre::setCentreID(string inCentreID) {centreID = inCentreID;}
void TestCentre::setCentreName(string inCentreName) {centreName = inCentreName;}
void TestCentre::setCentreManager(string inCentManager) {nameManager = inCentManager;}

//accessor
string TestCentre::getCentreID() {return centreID;}
string TestCentre::getCentreName() {return centreName;}
string TestCentre::getCentreManager() {return nameManager;}
vector<TestKit *> TestCentre::getVectorTestKit() {return testKitData;}

//method to add a new test kit data
TestKit *TestCentre::newTestKit(string kitName, int qty) {
    TestKit *newTestKitData;
    newTestKitData = new TestKit();
    testKitData.push_back(newTestKitData);
    newTestKitData->setTestKitName(kitName);
    newTestKitData->setAvailableStock(qty);
    return newTestKitData;
}

//method to verify if there is double name of test kit founded
bool TestCentre::doubleNameTestKit(string name) {
    for(int i = 0; i < getVectorTestKit().size(); i++){
        if (getVectorTestKit().at(i)->getTestName()==name)
            return true;
    }
    return false;
}

//method to generate test kit ID
string TestCentre::generateKitID() {
    string kitID;
    if(to_string(getVectorTestKit().size()).length() == 1)
        kitID = "TK000" + to_string(getVectorTestKit().size());
    else if(to_string(getVectorTestKit().size()).length() == 2)
        kitID = "TK00" + to_string(getVectorTestKit().size());
    else if(to_string(getVectorTestKit().size()).length() == 3)
        kitID = "TK0" + to_string(getVectorTestKit().size());
    else
        kitID = "TK" + to_string(getVectorTestKit().size());
    return kitID;
}

//method to set the new quantity of test kit based on kit id
int TestCentre::setNewTestKitQty(string kitID, int qty) {
    int newQty;
    for(int i = 0; i < getVectorTestKit().size(); i++){
        int getQty = getVectorTestKit().at(i)->getAvailableStock();
        if(getVectorTestKit().at(i)->getKitID()==kitID)
        {
            newQty = getQty+qty;
            getVectorTestKit().at(i)->setAvailableStock(newQty);
        }
    }
    return newQty;
}

//validate the kit ID that inputted by the manager,
//if the kit id that inputted match with the data,
//then the system will return true and vice versa
bool TestCentre::validateKitIDInputted(string kitID) {
    for(int i = 0; i < getVectorTestKit().size(); i++){
        if(getVectorTestKit().at(i)->getKitID()==kitID)
            return true;
    }
    return false;
}

//method that used to decrease the quantity
//of tes kit when the tester record a new test
void TestCentre::setTestKitWhenNewTestIsRecorded(int status) {
    for (int i = 0; i < getVectorTestKit().size(); i++) {
        int stock = getVectorTestKit().at(i)->getAvailableStock();
        if(getVectorTestKit().at(i)->getAvailableStock()!=0 && status == 1)
        {
            int newStock = stock - 1;
            testKitData.at(i)->setAvailableStock(newStock);
        }
    }
}

//destructor
TestCentre::~TestCentre() {}

ostream& operator<<(ostream& strm, TestCentre testCentre)
{
    return strm
            <<"Your test centre successfully registered with: " << endl
            <<"Centre ID        : " << testCentre.getCentreID() << endl
            <<"Centre Name      : " << testCentre.getCentreName() << endl
            <<"Centre Manager   : " << testCentre.getCentreManager() << endl;
}
