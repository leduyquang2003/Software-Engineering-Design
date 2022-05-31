#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

//Global Variables

//Role of User
bool Guest_choice, Member_choice, Admin_choice = false;
bool ExitProgram = false;
bool isLog = true;

//Bool Data
bool payAble = false;
bool Dup_username = true;
bool Exit = false;

class System;
class House;
class Member;


//Global Variables for system
vector<Member*> Database;

//Help to load data
vector<Member> DatabaseLoad; //this use for assign to Database later
vector<House*> HouseData;
vector<Member*> RequestData;

std::fstream data;
std::fstream listRequest;

//Class of House
class House
{
    private:
        string location = "NULL";
        string description = "NULL";
        double houseRatingScore_Avg = 0;
        string available = "NULL";
        string start_period = "NULL";
        string end_period = "NULL";
        

    
        //Record Data for OccupyMem   
        string username = "NULL";
        string fullname = "NULL";
        string phoneNumber = "NULL";

    //Method
    public: 
        House(){}
        House(string location, string description, string available, string start_period, string end_period){
            this->location = location;
            this->description = description;
            this->available = available;
            this->start_period = start_period;
            this->end_period = end_period;

        }
   
    friend class Member;
    friend class System;
    friend class Admin;
};

//Class of Member
class Member
{
    private:
        string userName = "NULL";
        string fullName = "NULL";
        string phoneNumber = "NULL";
        string password = "NULL";

        Member* OccupyMem = NULL;

        double creditPoint = 500; //500 credit when creating Member 
        double occupierRatingScore_Avg = 0;
        double rentingCreditPoint  = 0;
        double minimum_occupierRatingScore_Avg = 0;


        //Recored Data
        House* houseOwn; //Constraint only one house for Member
        House* houseOccupy = NULL; //Constraint only one house for Occupy
        vector<double> listHouseRating;
        vector<double> listOccupierRating;
        vector<Member*> listOfrequests;

        //This attribute for update database
        House houseData;

    //Method
    public:
        Member(){}

        //This version is for update database
        Member(string userName, string fullName, string phoneNumber, string password, double creditPoint, double occupierRatingScore_Avg, double rentingCreditPoint, double minimum_occupierRatingScore_Avg)
        {
            this->userName = userName;
            this->fullName = fullName;
            this->phoneNumber = phoneNumber;
            this->password = password;
            this->creditPoint = creditPoint;
            this->occupierRatingScore_Avg = occupierRatingScore_Avg;
            this->rentingCreditPoint = rentingCreditPoint;
            this->minimum_occupierRatingScore_Avg = minimum_occupierRatingScore_Avg;
        }
        Member(string userName, string phoneNumber, double occupierRatingScore_Avg)
        {
            this->userName = userName;
            this->phoneNumber = phoneNumber;
            this->occupierRatingScore_Avg = occupierRatingScore_Avg;
        }

