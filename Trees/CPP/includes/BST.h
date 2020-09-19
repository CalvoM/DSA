#ifndef BST_H
#define BST_H
    template<class _B>
    class BSTNode{
        public:
            BSTNode(){
                this->left=this->right =0;
            }
            BSTNode(const _B& el,NSTNode *l=0,BSTNode *r=0){
                this->key=el;
                this->left=l;
                this->right=r;
            }
            _B key;
            BSTNode *left,*right;
    };
    template<class _B>
    class BST{
        public:
            BST(){
              this->root=0;  
            }
            ~BST(){
                clear();
            }
            void clear(){
                root=0;
            }
            bool is_empty()const{
                return this->root==0;
            }
        protected:
            BSTNode<_B> *root;
            void clear(BSTNode<_B>*);
            _B* search(BSTNode<_B>*,const _B&)const;
            void preorder(BSTNode<_B>*);
            void inorder(BSTNode<_B>*);
            void postorder(BSTNode<_B>*);
    };
#endif