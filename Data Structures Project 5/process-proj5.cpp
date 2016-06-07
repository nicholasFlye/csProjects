/* CSI 3334
* Project  -- Batch Operating System
* Filename: process-proj5.h
* Student name: Nicholas Flye
* Date: 11/21/2013
* Due Date: 11/15/2013
*
* This file contains the implementation of a process object that
* represents a process being ran on a machine's batch operating
* SYSTEM.
*/
#include "process-proj5.h"
/*
* Process
*
* This function constructs a process object and initializes all
* its data members.
*
* Parameters:
*
* Return value:
*/
Process::Process(int theId){

    id = theId;  
    deadline = 10;
    requiredTime = 10;
    information = "process GW";

}
/*
* run
*
* This function simulates a process being ran by printing
* its process and return a time which it may finish.
*
* Parameters: An integer representing the current SYSTEM time
* to see when a certain process may complete.
*
* Return value: Returns an integer that represents the time at
* which a certain process finished.
*/
int Process::run(int currentSystemTime) const{

    cout << information << endl;
    return currentSystemTime + requiredTime;


}
/*
* canComplete
*
* This function determines whether or not a process can or cannot
* complete.
*
* Parameters: An integer representing the current SYSTEM time
* to see when a certain process may complete.
*
* Return value: Boolean value that represents whether or not a 
* process can complete.
*/
bool Process::canComplete(int currentSystemTime) const{

    if (deadline < (currentSystemTime + requiredTime))
        return false;
    else
        return true;

}
/*
* getId
*
* This function returns the id of a process.
*
* Parameters:
*
* Return value: An integer representing the id of the
* process.
*/
int Process::getId() const{

    return id;

}
/*
* operator<
*
* This function determines which process would be considered
* less than another. Overloads the < operator.
*
* Parameters: A constant referenced process object.
*
* Return value: Boolean value that represents whether or not a
* process is less than another.
*/
bool Process::operator<(const Process &p) const{

    if (p.deadline < deadline)
        return false;
    else if (deadline < p.deadline)
        return true;
    else{
            if (p.requiredTime < requiredTime)
                return false;
            else if (requiredTime < p.requiredTime)
                return true;
            else{

                    if (p.id < id)
                        return false;
                    else if (id < p.id)
                        return true;
            }
    }

}
/*
* operator>>
*
* This function overloads the insertion operator.
*
* Parameters: An istream object and a referenced process.
*
* Return value: Returns an istream to be stored as the objects.
*/
istream &operator>>(istream &is, Process &p){
    
    is >> p.deadline;
    is >> p.requiredTime;
    is.ignore(1, 1);
    getline(is, p.information);
    return is;

}