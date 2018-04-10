#include "DataStructures.h"//
// Created by eduardo on 23/02/18.
//

#include <cstdlib>
#include <iostream>

using namespace std;

//***************************Node****************************

template <class T>
Node<T>::Node() {}

template <class T>
T Node<T>::getData() {

    return data;

}

template <class T>
Node<T>* Node<T>::getNext() {

    return next;

}

template <class T>
void Node<T>::setData(T newdata) {

    data = newdata;

}

template <class T>
void Node<T>::setNext(Node<T>* newnext) {

    next = newnext;

}

//***********************************************************

//*********************DoubleNode****************************

template <class T>
DoubleNode<T>::DoubleNode(){

}

template <class T>
T DoubleNode<T>::getData() {

    return data;

}

template <class T>
DoubleNode<T>* DoubleNode<T>::getNext() {

    return next;

}

template <class T>
DoubleNode<T>* DoubleNode<T>::getPrev() {

    return prev;

}

template <class T>
void DoubleNode<T>::setData(T newdata) {

    data = newdata;

}

template <class T>
void DoubleNode<T>::setNext(DoubleNode<T>* newnext) {

    next = newnext;

}

template <class T>
void DoubleNode<T>::setPrev(DoubleNode<T>* newprev) {

    prev = newprev;

}


//***********************************************************

//**********************SingleList***************************
template <class T>
SingleList<T>::SingleList() {root = NULL;}

template <class T>
int SingleList<T>::getLength() {

    return length;

}

template <class T>
Node<T>* SingleList<T>::getNode(int pos)  {
    Node<T> *temp;
    temp = root;

    int len = getLength();

    bool foo = pos >= len;

    if (foo) {

        std::cout << "Index out of range \n";
        return NULL;

    } else {
        while (pos != 0) {
            temp = temp->getNext();
            pos--;
        }
        return temp;
    }
}

template  <class T>
void SingleList<T>::newNode(T data) {

    Node<T> *temp = new Node<T>;
    temp->setData(data);
    temp->setNext(NULL);

    if(root == NULL){
        length++;

        root = temp;
        temp = NULL;

    }
    else{

        Node<T> *current = root;
        while(current->getNext()!= NULL){

            current = current->getNext();

        }

        length++;

        current->setNext(temp);
        temp = NULL;
        return;

    }


}

template <class T>
void SingleList<T>::insertFirst(T data) {

    Node<T> *temp = new Node<T>;
    temp->setNext(root);
    temp->setData(data);
    root = temp;
    temp = NULL;
    delete(temp);
    length++;
    return;

}

template <class T>
void SingleList<T>::insertNode(int pos, T data) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    Node<T> *current = getNode(pos-1);
    Node<T> *temp = new Node<T>;

    temp->setData(data);
    temp->setNext(getNode(pos));
    current->setNext(temp);

    length++;
    return;

}

template <class T>
void SingleList<T>::deleteLast() {

    if(root == NULL){

        return;

    }

    if(length == 1){

        delete(root);
        root = NULL;
        length--;
        return;

    }

    Node<T> *current;

    current = root;

    while(current->getNext()->getNext() != NULL){

        current = current->getNext();

    }
    length--;
    delete(current->getNext());
    current->setNext(NULL);
    return;

}

template <class T>
void SingleList<T>::deleteFirst() {
    if(root == NULL){

        return;

    }

    if(length == 1){

        delete(root);
        root = NULL;
        length--;
        return;

    }

    Node<T> *temp;
    temp = root->getNext();
    delete(root);
    root = temp;
    length--;
    return;


}

template <class T>
void SingleList<T>::deleteNode(int pos) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    if(pos == 0){

           deleteFirst();
           return;

        }

    Node<T> *current = getNode(pos-1);
    Node<T> *temp = getNode(pos);

    current->setNext(current->getNext()->getNext());
    delete(temp);
    length--;
    return;

}

