#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List();

        int front(){
            return head->data;
        };
        int back(){
            return tail->data;
        };
        void push_front(T value) {
            Node* temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
            delete temp;
            nodes++;
        };
        void push_back(T value){
            Node* node = new Node;
            node->data = value;
            tail->next= node;
            tail = node;
            node->next= nullptr;
            nodes++;
        };
        void pop_front(){

            };

        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear(){
            if(head)
                head->killSelf();
            head = nullptr;
        };
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif
