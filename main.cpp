//
// Created by damin on 21/08/18.
//

#include <iostream>
#include "list.h"

using namespace std;

int main(){
    List<int> l;
    l.push_front(5);
    l.push_front(12);
    l.push_back(17);
    l.push_back(1532);
    cout<<l.front()<<"\n"<<l.back()<<"\n"<<l.nodes;
    return 0;
}
