#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
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
            else {
                cout << "Can't reach head." << endl;
                return -1; // Mejor deberías retornar una excepción
            }
        };

        T back(){
            if(tail)
                return this->tail->data;
            else {
                cout << "Can't reach tail" << endl;
                return -1; // Mejor deberías retornar una excepción
            }
        };

		void push_front(T value) {
		    auto* node = new Node<T>;
            node->data = value;
            node->next = this->head;
            if(!(this->head)) {
                this->tail= node;
                this->tail->next = nullptr;
            }
            this->head = node;
            (this->nodes)++;
		};
        void push_back(T value){
            auto* node = new Node<T>;
            node->data = value;
            if(head){
                this->tail->next = node;
                this->tail = node;
            }
            else{
                this->head = node;
                this->tail = node;
            }
            node->next = nullptr;
            (this->nodes)++;
        };
        void pop_front(){
        	if(head){
        		cout<<"head exists"<<endl; // No es necesario imprimir
        		auto* temp = new Node<T>; // No es necesario dar new
        		temp = this->head;
        		this->head = this->head->next;
        		(this->nodes)--;
        		delete temp;
        	}
        	else{
        		cout<<"Can't pop_back(). It's empty!"<<endl;
        	}
        };

        void pop_back(){
        	if(head){
        		auto* temp = head;
        		cout<<"head exists"<<endl; // No es necesario imprimir
        		while(temp->next->next){
        			temp = temp->next;
        		}
        		this->tail = temp;
                delete tail->next;
                tail->next = nullptr;
                (this->nodes)--;
        	}
        	else{
        		cout<<"Can't pop_back(). It's empty!"<<endl;
        	}
        }

        T get(int position); // No se implementó
        void concat(List<T> &other){ // Falta igualar tail al nuevo tail
        	this->tail->next = other.head;
        	this->nodes+=other.nodes;
        };
        bool empty(){
            return (bool)(!this->size());
        };
        int size(){
            return this->nodes;
        };
        void print(){
            auto* temp = head;
            cout<<"{";
            while(temp){
                cout<<temp->data;
                if(temp->next)
                    cout<<", ";
                temp = temp->next;
            }
            cout<<"}\n";
        };
        void print_reverse(); // No se implementó
        void clear(){
            auto* temp = head;
            while(head) {
                head->killSelf();
                this->head=temp->next;
                temp = temp->next;
            }
            head = nullptr;
            // No estás igualando el contador de nodos a 0
        };
        Iterator<T> begin();
        Iterator<T> end();

        ~List()=default; // Deberías haber limpiado tu lista aquí
};
#endif
