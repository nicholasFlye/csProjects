/* CSI 3334
 * Project  -- Encryption Tree
 * Filename: bst-student-proj3.h
 * Student name: Nicholas Flye
 * Date: 10/16/2013
 * Due Date: 10/11/2013
 *
 * This file contains the implementation of BSTNode functions, BST functions,
 * and EncryptionTree functions.
 */
#ifndef BST_STUDENT_PROJ3
#define BST_STUDENT_PROJ3

#include "bst-prof-proj3.h"

/* Place your implementation of the BSTNode, BST, and EncryptionTree classes
 * here.
 *
 * Your driver should #include this file, which (as you can see above) will also
 * #include the professor file.
 */
 
///BSTNode functions
/*
 * ~BSTNode
 *
 * This function is the destructor for the binary search node object.
 * (Recursively deallocates a node and any of its subtrees.) 
 * 
 * Parameters:
 *
 * Return value:
 */
template <class Base>
BSTNode<Base>::~BSTNode(){
    if(left != NULL)
        delete left;
    if(right != NULL)
        delete right;
}
/*
 * printPreorder
 *
 * This function prints a node and its children's data in pre-order format.
 * 
 * 
 * Parameters: Referenced ostream used to print data to the screen.
 *             String object used for indents.
 *
 * Return value: void
 */
template <class Base>
void BSTNode<Base>::printPreorder(ostream &os, string indent) const{
    os << indent;
    os << data << endl;
    if(left != NULL){
        indent.append("  ");
        left->printPreorder(os, indent);
        indent.erase(indent.size() - 2, 2);
    }
    else
        cout << indent << "  NULL" << endl;
    if(right != NULL){
        indent.append("  ");
        right->printPreorder(os, indent);
        indent.erase(indent.size() - 2, 2);
        
    }
    else
        cout << indent << "  NULL" << endl;
}
/*
 * minNode
 *
 * This function finds the left most node at or below the node its called upon.
 * 
 * Parameters:
 *
 * Return value: constant BSTNode of type Base that is to be the left most node.
 */
template <class Base>
const BSTNode<Base>* BSTNode<Base>::minNode() const{
    const BSTNode<Base>* thisNode = this;
    if(thisNode != NULL)
        while(thisNode->left)
            thisNode = thisNode->left;
    return thisNode;
}
/*
 * maxNode
 *
 * This function finds the right most node at or below the node its called upon.
 * 
 * Parameters:
 *
 * Return value: constant BSTNode of type Base that is to be the right most node.
 */
template <class Base>
const BSTNode<Base>* BSTNode<Base>::maxNode() const{
    const BSTNode<Base>* thisNode = this;
    if(thisNode != NULL)
        while(thisNode->right)
            thisNode = thisNode->right;
    return thisNode;
}
///BST functions
/*
 * insert
 *
 * The insert function inserts an item of type Base at the bottom of the BST.
 * 
 * Parameters: constant Base item to be inserted.
 *
 * Return value: void
 */
template <class Base>
void BST<Base>::insert(const Base &item){
    BSTNode<Base>* thisNode = NULL;
    BSTNode<Base>* parent = root;
    bool done = false;
    
    if(root == NULL)
        root = new BSTNode<Base>(item, NULL, NULL);
    else{
        if(item < parent->data){
            thisNode = parent->left;
        }
        else if(parent->data < item){
            thisNode = parent->right;
        }
        else{
            thisNode = parent;
        }
        
        if(parent == thisNode) {
            
        }
        else{
            while(thisNode != NULL && !done){
                if(item < thisNode->data){
                    parent = thisNode;
                    thisNode = parent->left;
                }
                else if(thisNode->data < item){
                    parent = thisNode;
                    thisNode = parent->right;
                }
                else{
                    done = true;
                }
            }
            if(thisNode == NULL){
                if(item < parent->data){
                    thisNode = new BSTNode<Base> (item, NULL, NULL);
                    parent->left = thisNode;
                }
                else if(parent->data < item){
                    thisNode = new BSTNode<Base> (item, NULL, NULL);
                    parent->right = thisNode;
                }
            }
            else{
                
            }
        }

    }
}
/*
 * remove
 *
 * The remove function removes an item of type Base from the BST while 
 * maintaining order of the tree.
 * 
 * Parameters: constant Base item to be removed.
 *
 * Return value: void
 */
