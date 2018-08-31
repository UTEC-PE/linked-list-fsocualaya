//
// Created by damin on 21/08/18.
//

#include <iostream>
#include "list.h"

using namespace std;

int main(){
    List<int> l,l2;
    l.print();
    l.push_back(5);
    l.push_front(6);
    l.push_back(7);
    l.pop_back();
    for(int i=8;i<15;i++){
        l.push_back(i);
    }
    cout<<"Head: "<<l.front()<<"\n"<<"Tail: "<<l.back()<<"\n"<<"Size: "<<l.size()<<"\n"<<l.empty()<<"\n";
    l.print();
    l.pop_front();cout<<"pop_front()\n";
    cout<<"Head: "<<l.front()<<"\n"<<"Size: "<<l.size()<<"\n";
    l.print();
    l.clear();
    l.print();
    return 0;
}
