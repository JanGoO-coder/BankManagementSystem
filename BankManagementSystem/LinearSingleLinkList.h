#include <iostream>
using namespace std;

template<class T> class Node {
public:
    T info; Node<T>* next;
    Node() { info = 0; next = 0; }
    Node(T val) { info = val; next = 0; }
};

template<class T> class LSLL {
public:
    Node<T>* head;
    LSLL() { head = 0; }
    void insertAtHead(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == 0)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtTail(T val) {
        if (head == 0)
            insertAtHead(val);
        else {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* temp = head;
            while (temp->next != 0)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void insertBefore(T val, T key) {
        bool check = false;
        Node<T>* temp = head;
        if (head == 0)
            cout << "Key Not Found. (Linear Single Link List is EMPTY)" << endl;
        else {
            if (head->info == key) {
                insertAtHead(val);
            }
            else {
                while (true) {
                    if (temp->next->info == key) {
                        Node<T>* newNode = new Node<T>(val);
                        newNode->next = temp->next;
                        temp->next = newNode; check = true;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }

        check ? cout << "" : cout << "Key Not Found!" << endl;
    }
    void insertAfter(T val, T key) {
        bool check = false;
        Node<T>* temp = head;
        if (head == 0)
            cout << "Key Not Found. (Linear Single Link List is EMPTY)" << endl;
        else {
            while (true) {
                if (temp->info == key) {
                    if (temp->next == 0)
                        insertAtTail(val);
                    else {
                        Node<T>* newNode = new Node<T>(val);
                        newNode->next = temp->next;
                        temp->next = newNode;
                    }
                    check = true;
                    break;
                }
                temp = temp->next;
            }
        }

        check ? cout << "" : cout << "Key Not Found!" << endl;
    }
    void removeAtHead() {
        Node<T>* temp = head;
        if (head == 0)
            cout << "Key Not Found. (Linear Single Link List is EMPTY)" << endl;
        else if (head->next == 0)
            head = 0;
        else {
            head = temp->next;
            temp->next = 0;
            temp = 0;
        }
    }
    void removeAtTail() {
        Node<T>* temp = head;
        if (head == 0)
            cout << "Linear Single Link List is Empty" << endl;
        else if (head->next == 0)
            head = 0;
        else {
            while (temp->next->next != 0)
                temp = temp->next;
            temp->next = 0;
        }
    }
    void removeBefore(T key) {
        bool check = false;
        Node<T>* temp = head;
        if (head == 0)
            cout << "Key Not Found. (Linear Single Link List is EMPTY)" << endl;
        else {
            if (head->info == key) {
                cout << "Nothing before " << head->info << " to remove" << endl;
                check = true;
            }
            else if (head->next->info == key) {
                removeAtHead();
                check = true;
            }
            else {
                while (true) {
                    if (temp->next->next->info == key) {
                        temp->next = temp->next->next; break; check = true;
                    }
                    temp = temp->next;
                }
            }
        }

        check ? cout << "" : cout << "Key Not Found!" << endl;
    }
    void removeAfter(T key) {
        bool check = false;
        Node<T>* temp = head;
        if (head == 0)
            cout << "Linear Single Link List is Empty" << endl;
        else {
            while (true) {
                if (temp->info == key) {
                    if (temp->next == 0) {
                        cout << "Nothing To Remove After " << temp->info << endl;
                    }
                    else {
                        temp->next = temp->next->next;
                    }
                    check = true;
                    break;
                }
                temp = temp->next;
            }
        }

        check ? cout << "" : cout << "Key Not Found!" << endl;
    }
    void displayList() {
        Node<T>* temp = head;
        if (head == 0)
            cout << "Linear Single Link List is Empty" << endl;
        else {
            while (temp != 0) {
                cout << " " << temp->info; temp = temp->next;
            }
        }
    }
};