template <class T>
void SingleList<T>::editNode(int pos, T data) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    getNode(pos)->setData(data);
    return;
}

template <class T>
std::string SingleList<T>::show() {

    string txt =  "[";

    for(int i = 0; i < getLength()-1; i++){

        txt.append(to_string(getNode(i)->getData()));
        txt.append(", ");

    }
    if(getLength()>0) {
        txt.append(to_string(getNode(getLength() - 1)->getData()));
    }
    txt.append("]");

    std::cout << txt << std::endl;

    return txt;
}

//***********************************************************


//**********************DoubleList***************************
template <class T>
DoubleList<T>::DoubleList() {root = NULL;}

template <class T>
int DoubleList<T>::getLength() {

    return length;

}

template <class T>
DoubleNode<T>* DoubleList<T>::getNode(int pos) {
    DoubleNode<T> *temp;
    temp = root;

    int len = getLength();

    bool foo = pos >= len;

    if (foo) {

        std::cout << "Index out of range \n";
        return NULL;

    } else {
        while (pos != 0) {
            temp = temp->getNext();
            pos--;
        }
        return temp;
    }
}

template  <class T>
void DoubleList<T>::newNode(T data){

    DoubleNode<T> *temp = new DoubleNode<T>;
    temp->setData(data);
    temp->setNext(NULL);
    temp->setPrev(NULL);


    if(root == NULL){
        length++;

        root = temp;
        temp = NULL;

    }
    else{

        DoubleNode<T> *current = root;
        while(current->getNext() != NULL){

            current = current->getNext();

        }

        length++;

        temp->setPrev(current);
        current->setNext(temp);
        temp = NULL;

    }


}

template <class T>
void DoubleList<T>::insertAtStart(T data) {

    DoubleNode<T> *temp = new DoubleNode<T>;
    temp->setNext(root);
    root->setPrev(temp);
    temp->setData(data);
    root = temp;
    temp = NULL;
    delete (temp);
    length++;

}

template <class T>
void DoubleList<T>::insertNode(int pos, T data) {

    if(pos > getLength()){
        cout << "The position is out of range";
        return;
    }

    DoubleNode<T> *current = getNode(pos-1);
    DoubleNode<T> *temp = new DoubleNode<T>;

    temp->setData(data);
    temp->setNext(getNode(pos));
    getNode(pos)->setPrev(temp);
    current->setNext(temp);
    temp->setPrev(current);
    length++;

}

template <class T>
void DoubleList<T>::deleteLast(){

    DoubleNode<T> *current;

    current = root;

    while(current->getNext()->getNext() != NULL){

        current = current->getNext();

    }
    length--;
    current->getNext()->setPrev(NULL);
    delete(current->getNext());
    current->setNext(NULL);

}

template <class T>
void DoubleList<T>::deleteFirst() {

    DoubleNode<T> *temp;
    temp = root->getNext();
    root->setPrev(NULL);
    root->setNext(NULL);
    delete(root);
    root = temp;
    length--;
    return;


}

template <class T>
void DoubleList<T>::deleteNode(int pos) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    DoubleNode<T> *current = getNode(pos-1);
    DoubleNode<T> *temp = getNode(pos);

    current->setNext(current->getNext()->getNext());
    current->getNext()->setPrev(current);
    temp->setNext(NULL);
    temp->setPrev(NULL);
    delete(temp);
    length--;
    return;

}

template <class T>
void DoubleList<T>::editNode(int pos, T data) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    getNode(pos)->setData(data);
    return;
}

template <class T>
std::string DoubleList<T>::show() {

    string txt =  "[";

    for(int i = 0; i < getLength()-1; i++){

        txt.append(to_string(getNode(i)->getData()));
        txt.append(", ");

    }
    if(getLength()>0) {
        txt.append(to_string(getNode(getLength() - 1)->getData()));
    }
    txt.append("]");

    std::cout << txt << std::endl;

    return txt;
}

