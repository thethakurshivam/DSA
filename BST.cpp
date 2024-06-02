#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    void insert(Node*& root, int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
        }
        if (data < root->data) {
            insert(root->left, data);
        } else if (data > root->data) {
            insert(root->right, data);
        }
    }

    Node* search(Node* root, int data) {
        if (root == nullptr || root->data == data) {
            return root;
        }
        if (data < root->data) {
            return search(root->left, data);
        } else {
            return search(root->right, data);
        }
    }

    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void deleteNode(Node*& root, int data) {
        if (root == nullptr) {
            return;
        }
        if (data < root->data) {
            deleteNode(root->left, data);
        } else if (data > root->data) {
            deleteNode(root->right, data);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                root = temp;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                deleteNode(root->right, temp->data);
            }
        }
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int data) {
        insert(root, data);
    }

    void search(int data) {
        if (search(root, data) != nullptr) {
            cout << "Value " << data << " found in the BST.\n";
        } else {
            cout << "Value " << data << " not found in the BST.\n";
        }
    }

    void deleteNode(int data) {
        deleteNode(root, data);
    }

    void display() {
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST bst;
    int choice, value;
    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display (In-order Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            bst.search(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            bst.deleteNode(value);
            break;
        case 4:
            cout << "In-order Traversal: ";
            bst.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
