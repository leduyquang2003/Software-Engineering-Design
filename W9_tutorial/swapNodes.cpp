#include <iostream>

class Node
{
    public:
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

void swapNodes(Node *&head, Node *&tail,Node *nodeA, Node *nodeB)
{
    std::cout << "Can swap!\n";

    #if 1
    if(nodeA->next == nodeB) // Two Nodes are adjacent
    {
        std::cout << "Two Nodes are adjacent\n";
        Node temp = *nodeA;

        nodeA->next = nodeB->next;
        (nodeB->next)->prev = nodeA;

        nodeA->prev = nodeB;
        (temp.prev)->next = nodeB;

        nodeB->next = nodeA;
        nodeB->prev = temp.prev;
        
    }
    else if(nodeB->next == nodeA)
    {
        std::cout << "Two Nodes are adjacent\n";
        Node temp = *nodeB;

        nodeB->next = nodeA->next;
        (nodeA->next)->prev = nodeB;

        nodeB->prev = nodeA;
        (temp.prev)->next = nodeA;

        nodeA->next = nodeB;
        nodeA->prev = temp.prev;
    }
    else if(nodeA->prev == NULL && nodeB->next != NULL) // Case switching with head (A is head)
    {
        std::cout << "Case switching with head\n";
        Node temp = *nodeA;

        nodeA->next = nodeB->next;
        (nodeB->next)->prev = nodeA;

        nodeA->prev = nodeB->prev;
        (nodeB->prev)->next = nodeA;

        nodeB->next = temp.next;
        (temp.next)->prev = nodeB;
        
        nodeB->prev = NULL;
        head = nodeB;
    }
    else if(nodeA->prev == NULL && nodeB->next == NULL) // Case switching head with tail
    {
        std::cout << "Case switching head with tail\n";
        Node temp = *nodeA;

        nodeA->next = NULL;
        nodeA->prev = nodeB->prev;
        (nodeB->prev)->next = nodeA;
    
        nodeB->prev = NULL;
        nodeB->next = temp.next;
        (temp.next)->prev = nodeB;

        head = nodeB;
        tail = nodeA;

    }
    else if(nodeA->next == NULL && nodeB->prev == NULL) // Case switching tail with head
    {
        std::cout << "Case switching tail with head\n";
        Node temp = *nodeB;

        nodeB->next = NULL;
        nodeB->prev = nodeA->prev;
        (nodeA->prev)->next = nodeB;
    
        nodeA->prev = NULL;
        nodeA->next = temp.next;
        (temp.next)->prev = nodeA;

        head = nodeA;
        tail = nodeB;
    }
    else if(nodeB->prev == NULL && nodeA->next != NULL) // Case switching with head (B is head)
    {
        std::cout << "Case switching with head\n";
        Node temp = *nodeB;

        nodeB->next = nodeA->next;
        (nodeA->next)->prev = nodeB;

        nodeB->prev = nodeA->prev;
        (nodeB->prev)->next = nodeB;

        nodeA->next = temp.next;
        (temp.next)->prev = nodeB;
        
        nodeA->prev = NULL;
        head = nodeA;
    }
    else if(nodeA->next == NULL) //case switching with tail (A is head)
    {
        std::cout << "Case switching with tail\n";
        Node temp = *nodeA;

        nodeA->next = nodeB->next;
        (nodeB->next)->prev = nodeA;

        nodeA->prev = nodeB->prev;
        (nodeB->prev)->next = nodeA;

        nodeB->next = NULL;

        nodeB->prev = temp.prev;
        (temp.prev)->next = nodeB;


        tail = nodeB;
    }
    else if(nodeB->next == NULL) //case switching with tail (B is head)
    {
        std::cout << "Case switching with tail\n";
        Node temp = *nodeB;

        nodeB->next = nodeA->next;
        (nodeA->next)->prev = nodeB;

        nodeB->prev = nodeA->prev;
        (nodeA->prev)->next = nodeB;

        nodeA->next = NULL;

        nodeA->prev = temp.prev;
        (temp.prev)->next = nodeA;


        tail = nodeA;
    }
    else //case 2 if two nodes are not adjacent
    {
        Node temp = *nodeA;

        nodeA->next = nodeB->next;
        (nodeB->next)->prev = nodeA;

        nodeA->prev = nodeB->prev;
        (nodeB->prev)->next = nodeA;

        nodeB->next = temp.next;
        (temp.next)->prev = nodeB;

        nodeB->prev = temp.prev;
        (temp.prev)->next = nodeB;
    }
    #endif
}

//InsertNode with given prior Node
void InsertNode (Node *&head, Node *&tail, Node *priorNode, Node *newNode)
{
    //case swap with head determine by priorNode
    if(priorNode == NULL)
    {
        std::cout << "Head case" << std::endl;
        newNode->next = head;
        head->prev = newNode;

        head = newNode;        
    }
    else if(priorNode->next == NULL)
    {
        std::cout << "Tail case" << std::endl;
        priorNode->next = newNode;
        newNode->next = NULL;
        newNode->prev = priorNode;

        tail = newNode;
    }
    else
    {
        //case swap not with head and tail
        newNode->next = priorNode->next;
        (priorNode->next)->prev = newNode;

        newNode->prev = priorNode;
        priorNode->next = newNode;
    }
}

void DeleteNode(Node *&head, Node *&tail, Node *nodeDelete)
{

    if(nodeDelete->prev == NULL)// headcase
    {
        std::cout << "Head case" << std::endl;
        head = nodeDelete->next;
    }
    else if(nodeDelete->next == NULL) //tail case
    {
        std::cout << "Tail case" << std::endl;
        (tail->prev)->next = NULL;
        tail = nodeDelete->prev;

    }
    else //delete elements
    {
        std::cout << "Delete elements not hail and tail\n";
        (nodeDelete->prev)->next = nodeDelete->next;
        (nodeDelete->next)->prev = nodeDelete;
    }
}

int main()
{
    Node node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
    
    //Connect nodes
    Node *head = &node1; //create head
    node1.setLinks(NULL, &node2);
    node2.setLinks(&node1, &node3);
    node3.setLinks(&node2, &node4);
    node4.setLinks(&node3, &node5);
    node5.setLinks(&node4, &node6);
    node6.setLinks(&node5, &node7);
    node7.setLinks(&node6, NULL);
    Node *tail = &node7; //create tail
    showFordLinks(head);

    //swapNodes(head, tail, &node3, &node2);

    Node newNode(30);
    //InsertNode(head, tail, &node7, &newNode);
    DeleteNode(head, tail, &node5);
    showFordLinks(head);


    return 0;
}