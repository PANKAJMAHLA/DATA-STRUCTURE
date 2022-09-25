// Pankaj Kumar 21105004 ECE 2nd Year

#include <iostream>
using namespace std;

// creating the node class
class Node
{
public:
    // Creating class objects
    string name;
    int age;
    Node *next; // A node pointer for next node
    Node *prev; // A node pointer for previous node
    // calling constructor
    Node(string name, int age)
    {
        this->name = name;
        this->age = age;
        next = NULL; // initialize next as NULL
        prev = NULL; // initialize prev as NULL
    }
};

void append(Node *&head, string name, int age)
{
    // Creating the node pointer and storing address of head in temp
    Node *temp = head;
    // creating the new node and storing name and age in it
    Node *new_node = new Node(name, age);
    // Inserting the node in an empty list
    if (temp == NULL)
    {
        head = new_node;
    }
    // Inserting node in non empty list
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertAtHead(Node *&head, string name, int age)
{
    // Creating a Node pointer and storing address of new node in it
    Node *new_node = new Node(name, age);
    // Inserting new node at head
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void displayFromStart(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[Name:" << temp->name << " Age:" << temp->age << "]"
             << "<=>";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *&head, int i)
{
    if (i == 0)
    {
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

// Function to delete the last element
void deleteEnd(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

int main()
{
    // Initialize an empty linked list
    Node *head = NULL;
    int noOfFamilyMem;
    // Taking no of family member as input
    cout << "Enter Number Of Family Members:";
    cin >> noOfFamilyMem;
    // Inserting the family member details in the doubly linked list
    for (int i = 1; i <= noOfFamilyMem; i++)
    {
        string name;
        int age;
        cout << "Enter Family Member " << i << " Name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Family Member " << i << " Age:";
        cin >> age;
        // appending data name and age in doubly linked list
        append(head, name, age);
    }
    cout << endl;
    // Displaying Family details
    cout << "Doubly Linked list with my family members as elements is shown below:" << endl;
    cout << endl;
    displayFromStart(head);
}


/*BONUS QUESTION

Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
Ans. This can be done by sorting the doubly linked list in decending order according to age,
by doing so we will get a doubly linked list in which older generation people will be closer 
to head in double linked list and new generation people will be closer to tail in doubly linked list.
*/
