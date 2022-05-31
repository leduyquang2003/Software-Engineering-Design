/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Nguyen Tuong Khang
  ID: s3927112
  Compiler used: gcc 8.1.0
  Created  date: 5/7/2022 
  Acknowledgement: None
*/
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/*A traveler would like to plan for her trip with list of visting cities in order as below
• Hue: 2.5 days
• Da Nang: 1.5 days
• Nha Trang: 4 days
• Da Lat: 2 days
• Can Tho: 1 day
a) Use linked list concepts to record that trip plan. Write a function to print out the trip plan exactly as 
above:
Hint: Define a class, e.g. namely City, with attributes are name, days and nextCity *.*/

class City
{
    public:
        string name;
        double days;
        City *next = NULL;
        City *prev = NULL;

        //Constructor
        City(){}
        City(string name, double days)
        {
            this->name = name;
            this->days = days;
        }

        //function to link to next node
        void linkNextNode(City *nextCity)
        {
            this->next = nextCity;
            if(nextCity != NULL)
            {
                nextCity->prev = this;
            }
        }

        //function to link to prev node
        void linkPrevNode(City *prevCity)
        {
            this->prev = prevCity;
            if(prevCity != NULL)
            {
                prevCity->next = this;
            }
        }
        /*b) Write a function to find and print out the two adjacent cities of which she will stay there for total 
        longest time and shortest time.
        Note: for example, for longest time, the result should be Nha Trang and Da Lat with total time is 6 days.*/
        //Sum of two adjacents city days
        double SumOfAdjacents_days()
        {
            double Sum = 0;
            Sum = next->days + days;
            return Sum;
        }

};

/*• Hue: 2.5 days
• Da Nang: 1.5 days
• Nha Trang: 4 days
• Da Lat: 2 days
• Can Tho: 1 day
a function to print out the trip plan exactly as 
above:*/
void showFordLinks(City *head)
{
    City *temp = head;
    while(temp != NULL)
    {
        cout << temp->name << ": " << temp->days;
        if(temp->days > 1)
            cout << " days\n";
        else
            cout << " day\n";
        temp = temp->next;
    }
    cout << "\n";
}

/*b) Write a function to find and print out the two adjacent cities of which she will stay there for total longest 
time and shortest time.
Note: for example, for longest time, the result should be Nha Trang and Da Lat with total time is 6 days.*/
void showLongestDay_Adjacents(City *head, City *tail)
{
    
    City *temp = head;
    double longestDays = 0;
    City *result = head;
    while(temp != tail)
    {
        if(longestDays < temp->SumOfAdjacents_days())
        {
            longestDays = temp->SumOfAdjacents_days();
            result = temp;
        }
        temp = temp->next;
    }
    cout << "Longest time adjacent:\n";
    cout << "It is " << result->name << " and " << (result->next)->name << "\n";
    cout << "Total longest time is " << longestDays << "\n";
}

void showShortestDay_Adjacents(City *head, City *tail)
{
    City *temp = head;
    double shortestDays = temp->SumOfAdjacents_days();
    City *result = head;
    while(temp != tail)
    {
        if(shortestDays > temp->SumOfAdjacents_days())
        {
            shortestDays = temp->SumOfAdjacents_days();
            result = temp;
        }
        temp = temp->next;
    }
    cout << "Shortest time adjacent:\n";
    cout << "It is " << result->name << " and " << (result->next)->name << "\n";
    cout << "Total shortest time is " << shortestDays << "\n";
}

/*c) Write a function which allow to insert a new City into the list before another one
bool insertCity(City *&head, City *newCity, Node *latterCity)
Test it in main, e.g., by adding Sai Gon with 2 days into the list before Can Tho*/
void InsertNode(City *&head, City *&tail, City *newCity, City *latterCity)
{
    //If latterCity not the head
    if(latterCity->prev != NULL)
    {
        newCity->linkPrevNode(latterCity->prev);
        newCity->linkNextNode(latterCity);

        //if latterCity is tail
        if(latterCity == tail)
        {
            newCity->linkPrevNode(latterCity->prev);
            newCity->next = latterCity;
        }
    }
    else //Replace the head
    {
        newCity->linkNextNode(head);
        head = newCity;
    }
}

int main()
{
    //Created Linked List Value
    City node1("Hue", 2.5), node2("Da Nang", 1.5), node3("Nha Trang", 4), node4("Dat Lat", 2), node5("Can Tho", 1);
    City *head = &node1;
    node1.linkNextNode(&node2);
    node2.linkNextNode(&node3);
    node3.linkNextNode(&node4);
    node4.linkNextNode(&node5);
    City *tail = &node5;

    //Show infor
    showFordLinks(head);

    //Test longest adjacent days
    showLongestDay_Adjacents(head, tail);
    //Test shortest adjacent days
    showShortestDay_Adjacents(head, tail);

    //Test InsertNode
    City newNode("Sai Gon", 2);
    InsertNode(head, tail, &newNode, &node5);
    showFordLinks(head);

    return 0;
}