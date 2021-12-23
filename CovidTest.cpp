/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>

using namespace std;

//constructor
CovidTest::CovidTest()
{
    setTestID("null");
    setTestDate("null");
    setResult("null");
    setResultDate("null");
    setStatus("null");
    setHealthCare("null");
}

//constructor with argument
CovidTest::CovidTest(string inTestID, string inTestDate, string inResult,
                     string inResultDate, string inStatus, string inHC)
{
    setTestID(inTestID);
    setTestDate(inTestDate);
    setResult(inResult);
    setResultDate(inResultDate);
    setStatus(inStatus);
    setHealthCare(inHC);
}

//mutator
void CovidTest::setTestID(string inTestID) {testID=inTestID;}
void CovidTest::setTestDate(string inTestDate) {testDate=inTestDate;}
void CovidTest::setResult(string inResult) {result=inResult;}
void CovidTest::setResultDate(string inResultDate) {resultDate=inResultDate;}
void CovidTest::setStatus(string inStatus) {status=inStatus;}
void CovidTest::setHealthCare(string inHc) {HC = inHc;}

//accessor
string CovidTest::getTestID(){return testID;}
string CovidTest::getTestDate() {return testDate;}
string CovidTest::getResult() {return result;}
string CovidTest::getResultDate() {return resultDate;}
string CovidTest::getStatus() {return status;}
string CovidTest::getHc() {return HC;}

ostream& operator<<(ostream& strm, CovidTest covidTest)
{
    return strm
            <<"Your test successfully registered with: " << endl
            <<"Test ID          : " << covidTest.getTestID() << endl
            <<"Test Date        : " << covidTest.getTestDate() << endl
            <<"Result Date      : " << covidTest.getResultDate() << endl
            <<"Result           : " << covidTest.getResult() << endl
            <<"Status           : " << covidTest.getStatus() << endl;
}