/* CSI 3334
* Project  -- Network Broadcasting
* Filename: graph-proj6.cpp
* Student name: Nicholas Flye
* Date: 12/15/2013
* Due Date: 12/11/2013
*
* This file contains the implementation of the Graph class.
* Within this implementation, a graph is constructed from a list
* of Edge objects, and has the ability to find the shortest paths
* from all vertices with the help of Dijkstra's algorithm.
*/
#include "graph-proj6.h"
#include "arrayheap-student-proj6.h"
#include <algorithm>
#include <cassert>
/*
* addEdge
*
* This function adds new Edge objects to an adjacency list.
*
* Parameters: An integer representation of the vertices (from
* & to) and cost between two vertices are taken as parameters.
*
* Return value: void
*/
void Graph::addEdge(int from, int to, int cost){

    if (from == to)
        cost = 0;

    Edge newEdge(to, cost);
    adjacencyList[from].push_back(newEdge);

}
/*
* dijkstra
*
* This function finds the shortest path from an integer
* representation of a source vertex to all other vertices in
* a Graph object.
*
* Parameters: An integer representation of the source vertex.
*
* Return value: Dijkstra returns a vector of integers that are
* the costs going from the source vertex to all other vertices in
* the graph.
*/
vector<int> Graph::dijkstra(int source) const {

    int vertices_size = adjacencyList.size();
    vector<int> shortestPath;
    vector<bool> visitedVertices;
    vector<int> vertices;
    ArrayHeap<pair<int, int> > minHeap;


    for (int i = 0; i < adjacencyList.size(); i++){

        visitedVertices.push_back(false);
        shortestPath.push_back(INFINITE_COST);
        vertices.push_back(-1);

    }

    int totalDelay = 0;
    pair<int, int> sourceVertex(0, source);
    vertices[source] = minHeap.insert(sourceVertex);
    visitedVertices[source] = true;
    shortestPath[source] = 0;

    while (minHeap.getNumItems() > 0) {

        pair<int, int> minVertex = minHeap.getMinItem();
        minHeap.removeMinItem();

        list<Edge>::const_iterator lookAtCost =
            adjacencyList[minVertex.second].begin();

        visitedVertices[minVertex.second] = true;

        for (int x = 0; x < adjacencyList[minVertex.second].size(); x++){

            totalDelay = minVertex.first + (*lookAtCost).cost;

            if (totalDelay < shortestPath[(*lookAtCost).to]){

                shortestPath[(*lookAtCost).to] = totalDelay;
                pair<int, int> revisedVertex(totalDelay, (*lookAtCost).to);
                minHeap.changeItemAtKey(vertices[(*lookAtCost).to], revisedVertex);
                if (!visitedVertices[(*lookAtCost).to]){

                    if (!minHeap.isOnHeap(vertices[(*lookAtCost).to])){

                        pair<int, int> unvisitedVertex(totalDelay, (*lookAtCost).to);
                        vertices[(*lookAtCost).to] = minHeap.insert(unvisitedVertex);
                    }
                }
            }
            lookAtCost++;
        }
    }

    return shortestPath;

}