//***********************************************************


//**********************CircleList***************************
template <class T>
CircleList<T>::CircleList() {root = NULL;}

template <class T>
int CircleList<T>::getLength() {

    return length;

}

template <class T>
DoubleNode<T>* CircleList<T>::getNode(int pos) {
    DoubleNode<T> *temp;
    temp = root;

    int len = getLength();

    bool foo = (pos >= len) || (pos < -1);

    if (foo) {

        std::cout << "Index out of range \n";
        return NULL;

    } else {
        while (pos != 0) {
            temp = temp->getNext();
            pos--;
        }
        return temp;
    }
}

template  <class T>
void CircleList<T>::newNode(T data) {

    DoubleNode<T> *temp = new DoubleNode<T>;
    temp->setData(data);
    temp->setNext(NULL);
    temp->setPrev(NULL);

    if (root == NULL) {
        length++;

        root = temp;
        root->setPrev(root);
        root->setNext(root);

    } else {

        DoubleNode<T> *current = root;
        while (current->getNext() != root) {

            current = current->getNext();

        }

        length++;

        temp->setPrev(current);
        current->setNext(temp);
        temp->setNext(root);
        root->setPrev(temp);

    }


}

template <class T>
void CircleList<T>::insertAtStart(T data) {

    DoubleNode<T> *temp = new DoubleNode<T>;
    temp->setNext(root);
    temp->setPrev(root->getPrev());
    root->getPrev()->setNext(temp);
    root->setPrev(temp);
    temp->setData(data);
    root = temp;
    length++;
}

template <class T>
void CircleList<T>::insertNode(int pos, T data) {

    if(pos > getLength()){
        cout << "The position is out of range";
        return;
    }

    DoubleNode<T> *current = getNode(pos-1);
    DoubleNode<T> *temp = new DoubleNode<T>;

    temp->setData(data);
    temp->setNext(getNode(pos));
    getNode(pos)->setPrev(temp);
    current->setNext(temp);
    temp->setPrev(current);
    length++;

}

template <class T>
void CircleList<T>::deleteLast(){

    if(length == 0){

        return;

    }

    DoubleNode<T> *current;

    current = root;

    while(current->getNext()->getNext() != root){

        current = current->getNext();

    }
    length--;
    current->getNext()->setPrev(NULL);
    delete(current->getNext());
    current->setNext(root);
    root->setPrev(current);

}

template <class T>
void CircleList<T>::deleteFirst() {

    if(length == 0){

        return;

    }
    if(length == 1){

        delete(root);
        root = NULL;

        length--;

    }

    DoubleNode<T> *temp;
    temp = root->getNext();
    temp->setPrev(root->getPrev());
    root->setPrev(NULL);
    root->setNext(NULL);
    delete(root);
    root = temp;
    length--;
    return;


}

template <class T>
void CircleList<T>::deleteNode(int pos) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }
    if(pos == 0){

        deleteFirst();

    }

    DoubleNode<T> *current = getNode(pos-1);
    DoubleNode<T> *temp = getNode(pos);

    current->setNext(current->getNext()->getNext());
    current->getNext()->setPrev(current);
    temp->setNext(NULL);
    temp->setPrev(NULL);
    delete(temp);
    length--;
    return;

}

template <class T>
void CircleList<T>::editNode(int pos, T data) {

    if(pos >= getLength()){
        cout << "The position is out of range\n";
        return;
    }

    getNode(pos)->setData(data);
    return;
}

template <class T>
std::string CircleList<T>::show() {

    string txt =  "[";

    for(int i = 0; i < getLength()-1; i++){

        txt.append(to_string(getNode(i)->getData()));
        txt.append(", ");

    }
    if(getLength()>0) {
        txt.append(to_string(getNode(getLength() - 1)->getData()));
    }
    txt.append("]");

    std::cout << txt << std::endl;

    return txt;
}

//***********************************************************