        void ShowInfo()
        {
            cout << "Your Information:\n";
            cout << "   Full name = " << fullName << ". User name = " << userName << ". Password = " << password << "\n"
                 << "   Phone number = " << phoneNumber << ". Credit point = " << creditPoint << ". Occupier Rating Score = " << occupierRatingScore_Avg << "\n";
                 
            cout << "\nYour House Information:\n";
            if(houseOwn->description == "NULL")
            {
                cout << "   House location = " << houseOwn->location 
                 << "   House Rating Score = " << houseOwn->houseRatingScore_Avg << ". Availability = " << houseOwn->available << ".\n"
                 << "   Require credit point for rent = " << rentingCreditPoint << ".  Minimum require occupier rating = " << minimum_occupierRatingScore_Avg 
                 << "   .Start Period = "<< houseOwn->start_period << ". End Period = " << houseOwn->end_period << ".\n";
            }
            else
            {
                cout << "   House location = " << houseOwn->location << ". House description = " << houseOwn->description << ".\n"
                 << "   House Rating Score = " << houseOwn->houseRatingScore_Avg << ". Availability = " << houseOwn->available << ".\n"
                 << "   Require credit point for rent = " << rentingCreditPoint << ".  Minimum require occupier rating = " << minimum_occupierRatingScore_Avg 
                 << "   .Start Period = "<< 
                 houseOwn->start_period << ". End Period = " << houseOwn->end_period << ".\n";
            }

            if(houseOccupy != NULL)
            {
                if(houseOccupy->description == "NULL")
                {
                    cout << "\nYour House Occupied:\n";
                    cout << "   House location = " << houseOccupy->location
                         << "   House Rating Score = " << houseOccupy->houseRatingScore_Avg << "\n"
                         << "Information of OccupyMem of this house: \n"
                         << "   OccupyMem = " << houseOccupy->fullname << ". Phone number = " << houseOccupy->phoneNumber << ". Username = " << houseOccupy->username << "\n";
                }
                else
                {
                     cout << "\nYour House Occupied:\n";
                     cout << "   House location = " << houseOccupy->location << ". House description = " << houseOccupy->description << "\n"
                          << "   House Rating Score = " << houseOccupy->houseRatingScore_Avg << ". House start period = " << houseOccupy->start_period << ". House end period = " << houseOccupy->end_period << "\n"
                          << "Information of OccupyMem of this house: \n"
                          << "   OccupyMem = " << houseOccupy->fullname << ". Phone number = " << houseOccupy->phoneNumber << ". Username = " << houseOccupy->username << "\n";
                }
            }
            else
                cout << "There is no information of your occupied house\n";

            if(OccupyMem != NULL)
            {
                cout << "The information of the member is occupying your house:\n";
                cout << "   Full name = " << OccupyMem->fullName << ". User name = " << OccupyMem->fullName << ".\n"
                     << "   Phone number = " << OccupyMem->phoneNumber << ". Occupied Score = " << OccupyMem->occupierRatingScore_Avg << "\n";
            }
            else
                cout << "There is no information of the member who is occupying your house\n";


        }

        //Show List of Request
        void ShowListRequest()
        {
            cout << "Your list of requests:\n";
            int cnt = 1;

            //Load database
            for(auto each : Database)
            {
                if(userName == each->userName)
                {
                    for(auto request : each->listOfrequests)
                    {
                        listOfrequests.push_back(request);
                    }
 
                }
                
            }
            for(auto each : listOfrequests)
            {
                cout << cnt << ") Username = " << each->userName << ". Phone number = " << each->phoneNumber << ". Occupied Rating Score = " << each->occupierRatingScore_Avg << "\n";
                cnt++;
            }
            cout << "\nChoose the member you want to occupy your house please enter the INDEX NUMBER: ";
            string input_index;
            cin >> input_index;
            int i = 0;
            for(auto Each : Database)
            {
                if(Each->userName == userName)
                {
                    for(auto each : Each->listOfrequests)
                    {
                        if(true)
                            i++;
                        if(input_index == std::to_string(i))
                        {
                            (each->houseOccupy)->username = userName;
                            (each->houseOccupy)->phoneNumber = phoneNumber;
                            (each->houseOccupy)->start_period = houseOwn->start_period;
                            (each->houseOccupy)->end_period = houseOwn->end_period;

                            Each->OccupyMem = each;
                            Each->OccupyMem->creditPoint = (each->creditPoint) - rentingCreditPoint;
                        }
                    }
                }
            }
        }

        //Feature 5 List House can be occupied
        void PutHouseToRent()
        {
            string choice;
            string Input_start_period;
            string Input_end_period;
            string choice2, choice3;
            double Input_RentingcreditPoint;
            double Input_MinimumOccupierRatingScore_Avg;
            bool loop = true;
            
            cout << "Do you want to list your house available to be occupied (Y/N): ";
            cin >> choice;
            if (choice == "Y") {
                houseOwn->available = "Available";
                cout << "Set the credit point to rent this house: ";
                cin >> Input_RentingcreditPoint;
                rentingCreditPoint = Input_RentingcreditPoint;
                for(auto each : Database)
                {
                    if(each->userName == userName)
                        each->rentingCreditPoint = Input_RentingcreditPoint;
                }
                cout << "Set the minimum required occupier rating to rent this houes: ";
                cin >> Input_MinimumOccupierRatingScore_Avg;
                minimum_occupierRatingScore_Avg = Input_MinimumOccupierRatingScore_Avg;
                for(auto each : Database)
                {
                    if(each->userName == userName)
                        each->minimum_occupierRatingScore_Avg = Input_MinimumOccupierRatingScore_Avg;
                }

                cout << "Set start period for house availability (dd/mm/yyyy): ";
                cin >> Input_start_period;
                houseOwn->start_period = Input_start_period;

                cout << "Set end period for house availability (dd/mm/yyyy): ";
                cin >> Input_end_period;
                houseOwn->end_period = Input_end_period;
               
            } else if (choice == "N") {
                houseOwn->available = "Unavailable";
            } else {
                cout << "Syntax error\n";
            }
            
        }

