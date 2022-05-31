/*Define a class namely Node with three attributes are value (int), next (pointer to the next 
linked node), prev (pointer to the previous linked node), and provide class constructors to 
initialize value.
a) Create four nodes with values are 8, 5, 3, 6. Create a doubly linked list by connect 
them together in sequence.
Write two functions to print out values of connected nodes in forward and backward
orders.
Sample Run:
8 --> 5 --> 3 --> 6 -->
6 --> 3 --> 5 --> 8 -->
*/

#include <iostream>
#include <string>

//Create class node
class Node
{
    public:
        //three attributes value/next/prev
        int value;
        Node *next = NULL;
        Node *prev = NULL;

    //Constructor
    Node(int value)
    {
        this->value = value;
    }

};

//Function to print value of connected nodes in forward
void forward(Node *head)
{
    std::cout << "Print value forward: ";
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout << temp->value << " --> ";
        temp = temp->next;
    }
    std::cout << "\n";
}

//Function to print value of connected nodes in backward
void backward(Node *tail)
{
    std::cout << "Print value  backward: ";
    Node *temp = tail;
    while(tail != NULL)
    {
        std::cout << temp->value << " --> ";
        temp = temp->prev;
    }
    std::cout << "xcxcx\n";
}

/*b) Write two functions to allow insert a node, and delete a node as below:
• void inserNode(Node *head, Node *priorNode, Node *newNode) 
insert the newNode right after priorNode (insert at the beginning if priorNode is NULL).
• void deleteNode(Node *head, Node *delNote) 
delete the delNote from the linked list.
Test it by inserting a new node with value 100 at the head of the list, another one with 
value 200 between nodes of values 3 and 6, and removing the node of value 5.
Print out values to check.
100 -->8 --> 3 --> 200 --> 6 -->*/

//function to insert Node
void insertNode(Node *head, Node *priorNode, Node *newNode)
{
    //insert at the beginning if priorNode is NULL
    if(priorNode->prev == NULL)
    {
        std::cout << "test case" << std::endl;
        newNode->next = head;
        newNode->prev = NULL;
        priorNode->prev = newNode; //address of Pre attribute of priorNode = address of NewNode
    }
    else
    {
        //Connect next of newNode with priorNode
        newNode->next = priorNode;
        priorNode->prev->next = newNode; //address of Node after Newnode (next = address of NewNode) 
        priorNode->prev = newNode; //address of Pre attribute of priorNode = address of NewNode
    }
}


int main()
{
    //Create four nodes with values are 8, 5, 3, 6
    Node n1(8), n2(5), n3(3), n4(6);

    //Create head
    Node *head = &n1;

    //Connect nodes
    n1.next = &n2;
    n2.prev = &n1;

    n2.next = &n3;
    n3.prev = &n2;

    n3.next = &n4;
    n4.prev = &n3;

    //Create tail
    Node *tail = &n4;

    //Function to print value of connected nodes in forward
    forward(head);
    std::cout << "Test";

    //Function to print value of connected nodes in backward
    backward(tail);
    std::cout << "Test";

    //function to insert Node
    Node newNode1(100), newNode2(200);
    
    //case1: Insert newNode1(100) after n1(8)
    std::cout << "Insert newNode1(100) after n1(8): ";
    #if 0
    insertNode(head, &n1, &newNode1);
    forward(head);
    #endif
    return 0;
}