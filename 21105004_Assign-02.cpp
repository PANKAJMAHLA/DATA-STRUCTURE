//Pankaj Kumar 21105004 ECE 2nd Year
//Question1


//creating a basic circular linked list
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    //Calling Node constructor
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

//Function to insert a node at the end of linked list
void append(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){head=new_node;new_node->next=head;return;}
    while(temp->next!=head){temp=temp->next;} //This condition establishes that the traversing element(temp) has reached the first element
    temp->next=new_node;
    new_node->next=head;
}

void pfun(Node*&head){
    Node*temp=head;
    do{cout<<temp->data<<"->";temp=temp->next;}
    while(temp!=head);
}
//*****************************************************************************
int main(){
    Node*head=NULL;
    append(head,1);
    append(head,2);
    append(head,3);
    pfun(head);
}

//Question 2
/*What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
Practical applications of circular linked list are :
1)Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
2)Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.
3)Fionacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.
4)Computer Networking:Circular linked list is also used in computer networking for token scheduling.
5)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.
6)Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one copmlete audio list finishes playing in music player then it again starts playing from start.
*/