        //Show House available for rent
        void showHouseAvailable()
        {
            int cnt = 1;
            for(auto each : Database)
            {

                if((each->houseOwn)->available == "Available")
                {
                    cout <<"\n" << cnt <<  ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                         << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg << 
                         ". Require credit point for rent = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg 
                         << ". Start period = " << (each->houseOwn)->start_period << ". End period = " << (each->houseOwn)->end_period << 
                         ". For more contact call " << each->phoneNumber << "\n";
                    cnt++;
                }
            }
        }

        void SuitableHouse();

        bool LogIn();
        //Gain access
        friend class System;
        friend class Admin;
     
};

//class of Admin
class Admin
{
    private:

    public:
        string admin_userName;
        string admin_password;
        Admin(){}
        Admin(string admin_userName, string admin_password){
            this->admin_userName = admin_userName;
            this->admin_password = admin_password;
        }
        void ShowDatabase()
        {
            //Show List of data of Members 
            int cnt = 1;
            cout << "\n";
            for(auto each: Database)
            {
                cout << cnt << ") Member's name: " << each->fullName << ". Username: " << each->userName << ". Phone number: " << each->phoneNumber
                     << ". Credit point: " << each->creditPoint << ". Occupier score: " << each->occupierRatingScore_Avg 
                     << ". House location: " << (each->houseOwn)->location << ". Description: " << (each->houseOwn)->description << ". Availability: " << (each->houseOwn)->available 
                     << ". Require credit point for rent = " << each->rentingCreditPoint << ".  Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg 
                     << "\n";
                cnt++;
            }
        }
    friend class System;    
};

//Class of System
class System
{
    private:
    
    public:
        //Constructor for testing
        System(){};

        
        //Feature for Sign UpF
        void SignUp(Member *user, House *house);

