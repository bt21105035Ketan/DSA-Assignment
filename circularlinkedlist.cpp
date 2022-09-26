
/*  Ques1: While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?
    Ans: Let us assume that a node name 'Tail'(last element) of a circular linked list stores the address of node name 'Head'(first element), this means that when we 
    will be traversing the linked list and if the current node will point towards the 'Head', this will indicate that we have reached the first element.


    Ques2: What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
    Ans: Practical applications of circular linked list are :
    1) Round Robin scheduling techniques in games.
    2) Audio/Video streaming.
    3) Circular escalators.
    4) Browser cache which allows you to hit the Back button.

    Applications relted to my field:
    1) While using any software, we can undo the functionalityto go back to previous step.
    2) Implementation of advanced data structures like fibonacci heap.
*/

// An example of creating the circular linked list, inserting, deleting, printing it

#include <iostream>
using namespace std;
//Creating Node class
class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

//inserting element at the end
void push(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){head=new_node;new_node->next=head;return;}
    while(temp->next!=head){temp=temp->next;}   // *This condition states that the traversing element has reached the first element*
    temp->next=new_node;
    new_node->next=head;
}
 
// Function to print nodes in a given
// circular linked list
void printList(Node* head)
{
    Node* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
 
    cout << endl;
}

int main()
{
    // Initialize lists as empty
    Node* head = NULL;
 
    // Created linked list will be
    // 2->5->7->8->10
    push(head, 2);
    push(head, 5);
    push(head, 7);
    push(head, 8);
    push(head, 10);
 
    cout << "circular linked List: ";
    printList(head);
 
    return 0;
}

/* SID : 21105035
   Name : Ketan Mattoo
*/
