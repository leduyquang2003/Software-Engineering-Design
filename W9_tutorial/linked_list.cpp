/*Define a class namely Node with three attributes are value (int), next (pointer to the next 
linked node), prev (pointer to the previous linked node), and provide class constructors to 
initialize value.*/

#include <iostream>
#include <string>

class Node
{
    private:
        int value;
        Node *next;
        Node *prev;

    public:
        Node(){}
        Node(int value){this->value = value;};

        //method to set connections to other nodes
        void setLinks(Node *prev, Node *next)
        {
            this->prev = prev;
            this->next = next;
        }

        friend void showFordLinks(Node *head);
        friend void showBackLinks(Node *tail);
        friend void insertNode(Node *&head, Node *priorNode, Node *newNode);
        friend void swapNodes(Node *nodeA, Node *nodeB);
        friend void BubbleSort(Node *head);
        friend void my_swap_value(Node *node1, Node *node2);
        friend int sizeOfLinkedList(Node *head);

};

void showFordLinks(Node *head)
{   
    Node *temp = head; //temp is current node
    while(temp != NULL)
    {
        std::cout << temp->value << "--> "; //print out value of current node
        temp = temp->next; //go to the next node
    }
    std::cout << "\n\n";
}

void showBackLinks(Node *tail)
{   
    Node *temp = tail; //temp is current node
    while(temp != NULL)
    {
        std::cout << temp->value << "--> "; //print out value of current node
        temp = temp->prev; //go to the next node
    }
    std::cout << "\n\n";
}

void insertNode(Node *&head, Node *priorNode, Node *newNode)
{
    if(priorNode != NULL)
    {
        //Connect newNode to the node after the priorNode
        newNode->next = priorNode->next;
        if(priorNode->next != NULL)
        {
            (priorNode->next)->prev = newNode; 
        }

        //Connect priorNode to the newNode
        priorNode->next = newNode;
        newNode->prev = priorNode;
    }
    else //Replace the head
    {
        //Connect newNode to the current head
        newNode->next = head;
        head->prev = newNode;

        //the newNode become the new head
        head = newNode;

    }
}


//function to swap two Nodes
void swapNodes(Node *nodeA, Node *nodeB)
{
    //case two nodes next to each other
    if(nodeA->next == nodeB)
    {
        Node temp = *nodeB;

        nodeB->prev = nodeA->prev;
        nodeB->next = nodeA->next;

        nodeA->next = temp.next;
        nodeA->prev = nodeB->next;     

    }
    else
    {
        //store all value of nodeB
        Node temp = *nodeB;

        //connect nodeB to the node after nodeA
        nodeB->next = nodeA->next;
        if(nodeA->next != NULL)
        {
            (nodeA->next)->prev = nodeB;
        } 
        //connect nodeB to the node before NodeA
        nodeB->prev = nodeA->prev;
        if(nodeA->prev != NULL)
        {
            (nodeA->prev)->next = nodeB;
        }


        //connect nodeA to the node after nodeB
        nodeA->next = temp.next;
        if(temp.next != NULL)
        {
            (temp.next)->prev = nodeA;
        } 
        //connect nodeA to the node before NodeB
        nodeA->prev = temp.prev;
        if(temp.prev != NULL)
        {
            (temp.prev)->next = nodeA;
        } 
    }

}

void my_swap_value (Node *node1, Node *node2)
{
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

int sizeOfLinkedList(Node *head)
{
    int size = 0;
    Node *temp = head; //temp is current node
    while(temp != NULL)
    {
        temp = temp->next; //go to the next node
        size++;
    }
    return size;
}

void BubbleSort(Node *head)
{
    int swapped = 0; 
    Node *left; // left pointer will always point to the start of the list
    Node *right = NULL; // right pointer will always point to the end of the list
    do
    {
        left = head;
        while(left->next != right)
        {
            if(left->value > (left->next)->value)
            {
                my_swap_value(left, left->next);
            }
            left = left->next;
        }
        //as the largest element is at the end of the list, assign that to right as there is no need to check
        swapped++;
        right = left;
    } while(swapped < sizeOfLinkedList(head));

}

int main()
{
    /*a) Create four nodes with values are 8, 5, 3, 6. Create a doubly linked list by connect 
them together in sequence.
Write two functions to print out values of connected nodes in forward and backward
orders.*/
    Node node1(8), node2(5), node3(3), node4(6), node5(0);

    //Connect nodes
    Node *head = &node1; //create head
    node1.setLinks(NULL, &node2);
    node2.setLinks(&node1, &node3);
    node3.setLinks(&node2, &node4);
    node4.setLinks(&node3, &node5);
    node5.setLinks(&node4, NULL);
    Node *tail = &node5; //create tail

    //show connections
    std::cout << "Show forward: ";
    showFordLinks(head);
    std::cout << "Show backward: ";
    showBackLinks(tail);

    #if 0
    //Test InsertNode function
    // Node newNode(10);
    // insertNode(head, &node2, &newNode);
    // showFordLinks(head);

    //Test replace the head
    Node newNode2(100);
    insertNode(head, NULL, &newNode2);
    showFordLinks(head);
    #endif

    #if 0
    //QC swap Nodes
    // std::cout << "swap node1(8) and node2(3)" << std::endl;
    swapNodes(&node4, &newNode2);
    showFordLinks(head);
    #endif

    int array[] = {4, 8, 3, 5, 0};
    int size = 5;
    
    #if 0
    //Bubble sort
    for(int i = size - 1; i >= 0; i--) //loop to assgin correct values from the last to the first element
    {
        for(int j  = 0; j <= i - 1; j++) //loop to go from the left
        {
            //compare two next elements and swap
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    #endif
    //Bubble Sort (swap by value)
    std::cout << "Bubbe Sort (swap by value): ";
    BubbleSort(head);
    showFordLinks(head);

    return 0;
}