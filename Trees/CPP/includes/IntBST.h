//
// Created by d1r3ct0r on 20/07/2021.
//

#ifndef INT_BST_H
#define INT_BST_H
#include <iostream>

class IntNode{
public:
    IntNode(int val){
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    int value;
    IntNode *left,*right;
};

class IntBST{
private:
    IntNode *root;
    unsigned int count=0;
    void insert(IntNode*, int );
    bool search(IntNode*,int);
    void preOrderTraversal(IntNode *node);
    void inOrderTraversal(IntNode *node);
    void postOrderTraversal(IntNode *node);
public:
    IntBST(){
        root = nullptr;
    }
    void insertArray(int [], bool);
    void insert(int);
    bool search(int value);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int max();
    int min();
    unsigned int length()const{return count;}
};
#endif //INT_BST_H