        //Feature 13
        void LoadDatabase()
        {
            string line;
            string userName;
            string fullName;
            string phoneNumber;
            string password;
            string location;
            string description;
            double creditPoint;
            double occupierRatingScore_Avg;
            double rentingCreditPoint;
            double minimum_requireOccupyScore;
            string available;
            string house_start_period;
            string house_end_period;
            string houseOccupylocation;
            string houseOccupyDescription;
            string houseOccupyUsername;
            string houseOccupyFullname;
            string houseOccupyPhonenumber;
            double houseOccupyRatingScore;
            string houseOccupyStartperiod;
            string houseOccupyEndperiod;
            
            string request_username;
            string request_phoneNumber;
            double request_occupiedScore;
            double request_creditPoint;


            string OccupyUsername;
            string OccupyFullname;
            string OccupyPhonenumber;
            double OccupyOccupyScore;
    

            data.open("database.txt", std::ios::in);
            vector<string> tokens;
            int i = 0;
            while(getline(data, line))
            {
                std::stringstream check1(line);
                string intermediate;
                while(getline(check1, intermediate, ','))
                {
                    tokens.push_back(intermediate);
                }
                cout << tokens.size() << "\n";
                userName = tokens[0];
                fullName = tokens[1];
                phoneNumber = tokens[2];
                password = tokens[3];
                creditPoint = stod(tokens[4]);
                occupierRatingScore_Avg = stod(tokens[5]);
                rentingCreditPoint = stod(tokens[6]);
                minimum_requireOccupyScore = stod(tokens[7]);
                OccupyUsername = tokens[8];
                OccupyFullname = tokens[9];
                OccupyPhonenumber = tokens[10];
                OccupyOccupyScore = stod(tokens[11]);


                location = tokens[12];
                description = tokens[13];
                available = tokens[14];
                house_start_period = tokens[15];
                house_end_period = tokens[16];

                houseOccupylocation = tokens[17];
                houseOccupyDescription = tokens[18];
                houseOccupyRatingScore = stod(tokens[19]);
                houseOccupyStartperiod = tokens[20];
                houseOccupyEndperiod = tokens[21];
                houseOccupyFullname = tokens[22];
                houseOccupyUsername = tokens[23];
                houseOccupyPhonenumber = tokens[24];

                Member *MemTemp = new Member;
                MemTemp->userName = userName;
                MemTemp->fullName = fullName;
                MemTemp->phoneNumber = phoneNumber;
                MemTemp->password = password;
                MemTemp->creditPoint = creditPoint;
                MemTemp->occupierRatingScore_Avg = occupierRatingScore_Avg;
                MemTemp->rentingCreditPoint = rentingCreditPoint;
                MemTemp->minimum_occupierRatingScore_Avg = minimum_requireOccupyScore;
                MemTemp->OccupyMem->userName = OccupyUsername;
                MemTemp->OccupyMem->fullName = OccupyFullname;
                MemTemp->OccupyMem->occupierRatingScore_Avg = OccupyOccupyScore;

                House *HouseTemp = new House;
                HouseTemp->location = location;
                HouseTemp->description = description;
                HouseTemp->available = available;
                HouseTemp->start_period = house_start_period;
                HouseTemp->end_period = house_end_period;

                House *HouseOccupyTemp = new House;
                HouseOccupyTemp->location = houseOccupylocation;
                HouseOccupyTemp->description = houseOccupyDescription;
                HouseOccupyTemp->houseRatingScore_Avg = houseOccupyRatingScore;
                HouseOccupyTemp->start_period = houseOccupyStartperiod;
                HouseOccupyTemp->end_period = houseOccupyEndperiod;
                HouseOccupyTemp->fullname = houseOccupyFullname;
                HouseOccupyTemp->phoneNumber = houseOccupyPhonenumber;
                HouseOccupyTemp->username = houseOccupyUsername;


                MemTemp->houseOwn = HouseTemp;
                MemTemp->houseOwn = HouseOccupyTemp;

                int i = 24;
                while (tokens.size() > 25 && i < tokens.size() - 1)
                {
                    request_username = tokens[i + 1];
                    request_phoneNumber = tokens[i + 2];
                    request_occupiedScore = stod(tokens[i + 3]);
                    request_creditPoint = stod(tokens[i + 4]);

                    Member *RequestTemp = new Member;
                    RequestTemp->userName = request_username;
                    RequestTemp->phoneNumber = request_phoneNumber;
                    RequestTemp->occupierRatingScore_Avg = request_occupiedScore;
                    MemTemp->listOfrequests.push_back(RequestTemp);
                    i = i + 4;
                }

                Database.push_back(MemTemp);
                tokens.clear();
            }
            data.close();
        }    

        //Show house detail in Guest
        void ShowHouseDataBase()
        {
            for(auto each: Database)
            {
                cout << "\nHouse of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                     << "Description: " << (each->houseOwn)->description << ". For more contact call " << each->phoneNumber << "\n";
            }
        }



        //Update new data for Customer
        void UpdateDataBase()
        {
            //Create a file to store data
            data.open("database.txt", std::ios::out); 
            //update data to file 
            for(auto each : Database)    
            {
                int i = 0;
                data << each->userName << ","<<each->fullName << ","<< each->phoneNumber << "," << each->password << ","<< each->creditPoint << "," << each->occupierRatingScore_Avg << "," << each->rentingCreditPoint  
                     << "," << each->minimum_occupierRatingScore_Avg << "," << each->OccupyMem->fullName << "," << each->OccupyMem->userName << "," << each->OccupyMem->phoneNumber << "," << each->OccupyMem->occupierRatingScore_Avg << ","
                     << (each->houseOwn)->location  << "," << (each->houseOwn)->description << "," 
                     << (each->houseOwn)->available  <<  "," << (each->houseOwn)->start_period << "," << (each->houseOwn)->end_period << ","
                     << (each->houseOccupy)->location << "," << (each->houseOccupy)->description << "," << (each->houseOccupy)->houseRatingScore_Avg << ","
                     << (each->houseOccupy)->start_period << "," << (each->houseOccupy)->end_period << "," << (each->houseOccupy)->fullname << "," << (each->houseOccupy)->phoneNumber 
                     << "," << (each->houseOccupy)->username;

                if(each->listOfrequests.empty() == 1)
                {
                    data << "\n";
                }    
                else{
                    for(auto request : each->listOfrequests)
                    {   
                        data << request->userName << "," << request->phoneNumber << "," << request->occupierRatingScore_Avg << "," << request->creditPoint <<",";
                    }
                    data << "\n";
                }

                                                                        
            }
            data.close();
        }

       


