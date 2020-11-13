#include "BST.h"
template<class _B>
_B* BST<_B>::search(BSTNode<_B>* n,const _B& el) const{
  while(n!=0){
    if(el==n->key) return &n->key;
    else if(el < &n->key) n = n->left;
    else n = n->right;
  }
  return 0;
}
template<class _B>
void BST<_B>::breadthFirst(){
  std::queue<BSTNode<_B>*> node_list;
  BSTNode<_B>* n = root;
  if (n!=0){
    node_list.push_back(n);
    while(!node_list.empty()){
       n = node_list.pop_front();
       this->visit(n);
       if(n->left!=0){
         node_list.push_back(n->left);
       }
       if(n->right!=0){
         node_list.push_back(n->right);
       }
    }
  }
}
template<class _B>
void BST<_B>::inorder(BSTNode<_B> *p){
  if (p!=0){
    this->inorder(p->left);
    this->visit(p);
    this->inorder(p->right);
  }
}
template<class _B>
void BST<_B>::preorder(BSTNode<_B> *p){
  if(p!=0){
    this->visit(p);
    this->preorder(p->left);
    this->preorder(p->right);
  }
}
template<class _B>
void BST<_B>::postorder(BSTNode<_B> *p){
  if(p!=0){
    this->postorder(p->left);
    this->postorder(p->right);
    this->visit(p);
  }
}
template<class _B>
void BST<_B>::insert(const _B &el){
  
}