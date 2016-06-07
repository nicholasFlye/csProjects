/* CSI 3334
* Project  -- Network Broadcasting
* Filename: graph-proj6.cpp
* Student name: Nicholas Flye
* Date: 12/15/2013
* Due Date: 12/11/2013
*
* This file contains the source code to find a simulated shortest
* delay time from a designated source computer to all other machines
* across a network in order to broadcast a television program.
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <sstream>
#include "arrayheap-student-proj6.h"
#include "graph-proj6.h"

using namespace std;
/* main
*  parameters:
*
*  return value: 0 (indicating a successful run)
*
*  main extracts data from a list of machines and their delay
*  times to each other to find a possible server to broadcast
*  a television program from. main makes use of the Graph class in
*  order to find the shortest delay time from all possible
*  machines that could run as a server. If the server(s) is/are
*  found, it is displayed along with the total delay time to all
*  machines. Else, if a machine is not reachable in the graph, an
*  error message is displayed.
*/
int main(){

    //Extract data from the file in order to contruct the network.
    int numOfConnections = 0;
    int delayTime = 0;
    vector<int> delayTimes;
    vector< pair<int, int> > networkConnections;
    map<string, int> machineToLocation;
    map<int, string> locationToMachine;

    const int INFINITE_COST = 1000000000;

    cin >> numOfConnections;

    int connectionCount = 0;
    string machineNameF = "";
    string machineNameT = "";
    int machineCount = 0;
    bool done = false;
    int connectFrom = 0;
    int connectTo = 0;

    while (!done){

        if (connectionCount == numOfConnections){

            done = true;

        }
        else{

            cin >> machineNameF;
            cin >> machineNameT;

            if (machineToLocation.find(machineNameF) == machineToLocation.end()){
                size_t location = machineToLocation.size();
                machineToLocation[machineNameF] = location;
                locationToMachine[location] = machineNameF;
            }
            if (machineToLocation.find(machineNameT) == machineToLocation.end()){
                size_t location = machineToLocation.size();
                machineToLocation[machineNameT] = location;
                locationToMachine[location] = machineNameT;
            }

            pair<int, int> connection(machineToLocation[machineNameF], 
                           machineToLocation[machineNameT]);
            networkConnections.push_back(connection);

            cin >> delayTime;
            delayTimes.push_back(delayTime);
            connectionCount++;

        }
    }

    //Construct the graph of network connections.
    Graph network(machineToLocation.size());
    vector<int> shortestPath;
    int positionFrom = 0;
    int positionTo = 0;

    for (int i = 0; i < networkConnections.size(); i++){

        positionFrom = networkConnections[i].first;
        positionTo = networkConnections[i].second;
        network.addEdge(positionFrom, positionTo, delayTimes[i]);

    }

    //Find the shortest path from all machines in each city.

        vector<int> totalDelayTimes;
        vector< pair<int, int> > serverDelays;
        int totalDelay = 0;
        vector<int> validServers;
        int unreachable = 0;
        string server = "_server";
        vector<string> serverMachines;
        map<string, int>::iterator lookAt = machineToLocation.begin();

        for (; lookAt != machineToLocation.end(); lookAt++){

            string serverMachine = lookAt->first;

            bool a_server = serverMachine.rfind(server) == serverMachine.size() - server.size()
                && serverMachine.rfind(server) != string::npos;

            if (a_server){

                shortestPath = network.dijkstra(lookAt->second);
                for(int x = 0; x < shortestPath.size(); x++){

                    if (shortestPath[x] >= INFINITE_COST)
                        unreachable++;
                    if (unreachable < 1){
                        totalDelay += shortestPath[x];
                    }
                }
                if (unreachable < 1){

                    pair<int, int> bestDelays(totalDelay, lookAt->second);
                    serverDelays.push_back(bestDelays);

                }
           }
            unreachable = 0;
            totalDelay = 0;
        }

    //Check if any valid servers are available to serve
    //the entire network. If there are no valid servers,
    //print an error message.
    if (serverDelays.size() < 1)
        cout << "No server can serve the whole network" << endl;
    else{
        
        vector<string> bestServers;
        sort(serverDelays.begin(), serverDelays.end());
        int shortestDelayTime = serverDelays[0].first;


        for (int i = 0; i < serverDelays.size(); i++){

            if (serverDelays[i].first == shortestDelayTime){

                bestServers.push_back(locationToMachine[serverDelays[i].second]);

            }
        }

        //Display best server(s)
        sort(bestServers.begin(), bestServers.end());

        cout << "Total delay: " << shortestDelayTime << endl;
        cout << "Best server(s):" << endl;
        for (int x = 0; x < bestServers.size(); x++){

            cout << bestServers[x] << endl;

        }
    }

    return 0;

}