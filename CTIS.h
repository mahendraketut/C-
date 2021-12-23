/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#ifndef NEWCOVIDTEST_CTIS_H
#define NEWCOVIDTEST_CTIS_H

class CTIS;
class User;
class Patient;
class CentreOfficer;
class TestCentre;
class TestKit;
class CovidTest;
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Header of class CTIS
 */
class CTIS {
private:
    vector<CentreOfficer*> centreOfficerData;
    vector<TestCentre*>testCentreData;
    vector<Patient*> patientData;

public:
    //constructor
    CTIS();

    //accessor vector
    vector<CentreOfficer*> getVectorOfficer();
    vector<TestCentre*> getVectorTestCentre();
    vector<Patient*> getVectorPatient();

    //vector mutator
    CentreOfficer* newOfficer(string, string, string);
    TestCentre* newCentre(string, string);
    Patient* newPatient(string username, string password, string name);

    //other method
    bool doubleUsernameOfficerVerification(string username);
    bool loginManager(string username, string password, string position);
    bool loginTester(string username, string password, string position);
    string generateCentreID();
    string findOfficerNameInWelcomeMessage(string username);
    bool validateNoDuplicatePatientTesting(string userName);
    bool loginPatient(string username, string password);
    void viewTestForPatient(string username, string password);
    string findTestCentre(string username);

    //destructor
    ~CTIS();
};

/**
 * Header of class User
 */
class User {
private:
    string username;
    string password;
    string name;

public:
    //constructor
    User();
    User(string inUname, string inPass, string inName);

    //mutator
    void setUserName(string inUn);
    void setPassword(string inPs);
    void setName(string inNm);

    //accessor
    string getUserName();
    string getPassword();
    string getName();

    //method
    virtual string viewTestHistory(string, string) = 0; //pure virtual function

    //destructor
    ~User();
};

ostream& operator<<(ostream& strm, const User& user);

/**
 * Header of class Patient
 */
class Patient: public User{
private:
    vector<CovidTest*> covidTestData;
    string type;
    string symptoms;

public:
    //constructor
    Patient();
    Patient(string inUn, string inPs, string inNm, string inPt, string inSym);

    //mutator
    CovidTest* newTesting(string date);
    void setPatientType(string inPt);
    void setPatientSymptoms(string inSym);

    //accessor
    vector<CovidTest*> getVectorCovidTesting();
    string getPatientType();
    string getPatientSymptoms();

    //method
    bool findTestID(string testID);
    void updateTest(string testID, string result, string resultDate);
    string viewTestHistory(string, string) override;
    string generateTestID();

    //destructor
    ~Patient();
};

ostream& operator<<(ostream& strm, Patient& patient);

/**
 * Header of class Centre Officer
 */
class CentreOfficer: public User{
private:
    vector<CovidTest*> covidTestData;
    vector<TestCentre*> testCentreData;
    string position;
    string testCentre;

public:
    //constructor
    CentreOfficer();
    CentreOfficer(string inUn, string inPs, string inNm, string inPos, string inTestCentre);

    //mutator
    CovidTest* newTesting(string date);
    TestCentre* newCentre(string, string);
    void setPosition(string inPos);
    void setTestCentre(string inTestCentre);

    //accessor
    vector<CovidTest*> getVectorCovidTesting();
    vector<TestCentre*> getVectorTestCentre();
    string getPosition();
    string getTestCentre();

    //method
    void updateTest(string testID, string result, string resultDate);
    string viewTestHistory(string, string) override;
    void generateTestRpt(string centre);

    //destructor
    ~CentreOfficer();
};

ostream& operator<<(ostream& strm, CentreOfficer officer);

/**
 * Header of class Test Centre
 */
class TestCentre{
private:
    vector<TestKit*> testKitData;
    string centreID;
    string centreName;
    string nameManager;
public:
    //constructor
    TestCentre();
    TestCentre(string inCentID, string inCentName, string inManager);

    //mutator
    TestKit* newTestKit(string kitName, int qty);
    void setCentreID(string inCentID);
    void setCentreName(string inCentName);
    void setCentreManager(string inCentManager);

    //accessor
    vector<TestKit*> getVectorTestKit();
    string getCentreID();
    string getCentreName();
    string getCentreManager();

    //methods
    bool doubleNameTestKit(string name);
    string generateKitID();
    int setNewTestKitQty(string kitID, int qty);
    bool validateKitIDInputted(string kitID);
    void setTestKitWhenNewTestIsRecorded(int status);

    //destructor
    ~TestCentre();
};

ostream& operator<<(ostream& strm, TestCentre testCentre);

/**
 * Header of Class Test Kit
 */
class TestKit{
private:
    vector<CovidTest*> covidTestData;
    string testKitName;
    string kitID;
    int availableStock{};
public:
    //constructor
    TestKit();
    TestKit(string inTestName, string inKitID, int inAvailable);

    //mutator
    CovidTest* newTesting(string date);
    void setTestKitName(string inTestName);
    void setKitID(string inKitID);
    void setAvailableStock(int inAvailable);

    //accessor
    vector<CovidTest*> getVectorCovidTesting();
    string getTestName();
    string getKitID();
    int getAvailableStock();

    //method
    void updateTest(string testID, string result, string resultDate);

    //destructor
    ~TestKit();
};

ostream& operator<<(ostream& strm, TestKit testKit);

/**
 * Header of Class Covid Test
 */
class CovidTest{
private:
    string testID;
    string testDate;
    string result;
    string resultDate;
    string status;
    string HC;

public:
    //Constructor
    CovidTest();
    CovidTest(string inTsId, string inTsDt, string inRs,
              string inRd, string inSt, string inHc);

    //mutator
    void setTestID(string inTsId);
    void setTestDate(string inTsDt);
    void setResult(string inRs);
    void setResultDate(string inRd);
    void setStatus(string inSt);
    void setHealthCare(string inHc);

    //accessor
    string getTestID();
    string getTestDate();
    string getResult();
    string getResultDate();
    string getStatus();
    string getHc();
};

ostream& operator<<(ostream& strm, CovidTest covidTest);

#endif //NEWCOVIDTEST_CTIS_H
