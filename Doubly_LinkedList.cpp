#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;
        int size;

        // A constructor which will initialize data members with 0/NULL
        DoublyLinkedList()
        {
            head = tail = NULL;
            size=0;
        }
        // This function will help the user top insert at the end or tail.
        void InsertAtEnd(int data)
        {
            Node* temp = new Node(data);
            if(size==0) 
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;  
                tail = temp;
            }
            size++;
        }

        // This function will help the user top insert at the start or head.
        void InsertAtStart(int data)
        {
            Node* temp = new Node(data);
            if(size==0)
            {
            head = tail = temp;
            }
            else
            {
                temp->next = head;
                head->prev = temp;
                head = temp; 
            }
            size++;
            return;
        }
        
        void InsertAtIndex(int idx,int data)
        {
            Node* temp = head;
            Node* insert = new Node(data);
            if(idx>size || idx<0)
            {
                cout<<"Cannot insert index out of bound !!"<<endl;
                return;
            }
            else if(idx==0) InsertAtStart(data);
            else if(idx==size) InsertAtEnd(data);
            else 
            {
                int mdx = 0;
                while(mdx!=idx-1)
                {
                    temp = temp->next;
                    mdx++;
                }
                insert->next = temp->next;
                temp->next = insert;
                insert->next->prev = insert;
                insert->prev = temp;
                size++;
            }
        }

        int getAtIdx(int idx)
        {
            if(idx<0 || idx>=size) 
            {
                cout<<"Invalid index !";
                return -1;
            }
            else if(idx==0) return head->val;
            else if(idx==size-1) return tail->val;
            else 
            {
                Node* temp = head;
                for(int i=0; i<idx; i++) temp = temp->next;
                return temp->val;
            }
        }

        void DeleteAthead()
        {
            if(size<=0) cout<<"Linked List is Empty "<<endl;
            else if(size >1)
            {
                head = head->next;
                head->prev = NULL;// Extra
                size--;
            }
            else head = tail = NULL;

        }

        void DeleteAtEnd()
        {
            if (size==0)
            {
            cout<<"List is Empty!";
            return;
            }
            Node* temp = head;
            while (temp->next!=tail)
            {
            temp = temp->next;
            }
            temp->next = NULL;
            tail->prev = NULL;
            tail = temp;
            size--;
        }
        void DeleteAtIdx(int idx)
        {
            if(size== 0) cout<<"Linked List is Empty "<<endl;
            else if(idx<0 || idx>=size) cout<<"Invalid index \n";
            else if(idx==1) DeleteAthead();
            else if(idx==size-1) DeleteAtEnd();
            else 
            {
                Node* temp = head;
                for(int i=0;i<idx-1;i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }


        }

        void Display()
        {
            Node* temp = head;
            while(temp!=NULL)
            {
                cout<<temp->val<<"  ";
                temp = temp->next;
            }
            cout<<endl;
        }
        
        void Dispaly_from_Back()
        {
            Node* last = tail;
            while(last!=NULL)
            {
                cout<<last->val<<"  ";
                last = last->prev;
            }
            cout<<endl;
            return;
        }
};


int main()
{
    DoublyLinkedList* ll= new DoublyLinkedList();
    ll->InsertAtStart(30);
    ll->InsertAtStart(20);
    ll->InsertAtStart(10);
    ll->InsertAtIndex(1,100);
    ll->Display();
    //ll-> Dispaly_from_Back();
    ll->DeleteAtEnd();
    ll->Display();
    ll-> Dispaly_from_Back();

}
