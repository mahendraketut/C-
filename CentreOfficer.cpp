/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>

using namespace std;

//constructor
CentreOfficer::CentreOfficer()
{
    setPosition("null");
    setTestCentre("No Test Centre Registered");
}

CentreOfficer::CentreOfficer(string inUsername, string inPass,
                             string inNameOffc, string inPosition,
                             string inTestCentre)
{
    setUserName(inUsername);
    setPassword(inPass);
    setName(inNameOffc);
    setPosition(inPosition);
    setTestCentre(inTestCentre);
}

//mutator
void CentreOfficer::setPosition(string inPosition) {position = inPosition;}
void CentreOfficer::setTestCentre(string inTestCentre) {testCentre = inTestCentre;}

//accessor
string CentreOfficer::getPosition() {return position;}
string CentreOfficer::getTestCentre() {return testCentre;}
vector<CovidTest*> CentreOfficer::getVectorCovidTesting() {return covidTestData;}
vector<TestCentre*> CentreOfficer::getVectorTestCentre() {return testCentreData;}

string CentreOfficer::viewTestHistory(string username, string password)
{
    return "no test data has recorded";
}

//method to create a new testing data
CovidTest *CentreOfficer::newTesting(string date)
{
    CovidTest *newCovidTest;
    newCovidTest = new CovidTest();
    covidTestData.push_back(newCovidTest);
    newCovidTest->setTestDate(date);
    return newCovidTest;
}

//method to update the result of the test
void CentreOfficer::updateTest(string testID, string result, string resultDate) {
    for(int i = 0; i < getVectorCovidTesting().size(); i++)
        if(getVectorCovidTesting().at(i)->getTestID()==testID)
        {
            getVectorCovidTesting().at(i)->setResult(result);
            getVectorCovidTesting().at(i)->setResultDate(resultDate);
            getVectorCovidTesting().at(i)->setStatus("Complete");
        }
}

//method to add a new test centre data
TestCentre *CentreOfficer::newCentre(string centreName, string manager)
{
    TestCentre *newTestCentreData;
    newTestCentreData = new TestCentre();
    testCentreData.push_back(newTestCentreData);
    newTestCentreData->setCentreName(centreName);
    newTestCentreData->setCentreManager(manager);
    return newTestCentreData;
}

//method to generate test report
void CentreOfficer::generateTestRpt(string centre) {
    for(int i = 0;i < getVectorCovidTesting().size(); i++){
        if(getVectorCovidTesting().at(i)->getHc()==centre)
        {
            cout << "Test " << i+1 << endl;
            cout << "Test ID    : " << getVectorCovidTesting().at(i)->getTestID() << endl;
            cout << "Test Date  : " << getVectorCovidTesting().at(i)->getTestDate() << endl;
            cout << "Result     : " << getVectorCovidTesting().at(i)->getResult() << endl;
            cout << "Result Date: " << getVectorCovidTesting().at(i)->getResultDate() << endl;
            cout << "Status     : " << getVectorCovidTesting().at(i)->getStatus() << endl;
            cout << endl;
        }
    }
}

//destructor
CentreOfficer::~CentreOfficer() {}

ostream& operator<<(ostream& strm, CentreOfficer officer)
{
    return strm
            <<"\nYou are successfully registered with: " << endl
            <<"Username     : " << officer.getUserName()<<endl
            <<"Password     : " << officer.getPassword()<<endl
            <<"Name         : " << officer.getName()<<endl
            <<"Test Centre  : " << officer.getTestCentre()<<endl
            <<"Position     : " << officer.getPosition()<<endl;
}
