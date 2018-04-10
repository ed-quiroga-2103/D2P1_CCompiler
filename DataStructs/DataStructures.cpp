#include "DataStructures.h"//
// Created by eduardo on 23/02/18.
//

//*************************LeafNode**************************

LeafNode::LeafNode(int newData){

    data = newData;

}

void LeafNode::setLeft(LeafNode* newNode){

    left_child = newNode;
    return;

}
void LeafNode::setRight(LeafNode* newNode){

    right_child = newNode;
    return;

}
void LeafNode::setData(int newData){

    data = newData;
    return;
}
void LeafNode::addCount(){

    count++;

}

int LeafNode::getCount() {

    return count;

}
LeafNode* LeafNode::getLeft(){ return left_child; }
LeafNode* LeafNode::getRight(){ return right_child; }
int LeafNode::getData(){ return data; }

//***********************************************************

//***************************BST*****************************

void BST::insert(int data){

    if(root == NULL){

        LeafNode* temp = new LeafNode(data);

        root = temp;
        return;

    }
    else if(root->getData() == data){

        root->addCount();
        return;

    }
    else {

        LeafNode *next = getNextNode(data);

        if (data > next->getData()) {

            LeafNode *temp = new LeafNode(data);

            next->setRight(temp);
            return;
        } else if (data < next->getData()) {

            LeafNode *temp = new LeafNode(data);

            next->setLeft(temp);
            return;
        } else {

            next->addCount();

        }


    }
}


void BST::deleteNode(int data){

    if(root->getData()==data){

        if(root->getRight() == NULL){

            LeafNode* temp = root->getLeft();

            root->setLeft(NULL);
            root->setRight(NULL);

            delete(root);

            root = temp;
            return;

        }
        else if(root->getLeft() == NULL && root->getRight() == NULL){

            root->setLeft(NULL);
            root->setRight(NULL);

            delete(root);

            root = NULL;
            return;

        }

        LeafNode* current = root->getRight();

        if(current->getLeft() == NULL && current->getRight()==NULL){

            current->setLeft(root->getLeft());
            delete(root);
            root = current;

            return;

        }

        while(current->getLeft() != NULL){
            current = current->getLeft();
        }
        //Checks if the node has a child to be relocated
        LeafNode *temp = NULL;

        if(current->getRight() != NULL) {
            temp = current->getRight();
        }

        LeafNode* prev = getPrevNode(current->getData());
        prev->setLeft(temp);

        current->setRight(root->getRight());
        current->setLeft(root->getLeft());

        root->setLeft(NULL);
        root->setRight(NULL);

        root = current;
    }
    else{

        LeafNode* current = getNode(data);


        if(current->getRight() != NULL){

            if(current->getRight()->getLeft() != NULL){

                LeafNode* replace = current->getRight()->getLeft();

                while(replace->getLeft() != NULL){

                    replace = replace->getLeft();

                }

                LeafNode *temp = NULL;

                if(current->getRight() != NULL) {
                    temp = current->getRight();
                }

                LeafNode* prev = getPrevNode(current->getData());
                prev->setLeft(temp);

                replace->setLeft(current->getLeft());
                replace->setRight(current->getRight());


                LeafNode* parent = getPrevNode(current->getData());

                if(parent->getData() > replace->getData()){

                    parent->setLeft(replace);

                }else{

                    parent->setRight(replace);

                }


                current->setRight(NULL);
                current->setLeft(NULL);

                delete(current);

            }
            else if(current->getRight()->getRight() != NULL){

                LeafNode* replace = current->getRight();

                replace->setLeft(current->getLeft());

                LeafNode* parent = getPrevNode(current->getData());

                if(parent->getData() > current->getData()){

                    parent->setLeft(replace);

                }else{

                    parent->setRight(replace);

                }

                current->setLeft(NULL);
                current->setRight(NULL);

                delete(current);

            }
            else{

                LeafNode* parent = getPrevNode(current->getData());

                if(parent->getData() > current->getData()){

                    parent->setLeft(current->getRight());

                }else{

                    parent->setRight(current->getRight());

                }

                current->setLeft(NULL);
                current->setRight(NULL);

                delete(current);

            }


        }
        else if (current->getLeft() != NULL){


            LeafNode* replace = current->getLeft();

            LeafNode* parent = getPrevNode(current->getData());

            if(parent->getData() > replace->getData()){

                parent->setLeft(replace);

            }else{

                parent->setRight(replace);

            }

        }
        else{

            LeafNode* parent = getPrevNode(current->getData());

            if(parent->getData() > current->getData()){

                parent->setLeft(NULL);

            }else{

                parent->setRight(NULL);

            }


            delete(current);

        }

    }


}

LeafNode* BST::getRoot() {return root;}

LeafNode* BST::getNode(int data){


    if(root->getData() == data){

        return root;

    }

    getNode_aux(root, data);

}

LeafNode* BST::getNode_aux(LeafNode *node, int data) {

    if(node->getData() == data) {

        return node;
    }
    if(data > node->getData()){

        return getNode_aux(node->getRight(), data);
    }
    else{

        return getNode_aux(node->getLeft(), data);
    }

}

LeafNode* BST::getPrevNode(int data) {

    if(root->getLeft() != NULL && root->getLeft()->getData() == data){

        return root;

    }else if(root->getRight() != NULL &&root->getRight()->getData() == data){

        return root;

    }
    else {
        getPrevNode_aux(root, data);
    }

}

LeafNode* BST::getPrevNode_aux(LeafNode *node, int data) {

    if(node->getLeft() != NULL && node->getLeft()->getData() == data){

        return node;

    }else if(node->getRight() != NULL && node->getRight()->getData() == data){

        return node;

    }

    if(data > node->getData()){

        return getPrevNode_aux(node->getRight(), data);
    }
    else{

        return getPrevNode_aux(node->getLeft(), data);
    }

}

LeafNode* BST::getNextNode(int data) {

    if(root->getData() == data){

        return root;

    }
    else if(data > root->getData() && root->getRight() ==  NULL){

        return root;

    }
    else if(data < root->getData() && root->getLeft() ==  NULL){

        return root;

    }

    else if (data > root->getData()){

        return getNextNode_aux(root->getRight(), data);

    }
    else{

        return getNextNode_aux(root->getLeft(), data);

    }



}

LeafNode* BST::getNextNode_aux(LeafNode *node, int data) {

    if(node->getData() == data){

        return node;

    }
    else if(data > node->getData() && node->getRight() ==  NULL){

        return node;

    }
    else if(data < node->getData() && node->getLeft() ==  NULL){

        return node;

    }

    else if (data > node->getData()){

        return getNextNode_aux(node->getRight(), data);

    }
    else{

        return getNextNode_aux(node->getLeft(), data);

    }

}

//***********************************************************

