/**
 *@author I Ketut Mahendra
 *Code Editor/IDE   : cLion 2021.3
 * Compiler         : MinGW 17.1
 */

#include "CTIS.h"
#include <iostream>
#include <string>
using namespace std;

//function prototype
void signUpAdmin();
void loginTCManager();
void loginTCTester();
void loginPatient();
void menuForPatient(string username, string password);
void generateTestRpt(string username);
void logout();
void close();

CTIS controlCTIS;
TestCentre controlTCentre;
Patient controlPatient;
CentreOfficer controlOfficer;
TestKit controlTestKit;

/**
 * below is the main method of the program
 * @return it will return 0 due to the structure
 * of the main that use class data type .
 */
int main() {
    int inputMenuFirst=0;
    cout << "Welcome to Covid-19 Testing Information System"<<endl;
    cout << "Provided by The Ministry of Health"<<endl;

    do{
        First:
        cout << "----------------------------------------------"<<endl;
        cout << "What would you like to do?"<<endl;
        cout << "1 : Register Test Centre Manager" << endl;
        cout << "2 : Login as Test Centre Manager" << endl;
        cout << "3 : Login as Tester" << endl;
        cout << "4 : Login as Patient" <<endl;
        cout << "5 : Exit" << endl;
        cout << "\nYour Choice: ";
        cin >> inputMenuFirst;

        switch(inputMenuFirst)
        {
            case 1:
                signUpAdmin();
                break;

            case 2:
                loginTCManager();
                break;

            case 3:
                loginTCTester();
                break;

            case 4:
                loginPatient();
                break;

            case 5:
                close();
                break;

            default:
                cout << "You are input incorrect menu" << endl;
                cout << "Try again, please!" << endl;
                goto First;
        }
    } while (inputMenuFirst < 5);
    return 0;
}

//function to signup officer manager
void signUpAdmin()
{
    //sign up administrator page
    cout << "-----------[ SIGN UP ADMINISTRATOR ]----------\n" << endl;
    uname:
    cout << "Username     :";
    string usernameSignUpAdmin;
    cin >> usernameSignUpAdmin;

    //verification username for duplicate data,
    // if the duplicate username data founded,
    // the user will be directed to back to input the new username
    if(controlCTIS.doubleUsernameOfficerVerification
    (usernameSignUpAdmin))
    {
        cout << "username has been used before, "
                "try another one" << endl;
        goto uname;
    }

    //if the username was confirmed not duplicate,
    // then the user need to input the password
    cout << "Password     :";
    string passwordSignUpAdmin;
    cin >> passwordSignUpAdmin;

    //create an officer
    CentreOfficer* admin = dynamic_cast<CentreOfficer*>
    (controlCTIS.newOfficer
    (usernameSignUpAdmin, passwordSignUpAdmin, "Manager"));

    //the user input the name of the manager that will be registered
    cout << "Name         :";
    string nameSignUpAdmin;
    getline(cin >> ws, nameSignUpAdmin);
    admin->setName(nameSignUpAdmin);

    //display the data of the manager that was successfully registered
    cout << *admin;

    //loginTest Centre Manager to registering the test centre
    login:
    cout << "\n------------[ LOGIN ADMINISTRATOR ]------------\n" << endl;
    cout << "Username     :";
    string usernameLoginAdmin;
    cin >> usernameLoginAdmin;
    cout << "Password     :";
    string passwordLoginAdmin;
    cin >> passwordLoginAdmin;

    //verification username and password for login,
    // if the data founded, then the user will be allowed
    // to register the test centre
    if(controlCTIS.loginManager
    (usernameLoginAdmin, passwordLoginAdmin, "Manager"))
    {
        //Registering Centre Name and Centre ID
        cout << "\n------------[ ADMINISTRATOR PAGE ]-------------\n" << endl;
        cout << "Hi, " << controlCTIS.findOfficerNameInWelcomeMessage
        (usernameLoginAdmin) << endl;
        cout <<"Welcome to CTIS" << endl;
        cout << "Please register your Test Centre!" << endl;
        cout << "Test Centre Name: ";
        string centreName;
        getline(cin >> ws, centreName);
        for(int i = 0; i < controlCTIS.getVectorOfficer().size(); i++)
        {
            if(controlCTIS.getVectorOfficer().at(i)->
            getUserName()==usernameLoginAdmin)
            {
                controlCTIS.getVectorOfficer().at(i)->
                setTestCentre(centreName);
            }
        }
        TestCentre* centreAtCTIS = dynamic_cast<TestCentre*>
                (controlCTIS.newCentre(centreName, nameSignUpAdmin));
        centreAtCTIS->setCentreID(controlCTIS.generateCentreID());
        TestCentre* centreAtOfficer = dynamic_cast<TestCentre*>
                (controlOfficer.newCentre(centreName, nameSignUpAdmin));
        centreAtOfficer->setCentreID(controlCTIS.generateCentreID());
        cout << endl;
        cout << *centreAtCTIS;
        loginTCManager();
    }
    else {
        cout << "\nYou're input wrong username or password" << endl;
        cout << "Please Try Again" << endl;
        goto login;
    }
}

