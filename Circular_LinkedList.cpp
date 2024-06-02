#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};


class LinkedList{
    public:
        Node* head;
        Node* tail;
        int size;

        // A constructor which will initialize data members with 0/NULL
        LinkedList()
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
                tail = temp;
            }
            // Make the last node point to the head to form a circular list
            tail->next = head;
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
                temp->next=head;
                head = temp;
            }
            // Make the last node point to the head to form a circular list
            tail->next = head;
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
                insert->next= temp->next;
                temp->next = insert;
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
                size--;
                tail->next = head;
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
            temp->next = head;
            tail = temp;
            size--;
        }
        void DeleteAtIdx(int idx)
        {
            if(size== 0) cout<<"Linked List is Empty "<<endl;
            else if(idx<0 || idx>=size) cout<<"Invalid index \n";
            else if(idx==0) DeleteAthead();
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
            while(temp->next!=head)
            {
                cout<<temp->val<<"  ";
                temp = temp->next;
            }
            cout<<temp->val;
            cout<<endl;
        }
       
};
int main()
{
    LinkedList ll;
    int choice,n,idx;
    do{
        cout<<"Press 1 for insert at end "<<endl;
        cout<<"Press 2 for insert at start "<<endl;
        cout<<"Press 3 for insert at at index "<<endl;
        cout<<"Press 4 for Display "<<endl;
        cout<<"Press 5 for printing the element at specific index "<<endl;
        cout<<"Press 6 for Delete at start "<<endl;
        cout<<"Press 7 for Delete at end "<<endl;
        cout<<"Press 8 for Delete at specific index "<<endl;
        cout<<"Press 0 to end the program "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"Enter the number : ";
                    cin>>n;
                    ll.InsertAtEnd(n);
                    break;
            case 2: cout<<"Enter the number : ";
                    cin>>n;
                    ll.InsertAtStart(n);
                    break;
            case 3: cout<<"Enter the number : ";
                    cin>>n;
                    cout<<"\nEnter the index : ";
                    cin>>idx;
                    ll.InsertAtIndex(idx,n);
                    break;
            case 4: ll.Display();
                    break;
            case 5: cout<<"\nEnter the index : ";
                    cin>>idx;
                    cout<<ll.getAtIdx(idx)<<endl;
                    break;
            case 6: ll.DeleteAthead();
                    break;
            case 7: ll.DeleteAtEnd();
                    break;
            case 8: cout<<"\nEnter the index : ";
                    cin>>idx;
                    ll.DeleteAtIdx(idx);
                    break;

        }
    }while(choice!=0);
}
