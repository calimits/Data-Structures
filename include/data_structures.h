#include<iostream>

using std::cout;
using std::endl;

//Declaración de la clase Node------------------------------------------------------------------------------
template <class T>
class Node{
    public:
    T data;
    Node<T> * pn;
    Node<T> * nn;
};
//Fin de la declaración----------------------------------------------------------------------------------

//Declaración de la clase lista-----------------------------------------------------------------------------
template <class T>
class List{
    public:
    List();
    virtual ~List();
    void inLast(const T &);
    void inFirst(const T &);
    void insert(const T &, int);
    void deleteitem(int);
    T & get(int);
    T take(int);
    bool isempty();
    int getsize();
    Node<T> * begin();
    Node<T> * end();

    private:
    Node<T> * first;
    Node<T> * last;
    int size;
};
//Fin de la declaración de la clase lista---------------------------------------------------------------

//Implementación de la clase lista-----------------------------------------------------------------------------------------------
template <class T>
List<T>::List(){
    this->size=0;
    this->first=new Node<T>();
    this->last=new Node<T>();
    first->pn=0;
    first->nn=last;
    last->pn=first;
    last->nn=0;
}

template <class T>
void List<T>::inLast(const T & d){
    Node<T> * n=new Node<T>();
    n->data=d;

    //Enlazando node
    n->pn=last->pn;
    n->nn=last;

    //Enlazando alrededores
    last->pn->nn=n;
    last->pn=n;

    size++;
} 

template <class T>
void List<T>::inFirst(const T & d){
    Node<T> * n=new Node<T>();
    n->data=d;

    //Enlazando  node
    n->pn=first;
    n->nn=first->nn;

    //Enlazando alredores
    first->nn->pn=n;
    first->nn=n;

    size++;
}

template <class T>
void List<T>::insert(const T & d, int pos){
    if (pos>size || pos<0) throw "Position out of limits";

    Node<T> *n=new Node<T>();
    n->data=d;

    Node<T> *cn=new Node<T>();
    cn=first->nn;

    for(int i=0; i<pos; i++){
        cn=cn->nn;
    }

    //Enlazando nodo insertado
    n->pn=cn->pn;
    n->nn=cn;

    //Enlazando alrededores
    cn->pn->nn=n;
    cn->pn=n;
    size++;
}

template <class T>
void List<T>::deleteitem(int pos){
    if (pos>size || pos<0) throw "Position out of limits";

    Node<T> *cn=first->nn;
        for(int i=0; i<pos; i++){
        cn=cn->nn;
    }

    cn->nn->pn=cn->pn;
    cn->pn->nn=cn->nn;
    delete cn;

    size--;
}

template <class T>
T & List<T>::get(int pos){
    Node<T> *cn=first->nn;
    for(int i=0; i<pos; i++){
        cn=cn->nn;
    }

    return cn->data;

}

template <class T>
T List<T>::take(int pos){
    Node<T> *cn=first->nn;
    for(int i=0; i<pos; i++){
        cn=cn->nn;
    }

    T d=cn->data;
    cn->pn->nn=cn->nn;
    cn->nn->pn=cn->pn;
    size--;
    delete cn;
    return d;
}

template <class T>
bool List<T>::isempty(){
    return size==0;
}

template <class T>
int List<T>::getsize(){
    return size;
}

template <class T>
Node<T> * List<T>::begin(){
    return first->nn;
}

template <class T>
Node<T> * List<T>::end(){
    return last;
}

template <class T>
List<T>::~List(){
    Node<T> * cn=first->nn;
    while(size>0){
        cn=cn->nn;
        cout<<"Deleting "<<cn->pn->data<<endl;
        delete cn->pn;
        size--;
    }
    delete first;
    delete last;
}

template <class T>
class Stack : protected List<T> {
    public:
    Stack();
    ~Stack();
    void push(const T & d);
    T pop();
    T & top();
    Node<T> * begin();
    Node<T> * end();
};

template <class T>
Stack<T>::Stack() : List<T>(){}

template <class T>
Stack<T>::~Stack() {}

template <class T>
void Stack<T>::push(const T & d){
    this->inFirst(d);
}

template <class T>
T Stack<T>::pop(){
    return this->take(0);
}

template <class T>
T & Stack<T>::top(){
    return (this->get(this->getsize()-1));
}

template <class T>
Node<T> * Stack<T>::begin(){
    return List<T>::begin();
}

template <class T>
Node<T> * Stack<T>::end(){
    return List<T>::end();
}



