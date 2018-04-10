//
// Created by eduardo on 23/02/18.
//

#ifndef LISTAS_DATASTRUCTURES_H
#define LISTAS_DATASTRUCTURES_H



#include <cstdlib>
#include <iostream>

//************************Node**************************
template <class T>
class Node;

template <class T>
class Node {
public:

    Node();

    void setData(T newdata);
    void setNext(Node<T>* newnext);

    T getData();
    Node<T>* getNext();

private:

    T data;
    Node<T>* next;

};
//******************************************************

//********************DoubleNode************************
template <class T>
class DoubleNode;

template <class T>
class DoubleNode {
public:

    DoubleNode();

    void setData(T newdata);
    void setNext(DoubleNode<T>* newnext);
    void setPrev(DoubleNode<T>* newprev);


    T getData();
    DoubleNode<T>* getNext();
    DoubleNode<T>* getPrev();


private:

    T data;
    DoubleNode<T>* next;
    DoubleNode<T>* prev;

};
//******************************************************

//***********************SingleList*********************
template <class T>
class SingleList;

template <class T>
class SingleList{
private:
    Node<T> *root;
    int length = 0;
public:
    SingleList();

    T operator[](int i){

        return getNode(i)->getData();

    }

    int getLength();

    Node<T>* getNode(int pos);

    void newNode(T data);

    void insertFirst(T data);

    void insertNode(int pos, T data);

    void deleteLast();

    void deleteFirst();

    void deleteNode(int pos);

    void editNode(int pos, T data);

    std::string show();

};
//******************************************************

//********************DoubleList************************
template <class T>
class DoubleList;

template <class T>
class DoubleList {
private:
    DoubleNode<T> *root;
    int length = 0;
public:
    DoubleList();

    int getLength();

    void newNode(T data);

    void insertAtStart(T data);

    DoubleNode<T>* getNode(int pos);

    void insertNode(int pos, T data);

    void deleteLast();

    void deleteFirst();

    void deleteNode(int pos);

    void editNode(int pos, T data);

    std::string show();


};

//******************************************************

//********************CircleList************************

template <class T>
class CircleList;

template <class T>
class CircleList {
private:
    DoubleNode<T> *root;
    int length = 0;
public:
    CircleList();

    int getLength();

    void newNode(T data);

    void insertAtStart(T data);

    DoubleNode<T> *getNode(int pos);

    void insertNode(int pos, T data);

    void deleteLast();

    void deleteFirst();

    void deleteNode(int pos);

    void editNode(int pos, T data);

    std::string show();


};

//******************************************************

//**********************LeafNode************************

class LeafNode;

class LeafNode{

private:
    int data;
    int count = 1;
    LeafNode* left_child = NULL;
    LeafNode* right_child = NULL;
public:

    LeafNode(int newData);

    void setLeft(LeafNode* newNode);
    void setRight(LeafNode* newNode);
    void setData(int newData);
    void addCount();

    int getCount();
    LeafNode* getLeft();
    LeafNode* getRight();
    int getData();

};

//******************************************************

//*************************BST**************************

class BST;

class BST{

private:

    LeafNode* root = NULL;
    LeafNode* getNextNode(int data);
    LeafNode* getNextNode_aux(LeafNode* node, int data);
    LeafNode* getPrevNode(int data);
    LeafNode* getPrevNode_aux(LeafNode *node, int data);

public:

    void insert(int data);

    void deleteNode(int data);

    void print();

    LeafNode* getNode(int data);

    LeafNode* getNode_aux(LeafNode* node,  int data);

    LeafNode* getRoot();
};

//******************************************************

#include "DataStructures.tpp"


#endif //LISTAS_DATASTRUCTURES_H
