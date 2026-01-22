#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode; // Tail must always point to the new head
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        if (head == tail)
        { // Single node case
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *tmp = head;
        while (tmp->next != tail)
        {
            tmp = tmp->next;
        }
        Node *toDelete = tail;
        tail = tmp;
        tail->next = head;
        delete toDelete;
    }

    void pop(int val)
    {
        if (head == NULL)
            return;

        if (head->data == val)
        {
            pop_front();
            return;
        }

        Node *curr = head;
        Node *prev = NULL;
        do
        {
            prev = curr;
            curr = curr->next;

            if (curr->data == val)
            {
                if (curr == tail)
                {
                    pop_back();
                    return;
                }
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main()

{

    CircularList cll;

    cll.push_front(1);

    cll.push_front(2);

    cll.push_front(3);

    cll.push_back(4);

    cll.pop(3);

    cll.print();

    return 0;
}