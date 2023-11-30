#include <iostream>
#include "data_structures.h"

using namespace std;

int main(){
    List<int> list;
    Stack<int> stack;
    Queue<int> queue;

    for(int i=0;i<20;i++){
    list.inFirst(i);
    }

    cout<<"List elements:"<<endl;
    for(Node<int>* ini=list.begin(); ini!=list.end(); ini=ini->nn){
        cout<<ini->data<<" ";
    }


        cout<<endl<<"List elements:"<<endl;
    for(Node<int>* ini=list.begin(); ini!=list.end(); ini=ini->nn){
        cout<<ini->data<<" ";
    }

    stack.push(2);
    stack.push(4);
    stack.push(10);

    cout<<endl<<"Stack elements:";
    cout<<stack.pop()<<" "<<stack.pop();
    cout<<endl;
    
    queue.enqueue(3);
    queue.enqueue(6);
    queue.enqueue(16);
    cout<<"Queue elements: "<<endl<<queue.dequeue()<<" "<<queue.dequeue()<<endl;


    return 0;
}