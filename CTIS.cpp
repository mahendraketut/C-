/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"

//constructor
CTIS::CTIS(){}

//vector mutator
vector<CentreOfficer*> CTIS::getVectorOfficer() {return centreOfficerData;}
vector<TestCentre*> CTIS::getVectorTestCentre() {return testCentreData;}
vector<Patient*> CTIS::getVectorPatient() {return patientData;}

//destructor
CTIS::~CTIS() {}

//other Method:
//method to add a new officer
CentreOfficer* CTIS::newOfficer(string usname, string uspass, string position)
{
    CentreOfficer *newOfficerData;
    newOfficerData = new CentreOfficer();
    centreOfficerData.push_back(newOfficerData);
    newOfficerData->setUserName(usname);
    newOfficerData->setPassword(uspass);
    newOfficerData->setPosition(position);
    return newOfficerData;
}

//method to verify double username data
bool CTIS::doubleUsernameOfficerVerification(string username) {
    for (int i = 0; i < getVectorOfficer().size(); ++i) {
        if (getVectorOfficer().at(i)->getUserName()==username)
            return true;
    }
    return false;
}

//method to check the username, and password data when
// the manager want to log in to the system. if the manager
// data was founded this method will return "true" and vice versa
bool CTIS::loginManager(string username, string password, string position)
{
    for (int i = 0; i < getVectorOfficer().size(); i++) {
        if (getVectorOfficer().at(i)->getUserName() == username &&
        getVectorOfficer().at(i)->getPassword() == password &&
        getVectorOfficer().at(i)->getPosition() == "Manager")
            return true;
    }
    return false;
}

//method to check the username, and password data when
// the tester want to log in to the system. if the tester
// data was founded this method will return "true" and vice versa
bool CTIS::loginTester(string username, string password, string position)
{
    for (int i = 0; i < getVectorOfficer().size(); i++) {
        if (getVectorOfficer().at(i)->getUserName() == username &&
        getVectorOfficer().at(i)->getPassword() == password &&
        getVectorOfficer().at(i)->getPosition() == "Tester")
            return true;
    }
    return false;
}

//method to add a new test centre
TestCentre *CTIS::newCentre(string centreName, string manager)
{
    TestCentre *newTestCentreData;
    newTestCentreData = new TestCentre();
    testCentreData.push_back(newTestCentreData);
    newTestCentreData->setCentreName(centreName);
    newTestCentreData->setCentreManager(manager);
    return newTestCentreData;
}

//method to generate test centre ID
string CTIS::generateCentreID() {
    string cenId;
    if (to_string(getVectorTestCentre().size()).length() == 1)
        cenId = "TC000" + to_string(getVectorTestCentre().size());
    else if (to_string(getVectorTestCentre().size()).length() == 2)
        cenId = "TC00" + to_string(getVectorTestCentre().size());
    else if (to_string(getVectorTestCentre().size()).length() == 3)
        cenId = "TC0" + to_string(getVectorTestCentre().size());
    else
        cenId = "TC" + to_string(getVectorTestCentre().size());
    return cenId;
}

//method to find the officer name when the officer log in to the system.
//it will return the officer name if the data was founded
string CTIS::findOfficerNameInWelcomeMessage(string username){
    for (int i = 0; i < getVectorOfficer().size(); i++) {
        if (getVectorOfficer().at(i)->getUserName()==username)
            return getVectorOfficer().at(i)->getName();
    }
    return NULL;
}

//method to add a new patient
Patient *CTIS::newPatient(string username, string password, string name) {
    Patient *newPatientData;
    newPatientData = new Patient();
    patientData.push_back(newPatientData);
    newPatientData->setUserName(username);
    newPatientData->setPassword(password);
    newPatientData->setName(name);
    return newPatientData;
}

//method to validate no duplication data of patient.
// if there is founded the same username and password of patient,
// then the method will return true, and vice versa
bool CTIS::validateNoDuplicatePatientTesting(string userName){
    for(int i=0; i < getVectorPatient().size(); i++){
        if (getVectorPatient().at(i)->getUserName()==userName){
            return true;
        }
    }
    return  false;
}

//method to validate patient login, if the patient input the same username
//and password with the data in vector,
//then the method will return true and vice versa
bool CTIS::loginPatient(string username, string password) {
    for (int i = 0; i < getVectorPatient().size(); i++){
        if(getVectorPatient().at(i)->getUserName()==username &&
        getVectorPatient().at(i)->getPassword()==password)
            return true;
    }
    return false;
}

//method to find the test centre name for tester.
//if the username of administrator that registering the tester founded,
//then the method will get the test centre name based
//on where the index of username that founded
string CTIS::findTestCentre(string username) {
    for(int i = 0; i < getVectorOfficer().size(); i++)
    {
        if (getVectorOfficer().at(i)->getUserName()==username)
        {
            return getVectorOfficer().at(i)->getTestCentre();
        }
    }
    return NULL;
}

//method to view the test for patient
void CTIS::viewTestForPatient(string username, string password) {
    for (int i = 0; i < getVectorPatient().size(); i++) {
        if (getVectorPatient().at(i)->getUserName() == username &&
            getVectorPatient().at(i)->getPassword() == password) {
            cout << "Hi, " << getVectorPatient().at(i)->getName() << endl;
            cout << "you have been recorded as having tested with Testing Data:" << endl;
            cout << "Patient Username   : " << getVectorPatient().at(i)->getUserName() << endl;
            cout << "Patient Name       : " << getVectorPatient().at(i)->getName() << endl;
            cout << "Patient Type       : " << getVectorPatient().at(i)->getPatientType() << endl;
            cout << "Patient Symptoms   : " << getVectorPatient().at(i)->getPatientSymptoms() << endl;
        }
    }
}

