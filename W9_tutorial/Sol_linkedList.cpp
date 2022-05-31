#include <iostream>
#include <iomanip>
using std::cout;


/*
* CLASS DECLARATION
*/
class Node {
public:
    int value;
    Node *next = NULL; //by default points to nothing
    Node *prev = NULL; //by default points to nothing

public:
    Node(){}
    Node(int value){this->value = value;}

    //method to set connections to other nodes
    void setLinks(Node *prev, Node *next){
        this->next = next;
        this->prev = prev;
    }

    //function to link to the next node
    void linkNextNode(Node *next)
    {
        this->next = next;
        if(next != NULL)
        {
            next->prev = this;
        }
    }

    //function to link the previous node
    void linkPrevNode(Node *prev)
    {
        this->prev = prev;
        if(prev != NULL)
        {
            prev->next = this;
        }
    }

};



/*
* FUNCTIONS TO SHOW LINKS
*/
void showFordLinks(Node *head){
    cout << "Forward links : ";
    Node *temp = head; //temp is the current node
    while (temp != NULL){
        cout << std::setw(3) << temp->value  << " -> "; //value of current node
        temp = temp->next; //go the next node
    }
    cout << "\n";
}

void showBackwLinks(Node *tail){
    cout << "Backward links: ";
    Node *temp = tail; //temp is the current node
    while (temp != NULL){
        cout << std::setw(3) << temp->value << " -> "; //value of current node
        temp = temp->prev; //go the next node
    }
    cout << "\n";
}


void showLinks(Node *head, Node *tail){
    showFordLinks(head);
    showBackwLinks(tail);
}



/*
* FUNCTION TO INSERT NODE
*/
//Note: *& is pass-by-reference for the pointer variable
//(same as pass-by-reference for a normal data type)

void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode){
    if (priorNode != NULL) {
        //Connect newNode to the node after the priorNode
        newNode->linkNextNode(priorNode->next);

        //Connect priorNode to the newNode
        priorNode->linkNextNode(newNode);

        //Update the tail if insert at the tail
        if (priorNode == tailNode) {
            tailNode = newNode;
        }

    } else { //Replace the head
        //Connect newNode to the current head
        newNode->linkNextNode(headNode);

        //the newNode become the new head
        headNode = newNode;
    }
}

//DeleteNode
void DeleteNode(Node *&head, Node *&tail, Node *nodeDelete)
{

    if(nodeDelete->prev == NULL)// node is head
    {
        std::cout << "Head case" << std::endl;
        head = nodeDelete->next;
    }
    else if(nodeDelete->next == NULL) //node is tail 
    {
        std::cout << "Tail case" << std::endl;
        (nodeDelete->prev)->next = NULL;
        tail = nodeDelete->prev;

    }
    else //Node != head & tail
    {
        std::cout << "Delete elements not hail and tail\n";
        (nodeDelete->prev)->linkNextNode(nodeDelete->next);
        (nodeDelete->next)->linkPrevNode(nodeDelete->prev);
    }
}

//Function to Swap Nodes
void swapNodes(Node *&headNode, Node *&tailNode, Node *nodeA, Node *nodeB)
{
    //store all values of NodeB in a temp
    Node temp = *nodeB;

    //A stands before B --> after swapping, A will stand after
    if(nodeB->prev == nodeA)
    {
        nodeB->linkPrevNode(nodeA->prev);
        nodeB->linkNextNode(nodeA);
        nodeA->linkNextNode(temp.next);
    }

    //A stands after B --> after swapping, A will stand before B
    else if(nodeB->next == nodeA)
    {
        nodeB->linkNextNode(nodeA->next);
        nodeB->linkPrevNode(nodeA);
        nodeA->linkPrevNode(temp.prev);
    }

    //Normal case
    else
    {
        nodeB->linkPrevNode(nodeA->prev);
        nodeB->linkNextNode(nodeA->next);
        nodeA->linkPrevNode(temp.prev);
        nodeA->linkNextNode(temp.next);
    }

    //Update the head and the tail if A or B is head/tail
    headNode = (headNode == nodeA) ? nodeB :
               (headNode == nodeB) ? nodeA : headNode;

    tailNode = (tailNode == nodeA) ? nodeB:
               (tailNode == nodeB) ? nodeA : tailNode;

}

//Function to sort using Bubble Sort(ASCENDING: left < right)
void sortNodesAcend(Node *&headNode, Node *&tailNode)
{
    while(1)
    {
        int swap = 0;
        //Loop to go from the left(beginning)
        for(Node *left = headNode; left != NULL && left != tailNode;)
        {
            //compare with the next element and swap if not in correct order
            if(left->value > left->next->value)
            {
                swapNodes(headNode, tailNode, left, left->next);
                swap = 1;
            }
            else
            {
                left = left->next;
            }
        }
        
        if(swap == 0)
            break;
    }
}


int main()
{
    Node node1(8), node2(5), node3(3), node4(6);

    //Connect nodes
    Node *head = &node1;   //head is a pointer variable
    node1.linkNextNode(&node2);
    node2.linkNextNode(&node3);
    node3.linkNextNode(&node4);

    Node *tail = &node4;

    //show connections
    cout << "Original linked list: \n";
    showLinks(head, tail);

    //Test delete
    cout << "\nTest Delete: \n";
    DeleteNode(head,tail, &node4);
    showLinks(head, tail);

    // Qb)
    // Test insert node in the middle
    cout << "\nInsert 200 after 3: \n";
    Node newNode1(200);
    insertNode(head, tail, &node3, &newNode1);
    showLinks(head, tail);

    //Test replace the head
    cout << "\nInsert 100 at the head: \n";
    Node newNode2(100);
    insertNode(head, tail, NULL, &newNode2);
    showLinks(head, tail);

    //Qc Swap Nodes
    cout << "\nTest Swapping: \n";
    swapNodes(head, tail, &node2, &node3);
    showLinks(head, tail);

    //Bubble Sort
    sortNodesAcend(head, tail);
    showLinks(head, tail);

    //Test delete
    cout << "\nTest Delete: \n";
    DeleteNode(head,tail, &node2);
    showLinks(head, tail);

    return 0;
}
