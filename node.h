#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    void killSelf(){
        this->next=nullptr;
        this->data=NULL;
        delete this;
    };
};

#endif