#include <iostream>
#include "data_structures.h"

using namespace std;

int main(){
    List<int> list;
    Stack<int> stack;

    for(int i=0;i<20;i++){
    list.inFirst(i);
    }

    cout<<"List elements:"<<endl;
    for(Node<int>* ini=list.begin(); ini!=list.end(); ini=ini->nn){
        cout<<ini->data<<" ";
    }

    for(int i=list.getsize()-1; i<=0;i--){
        list.deleteitem(i);
    }

        cout<<"List elements:"<<endl;
    for(Node<int>* ini=list.begin(); ini!=list.end(); ini=ini->nn){
        cout<<ini->data<<" ";
    }



    return 0;
}