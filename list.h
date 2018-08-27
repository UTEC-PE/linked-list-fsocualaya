#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    public:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List(){
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
        };

        T front(){
            if(head)
                return this->head->data;
            else
                return -1;
        };

        T back(){
            if(tail)
                return this->tail->data;
            else
                return -1;
        };

		void push_front(T value) {
		    auto* node = new Node<T>;
            node->data = value;
            node->next = this->head;
            if(!head){
                this->tail = node;
            }
            this->head = node;
            (this->nodes)++;
		};
        void push_back(T value){
            auto* node = new Node<T>;
            node->data = value;
            if(!head){
                this->head = node;
            }
            this->tail=node;
            (this->nodes)++;
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

        ~List()=default;
};
#endif
