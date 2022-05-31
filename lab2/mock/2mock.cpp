#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/*Use linked list concepts to record real estate transactions (selling and buying a house) as below. 
• David: initially bought the house for $800
• David --> John : price = $1000
• John --> Peter : price = $1200
• Peter --> Luna : price = $1800
• Luna --> Sophia: price = $3500
Hint: Define a class, e.g. namely Broker, with attributes are name, buyPrice, sellPrice and 
nextBuyer.*/

/*a) Write a function to print out all transactions exactly as above
o David: initially bought the house for $800
o David --> John : price = $1000
o John --> Peter : price = $1200
o Peter --> Luna : price = $1800
o Luna --> Sophia: price = $3500*/

class Broker
{
    private:
        //attributes are name, buyPrice, sellPrice and nextBuyer.
        string name;
        float buyPrice;
        float sellPrice;
        Broker *nextBuyer = NULL; //by default points to nothing
        Broker *prevBuyer = NULL; 
        

    public:
        //Constructor
        Broker(){}
        Broker(string name, float sellPrice)
        {
            this->name = name;
            this->sellPrice = sellPrice;
        }
        Broker(string name, float buyPrice, float sellPrice)
        {
            this->name = name;
            this->buyPrice = buyPrice;
            this->sellPrice = sellPrice;
        }

        //method to set connections to other nodes
        void setLinks(Broker *nextBuyer)
        {
            this->nextBuyer = nextBuyer;
            nextBuyer->buyPrice = sellPrice;
        }

        //function to link to next node
        void linkNextNode(Broker *nextBuyer)
        {
            this->nextBuyer = nextBuyer;
            if(nextBuyer != NULL)
            {
                nextBuyer->prevBuyer = this;
                nextBuyer->buyPrice = sellPrice;
            }
            
        }

        //function to link to prev node
        void linkPrevNode(Broker *prevBuyer)
        {
            this->prevBuyer = prevBuyer;
            if(prevBuyer != NULL)
            {
                prevBuyer->nextBuyer = this;
                prevBuyer->sellPrice = buyPrice;
            }
        }

        //calculate Profit
        float Profit()
        {
            float Profit;
            Profit = sellPrice - buyPrice;
            return Profit;
        }

        //Show object Info
        void showObjectInfo()
        {
            cout << "Name = " << name << ". Profit = " << this->Profit() << "$\n";
        }

        //friends to grant access
        friend void showFordLinks(Broker *head);
        friend void showBackLinks(Broker *tail);
        friend void showLinks(Broker *head, Broker *tail);
        friend void showProfit(Broker *head, Broker *tail);
        friend void showMaxProfit(Broker *head, Broker *tail);
        friend void deleteTransaction(Broker *&head, Broker *&tail, Broker *Node);
    

};

/*o David: initially bought the house for $800
o David --> John : price = $1000
o John --> Peter : price = $1200
o Peter --> Luna : price = $1800
o Luna --> Sophia: price = $3500*/
void showFordLinks(Broker *head)
{
    cout << "Show Fordward Links: \n";
    cout << head->name << ": initially bought the house for " << head->buyPrice << "$\n";
    Broker *temp = head;
    while(temp->nextBuyer !=  NULL)
    {

        cout << temp->name << "--> " << (temp->nextBuyer)->name << ": Buy Price = " << temp->buyPrice << "$ " << 
                              ": Sell Price = " << temp->sellPrice <<"$\n";
        temp = temp->nextBuyer; 
    }
    cout << "\n";
}

void showBackLinks(Broker *tail)
{
    cout << "Show Backward Links: \n";
    Broker *temp = tail;
    while(temp->prevBuyer != NULL)
    {
        cout << temp->name << "--> " << (temp->prevBuyer)->name << ": Buy Price = " << temp->buyPrice << "$ " << 
                              ": Sell Price = " << temp->sellPrice <<"$\n";
        temp = temp->prevBuyer;
    }
    cout << temp->name << ": initially bought the house for " << temp->buyPrice << "$\n";
    cout << "\n";    
}


void showLinks(Broker *head, Broker *tail)
{
    showFordLinks(head);
    showBackLinks(tail);
}

/*b) Write a function to print out information of the brokers with the lowest and highest profit
(note: profit = sellPrice - buyPrice).*/
void showMaxProfit(Broker *head, Broker *tail)
{
    double Profit = 0;
    double Profit_Next = 0;

    vector<Broker*> HouseholdList;

    for(Broker *left = head; left != NULL; left = left->nextBuyer)
    {
        //update Profit of people to a list
        HouseholdList.push_back(left);    
    }

    //To get highest Profit
    Broker *Max_Profit = HouseholdList[0];
    for(auto list : HouseholdList)
    {
        if(Max_Profit->Profit() < list->Profit())
        {
            Max_Profit = list;
        }
    }
    cout << "User has the highest profit:\n";
    Max_Profit->showObjectInfo();

    //To get minimum Profit
    Broker *Min_Profit = HouseholdList[0];
    for(auto list : HouseholdList)
    {
        if(Min_Profit->Profit() > list->Profit())
        {
            Min_Profit = list;
        }
    }
    cout << "User has the lowest profit:\n";
    Min_Profit->showObjectInfo();
    
}

/*c) Write a function to allow deleting a transaction within the linked list. Test it in main().*/
void deleteTransaction(Broker *&head, Broker *&tail, Broker *Node)
{
    //head case
    if(Node->prevBuyer == NULL)
    {
        head = Node->nextBuyer;
        (Node->nextBuyer)->prevBuyer = NULL;
    }
    else if(Node->nextBuyer == NULL) //tail case
    {
        tail = Node->prevBuyer;
        Node->nextBuyer = NULL;
    }
    else //other case
    {
        (Node->prevBuyer)->linkNextNode(Node->nextBuyer);
    }
}






int main()
{
    /*CREATE LINKED LIST VALUE*/
    Broker node1("David", 800.00, 1023.32), node2("John", 1299.99), node3("Peter", 1800),
           node4("Luna", 3555.324), node5("Sophia", 4673.23);
    Broker *head = &node1;
    node1.linkNextNode(&node2);
    node2.linkNextNode(&node3);
    node3.linkNextNode(&node4);
    node4.linkNextNode(&node5);
    Broker *tail = &node5;

    //show forward link
    cout << "\nRecord real estate transactions:\n";
    showLinks(head, tail);

    showMaxProfit(head, tail);

    //Delete transaction:
    cout << "\n\nDelete transaction: ";
    deleteTransaction(head, tail, &node3);
    showLinks(head, tail);

    return 0;
}