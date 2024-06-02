#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
public:
    Node* head;
    Node* tail;
    int size;

    Stack() {
        head = tail = NULL;
        size = 0;
    }

    void Push(int data) {
        Node* temp = new Node(data);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void Pop() {
        if (size == 0) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        cout << tail->val << " is popped out " << endl;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void DisplayReverse(Node* node) {
        if (node == NULL) {
            return;
        }
        DisplayReverse(node->next);
        cout << node->val << " ";
    }

    void Display() {
        DisplayReverse(head);
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, n;
    do {
        cout << "Press 1 for Push " << endl;
        cout << "Press 2 for Pop " << endl;
        cout << "Press 3 Display " << endl;
        cout << "Press 0 to end the program " << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the number: ";
            cin >> n;
            s.Push(n);
            break;
        case 2:
            s.Pop();
            break;
        case 3:
            s.Display();
            break;
        default:
            if (choice != 0) {
                cout << "Please Enter a valid input." << endl;
            }
            break;
        }
    } while (choice != 0);
    return 0;
}
