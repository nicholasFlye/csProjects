/* CSI 3334
 * Project  -- AVL Tree
 * Filename: avl-tree-student-proj4.h
 * Student name: Nicholas Flye
 * Date: 11/18/2013
 * Due Date: 11/1/2013
 *
 * This file contains the implementation of AVL Tree functionality. If an
 * imbalance occurs, proper rotations to nodes in the tree are applied.
 */
#ifndef AVL_TREE_STUDENT_PROJ4 
#define AVL_TREE_STUDENT_PROJ4 

#include "avl-tree-prof-proj4.h"
#include <queue>
#include <cmath>

/* Place your implementation of the AVLNode, AVLNode, and EncryptionTree classes
* here.
*
* Your driver should #include this file, which (as you can see above) will also
* #include the professor file.
*/

///AVL Node functions
/*
 * ~AVLNode
 *
 * This function is the destructor for the AVL node object.
 * (Recursively deallocates a node and any of its subtrees.) 
 * 
 * Parameters:
 *
 * Return value:
 */
template <class Base>
AVLNode<Base>::~AVLNode(){
    if(left != NULL)
        delete left;
    if(right != NULL)
        delete right;

}

/*
 * singleRotateLeft
 *
 * This function rotates the node its called upon left to maintain AVL balance.
 * 
 * 
 * Parameters:
 *
 * Return value: Returns an AVL node so its parent's pointer can be changed. 
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::singleRotateLeft(){

    AVLNode<Base>* thisNode = this;
    AVLNode<Base>* replacement = NULL;
    AVLNode<Base>* repSubTree = thisNode->right->left;
    
    thisNode->right->left = thisNode;
    replacement = thisNode->right;
    thisNode->right = repSubTree;
    
    thisNode->updateHeight();
    replacement->updateHeight();
   
    return replacement;
}
/*
 * singleRotateRight
 *
 * This function rotates the node its called upon right to maintain AVL balance.
 * 
 * 
 * Parameters:
 *
 * Return value: Returns an AVL node so its parent's pointer can be changed. 
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::singleRotateRight(){
    
    AVLNode<Base>* thisNode = this;
    AVLNode<Base>* replacement = NULL;
    AVLNode<Base>* repSubTree = thisNode->left->right;
    
    thisNode->left->right = thisNode;
    replacement = thisNode->left;
    thisNode->left = repSubTree;
    
    
    thisNode->updateHeight();
    replacement->updateHeight();
    
    return replacement;
    
}
/*
 * doubleRotateLeftRight
 *
 * This function performs a double rotation by doing two single rotations to the
 * left then to the right. 
 * 
 * 
 * Parameters:
 *
 * Return value: Returns an AVL node so its parent's pointer can be changed. 
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateLeftRight(){
    
    left = left->singleRotateLeft();
    return singleRotateRight();
    
}
/*
 * doubleRotateRightLeft
 *
 * This function performs a double rotation by doing two single rotations to the
 * right then to the left. 
 * 
 * 
 * Parameters:
 *
 * Return value: Returns an AVL node so its parent's pointer can be changed. 
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateRightLeft(){

    right = right->singleRotateRight();
    return singleRotateLeft();
    
}

/*
 * minNode
 *
 * This function finds the left most node at or below the node its called upon.
 * 
 * Parameters:
 *
 * Return value: constant AVLNode of type Base that is to be the left most node.
 */
