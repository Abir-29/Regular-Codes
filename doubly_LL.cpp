#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void print()
    {
        Node *tmp = head;
        cout << "Linked List: NULL <-> ";
        while (tmp != NULL)
        {
            cout << tmp->data << " <-> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty Linked-List!\n";
            return;
        }
        Node *temp=head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Empty Linked-List!\n";
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
};

int main()
{
    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_back(4);
    dll.pop_front();
    dll.pop_back();
    dll.print();
    return 0;
}