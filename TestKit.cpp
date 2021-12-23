/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>

using namespace std;

//constructor
TestKit::TestKit()
{
    setTestKitName("null");
    setKitID("null");
    setAvailableStock(0);
}

//constructor with argument
TestKit::TestKit(string inTestName, string inKitID, int inAvailable)
{
    setTestKitName(inTestName);
    setKitID(inKitID);
    setAvailableStock(inAvailable);
}

//mutator
void TestKit::setTestKitName(string inTestName) {testKitName = inTestName;}
void TestKit::setKitID(string inKitID) {kitID = inKitID;}
void TestKit::setAvailableStock(int inAvailable) {availableStock = inAvailable;}

//accessor
string TestKit::getTestName() {return testKitName;}
string TestKit::getKitID() {return kitID;}
int TestKit::getAvailableStock() {return availableStock;}
vector<CovidTest *> TestKit::getVectorCovidTesting() {return covidTestData;}

//method to add a new test
CovidTest *TestKit::newTesting(string date)
{
    CovidTest *newCovidTest;
    newCovidTest = new CovidTest();
    covidTestData.push_back(newCovidTest);
    newCovidTest->setTestDate(date);
    return newCovidTest;
}

//method to update test based on the test id
void TestKit::updateTest(string testID, string result, string resultDate) {
    for(int i = 0; i < getVectorCovidTesting().size(); i++)
        if(getVectorCovidTesting().at(i)->getTestID()==testID)
        {
            getVectorCovidTesting().at(i)->setResult(result);
            getVectorCovidTesting().at(i)->setResultDate(resultDate);
            getVectorCovidTesting().at(i)->setStatus("Complete");
        }
}

//destructor
TestKit::~TestKit() {}

ostream& operator<<(ostream& strm, TestKit testKit)
{
    return strm
            <<"Your Kit are registered with: "<<endl
            <<"Test Kit ID          : " << testKit.getKitID()<< endl
            <<"Test Kit Name        : " << testKit.getTestName()<<endl
            <<"Test Kit Quantity    : " << testKit.getAvailableStock()<< endl;
}