//function to log in as a manager of the test centre
void loginTCManager()
{
    login:
    cout << "\n------------[ LOGIN ADMINISTRATOR ]------------\n" << endl;
    cout << "Username     :";
    string usernameLogAdmin;
    cin >> usernameLogAdmin;
    cout << "Password     :";
    string passwordLogAdmin;
    cin >> passwordLogAdmin;

    //verification username and password for login
    if(controlCTIS.loginManager
    (usernameLogAdmin, passwordLogAdmin, "Manager"))
    {
        cout << "\n------------[ ADMINISTRATOR PAGE ]-------------\n" << endl;
        cout << "Hi, " << controlCTIS.
        findOfficerNameInWelcomeMessage(usernameLogAdmin) << endl;
        cout <<"Welcome to CTIS" << endl;

        //menuForManager();
        int menuManager = 0;
        do {
            First:
            cout << "\n------------[ ADMINISTRATOR PAGE ]-------------\n" << endl;
            cout << "Menu: " << endl;
            cout << "1 : Register Tester" << endl;
            cout << "2 : Manage Test Kit Stock" << endl;
            cout << "3 : Generate Test Report" << endl;
            cout << "4 : Logout" << endl;
            cout << "\nYour Choice: ";
            cin >> menuManager;

            switch(menuManager)
            {
                case 1:
                    //Sign Up the tester
                    {
                        cout << "---------------[ SIGN UP TESTER ]-------------\n" << endl;
                        uname:
                        cout << "Username   : ";
                        string usernameSignInTester;
                        cin >> usernameSignInTester;

                        //validate username has not duplicate
                        if(controlCTIS.doubleUsernameOfficerVerification
                        (usernameSignInTester))
                        {
                            cout << "username has been used before, try another one" << endl;
                            goto uname;
                        }
                        cout << "Password   : ";
                        string passwordSignInTester;
                        cin >> passwordSignInTester;
                        CentreOfficer* tester = dynamic_cast<CentreOfficer*>
                                (controlCTIS.newOfficer(usernameSignInTester,
                                                        passwordSignInTester, "Tester"));
                        cout << "Name       : ";
                        string nameSignInTester;
                        getline(cin >> ws, nameSignInTester);
                        tester -> setName(nameSignInTester);
                        tester ->setTestCentre(controlCTIS.findTestCentre
                        (usernameLogAdmin));
                        cout << endl;
                        cout << *tester;
                        break;
                    }

                case 2:
                    //menuManageTestKit();
                    {
                        int mngTestKit = 0;
                        cout << "\n--------------[ MANAGE TEST KIT ]--------------\n" << endl;
                        do {
                            FirstManageTK:
                            cout << "Menu:" << endl;
                            cout << "1 : Record New Test Kit" << endl;
                            cout << "2 : Update Test Kit Stock" << endl;
                            cout << "3 : Back" << endl;
                            cout << "\nYour Choice: ";
                            cin >> mngTestKit;
                            switch(mngTestKit)
                            {
                                case 1:
                                {
                                    cout << "-------------[ RECORD NEW TEST KIT ]----------\n" << endl;
                                    FirstRecTestKit:
                                    cout << "Test Kit Name  : ";
                                    string kitName;
                                    getline(cin >> ws, kitName);
                                    if(controlTCentre.doubleNameTestKit(kitName))
                                    {
                                        cout << "Test Kit "<< kitName <<" has been registered before" << endl;
                                        tryInput:
                                        cout << "1 : Try to record another test kit" << endl;
                                        cout << "2 : Update test kit" << endl;
                                        cout << "3 : Back" << endl;
                                        cout << "Input  : "; int input; cin >> input;
                                        switch(input)
                                        {
                                            case 1:
                                                goto FirstRecTestKit;

                                            case 2:
                                            {
                                                cout << "---------------[ UPDATE TEST KIT ]------------\n" << endl;
                                                FirstUpdateTK:
                                                cout << "Test Kit ID    : "; string kitID; cin >> kitID;
                                                if (controlTCentre.validateKitIDInputted(kitID))
                                                {
                                                    cout << "Update Stock   : "; int qty; cin >> qty;
                                                    controlTCentre.setNewTestKitQty(kitID, qty);

                                                }
                                                else{
                                                    cout << "No Test Kit ID founded" << endl;
                                                    cout << "Please Try Again!" << endl;
                                                    goto FirstUpdateTK;
                                                }
                                                break;
                                            }
                                                break;

                                            case 3:
                                                goto FirstManageTK;
                                                break;

                                            default:
                                                cout << "You are input incorrect menu" << endl;
                                                cout << "Try again, please!" << endl;
                                                goto tryInput;
                                        }
                                    }
                                    cout << "Stock          : "; int stock; cin >> stock;
                                    TestKit* kit = dynamic_cast<TestKit*>
                                    (controlTCentre.newTestKit(kitName, stock));
                                    kit ->setKitID(controlTCentre.generateKitID());
                                    cout << endl;
                                    cout << *kit;
                                    cout << endl;
                                    cout << "----------------------------------------------" << endl;
                                    break;
                                }
                                case 2:
                                {
                                    cout << "---------------[ UPDATE TEST KIT ]------------\n" << endl;
                                    FirstUpdateTKStock:
                                    cout << "Test Kit ID    : "; string kitID; cin >> kitID;
                                    if (controlTCentre.validateKitIDInputted(kitID))
                                    {
                                        cout << "Update Stock   : "; int qty; cin >> qty;
                                        controlTCentre.setNewTestKitQty(kitID, qty);

                                    }
                                    else{
                                        cout << "No Test Kit ID founded" << endl;
                                        cout << "Please Try Again!" << endl;
                                        goto FirstUpdateTKStock;
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    goto First;
                                    break;
                                }
                                default:
                                    cout << "You are input incorrect menu" << endl;
                                    cout << "Try again, please!" << endl;
                                    goto FirstManageTK;
                            }
                        }while(mngTestKit<3);
                        break;
                    }

                case 3:
                    cout << "-----------------[ TEST REPORT ]--------------\n" << endl;
                    generateTestRpt(usernameLogAdmin);
                    break;

                case 4:
                    logout();
                    break;

                default:
                    cout << "You are input incorrect menu" << endl;
                    cout << "Try again, please!" << endl;
                    goto First;
            }
        }while(menuManager<4);
    }
    else
    {
        cout << "\nYou're input wrong username or password" << endl;
        cout << "Do you already have a manager account? (Y/N) ";
        char having; cin >> having;
        if(toupper(having)=='Y')
        {
            cout << "Please Try Again" << endl;
            goto login;
        }
        else if(toupper(having)=='N'){
            cout << endl;
            signUpAdmin();
        }
        else
        {
            cout << "wrong input, redirect to main menu" << endl;
        }
    }
}

//function to log in as test centre tester
void loginTCTester(){
    cout << "\n----------------[ LOGIN TESTER ]---------------\n" << endl;
    login:
    cout << "Username     :"; string usernameLoginTester; cin >> usernameLoginTester;
    cout << "Password     :"; string passwordSignInTester; cin >> passwordSignInTester;

    //verification username and password for login
    if(controlCTIS.loginTester(usernameLoginTester, passwordSignInTester, "Tester"))
    {
        cout << "\n----------------[ TESTER PAGE ]----------------\n" << endl;
        cout << "Hi, "<< controlCTIS.findOfficerNameInWelcomeMessage(usernameLoginTester) << endl;
        cout <<"Welcome to CTIS" << endl;

        int menuTester = 0;
        FirstMenuTester:
        do {
            cout << "----------------------------------------------" << endl;
            cout << "Menu: " << endl;
            cout << "1 : Record Test" << endl;
            cout << "2 : Generate Test Report" << endl;
            cout << "3 : Logout" << endl;
            cout << "\nYour Choice: ";
            cin >> menuTester;
            switch (menuTester)
            {
                case 1:
                {
                    cout << "-------------[ TESTING MANAGEMENT ]-----------\n" << endl;
                    First:
                    cout << "Have you ever tested for COVID-19 before? (Y/N): ";
                    char inputTest; cin >> inputTest;
                    if(toupper(inputTest)=='Y')
                    {
                        //updateTest();
                        {
                            cout << "----------------[ UPDATE TEST ]---------------\n" << endl;
                            TestLogin:
                            cout << "Test ID                  : "; string idTest; cin >> idTest;
                            if(!(controlPatient.findTestID(idTest)))
                            {
                                cout << "Test ID not found" << endl;
                                cout << "make sure you have entered the correct Test ID" << endl;
                                cout << "try again" << endl;
                                goto TestLogin;
                            }
                            typeUpdatePg:
                            cout << "Patient Type             : " << endl;
                            cout << "                           1 : Returnee" << endl;
                            cout << "                           2 : Quarantined" << endl;
                            cout << "                           3 : Close Contact" << endl;
                            cout << "                           4 : Infected" << endl;
                            cout << "                           5 : Suspected" << endl;
                            cout << "Type                     : ";
                            int typeUpdate; cin >> typeUpdate;
                            string patientTypeUpdate;
                            switch(typeUpdate)
                            {
                                case 1:
                                    patientTypeUpdate = "Returnee";
                                    break;
                                case 2:
                                    patientTypeUpdate = "Quarantined";
                                    break;
                                case 3:
                                    patientTypeUpdate = "Close Contact";
                                    break;
                                case 4:
                                    patientTypeUpdate = "Infected";
                                    break;
                                case 5:
                                    patientTypeUpdate = "Suspected";
                                    break;
                                default:
                                    goto typeUpdatePg;
                                    break;
                            }
                            for(int i = 0; i < controlPatient.getVectorCovidTesting().size();i++)
                            {
                                controlCTIS.getVectorPatient().at(i)->setPatientType(patientTypeUpdate);
                            }
                            cout <<"Result                    : "; string result; cin >> result;
                            cout <<"Result Date (dd/mm/yyyy)  : "; string date; cin >> date;
                            cout << endl;
                            controlPatient.updateTest(idTest, result, date);
                            controlOfficer.updateTest(idTest, result, date);
                            controlTestKit.updateTest(idTest, result, date);

                        }
                    }
                    else if (toupper(inputTest)=='N')
                    {
                        //newTest
                        {
                            cout << "----------------[ RECORD TEST ]---------------\n" << endl;
                            FirstRecTest:
                            cout << "Username               : "; string usernamePatientTested; cin >> usernamePatientTested;
                            if(controlCTIS.validateNoDuplicatePatientTesting(usernamePatientTested))
                            {
                                cout << "The username has been used before" << endl;
                                cout << "please try using another username" << endl;
                                goto FirstRecTest;
                            }
                            cout << "Password                : "; string passwordPatientTested; cin >> passwordPatientTested;
                            cout << "Name                    : "; string namePatientTested; getline(cin >> ws, namePatientTested);
                            Patient* patient = dynamic_cast<Patient*>
                            (controlCTIS.newPatient(usernamePatientTested, passwordPatientTested, namePatientTested));
                            type:
                            cout << "Patient Type            :" << endl;
                            cout << "1 : Returnee" << endl;
                            cout << "2 : Quarantined" << endl;
                            cout << "3 : Close Contact" << endl;
                            cout << "4 : Infected" << endl;
                            cout << "5 : Suspected" << endl;
                            cout << "Type                    : ";
                            int type; cin >> type;
                            string patientType;
                            switch(type)
                            {
                                case 1:
                                    patientType = "Returnee";
                                    break;
                                case 2:
                                    patientType = "Quarantined";
                                    break;
                                case 3:
                                    patientType = "Close Contact";
                                    break;
                                case 4:
                                    patientType = "Infected";
                                    break;
                                case 5:
                                    patientType = "Suspected";
                                    break;
                                default:
                                    goto type;
                                    break;
                            }
                            patient->setPatientType(patientType);
                            cout << "Symptoms                : "; string symptoms;
                            getline(cin >> ws, symptoms);
                            patient->setPatientSymptoms(symptoms);
                            cout << "Test Date (dd/mm/yyyy)  : "; string date; cin >> date;
                            CovidTest* covidTestAtPatient = dynamic_cast<CovidTest*>
                            (controlPatient.newTesting(date));
                            covidTestAtPatient->setTestID(controlPatient.generateTestID());
                            covidTestAtPatient->setStatus("Pending");
                            covidTestAtPatient->setResultDate("-");
                            covidTestAtPatient->setResult("-");
                            covidTestAtPatient->setHealthCare(controlCTIS.findTestCentre(usernameLoginTester));
                            controlTCentre.setTestKitWhenNewTestIsRecorded(1);
                            CovidTest* covidTestAtCentreOfficer = dynamic_cast<CovidTest*>
                            (controlOfficer.newTesting(date));
                            controlTCentre.setTestKitWhenNewTestIsRecorded(1);

                            covidTestAtCentreOfficer->setTestID(controlPatient.generateTestID());
                            covidTestAtCentreOfficer->setStatus("Pending");
                            covidTestAtCentreOfficer->setResultDate("-");
                            covidTestAtCentreOfficer->setResult("-");
                            covidTestAtCentreOfficer->setHealthCare(controlCTIS.findTestCentre(usernameLoginTester));

                            CovidTest* covidTestAtTestKit = dynamic_cast<CovidTest*>
                            (controlTestKit.newTesting(date));
                            covidTestAtTestKit->setTestID(controlPatient.generateTestID());
                            covidTestAtTestKit->setStatus("Pending");
                            covidTestAtTestKit->setResultDate("-");
                            covidTestAtTestKit->setResult("-");
                            covidTestAtPatient->setHealthCare(controlCTIS.findTestCentre(usernameLoginTester));
                            cout << endl;
                            cout << *covidTestAtTestKit;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "You are input incorrect menu" << endl;
                        cout << "Try again, please!" << endl;
                        goto FirstRecTest;
                    }
                    break;
                }

                case 2:
                    cout << "-----------------[ TEST REPORT ]--------------\n" << endl;
                    generateTestRpt(usernameLoginTester);
                    break;
                case 3:
                    logout();
                    break;
                default:
                    cout << "You are input incorrect menu" << endl;
                    cout << "Try again, please!" << endl;
                    goto FirstMenuTester;

            }
        }while(menuTester<3);

    }
    else {
        cout << "\nYou're input wrong username or password" << endl;
        cout << "Do you already have a tester account? (Y/N) ";
        char having;
        cin >> having;
        if (toupper(having) == 'Y') {
            cout << "Please Try Again" << endl;
            goto login;
        } else if (toupper(having) == 'N') {
            cout << "please contact your test center manager" << endl;
            cout << "to get your tester account" << endl;
            cout << "then after you get your tester account," << endl;
            cout << "please login again in this menu" << endl;
        } else {
            cout << "wrong input, redirect to main menu" << endl;
        }
    }
}

//function to log in as patient
void loginPatient() {
    cout << "---------------[ PATIENT PAGE ]----------------\n" << endl;
    First:
    cout << "Username   : "; string uname; cin >> uname;
    cout << "Pasword    : "; string upass; cin >> upass;

    if (!controlCTIS.loginPatient(uname, upass))
    {
        cout << "Patient Username or Password not found!\n"
                "Please try again" << endl;
        cout << "\n-----------------------------------------------" << endl;
        goto First;
    }
    else{
        menuForPatient(uname, upass);
    }
}

//function to display the menu for the patient
void menuForPatient(string username, string password) {
    const string& usname = username;
    const string& uspass = password;

    cout << "\n----------------[ PATIENT PAGE ]---------------\n" << endl;
    First:
    cout << "Menu: " << endl;
    cout << "1 : View Test History" << endl;
    cout << "2 : Logout" << endl;
    cout << "\nYour Choice: "; int choice = 0; cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "\n---------------[ VIEW TEST PAGE ]--------------\n" << endl;
            controlCTIS.viewTestForPatient(usname, uspass);
            break;
        case 2:
            logout();
            break;
        default:
            cout << "You are input incorrect menu" << endl;
            cout << "Try again, please!" << endl;
            goto First;
    }
}

//function to generate test report,
// it will called in loginTCManager and loginTCTester as the Centre Officer
void generateTestRpt(string username) {
    for (int i = 0; i < controlCTIS.getVectorOfficer().size(); i++)
    {
        if(controlCTIS.getVectorOfficer().at(i)->getUserName()==username)
        {
            string testCentre = controlCTIS.getVectorOfficer().at(i)->getTestCentre();
            controlOfficer.generateTestRpt(testCentre);
        }
    }
}

//function to log out from a menu and back to previous page
void logout()
{
    cout << "Logged out . . ." << endl;
}

//function that will be displayed when the program was terminated
void close()
{
    cout << endl;
    cout << "===============[ System Closed ]==============" << endl;
    cout << "================[ Thank You! ]================" << endl;
}