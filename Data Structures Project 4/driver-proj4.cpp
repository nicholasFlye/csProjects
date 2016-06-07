/* CSI 3334
 * Project  -- AVL Tree
 * Filename: driver-proj4.cpp
 * Student name: Nicholas Flye
 * Date: 11/18/2013
 * Due Date: 11/1/2013
 *
 * This file contains the source code of one function (main)
 * to take data from a file, store the data in a AVL tree, and
 * encrypt or decrypt the data.
 */
 
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include "avl-tree-student-proj4.h"
#include "avl-tree-prof-proj4.h"
 
 using namespace std;
/* main
 *  parameters:
 *
 *  return value: 0 (indicating a successful run)
 * 
 *  main constructs an AVL self-balancing binary search tree of data that is to be encrypted.
 *  Depending on the input, data will either be encrypted, decrypted, or
 *  printed to the screen to display a certain message.
 */
int main(){

    EncryptionTree<string> secretly;
    string data;
    string stringBuffer, decrypted = "", encrypted = "";
    char* cstrData;
    char* token;

    while(getline(cin,data)){
    
        if(data[0] == 'i'){
        
            data.erase(0, 1);
            stringstream extract(data);
            extract >> stringBuffer;
            secretly.insert(stringBuffer);
            
        }
        else if(data[0] == 'p'){
        
            secretly.printPreorder(cout);
            
        }
        else if(data[0] == 'l'){
        
            secretly.printLevelOrder(cout);
            
        }
        else if(data[0] == 'r'){
        
            data.erase(0, 1);
            stringstream extract(data);
            extract >> stringBuffer;
            secretly.remove(stringBuffer);
            
        }
        else if(data[0] == 'e'){
        
            encrypted = "";
            data.erase(0, 1);
            
            size_t found = data.find("'");
            if(found != string::npos){
            
                data.erase(found, 1);
                
            }
            
            found = data.find("'");
            if(found != string::npos){
            
                data.erase(found, 1);
                
            }
            
            stringstream extract(data);
            while(extract >> stringBuffer){
            
                encrypted.append(secretly.encrypt(stringBuffer));
                
            }
            
            if(encrypted[encrypted.size() - 1] == ' ')
                encrypted.erase(encrypted.size() - 1, 1);
                
            if(encrypted.size() != 0)
                cout << encrypted;
                
            cout << endl;
            
        }
        else if(data[0] == 'd'){
        
            decrypted = "";
            data.erase(0, 1);
            
            size_t found = data.find("'");
            if(found != string::npos){
            
                data.erase(found, 1);
                
            }
            
            found = data.find("'");
            if(found != string::npos){
            
                data.erase(found, 1);
                
            }
            
            stringstream extract(data);
            while(extract >> stringBuffer){
            
                if(secretly.decrypt(stringBuffer) == NULL){
                
                    decrypted.append("? ");
                    
                }
                else{
                
                    decrypted.append(*secretly.decrypt(stringBuffer));
                    decrypted.append(" ");
                    
                }
            }
            
            if(decrypted[decrypted.size() - 1] == ' ')
                decrypted.erase(decrypted.size() - 1, 1);
                
            if(decrypted.size() != 0)
                cout << decrypted;
                
            cout << endl;
            
        }
        else if(data[0] == 'q'){
            
            exit(0);
            
        }
    }
    
    return 0;
}