template <class Base>
void BST<Base>::remove(const Base &item){
    BSTNode<Base>* toRemove = root;
    BSTNode<Base>* grandchild;
    BSTNode<Base>* parent;
    BSTNode<Base>* leftMostRightChild;
    bool done = false;
    
    //find node to remove
    if(toRemove != NULL){
        while(!done){
            if(item < toRemove->data){
                if(toRemove->left){
                    parent = toRemove;
                    toRemove = toRemove->left;
                }
                else{
                    toRemove = NULL;
                    return;
                }
            }
            else if(toRemove->data < item){
                if(toRemove->right){
                    parent = toRemove;
                    toRemove = toRemove->right;
                }
                else{
                    toRemove = NULL;
                    return;
                }
            }
            else{
                done = true;
            }
        }
    }
    if(root != NULL){
        //Remove the root
        if(toRemove == root){
            if(root->left && root->right){
                BSTNode<Base>* leftMost = toRemove->right;
                BSTNode<Base>* leftMostParent = toRemove;
                
                if(leftMost->left != NULL){
                    while(leftMost->left != NULL){
                        leftMostParent = leftMost;
                        leftMost = leftMost->left;
                    }
                    leftMostRightChild = leftMost->right;
                    root = leftMost;
                    root->right = toRemove->right;
                    root->left = toRemove->left;
                    leftMostParent->left = leftMostRightChild;
                    toRemove->left = toRemove->right = NULL;
                    delete toRemove;
                }
                else{
                    root = root->right;
                    root->left = toRemove->left;
                    if(toRemove->right->right){
                        root->right = toRemove->right->right;
                    }
                    toRemove->left = toRemove->right = NULL;
                    delete toRemove;
                }
            }
            else if(root->right){
                root = root->right;
                toRemove->left = toRemove->right = NULL;
                delete toRemove;
            }
            else if(root->left){
                root = root->left;
                toRemove->left = toRemove->right = NULL;
                delete toRemove;
            }
            else{
                delete root;
                root = NULL;
            }
        }
        //No children
        else if(toRemove->left == NULL && toRemove->right == NULL
            && toRemove != root){
            if(parent->left == toRemove){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete toRemove;
            toRemove = NULL;
        }
        //one child
        else if((toRemove->left != NULL && toRemove->right == NULL) ||
                (toRemove->left == NULL && toRemove->right != NULL)){
            if(toRemove->left != NULL){
                grandchild = toRemove->left;
                toRemove->left = NULL;
            }
            else{
                grandchild = toRemove->right;
                toRemove->right = NULL;
            }
            if(parent->left == toRemove){
                parent->left = grandchild;
            }
            else{
                parent->right = grandchild;
            }
            delete toRemove;
        }
        //two children
        else if(toRemove->left != NULL && toRemove->right != NULL){
            BSTNode<Base>* leftMost = toRemove->right;
            BSTNode<Base>* leftMostParent = toRemove;
            
            if(leftMost->left != NULL){
                while(leftMost->left != NULL){
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }
                leftMostParent->left = leftMost->right;
                leftMost->right = toRemove->right;
            }
            leftMost->left = toRemove->left;
            if(parent->left == toRemove){
                parent->left = leftMost;
            }
            else{
                parent->right = leftMost;
            }
            toRemove->left = toRemove->right = NULL;
            delete toRemove;
        }
        else{
        
        }
    }
}
///EncryptionTree functions
/*
 * encrypt
 *
 * The encrypt function takes a constant referenced item of type Base and encrypts
 * the item based upon its location in the tree. Any path that goes left in the tree
 * adds a 0 to the encrypted message. Any path that goes right in the tree adds
 * 1 to the encrypted message.
 * 
 * Parameters: constant Base item to be encrypted.
 *
 * Return value: string object that is the encrypted message.
 */
template <class Base>
string EncryptionTree<Base>::encrypt(const Base &item) const{
    string encryptionItem = "r";
    bool done = false;
    const BSTNode<Base>* thisNode = this->root;

    if(thisNode != NULL){
        while(!done){
            if(item < thisNode->getData()){
                if(thisNode->getLeft() != NULL){
                    thisNode = thisNode->getLeft();
                    encryptionItem.append(1, '0');
                }
                else{
                    encryptionItem = "?";
                    done = true;
                }
            }
            else if(thisNode->getData() < item){
                if(thisNode->getRight() != NULL){
                    thisNode = thisNode->getRight();
                    encryptionItem.append(1, '1');
                }
                else{
                    encryptionItem = "?";
                    done = true;
                }
            }
            else
                done = true;
        }
    }
    else
        encryptionItem = "?";
        
    return encryptionItem + " ";
}
/*
 * decrypt
 *
 * The decrypt function decrypts a constant referenced string called path.
 * The path represents a pathway down the tree to find the cleartext to be returned
 * by the function.
 * 
 * Parameters: constant referenced string object known as path. path is a
 * string representation of a pathway down the tree.
 *
 * Return value: constant Base pointer to the cleartext
 */
template <class Base>
const Base *EncryptionTree<Base>::decrypt(const string &path) const{
    const BSTNode<Base>* thisNode = this->root;
    const Base* cleartext = &thisNode->getData();
    int pathLength = 0, x = 1;
    bool validPath = true;
    
    if(this->root != NULL){
        if(path[0] == 'r'){
            while((x < path.size()) && validPath){
                if(path[x] == '0'){
                    thisNode = thisNode->getLeft();
                    if((thisNode == NULL) && (x < path.size()))
                        validPath = false;
                }
                else if(path[x] == '1'){
                    thisNode = thisNode->getRight();
                    if((thisNode == NULL) && (x < path.size()))
                        validPath = false;
                }
                else
                    validPath = false;
                x++;
            }
        }
        
        thisNode = this->root;
        if(path[0] == 'r'){
            if(validPath){
                for(int i = 0; i < path.size(); i++){
                    if(path[i] == '0'){
                        thisNode = thisNode->getLeft();
                    }
                    else if(path[i] == '1'){
                        thisNode = thisNode->getRight();
                    }
                }
                cleartext = &thisNode->getData();
            }
            else{
                cleartext = NULL;
            }
        }
        else{
            cleartext = NULL;
        }
    }

    return cleartext;
}

#endif

