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



    //Record Data for Owner   
    string username = "NULL";
    string fullname = "NULL";
    string phoneNumber = "NULL";

    //Method
public:
    House() {}
    House(string location, string description, string available, string start_period, string end_period) {
        this->location = location;
        this->description = description;
        this->available = available;
        this->start_period = start_period;
        this->end_period = end_period;

    }

    //ShowInfo
    void ShowInfo()
    {
        cout << "Location: " << location << "\n"
            << "Description: " << description << "\n"
            << "Owner: > username: " << username << "\n"
            << "       > fullname: " << fullname << "\n"
            << "       > phone number: " << phoneNumber << "\n\n";
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
    string comment = "NULL";
    double creditPoint = 500; //500 credit when creating Member 

    Member* OccupyMem;


    double occupierRatingScore_Avg = 0;
    double HouseRatingScore_Avg = 0;
    double rentingCreditPoint = 0;
    double minimum_occupierRatingScore_Avg = 0;


    //Recored Data
    House* houseOwn; //Constraint only one house for Member
    House* houseOccupy; //Constraint only one house for Occupy
    vector<double> listHouseRating;
    vector<double> listOccupierRating;
    vector<Member*> listOfrequests;
    vector<Member*> listOfreviews;


    //This attribute for update database
    House houseData;

    //Method
public:
    Member() {}
    Member(string userName, string fullName, string phoneNumber, string password, House* houseOwn)  //Input data for member through Constructor for testing
    {
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->password = password;
        this->houseOwn = houseOwn;

        //Update to list of members in GLOBAL
        Database.push_back(this);

        //Already Existing House
        houseOwn->username = this->userName;
        houseOwn->fullname = this->fullName;
        houseOwn->phoneNumber = this->phoneNumber;
    }
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
        cout << "   House location = " << houseOwn->location << ". House description = " << houseOwn->description << ".\n"
            << "   House Rating Score = " << houseOwn->houseRatingScore_Avg << ". Availability = " << houseOwn->available << ".\n"
            << "   Require credit point for rent = " << rentingCreditPoint << ".  Minimum require occupier rating = " << minimum_occupierRatingScore_Avg
            << "   .Start Period = " << houseOwn->start_period << ". End Period = " << houseOwn->end_period << ".\n";

        if (houseOccupy->location != "NULL")
        {
            cout << "\nYour House Occupied:\n";
            cout << "   House location = " << houseOccupy->location << ". House description = " << houseOccupy->description << "\n"
                << "   House Rating Score = " << houseOccupy->houseRatingScore_Avg << ". House start period = " << houseOccupy->start_period << ". House end period = " << houseOccupy->end_period << "\n"
                << "   Information of Owner of this house: \n"
                << "        >Fullname = " << houseOccupy->fullname << ". Phone number = " << houseOccupy->phoneNumber << ". Username = " << houseOccupy->username << "\n";
        }
        else
            cout << "\nThere is no information of your occupied house\n";
        if (OccupyMem->userName != "NULL")
        {
            cout << "\nThe information of the member is occupying your house:\n";
            cout << "   Full name = " << OccupyMem->fullName << ". User name = " << OccupyMem->fullName << ".\n"
                << "   Phone number = " << OccupyMem->phoneNumber << ". Occupied Score = " << OccupyMem->occupierRatingScore_Avg << "\n";
        }
        else
            cout << "\nThere is no information of the member who is occupying your house\n";


    }

    //Show List of Request
    void ShowListRequest()
    {
        bool check = false;
        cout << "Your list of requests:\n";
        int cnt = 1;


        for (auto each : listOfrequests)
        {
            cout << cnt << ") Username = " << each->userName << ". Phone number = " << each->phoneNumber << ". Occupied Rating Score = " << each->occupierRatingScore_Avg << "\n";
            cnt++;
        }

        if (listOfrequests.empty() != 1)
        {
            cout << "\nChoose the member you want to occupy your house please enter the INDEX NUMBER: ";
            string input_index;
            cin >> input_index;
            int i = 0;
            for (auto Each : Database)
            {
                if (Each->userName == userName)
                {
                    for (auto each : Each->listOfrequests)
                    {
                        if (true)
                            i++;
                        if (input_index == std::to_string(i))
                        {

                            //Check for requirements
                            if (each->creditPoint >= rentingCreditPoint && each->occupierRatingScore_Avg >= minimum_occupierRatingScore_Avg && each->houseOccupy->username == "NULL")
                            {
                                check = true;
                                //Update House Occupier
                                OccupyMem = each;

                                for (auto each : Database)
                                {
                                    if (each->userName == OccupyMem->userName)
                                    {
                                        each->houseOccupy = houseOwn;
                                    }
                                }

                                Each->houseOwn->available = "Unavailable";

                                //Reduce money from occupier
                                each->creditPoint = each->creditPoint - rentingCreditPoint;
                                //Add money to House Owner
                                creditPoint = creditPoint + rentingCreditPoint;

                                Each->listOfrequests.clear();
                            }
                        }

                    }

                }
            }

            //Update Database
            for (auto each : Database)
            {
                if (each->userName == userName)
                {
                    each->OccupyMem = OccupyMem;
                    each->creditPoint = creditPoint;
                }
            }

            for (auto each : Database)
            {
                if (each->userName == OccupyMem->userName) {
                    each->creditPoint = each->creditPoint - rentingCreditPoint;
                }
            }


            if (check == true)
                listOfrequests.clear();
        }

    }

    void ReturnHouse()
    {
        bool check = false;
        double score;
        string comment;
        for (auto each : Database)
        {
            if (each->houseOccupy->username != "NULL")
            {
                check = true;
                string choice;
                cout << "Do you want to return the house (Y/N)?: ";
                cin >> choice;
                if (choice == "N")
                    cout << "Exit to the main menu!\n";
                else if (choice == "Y")
                {
                    houseOccupy->location = "NULL";
                    houseOccupy->description = "NULL";
                    houseOccupy->houseRatingScore_Avg = 0;
                    houseOccupy->fullname = "NULL";
                    houseOccupy->start_period = "NULL";
                    houseOccupy->end_period = "NULL";
                    houseOccupy->fullname = "NULL";
                    string temp = houseOccupy->username;
                    houseOccupy->username = "NULL";

                    cout << "Please enter the House-rating score for this house after occupied it from -10 to +10:";
                    cin >> score;
                    if (score >= -10 && score <= 10)
                    {
                        for (auto each : Database)
                        {
                            if (temp == each->userName)
                            {
                                if (each->HouseRatingScore_Avg == 0)
                                    each->HouseRatingScore_Avg = score;
                                else
                                {
                                    each->HouseRatingScore_Avg = (each->HouseRatingScore_Avg + score) / 2;
                                }
                                each->OccupyMem->userName = "NULL";
                                each->OccupyMem->fullName = "NULL";
                                each->OccupyMem->phoneNumber = "NULL";
                                //Waiting to score the OccupierRatingScore Avg

                                cout << "Please leave a comment for this house after occupied: ";
                                cin.clear();
                                cin.ignore(1, '\n');
                                getline(cin, comment);
                                cin.clear();

                                //Update to the review list

                                Member* ReviewTemp = new Member;
                                ReviewTemp->userName = userName;
                                ReviewTemp->comment = comment;
                                ReviewTemp->HouseRatingScore_Avg = score;

                                each->listOfreviews.push_back(ReviewTemp);
                            }
                        }
                    }
                }
                else
                    cout << "Syntax Error\n";
            }

        }
        if (check == false)
            cout << "Sorry! You dont have a house to return.\n";

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
            for (auto each : Database)
            {
                if (each->userName == userName)
                    each->rentingCreditPoint = Input_RentingcreditPoint;
            }
            cout << "Set the minimum required occupier rating to rent this house: ";
            cin >> Input_MinimumOccupierRatingScore_Avg;
            minimum_occupierRatingScore_Avg = Input_MinimumOccupierRatingScore_Avg;
            for (auto each : Database)
            {
                if (each->userName == userName)
                    each->minimum_occupierRatingScore_Avg = Input_MinimumOccupierRatingScore_Avg;
            }

            cout << "Set start period for house availability (dd/mm/yyyy): ";
            cin >> Input_start_period;
            houseOwn->start_period = Input_start_period;

            cout << "Set end period for house availability (dd/mm/yyyy): ";
            cin >> Input_end_period;
            houseOwn->end_period = Input_end_period;

        }
        else if (choice == "N") {
            houseOwn->available = "Unavailable";
        }
        else {
            cout << "Syntax error\n";
        }

    }

    //Show House available for rent
    void showHouseAvailable()
    {
        int cnt = 1;
        for (auto each : Database)
        {

            if ((each->houseOwn)->available == "Available")
            {
                cout << "\n" << cnt << ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                    << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg <<
                    ". Require credit point for occupy = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg
                    << ". Start period = " << (each->houseOwn)->start_period << ". End period = " << (each->houseOwn)->end_period <<
                    ". For more contact call " << each->phoneNumber << "\n";
                cnt++;
            }
        }
    }

    void ShowListOfReviews()
    {
        int cnt = 1;
        for (auto each : Database)
        {

            if (each->userName == userName)
            {
                for (auto review : each->listOfreviews)
                {
                    cout << cnt << ")   User" << review->userName << ": " << review->comment << ". House Rating Score = " << review->HouseRatingScore_Avg << "\n";
                    cnt++;
                }
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
    Admin() {}
    Admin(string admin_userName, string admin_password) {
        this->admin_userName = admin_userName;
        this->admin_password = admin_password;
    }
    void ShowDatabase()
    {
        //Show List of data of Members 
        int cnt = 1;
        cout << "\n";
        for (auto each : Database)
        {
            cout << cnt << ") Member's name: " << each->fullName << ". Username: " << each->userName << ". Phone number: " << each->phoneNumber
                << ". Credit point: " << each->creditPoint << ". Occupier score: " << each->occupierRatingScore_Avg
                << ". House location: " << (each->houseOwn)->location << ". Description: " << (each->houseOwn)->description << ". Availability: " << (each->houseOwn)->available
                << ". Require credit point for occupy = " << each->rentingCreditPoint << ".  Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg
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
    System() {};


    //Feature for Sign UpF
    void SignUp(Member* user, House* house, Member* OccupyMem, House* houseOccupy);

    //Feature 13
    void LoadDatabase()
    {
        string line;
        string userName;
        string fullName;
        string phoneNumber;
        double houseRatingScore;
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
        string houseUsername;
        string houseFullname;
        string housePhonenumber;

        string request_fullname;
        string request_username;
        string request_phoneNumber;
        double request_occupiedScore;
        double request_creditPoint;
        string request_comment;
        double request_houseRatingScore;


        string OccupyUsername;
        string OccupyFullname;
        string OccupyPhonenumber;
        double OccupyOccupyScore;

        string reviewFullname;
        string reviewUsername;
        string reviewPhonenumber;
        string reviewComment;
        double reviewHouseRatingScore;

        int sizeOfRequest;
        int sizeOfReviews;


        data.open("database.txt", std::ios::in);
        vector<string> tokens;
        int i = 0;
        while (getline(data, line))
        {
            std::stringstream check1(line);
            string intermediate;
            while (getline(check1, intermediate, ','))
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
            houseRatingScore = stod(tokens[6]);
            rentingCreditPoint = stod(tokens[7]);
            minimum_requireOccupyScore = stod(tokens[8]);

            OccupyUsername = tokens[9];
            OccupyFullname = tokens[10];
            OccupyPhonenumber = tokens[11];
            OccupyOccupyScore = stod(tokens[12]);


            location = tokens[13];
            description = tokens[14];
            available = tokens[15];
            house_start_period = tokens[16];
            house_end_period = tokens[17];
            houseFullname = tokens[18];
            houseUsername = tokens[19];
            housePhonenumber = tokens[20];


            houseOccupylocation = tokens[21];
            houseOccupyDescription = tokens[22];
            houseOccupyRatingScore = stod(tokens[23]);
            houseOccupyStartperiod = tokens[24];
            houseOccupyEndperiod = tokens[25];
            houseOccupyFullname = tokens[26];
            houseOccupyUsername = tokens[27];
            houseOccupyPhonenumber = tokens[28];

            sizeOfRequest = stoi(tokens[29]);
            sizeOfReviews = stoi(tokens[30]);

            Member* MemTemp = new Member;
            MemTemp->userName = userName;
            MemTemp->fullName = fullName;
            MemTemp->password = password;
            MemTemp->phoneNumber = phoneNumber;
            MemTemp->creditPoint = creditPoint;
            MemTemp->HouseRatingScore_Avg = houseRatingScore;
            MemTemp->occupierRatingScore_Avg = occupierRatingScore_Avg;
            MemTemp->rentingCreditPoint = rentingCreditPoint;
            MemTemp->minimum_occupierRatingScore_Avg = minimum_requireOccupyScore;

            Member* OccMem = new Member;
            OccMem->userName = OccupyUsername;
            OccMem->fullName = OccupyFullname;
            OccMem->phoneNumber = OccupyPhonenumber;
            OccMem->occupierRatingScore_Avg = OccupyOccupyScore;

            MemTemp->OccupyMem = OccMem;

            //House of Owner
            House* HouseTemp = new House;
            HouseTemp->location = location;
            HouseTemp->description = description;
            HouseTemp->available = available;
            HouseTemp->start_period = house_start_period;
            HouseTemp->end_period = house_end_period;
            HouseTemp->fullname = houseFullname;
            HouseTemp->username = houseUsername;
            HouseTemp->phoneNumber = housePhonenumber;

            //Member occupy house
            House* HouseOccupyTemp = new House;
            HouseOccupyTemp->location = houseOccupylocation;
            HouseOccupyTemp->description = houseOccupyDescription;
            HouseOccupyTemp->houseRatingScore_Avg = houseOccupyRatingScore;
            HouseOccupyTemp->start_period = houseOccupyStartperiod;
            HouseOccupyTemp->end_period = houseOccupyEndperiod;
            HouseOccupyTemp->fullname = houseOccupyFullname;
            HouseOccupyTemp->username = houseOccupyUsername;
            HouseOccupyTemp->phoneNumber = houseOccupyPhonenumber;



            MemTemp->houseOwn = HouseTemp;
            MemTemp->houseOccupy = HouseOccupyTemp;



            int i = 30;
#if 1
            while (tokens.size() > 30 && i < sizeOfRequest * 4 + 30)
            {
                request_fullname = tokens[i + 1];
                request_username = tokens[i + 2];
                request_phoneNumber = tokens[i + 3];
                request_occupiedScore = stod(tokens[i + 4]);


                Member* RequestTemp = new Member;
                RequestTemp->fullName = request_fullname;
                RequestTemp->userName = request_username;
                RequestTemp->phoneNumber = request_phoneNumber;
                RequestTemp->occupierRatingScore_Avg = request_occupiedScore;
                MemTemp->listOfrequests.push_back(RequestTemp);
                i = i + 5;
            }

            int next = 30 + sizeOfRequest * 4;
            while (tokens.size() > next && i < sizeOfReviews * 3 + next)
            {
                reviewUsername = tokens[i + 1];
                reviewComment = tokens[i + 2];
                reviewHouseRatingScore = stod(tokens[i + 3]);

                Member* ReviewTemp = new Member;
                ReviewTemp->userName = reviewUsername;
                ReviewTemp->comment = reviewComment;
                ReviewTemp->HouseRatingScore_Avg = reviewHouseRatingScore;

                MemTemp->listOfreviews.push_back(ReviewTemp);
                i = i + 4;
            }

#endif

            Database.push_back(MemTemp);
            tokens.clear();
        }
        data.close();
    }

    //Show house detail in Guest
    void ShowHouseDataBase()
    {
        for (auto each : Database)
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
        for (auto each : Database)
        {
            int i = 0;
            int sizeRequest = each->listOfrequests.size();
            int sizeReview = each->listOfreviews.size();
            data << each->userName << "," << each->fullName << "," << each->phoneNumber << "," << each->password << "," << each->creditPoint << "," << each->occupierRatingScore_Avg << "," << each->HouseRatingScore_Avg << "," << each->rentingCreditPoint
                << "," << each->minimum_occupierRatingScore_Avg << "," << each->OccupyMem->userName << "," << each->OccupyMem->fullName << "," << each->OccupyMem->phoneNumber << "," << each->OccupyMem->occupierRatingScore_Avg << ","
                << (each->houseOwn)->location << "," << (each->houseOwn)->description << ","
                << (each->houseOwn)->available << "," << (each->houseOwn)->start_period << "," << (each->houseOwn)->end_period << "," << (each->houseOwn)->fullname << "," << (each->houseOwn)->username << "," << (each->houseOwn)->phoneNumber << ","
                << (each->houseOccupy)->location << "," << (each->houseOccupy)->description << "," << (each->houseOccupy)->houseRatingScore_Avg << ","
                << (each->houseOccupy)->start_period << "," << (each->houseOccupy)->end_period << "," << (each->houseOccupy)->fullname << "," << (each->houseOccupy)->username
                << "," << (each->houseOccupy)->phoneNumber << "," << sizeRequest << "," << sizeReview << ",";

            if (each->listOfrequests.empty() == 1 && each->listOfreviews.empty() == 1)
            {
                data << "\n";
            }
            else {
                for (auto request : each->listOfrequests)
                {
                    cout << "Check\n";
                    data << request->fullName << "," << request->userName << "," << request->phoneNumber << "," << request->occupierRatingScore_Avg << "," << request->creditPoint << ",";
                }
                for (auto review : each->listOfreviews)
                {
                    data << review->userName << "," << review->comment << "," << review->HouseRatingScore_Avg << ",";
                }
                data << "\n";
            }


        }
        data.close();
    }




    void Admin_Login(Admin* input);

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
    do {
        cout << "\nUse the app as 1. Guest    2. Member   3. Admin  4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;


        if (choice == "1")
        {
            Guest_choice = true;
            break;
        }
        else if (choice == "2")
        {
            Member_choice = true;
            break;
        }
        else if (choice == "3")
        {
            Admin_choice = true;
            break;
        }
        else if (choice == "4")
        {
            ExitProgram = true;
            break;
        }
        else
        {
            cout << "Syntax Error! Please enter your choice again!\n";
            loop = true;
        }
    } while (loop == true);
}

//LogIn feature should be fix in mem class
bool Member::LogIn()
{
    bool SuccessLog = false;
    bool SuccessUsername = false;
    int i = 0;
    int j = 0;
    string Input_UserName;
    string Input_Password;
    cout << "Enter username: ";
    cin >> Input_UserName;
    //Check the Input UserName is existed in Database
    for (auto each : Database)
    {
        i++;
        if (Input_UserName == each->userName)
        {

            SuccessUsername = true;
            cout << "Enter password: ";
            cin >> Input_Password;

            if (Input_Password == each->password)
            {
                cout << "Log In Successfully!!\n";
                fullName = each->fullName;
                userName = each->userName;
                phoneNumber = each->phoneNumber;
                HouseRatingScore_Avg = each->HouseRatingScore_Avg;
                occupierRatingScore_Avg = each->occupierRatingScore_Avg;
                creditPoint = each->creditPoint;
                password = each->password;
                rentingCreditPoint = each->rentingCreditPoint;
                minimum_occupierRatingScore_Avg = each->minimum_occupierRatingScore_Avg;


                houseOwn = each->houseOwn;
                houseOccupy = each->houseOccupy;
                OccupyMem = each->OccupyMem;

                // //Load list of request
                for (auto request : each->listOfrequests)
                {
                    listOfrequests.push_back(request);
                }

                for (auto review : each->listOfreviews)
                {
                    listOfreviews.push_back(review);
                }

                SuccessLog = true;
                return true;
            }
        }

    }
    if (SuccessUsername == false)
    {
        cout << "Wrong Username\n";
        return false;
    }
    else
    {
        cout << "Wrong Password\n";
        return false;
    }
}

bool Admin_Success = false;
void System::Admin_Login(Admin* temp) {
    string Input_admin_username;
    string Input_admin_password;
    cout << "Please enter username: ";
    cin >> Input_admin_username;
    if (Input_admin_username == temp->admin_userName) {
        cout << "Please enter password: ";
        cin >> Input_admin_password;
        if (Input_admin_password == temp->admin_password) {
            cout << "Log In Successfully!!";
            Admin_Success = true;
        }
        else {
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
    int balance = (int)rand();
    return balance;
}


//Feature for Sign Up
void System::SignUp(Member* user, House* house, Member* OccupyMem, House* houseOccupy)
{
    string Input_UserName;
    string Input_Password;
    string Input_PhoneNumber;
    string Input_FullName;

    string Input_Location;
    string Input_Description;

    int balance = randomBalance();

    user->OccupyMem = OccupyMem;
    user->houseOccupy = houseOccupy;

    cout << "Require intial entry of $500 to become a member($500 = 500 credit points)\n";
    if (balance >= 500)
    {
        cout << "Balance has changed from $" << balance << " to  $" << balance - 500 << "\n";
        cout << "Successfully paid initial entry fee!!\n";
        user->creditPoint = 500;
        payAble = true;
    }
    else
        cout << "Your balance doens't have enough money to pay for initial entry. Your balance is " << balance << "$\n";

    if (payAble == true)
    {
        //-------------------------FILLLING THE FORM-----------------------------//
        cout << "\n\n//-------------------------FILLLING THE FORM-----------------------------//\n";
        cout << "Please Fill the form: \n";
        cout << "   > Full name: ";
        cin.ignore(1, '\n');
        getline(cin, Input_FullName);
        user->fullName = Input_FullName;
        house->fullname = Input_FullName;
        cout << "   > Phone number: ";
        getline(cin, Input_PhoneNumber);
        user->phoneNumber = Input_PhoneNumber;
        house->phoneNumber = Input_PhoneNumber;
        cout << "Adding your house information:\n";
        cout << "   > Location: ";
        getline(cin, Input_Location);
        while (true) {
            if (Input_Location != "Hanoi" && Input_Location != "Saigon" && Input_Location != "Da Nang")
            {
                cout << "The application is early available to users in several cities: Hanoi, Saigon, Da Nang.\n";
                Input_Location = "";
                cout << "   > Location: ";
                getline(cin, Input_Location);
            }
            else
            {
                house->location = Input_Location;
                break;
            }
        }

        cout << "   > House Description \"OPTIONAL\" (press ENTER if no description): ";
        // cin.ignore(1, '\n');
        getline(cin, Input_Description);
        if (Input_Description.length() != 0)
            house->description = Input_Description;




        cout << "\n\n//-------------------REGISTER USERNAME AND PASSWORD-----------------------//\n";

        //-------------------REGISTER USERNAME AND PASSWORD-----------------------// 
        //Check if Input_UserName is not duplicate in Database
        do {
            int check = 0;
            cout << "   > Username (No Space!): ";
            cin >> Input_UserName;
            for (auto each : Database)
            {
                if (Input_UserName == each->userName)
                {
                    cout << "   < This username has already been used >\n";
                    check = 1;
                }
            }
            if (check != 1)
            {
                Dup_username = false;
                user->userName = Input_UserName;
            }
        } while (Dup_username == true);



        cout << "   > Password (No space!): ";
        cin >> Input_Password;
        user->password = Input_Password;
        cout << "Sign In Successfully!!\n\n";

        house->username = Input_UserName;


        user->houseOwn = house;
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
    cout << "Do you want to search for particulary city you want to occupy the house (Y/N)?: ";
    cin >> decision;
    if (decision == "Y")
    {
        cout << "\nSearch for particulary city you want to occupy the house: ";
        cin.clear();
        cin.ignore(1, '\n');
        getline(cin, city);
        cin.clear();



        cout << "Enter your start period in format dd/mm/yyyy: ";
        cin >> input_startPeriod;

        cout << "Enter your end period in format dd/mm/yyyy: ";
        cin >> input_endPeriod;

        int cnt = 0;
        for (auto each : Database)
        {
            if ((each->houseOwn)->location == city && (each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint
                && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName
                && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod && houseOccupy->username == "NULL")
            {
                cnt++;
                cout << "\n" << cnt << ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                    << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg
                    << ". Require credit point for rent = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg
                    << ". Start Period = " << (each->houseOwn)->start_period << ". End Period = " << (each->houseOwn)->end_period << ". For more contact call " << each->phoneNumber << "\n";
            }
        }
        if (cnt == 0)
        {
            cout << "There is no suitable house for you\n";
        }
        else {
            cout << "\nChoosing the house to send the request for the owner (please enter INDEX NUMBER):";
            cin >> input_index;
            int i = 0;
            for (auto each : Database)
            {
                if ((each->houseOwn)->location == city && (each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint
                    && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName
                    && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod)
                    i++;
                if (input_index == std::to_string(i))
                {
                    // user send the request to the owner                                    
                    each->listOfrequests.push_back(this);
                    break;
                }
            }
            cout << i << "\n";
        }

    }
    else if (decision == "N")
    {
        int cnt = 0;

        cout << "Enter your start period in format dd/mm/yyyy: ";
        cin >> input_startPeriod;

        cout << "Enter your end period in format dd/mm/yyyy: ";
        cin >> input_endPeriod;
        for (auto each : Database)
        {
            if ((each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint
                && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName
                && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod && houseOccupy->username == "NULL")
            {
                cnt++;
                cout << "\n" << cnt << ") House of " << each->fullName << ". Location at " << (each->houseOwn)->location << ".\n"
                    << "Description: " << (each->houseOwn)->description << ". House Rating Score =  " << (each->houseOwn)->houseRatingScore_Avg
                    << ". Require credit point for rent = " << each->rentingCreditPoint << ". Minimum require occupier rating = " << each->minimum_occupierRatingScore_Avg
                    << ". Period = " << (each->houseOwn)->start_period << ". For more contact call " << each->phoneNumber << "\n";
            }
        }
        if (cnt == 0)
        {
            cout << "There is no suitable house for you\n";
        }
        else {
            cout << "\nChoosing the house to send the request for the owner (please enter INDEX NUMBER):";
            cin >> input_index;
            int i = 0;
            for (auto each : Database)
            {
                if ((each->houseOwn)->available == "Available" && creditPoint >= each->rentingCreditPoint
                    && occupierRatingScore_Avg >= each->minimum_occupierRatingScore_Avg && each->userName != userName
                    && (each->houseOwn)->start_period == input_startPeriod && (each->houseOwn)->end_period == input_endPeriod && houseOccupy->username == "NULL")
                    i++;
                if (input_index == std::to_string(i))
                {
                    // user send the request to the owner 
                    each->listOfrequests.push_back(this);
                    break;
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
    while (1)
    {

        if (ExitProgram == true)
        {
            cout << "\nThank You for using Trading House App!\n";
            Sys.UpdateDataBase();
            return -1;
        }
        else if (Guest_choice == true)
        {
            cout << "\nThis is your menu: \n";
            cout << "0. Exit\n";
            cout << "1. View all house details\n";
            cout << "2. Register\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == "0")
            {
                Guest_choice = false;
                isLog = true;
                WelcomeScreen();
                Sys.UpdateDataBase();
            }
            else if (choice == "1")
            {
                Sys.ShowHouseDataBase();
                Sys.UpdateDataBase();
            }
            else if (choice == "2")
            {
                Member* mem = new Member;
                House* house = new House;
                Member* OccupyMem = new Member;
                House* houseOccupy = new House;
                Sys.SignUp(mem, house, OccupyMem, houseOccupy);
                Sys.UpdateDataBase();
            }
            else
                cout << "Syntax error!\n";
            Sys.UpdateDataBase();
        }
        else if (Member_choice == true)
        {
            Member* add = new Member;
            if (add->LogIn() == true)
            {
                int loop = 1;
                while (loop == 1)
                {
                    cout << "\nThis is your menu: \n";
                    cout << "0. Exit\n";
                    cout << "1. View Informations detail\n";
                    cout << "2. Put your house for occupying\n";
                    cout << "3. View house for occupied menu\n";
                    cout << "4. Show list of requests\n";
                    cout << "5. Show your house reviews\n";
                    cout << "6. Return your occupied house\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (choice == "0")
                    {
                        Member_choice = false;
                        loop = 2;
                        WelcomeScreen();
                        Sys.UpdateDataBase();
                    }
                    else if (choice == "1")
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
                        while (true) {
                            string choice1;
                            cout << "\nThis is your menu: \n";
                            cout << "0. Exit\n";
                            cout << "1. Show list of houses are available for renting\n";
                            cout << "2. Show all the suitable house for user requirements\n";
                            cout << "Enter your choice: ";
                            cin >> choice1;
                            if (choice1 == "0")
                            {
                                break;
                                Sys.UpdateDataBase();
                            }
                            else if (choice1 == "1")
                            {
                                add->showHouseAvailable();
                                Sys.UpdateDataBase();
                            }
                            else if (choice1 == "2")
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
                    else if (choice == "5")
                    {
                        add->ShowListOfReviews();
                        Sys.UpdateDataBase();
                    }
                    else if (choice == "6")
                    {
                        add->ReturnHouse();
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
        else if (Admin_choice == true)
        {
            Sys.Admin_Login(&admin);
            if (Admin_Success == true)
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

