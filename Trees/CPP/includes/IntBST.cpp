//
// Created by d1r3ct0r on 20/07/2021.
//

#include "IntBST.h"

void IntBST::insert(int value) {
    if(this->root == nullptr){
        this->root = new IntNode(value);
        this->count++;
    }else{
        insert(this->root,value);
    }
}

void IntBST::insert(IntNode *node, int value) {
    if(value < node->value){
        if(node->left == nullptr){
            IntNode * leftNode = new IntNode(value);
            node->left = leftNode;
            this->count++;
        }else{
            insert(node->left,value);
        }
    }else{
        if(node->right == nullptr){
            IntNode *rightNode = new IntNode(value);
            node->right = rightNode;
            this->count++;
        }else{
            insert(node->right,value);
        }
    }
}

bool IntBST::search(int value) {
    if(this->root == nullptr){
        return false;
    }
    return search(this->root,value);
}

bool IntBST::search(IntNode *node, int value) {
    if(value == node->value) return true;
    else if(value < node->value){
        if(node->left == nullptr) return false;
        return search(node->left,value);
    }else if(value > node->value){
        if(node->right == nullptr) return false;
        return search(node->right,value);
    }
    return false;
}

void IntBST::inOrderTraversal() {
    if(this->root == nullptr){
        std::cout<<"What are you doing, bruv???"<<std::endl;
        return;
    }
    inOrderTraversal(this->root);

}
void IntBST::inOrderTraversal(IntNode *node) {
    if(node != nullptr){
        inOrderTraversal(node->left);
        std::cout<<node->value<<std::endl;
        inOrderTraversal(node->right);
    }
}
void IntBST::preOrderTraversal() {
    if(this->root == nullptr){
        std::cout<<"What are you doing, bruv???"<<std::endl;
        return;
    }
    preOrderTraversal(this->root);

}
void IntBST::preOrderTraversal(IntNode *node) {
    if(node != nullptr){
        std::cout<<node->value<<std::endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}
void IntBST::postOrderTraversal() {
    if(this->root == nullptr){
        std::cout<<"What are you doing, bruv???"<<std::endl;
        return;
    }
    postOrderTraversal(this->root);

}
void IntBST::postOrderTraversal(IntNode *node) {
    if(node != nullptr){
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout<<node->value<<std::endl;
    }
}
int IntBST::max(){
    if(this->root == nullptr){
        return -1;
    }
    IntNode *node=root;
    while(node->right != nullptr)node = node->right;
    return node->value;
}
int IntBST::min(){
    if(this->root == nullptr){
        return -1;
    }
    IntNode *node=root;
    while(node->left != nullptr)node = node->left;
    return node->value;
}

