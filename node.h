#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    void killSelf(){ // Así no es la función
        this->next=nullptr; // Estás borrando next, va a impedir que iteres
        this->data=NULL; // Data no puede ser null
        delete this;
    };
};

#endif