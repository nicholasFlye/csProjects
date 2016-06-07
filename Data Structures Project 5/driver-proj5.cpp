/* CSI 3334
* Project  -- Batch Operating System
* Filename: driver-proj5.cpp
* Student name: Nicholas Flye
* Date: 11/21/2013
* Due Date: 11/15/2013
*
* This file contains the implementation of a real time virtual
* bash operating SYSTEM. Processes are  ran virtually to
* determine how to use a minimum heap.
*/
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include "arrayheap-student-proj5.h"
#include "process-proj5.h"

using namespace std;
/*
* main
*
* This function runs the code for a heap and the processes
* stored in the heap. Main runs just like a batch operating
* SYSTEM.
*
* Parameters:
*
* Return value: 0
*/
int main(){
    
    ArrayHeap<Process> processManager;
    int SYSTEMClock = 0;
    int numOfProcesses = 0;
    int submitted = 0;
    int id = 0;
    int startTime = 0;
    
    cin >> numOfProcesses;
    cin >> startTime;

    if (startTime == SYSTEMClock){

        Process SYSTEMProcess(id);
        cin >> SYSTEMProcess;
        processManager.insert(SYSTEMProcess);
        id++;
        submitted++;

    }
    else{

        SYSTEMClock = startTime;
        Process SYSTEMProcess(id);
        cin >> SYSTEMProcess;
        processManager.insert(SYSTEMProcess);
        id++;
        submitted++;

    }

    int numberSkipped = 0;
    int numberRun = 0;

    cin >> startTime;

    while (numOfProcesses > numberRun + numberSkipped){

        while (submitted < numOfProcesses && startTime <= SYSTEMClock){

            Process SYSTEMProcess(id);
            cin >> SYSTEMProcess;
            processManager.insert(SYSTEMProcess);
            submitted++;
            id++;
            if (submitted < numOfProcesses)
                cin >> startTime;

        }

        if (processManager.getMinItem().canComplete(SYSTEMClock)){

            cout << "running process id " << processManager.getMinItem().getId();
            cout << " at " << SYSTEMClock << endl;
            SYSTEMClock = processManager.getMinItem().run(SYSTEMClock);
            numberRun++;
            processManager.removeMinItem();

        }
        else{

            numberSkipped++;
            cout << "skipping process id " << processManager.getMinItem().getId();
            cout << " at " << SYSTEMClock << endl;
            SYSTEMClock++;
            processManager.removeMinItem();

        }

        if (SYSTEMClock < startTime && processManager.getNumItems() == 0)
            SYSTEMClock = startTime;
    }
    
    string finalClock = "final clock is ";
    string run = "number of processes run is ";
    string skipped = "number of processes skipped is ";
    const int JUSTIFY_LENGTH = 31;
    int justifyWidth;

    justifyWidth = JUSTIFY_LENGTH - finalClock.size();
    cout << finalClock << setw(justifyWidth) << "";
    cout << left << SYSTEMClock << endl;

    justifyWidth = JUSTIFY_LENGTH - run.size();
    cout << run << setw(justifyWidth) << "";
    cout << left << numberRun << endl;

    justifyWidth = JUSTIFY_LENGTH - skipped.size();
    cout << skipped << setw(justifyWidth) << "";
    cout << left << numberSkipped << endl;

    return 0;
}