        void Admin_Login(Admin *input);

        //Gain access
        friend class Member;
        friend class Admin;
};

//Welcome Screen
void WelcomeScreen()
{
    //Choosing Role
    string choice;
    bool loop = false;
    do{
        cout << "\nUse the app as 1. Guest    2. Member   3. Admin  4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;


        if(choice == "1")
        {
            Guest_choice = true;
            break;
        }
        else if(choice == "2")
        {
            Member_choice = true;
            break;
        }
        else if(choice == "3")
        {
            Admin_choice = true;
            break;
        }
        else if(choice == "4")
        {
            ExitProgram = true;
            break;
        }
        else
        {
            cout << "Syntax Error Please Enter your choice again!\n";
            loop = true;
        }
    } while(loop == true);
}

//LogIn feature should be fix in mem class
bool Member::LogIn()
{
    bool SuccessLog = false;
    int i = 0;
    int j = 0;
    string Input_UserName;
    string Input_Password;
    cout << "Enter username(No space!): ";
    cin >> Input_UserName;
    //Check the Input UserName is existed in Database
    for(auto each : Database)
    {
        i++;
        if(Input_UserName == each->userName)
        {
            cout << "Enter password(No space!): ";
            cin >> Input_Password;
            for(auto each : Database)
            {
                j++;
                if(Input_Password == each->password)
                {
                    cout << "Log In Successfully!!\n";
                    fullName = each->fullName;
                    userName = each->userName;
                    phoneNumber = each->phoneNumber;
                    occupierRatingScore_Avg = each->occupierRatingScore_Avg;
                    creditPoint = each->creditPoint;
                    houseOwn = each->houseOwn;
                    password = each->password;
                    SuccessLog = true;
                    return true;
                }
            }
            if(SuccessLog == false)
            {
                cout << "Wrong Password!\n";
                return false;
            }
        }
    
    }
    if(SuccessLog == false)
    {
        cout << "Wrong Username\n";
        return false;
    }
    else
        return true;
}

bool Admin_Success = false;
void System::Admin_Login(Admin* temp){
    string Input_admin_username;
    string Input_admin_password;
    cout << "Please enter username(No Space!): ";
    cin >> Input_admin_username;
    if(Input_admin_username == temp->admin_userName){
        cout << "Please enter password: ";
        cin >> Input_admin_password;
        if(Input_admin_password == temp->admin_password){
            cout << "Log In Successfully!!";
            Admin_Success = true;
        }
        else{
            cout << "Wrong password!\n";
        }
    }
    else
    {
        cout << "Wrong Username!\n";
        Admin_Success = false;
    }
}


//Genrate random balance
int randomBalance()
{
    int balance =  (int) rand();

    return balance;
}