template <class Base>
const AVLNode<Base>* AVLNode<Base>::minNode() const{

    const AVLNode<Base>* thisNode = this;
    
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
 * Return value: constant AVLNode of type Base that is to be the right most node.
 */
template <class Base>
const AVLNode<Base>* AVLNode<Base>::maxNode() const{

    const AVLNode<Base>* thisNode = this;
    
    while(thisNode->right)
        thisNode = thisNode->right;
        
    return thisNode;
    
}

///AVL Tree Functions
/*
 * printLevelOrder
 *
 * This function prints a node and its children's data in level-order format.
 * 
 * 
 * Parameters: Referenced ostream used to print data to the screen.
 *
 * Return value: void
 */
template <class Base>
void AVLTree<Base>::printLevelOrder(ostream &os) const{
    
    const int MAX_NODE_LINE = 20;
    int nodeCount = 0;
    bool done = false;
    queue <AVLNode<Base>*> printLevel;
    AVLNode<Base>* thisNode = root;
    
    if(root){
        printLevel.push(root);
    
        while(!printLevel.empty()){
            
            if(nodeCount == MAX_NODE_LINE){
                os << endl;
                nodeCount = 0;
            }
            if(printLevel.front()){
                
                if(nodeCount == MAX_NODE_LINE - 1)
                    os << printLevel.front()->getData();
                else
                    os << printLevel.front()->getData() << " ";
                printLevel.push(printLevel.front()->left);
                printLevel.push(printLevel.front()->right);
                
            }
            else{
                if(nodeCount == MAX_NODE_LINE - 1)
                    os << "NULL";
                else if(printLevel.size() == 1)
                    os << "NULL" << endl;
                else{
                
                    os << "NULL ";
                    
                }    
            }
            printLevel.pop();
                
            nodeCount++;
            
        }
    }
    else{
        os << "NULL" << endl;
        
    }
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
void AVLNode<Base>::printPreorder(ostream &os, string indent) const{
    const int INDENT_SPACE = 2;
    os << indent;
    os << data << endl;
    if(left != NULL){
        indent.append("  ");
        left->printPreorder(os, indent);
        indent.erase(indent.size() - INDENT_SPACE, INDENT_SPACE);
    }
    else
        os << indent << "  NULL" << endl;
    if(right != NULL){
        indent.append("  ");
        right->printPreorder(os, indent);
        indent.erase(indent.size() - INDENT_SPACE, INDENT_SPACE);
        
    }
    else
        os << indent << "  NULL" << endl;
}
/*
 * insert
 *
 * The insert function inserts an item of type Base at the bottom of the AVL tree.
 * 
 * Parameters: constant Base item to be inserted.
 *
 * Return value: void
 */
template <class Base>
void AVLTree<Base>::insert(const Base &item){
    AVLNode<Base>* thisNode = NULL;
    AVLNode<Base>* parent = root;
    AVLNode<Base>* grandparent = root;
    bool done = false;
    int numOnPath = 0;
    const int MAX_NODE_PATH = 30;
    AVLNode<Base>* path[MAX_NODE_PATH];
    
    if(root == NULL){
        
        root = new AVLNode<Base>(item, NULL, NULL);
    }
        
    else{
        
        path[numOnPath] = root;
        numOnPath++;

        if(item < parent->data){
            
            thisNode = parent->left;
            if(thisNode != NULL){
                path[numOnPath] = thisNode;
                numOnPath++;
            }
            
        }
        else if(parent->data < item){
            
            thisNode = parent->right;
            if(thisNode != NULL){
                path[numOnPath] = thisNode;
                numOnPath++;
            }
            
        }
        else{
        
            thisNode = parent;
            
        }

        if(parent == thisNode) {
            
        }
        else{
        
            while(thisNode != NULL && !done){
            
                if(item < thisNode->data){
                    
                    grandparent = parent;
                    parent = thisNode;
                    thisNode = parent->left;
                    if(thisNode != NULL){
                        path[numOnPath] = thisNode;
                        numOnPath++;
                    }
                    
                }
                else if(thisNode->data < item){
                    
                    grandparent = parent;
                    parent = thisNode;
                    thisNode = parent->right;
                    if(thisNode != NULL){
                        path[numOnPath] = thisNode;
                        numOnPath++;
                    }
                        
                }
                else{
                
                    done = true;
                    
                }
            }
            
            if(thisNode == NULL){
            
                if(item < parent->data){
                
                    thisNode = new AVLNode<Base> (item, NULL, NULL);
                    path[numOnPath] = thisNode;
                    numOnPath++;
                    parent->left = thisNode;
                    
                }
                else if(parent->data < item){
                
                    thisNode = new AVLNode<Base> (item, NULL, NULL);
                    path[numOnPath] = thisNode;
                    numOnPath++;
                    parent->right = thisNode;
                    
                }
            }
            else{
                
            }
        }
    
        //Check for imbalance

        rebalancePathToRoot(path, numOnPath);
        
    }
}
/*
 * remove
 *
 * The remove function removes an item of type Base from the AVL while 
 * maintaining order of the tree.
 * 
 * Parameters: constant Base item to be removed.
 *
 * Return value: void
 */
template <class Base>
void AVLTree<Base>::remove(const Base &item){
    AVLNode<Base>* toRemove = NULL;
    AVLNode<Base>* grandchild;
    AVLNode<Base>* parent;
    AVLNode<Base>* leftMostRightChild;
    bool done = false;
    int numOnPath = 0;
    const int MAX_NODE_PATH = 30;
    AVLNode<Base>* path[MAX_NODE_PATH];
    
    //find node to remove
    if(root){
        toRemove = root;
        while(!done){
            if(item < toRemove->data){
                if(toRemove->left){
                    parent = toRemove;
                    toRemove = toRemove->left;
                    path[numOnPath] = parent;
                    numOnPath++;
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
                    path[numOnPath] = parent;
                    numOnPath++;
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
                AVLNode<Base>* leftMost = toRemove->right;
                AVLNode<Base>* leftMostParent = toRemove;
                
                path[numOnPath] = root;
                numOnPath++;
                
                if(leftMost->left != NULL){
                
                    while(leftMost->left != NULL){
                        leftMostParent = leftMost;
                        leftMost = leftMost->left;
                        path[numOnPath] = leftMostParent;
                        numOnPath++;
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
                if(root)
                    path[0] = root;
            }
            else if(root->right){
                root = root->right;
                path[0] = root;
                toRemove->left = toRemove->right = NULL;
                delete toRemove;
            }
            else if(root->left){
                root = root->left;
                path[0] = root;
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
                path[numOnPath] = grandchild;
                numOnPath++;
            }
            if(parent->left == toRemove){
                parent->left = grandchild;
                path[numOnPath] = grandchild;
                numOnPath++;
            }
            else{
                parent->right = grandchild;
            }
            delete toRemove;
        }
        //two children
        else if(toRemove->left != NULL && toRemove->right != NULL){
            AVLNode<Base>* leftMost = toRemove->right;
            AVLNode<Base>* leftMostParent = toRemove;
            int indexToRemove = numOnPath;
            path[numOnPath] = toRemove->right;
            numOnPath++;
            if(leftMost->left != NULL){
                while(leftMost->left != NULL){

                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                    path[numOnPath] = leftMostParent;
                    numOnPath++;
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
            path[indexToRemove] = leftMost;
            toRemove->left = toRemove->right = NULL;
            delete toRemove;
        }
        else{
        
        }
    }

    //Check for imbalance

    rebalancePathToRoot(path, numOnPath);
    
}
/*
 * rebalancePathToRoot
 *
 * This function rebalances the nodes in the AVL tree where necessary by
 * performing single or double rotations where a node's left or right subtree's
 * height differs by a number greater than 1. 
 * 
 * 
 * Parameters: The path in which the imbalance occurs and the number of items on
 * the path.
 *
 * Return value: void
 */
template <class Base>
void AVLTree<Base>::rebalancePathToRoot(AVLNode<Base> **path, int numOnPath){
   
    AVLNode<Base>* imbalance = NULL;

    for(int i = numOnPath-1; i >=0; i--){

        path[i]->updateHeight();
        
    }
    for (int i = numOnPath-1; i >=0; i--){
    
        int leftSubTree = path[i]->getHeight(path[i]->left);
        int rightSubTree = path[i]->getHeight(path[i]->right);
        if(abs(leftSubTree - rightSubTree) > 1){
        
            imbalance = path[i];
            
            if(i == 0){
                if(imbalance == root){

                    if(rightSubTree < leftSubTree){
                
                        imbalance = imbalance->left;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            root = path[i]->singleRotateRight();
                        else if(leftSubTree < rightSubTree)
                            root = path[i]->doubleRotateLeftRight();
                        else{
                            root = path[i]->singleRotateRight();
                        }
                        
                    }
                    else if(leftSubTree < rightSubTree){
                        
                        imbalance = imbalance->right;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            root = path[i]->doubleRotateRightLeft();
                        else if(leftSubTree < rightSubTree)
                            root = path[i]->singleRotateLeft();
                        else{
                            root = path[i]->singleRotateLeft();
                        }
                        
                    }
                    AVLNode<Base>** updatePath = NULL;
                    AVLNode<Base>* thisNode = root;
                    int numToUpdate = 0;
                    bool done = false;
                    queue<AVLNode<Base>*> pathToUpdate;
                    
                    while(!done){
                        
                        if(root->getData() < thisNode->data){
                            
                            numToUpdate++;
                            thisNode = thisNode->left;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                            
                        }
                        else if(thisNode->data < root->getData()){
                            
                            numToUpdate++;
                            thisNode = thisNode->right;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                                
                        }
                        else{
                        
                            done = true;
                            
                        }
                    }
                    updatePath = new AVLNode<Base>* [numToUpdate];
                    for(int x = 0; x < numToUpdate; x++){
            
                        updatePath[x] = pathToUpdate.front();
                        pathToUpdate.pop();
                
                    }
                    for (int x = numToUpdate-1; x >=0; x--) {
                    
                        if(updatePath[x]->left)
                            updatePath[x]->left->updateHeight();
                        if(updatePath[x]->right)
                            updatePath[x]->right->updateHeight();
                        updatePath[x]->updateHeight();

                    }
                    delete [] updatePath;
                }
            }
            else{
                if(path[i - 1]->left == imbalance){
                
                    if(rightSubTree < leftSubTree){
                    
                        imbalance = imbalance->left;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            path[i - 1]->left = path[i]->singleRotateRight();
                        else if(leftSubTree < rightSubTree)
                            path[i - 1]->left = path[i]->doubleRotateLeftRight();
                        else{
                            path[i - 1]->left = path[i]->singleRotateRight();
                        }
                        
                    }
                    else if(leftSubTree < rightSubTree){
                        
                        imbalance = imbalance->right;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            path[i - 1]->left = path[i]->doubleRotateRightLeft();
                        else if(leftSubTree < rightSubTree)
                            path[i - 1]->left = path[i]->singleRotateLeft();
                        else{
                            path[i - 1]->left = path[i]->singleRotateLeft();
                        }
                        
                    }
                    AVLNode<Base>** updatePath = NULL;
                    AVLNode<Base>* thisNode = root;
                    int numToUpdate = 0;
                    bool done = false;
                    queue<AVLNode<Base>*> pathToUpdate;
                    
                    while(!done){
                        
                        if(path[i - 1]->left->getData() < thisNode->data){
                            
                            numToUpdate++;
                            thisNode = thisNode->left;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                            
                        }
                        else if(thisNode->data < path[i - 1]->left->getData()){
                            
                            numToUpdate++;
                            thisNode = thisNode->right;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                                
                        }
                        else{
                        
                            done = true;
                            
                        }
                    }
                    updatePath = new AVLNode<Base>* [numToUpdate];
                    for(int x = 0; x < numToUpdate; x++){
            
                        updatePath[x] = pathToUpdate.front();
                        pathToUpdate.pop();
                
                    }
                    for (int x = numToUpdate-1; x >=0; x--) {
                    
                        if(updatePath[x]->left)
                            updatePath[x]->left->updateHeight();
                        if(updatePath[x]->right)
                            updatePath[x]->right->updateHeight();
                        updatePath[x]->updateHeight();

                    }  
                    delete [] updatePath;                
                }
                else if(path[i - 1]->right == imbalance){
                
                    if(rightSubTree < leftSubTree){
                    
                        imbalance = imbalance->left;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            path[i - 1]->right = path[i]->singleRotateRight();
                        else if(leftSubTree < rightSubTree)
                            path[i - 1]->right = path[i]->doubleRotateLeftRight();
                        else{
                            path[i - 1]->right = path[i]->singleRotateRight();
                        }
                        
                    }
                    else if(leftSubTree < rightSubTree){
                        
                        imbalance = imbalance->right;
                        leftSubTree = path[i]->getHeight(imbalance->left);
                        rightSubTree = path[i]->getHeight(imbalance->right);
                        if(rightSubTree < leftSubTree)
                            path[i - 1]->right = path[i]->doubleRotateRightLeft();
                        else if(leftSubTree < rightSubTree)
                            path[i - 1]->right = path[i]->singleRotateLeft();
                        else{
                            path[i - 1]->right = path[i]->singleRotateLeft();
                        }
                        
                    }
                    AVLNode<Base>** updatePath = NULL;
                    AVLNode<Base>* thisNode = root;
                    int numToUpdate = 0;
                    bool done = false;
                    queue<AVLNode<Base>*> pathToUpdate;
                    
                    while(!done){
                        
                        if(path[i - 1]->right->getData() < thisNode->data){
                            
                            numToUpdate++;
                            thisNode = thisNode->left;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                            
                        }
                        else if(thisNode->data < path[i - 1]->right->getData()){
                            
                            numToUpdate++;
                            thisNode = thisNode->right;
                            if(thisNode != NULL){
                                pathToUpdate.push(thisNode);
                            }
                                
                        }
                        else{
                        
                            done = true;
                            
                        }
                    }
                    updatePath = new AVLNode<Base>* [numToUpdate];
                    for(int x = 0; x < numToUpdate; x++){
            
                        updatePath[x] = pathToUpdate.front();
                        pathToUpdate.pop();
                
                    }
                    for (int x = numToUpdate-1; x >=0; x--) {
                    
                        if(updatePath[x]->left)
                            updatePath[x]->left->updateHeight();
                        if(updatePath[x]->right)
                            updatePath[x]->right->updateHeight();
                        updatePath[x]->updateHeight();

                    }
                    delete [] updatePath;
                }
            }
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
    const AVLNode<Base>* thisNode = this->root;

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
    const AVLNode<Base>* thisNode = this->root;
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

