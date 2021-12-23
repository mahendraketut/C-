/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>
using namespace std;

//constructor
Patient::Patient()
{
    setPatientType("Null");
    setPatientSymptoms("null");
}

//constructor with argument
Patient::Patient(string inUsername, string inPass, string inName, string inType, string inSymptoms)
{
    setUserName(inUsername);
    setPassword(inPass);
    setName(inName);
    setPatientType(inType);
    setPatientSymptoms(inSymptoms);
}

//mutator
void Patient::setPatientType(string inType){type = inType;}
void Patient::setPatientSymptoms(string inSymptoms){symptoms = inSymptoms;}

//accessor
string Patient::getPatientType(){return type;}
string Patient::getPatientSymptoms(){return symptoms;}
vector<CovidTest*> Patient::getVectorCovidTesting() {return covidTestData;}

//method to add a new covid testing data
CovidTest *Patient::newTesting(string date)
{
    CovidTest *newCovidTest;
    newCovidTest = new CovidTest();
    covidTestData.push_back(newCovidTest);
    newCovidTest->setTestDate(date);
    return newCovidTest;
}

//method that used to find Test ID, if the Test ID that inputted was
// founded in the data, this method will return true and vice versa
bool Patient::findTestID(string testID) {
    for (int i = 0; i < getVectorCovidTesting().size(); i++) {
        if (getVectorCovidTesting().at(i)->getTestID() == testID)
            return true;
    }
    return false;
}

//method that used to update the test data based on the test id
void Patient::updateTest(string testID, string result, string resultDate) {
    for(int i = 0; i < getVectorCovidTesting().size(); i++)
        if(getVectorCovidTesting().at(i)->getTestID()==testID)
        {
            getVectorCovidTesting().at(i)->setResult(result);
            getVectorCovidTesting().at(i)->setResultDate(resultDate);
            getVectorCovidTesting().at(i)->setStatus("Complete");
        }
}

//method to generate test id
string Patient::generateTestID() {
    string TestID;
    if(to_string(getVectorCovidTesting().size()).length() == 1)
        TestID = "CT000" + to_string(getVectorCovidTesting().size());
    else if(to_string(getVectorCovidTesting().size()).length() == 2)
        TestID = "CT00" + to_string(getVectorCovidTesting().size());
    else if(to_string(getVectorCovidTesting().size()).length() == 3)
        TestID = "CT0" + to_string(getVectorCovidTesting().size());
    else
        TestID = "CT" + to_string(getVectorCovidTesting().size());
    return TestID;
}

string Patient::viewTestHistory(string username, string password)
{
    return "no test data has recorded";
}

//destructor
Patient::~Patient() {}

ostream& operator<<(ostream& strm, Patient pat)
{
    return strm
            <<"\nYou are successfully registered with:"<<endl
            <<"Username     : " << pat.getUserName() << endl
            <<"Password     : " << pat.getPassword() << endl
            <<"Name         : " << pat.getName() << endl
            <<"Patient type : " << pat.getPatientType() << endl
            <<"Symptoms     : " << pat.getPatientSymptoms() << endl;
}