//Feature for Sign Up
void System::SignUp(Member *user, House *house)
{   
    string Input_UserName;
    string Input_Password;
    string Input_PhoneNumber;
    string Input_FullName;

    string Input_Location;
    string Input_Description;

    int balance = randomBalance();

    cout << "Require intial entry of $500 to become a member($500 = 500 credit points)\n";
    if(balance >= 500)
    {
        cout << "Balance has changed from " << balance << "$ to " << balance - 500 << "$\n";
        cout << "Successfully paid initial entry fee!!\n";
        user->creditPoint = 500;
        payAble = true;
    }
    else
        cout << "Your balance doens't have enough money to pay for intial entry. Your balance is " << balance << "$\n"; 

    if(payAble == true)
    {
        //-------------------------FILLLING THE FORM-----------------------------//
        cout << "\n\n//-------------------------FILLLING THE FORM-----------------------------//\n";
        cout << "Please Fill the form: \n";
        cout << "   >Full name: ";
        cin.ignore(1, '\n');
        getline(cin, Input_FullName);
        user->fullName = Input_FullName;
        cout << "   >Phone number: ";
        getline(cin, Input_PhoneNumber);
        user->phoneNumber = Input_PhoneNumber;
        cout << "Adding your house information:\n";
        cout << "   >Location: ";
        // cin.ignore(1, '\n');
        getline(cin, Input_Location);
        house->location = Input_Location;
        cout << "   >House Description \"OPTIONAL\" (press ENTER if no description): ";
        // cin.ignore(1, '\n');
        getline(cin, Input_Description);
        house->description = Input_Description;

        user->houseOwn = house;

        cout << "\n\n//-------------------REGISTER USERNAME AND PASSWORD-----------------------//\n";

        //-------------------REGISTER USERNAME AND PASSWORD-----------------------// 
        //Check if Input_UserName is not duplicate in Database
        do {
            int check = 0;
            cout << "   >User name (No Space require!): ";
            cin >> Input_UserName;
            for(auto each : Database)
            {
                if(Input_UserName == each->userName)
                {
                    cout << "This name has already use please enter a again your User Name!\n";
                    check = 1;
                }
            }
            if(check != 1)
                Dup_username = false;
        } while(Dup_username == true);
        user->userName = Input_UserName;

        cout << "   >Password (No space require!): ";
        cin >> Input_Password;
        user->password = Input_Password;
        cout << "Sign In Successfully!!\n\n";

        //Update the data of this member to Database
        Database.push_back(user);
    }
}

