#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List
{
    Node* head;
    Node* tail;
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printLL(){
        if(head==NULL)
        {
            cout<<"Empty!\n";
        }
        else{
            Node* tmp=head;
            while(tmp!=NULL)
            {
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
            cout<<endl;
        }
    }
    int pop_front(){
        if(head==NULL)
        {
            cout<<"Empty!\n";
            return -1;
        }
        else
        {
            int tmp=head->data;
            head=head->next;
            return tmp;
        }
    }
    int pop_back(){
      if(head==NULL)
        {
            cout<<"Empty!\n";
            return -1;
        }
        else{
            int tmp1=tail->data;
            Node* tmp2=head;
            while(tmp2->next!=tail)
            {
                tmp2=tmp2->next;
            }
            delete tail;
            tail=tmp2;
            tail->next=NULL;
            return tmp1;
        }
    }

    void insert(int val,int pos)
    {
        Node* newNode=new Node(val);
        if(pos<0)
        {
            cout<<"Invalid position!\n";
        }
        else if(pos==0)
        {
            push_front(val);
        }
        else
        {
            Node* tmp=head;
            for(int i=0;i<pos-1;i++)
            {
                tmp=tmp->next;
            }
            newNode->next=tmp->next;
            tmp->next=newNode;
        }
    }
    int search(int val)
    {
        Node* tmp=head;
        int i=0;
        while(tmp->data!=val&&tmp->next!=NULL)
        {
            tmp=tmp->next;
            i++;
        }
        if(tmp->next==NULL)
        return -1;
        else
        return i;
    }
};

int main()
{
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.insert(5,2);
    cout<<ll.search(1)<<endl;
   // ll.pop_back();

    ll.printLL(); 
    return 0; 
}