//Search for suitable houeses
void Member::SuitableHouse()
{
    string city;
    string decision;
    string input_index;
    string input_startPeriod;
    string input_endPeriod;
    cout << "Do you want to search for particulary city you want to rent the house (Y/N)?: ";
    cin >> decision;
    if(decision == "Y")
    {
        cout << "\nSearch for particulary city you want to rent the house: ";
        cin.clear();
        cin.ignore(1, '\n');
        getline(cin, city);
        cin.clear();

        

        cout << "Enter your start period in format dd/mm/yyyy: ";
        cin >> input_startPeriod;              

        cout << "Enter your end period in format dd/mm/yyyy: ";
        cin >> input_endPeriod;

        int cnt = 0;
        for(auto each : Database)
        {
            if((each->houseOwn)->location == city && (each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint 
            && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName 
            && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod)
            {
                cnt++;
                cout <<"\n" << cnt <<  ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                            << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg 
                            << ". Require credit point for rent = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg 
                            << ". Start Period = " << (each->houseOwn)->start_period << ". End Period = " << (each->houseOwn)->end_period <<". For more contact call " << each->phoneNumber << "\n";
            }
        }
        if(cnt == 0)
        {
            cout << "There are no house suitable with you\n";
        }
        else{
            cout << "\nChoosing the house to send the request for the OccupyMem please enter INDEX NUMBER:";
            cin >> input_index;
            int i = 0;
            for(auto each: Database)
            {
                if((each->houseOwn)->location == city && (each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint 
                && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName 
                && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod)
                    i++;
                if(input_index == std::to_string(i))
                {
                    // user send the request to the OccupyMem    
                    cout << "Check\n";
                    cout << i << "\n";                                           
                    each->listOfrequests.push_back(this);
                    break;
                }
            }
            cout << i << "\n";
        }
        
    }
    else if(decision == "N")
    {
        int cnt = 0;

        cout << "Enter your start period in format dd/mm/yyyy: ";
        cin >> input_startPeriod;              

        cout << "Enter your end period in format dd/mm/yyyy: ";
        cin >> input_endPeriod;

        for(auto each : Database)
        {
            if((each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint 
            && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName 
            && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod)
            {
                cnt++;
                cout <<"\n" << cnt <<  ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                            << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg 
                            << ". Require credit point for rent = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg 
                            << ". Period = " << (each->houseOwn)->start_period <<". For more contact call " << each->phoneNumber << "\n";
            }
        }
        if(cnt == 0)
        {
            cout << "There are no house suitable with you\n";
        }
        else{
            cout << "\nChoosing the house to send the request for the OccupyMem please enter INDEX NUMBER:";
            cin >> input_index;
            int i = 0;
            for(auto each: Database)
            {
                if((each->houseOwn)->location == city && (each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint 
                && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName 
                && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod)
                    i++;
                if(input_index == std::to_string(i))
                {
                    // user send the request to the OccupyMem 
                    each->listOfrequests.push_back(this); 

                }
            }
        }
    }
    else
        cout << "Syntax error\n";
}


int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    
    System Sys;
    House house; 
    Admin admin("admin", "12345");
    Sys.LoadDatabase();

    cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    cout << "VACATION HOUSE EXCHANGE APPLICATION\n\n";
    cout << "Instructor: Mr. Linh Tran\n";
    cout << "Group: BeautifulCoders\n";
    cout << "s3927112, Nguyen Tuong Khang\n";
    cout << "s3912105, Le Duy Quang\n";
    cout << "s3926823, Do Phuong Linh\n";
    cout << "s3915181, Nguyen Phan Duc Anh\n\n";

    //Use the app as Guest
    WelcomeScreen();
    int run = 1;
    string choice;
    while(1)
    {
        
        if(ExitProgram == true)
        {
            cout << "\nThank You for using Trading House App!\n";
            Sys.UpdateDataBase();
            return -1;
        }
        else if(Guest_choice == true)
        {
            cout << "\nThis is your menu: \n";
            cout << "0. Exit\n";
            cout << "1. View all house details\n";
            cout << "2. Register\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if(choice == "0")
            {
                Guest_choice = false;
                isLog = true;
                WelcomeScreen();
                Sys.UpdateDataBase();                
            }
            else if(choice == "1")
            {   
                Sys.ShowHouseDataBase();
                Sys.UpdateDataBase();
            }   
            else if(choice == "2")
            {
                Member *mem = new Member;
                House *house = new House;
                Sys.SignUp(mem, house);
                Sys.UpdateDataBase();
            }
            else
                cout << "Syntax error!\n";
            Sys.UpdateDataBase();
        }
        else if(Member_choice == true)
        {
            Member *add = new Member;
            if(add->LogIn() == true)
            {
                int loop = 1;
                while(loop == 1)
                {
                    cout << "\nThis is your menu: \n";
                    cout << "0. Exit\n";
                    cout << "1. View Informations detail\n";
                    cout << "2. Put your house for occupying\n";
                    cout << "3. View all houses menu\n";
                    cout << "4. Show list of requests\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if(choice == "0")
                    {
                        Member_choice = false;
                        loop = 2;
                        WelcomeScreen();
                        Sys.UpdateDataBase();
                    }
                    else if(choice == "1")
                    {
                        add->ShowInfo();
                        Sys.UpdateDataBase();
                    }
                    else if (choice == "2") 
                    {
                        add->PutHouseToRent();
                        Sys.UpdateDataBase(); 
                    } 
                    else if (choice == "3") 
                    {
                        while(true){
                            string choice1;
                            cout << "\nThis is your menu: \n";
                            cout << "0. Exit\n";
                            cout << "1. Show list of houses are available for occupying\n";
                            cout << "2. Show all the suitable house that user requirements are met\n";
                            cout << "Enter your choice: ";
                            cin >> choice1;
                            if(choice1 == "0")
                            {
                                break;
                                Sys.UpdateDataBase();
                            }
                            else if(choice1 == "1")
                            {
                                add->showHouseAvailable();
                                Sys.UpdateDataBase();
                            }
                            else if(choice1 == "2")
                            {
                                add->SuitableHouse();
                                Sys.UpdateDataBase();
                            }
                            else
                            {
                                Member_choice = false;
                                isLog = true;
                                cout << "Syntax error!\n";
                                Sys.UpdateDataBase();
                            }
                        }

                    } 
                    else if (choice == "4") {
                        add->ShowListRequest();
                        Sys.UpdateDataBase();
                    }
                    else
                    {
                        cout << "Syntax error!\n";
                        Sys.UpdateDataBase();
                    }
                }
            }
            else
            {
                Member_choice = false;
                WelcomeScreen();
                Sys.UpdateDataBase();
            }
        }
        else if(Admin_choice == true)
        {
            Sys.Admin_Login(&admin);
            if(Admin_Success == true)
            {
                admin.ShowDatabase();
                Admin_choice = false;
                Sys.UpdateDataBase();
                WelcomeScreen();
            }
            else
            {
                Admin_choice = false;
                WelcomeScreen();
            }
        }
    }
 
    return 0;
}