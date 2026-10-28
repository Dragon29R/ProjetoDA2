
#ifndef DA2_MANAGER_H
#define DA2_MANAGER_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stack>
#include <unordered_set>
#include "Graph.h"


const double RADIUS_OF_EARTH = 6371000.0;      // Radius of the Earth in meters
/**
 * @class Manager
 * @brief Manages the whole system and provides various functions needed for the various applications.
 */
class  Manager{
    public:
        Graph network;
/**
 * @brief Reads the file tourism file and  creates a graph with the information in it.
 * @Complexity O(V*E),Where V is the number of vertexs and E is the number of edges.
 */
        void ReadFileToyGraphTourism();
/**
 * @brief Reads the file shipping file and  creates a graph with the information in it.
 * @Complexity O(V*E),Where V is the number of vertexs and E is the number of edges.
 */
        void ReadFileToyGraphShipping();

/**
 * @brief Reads the file stadiums file and  creates a graph with the information in it.
 * @Complexity O(V*E),Where V is the number of vertexs and E is the number of edges.
 */
        void ReadFileToyGraphStadiums();

/**
 * @param file_number
 * @brief Reads the RealWorldGraph file nª file_number and  creates a graph with the information in it.
 * @Complexity O(V+E),Where V is the number of vertexs and E is the number of edges.
 */
        void ReadRealWorldGraphs(string file_number);

/**
 * @brief Reads the ReadMediumGraph file nº node_number and  creates a graph with the information in it.
 * @param node_number
 * @Complexity O(V*E),Where V is the number of vertexs and E is the number of edges.
 */
        void ReadMediumGraphs(string node_number);


/**
 * @brief This function performs the traveling salesman problem using backtracking algorithm.
 * @Complexity O(2^V), where V is the number of vertexs.
 */
    tuple<vector<int>, double, double> tspBacktracking();

/**
 * @brief This function calculates an approximate solution to the Traveling Salesman Problem (TSP)
 * using a combination of Prim's algorithm, Depth-First Search (DFS), and other utility functions.
 *
 * @return A tuple containing the total distance of the approximate TSP solution and the duration of the function execution.
 * @Complexity O((V + E) log V), where V is the number of vertexs.
 */
    tuple<double, double> tspApproximation();

/**
 * @brief Applies the Christofides algorithm to find an approximate solution to the Traveling Salesman Problem (TSP).
 * @Complexity O((V+E)*V^2), where V is the number of vertexs.
 */
        tuple<double, double> christofides();

private:

/**
 * @brief function used by tspBacktracking() to recursively find the best path for the Traveling Salesman Problem (TSP).
 * It explores all possible paths in a depth-first manner and updates the bestCost and bestPath variables accordingly.
 *
 * @param currentVertex: Pointer to the current vertex being visited in the path.
 * @param path: Reference to the vector that stores the current path being explored.
 * @param cost: The cost of the current path.
 * @param bestCost: Reference to the variable storing the best cost found so far.
 * @param bestPath: Reference to the vector storing the best path found so far.
 * @Complexity O(2^V), where V is the number of vertexs.
 */
        void tspBacktrackingUtil(Vertex* currentVertex, vector<int>& path, double cost, double& bestCost, vector<int>& bestPath);
/**
 * @brief Calculates the Haversine distance between two points on the Earth's surface
 *
 *
 * @param lat1 Latitude of the first point in degrees
 * @param lon1 Longitude of the first point in degrees
 * @param lat2 Latitude of the second point in degrees
 * @param lon2 Longitude of the second point in degrees
 * @return The Haversine distance between the two points in the same unit as the Earth's radius
 * @Complexity O(1)
 */
        double haversine(double lat1, double lon1, double lat2, double lon2);
/**
 * @brief Applies the Prim's algorithm to find a minimum spanning tree in the network.
 * @Complexity O((V+E) * log V) , where V is the number of vertexs and E is the number of edges.
 */
        void prim();
/**
* @brief Performs a depth-first search (DFS) starting from the given vertex, exploring only the selected edges.
* @param vertex The starting vertex for the DFS.
* @param path A vector to store the visited path.
 *@Complexity O(V+E), where V is the number of vertexs and E is the number of edges.
*/
        void dfs(Vertex *vertex, vector<Vertex*> &path);

/**
 * @brief Calculates the total approximate distance of a given path, considering both direct connections and Haversine connections.
 * @param path A vector containing the vertices of the path.
 * @return The total distance of the path.
 */
        double ApproximationDistance(const vector<Vertex *> &path);
/**
*
* @brief Creates a new graph based on a template graph.
* @param TemplateGraph The template graph to create the new graph from.
* @return The newly created graph.
 *@Complexity O((V+E) log V)
*/
        Graph createNewGraph(Graph TemplateGraph);
/**
 *
 * @brief Creates a minimum weight matching graph based on the given vertices.
 *
 * @param vertices A vector of pointers to vertices.
 * @return The minimum weight matching graph.
 * @Complexity O((V+E)*V^2), where V is the number of vertexs and E is the number of edges.
 */
        Graph minimumWeightMatching(const vector<Vertex *> &vertices);
/**
 * @brief resets the graph.
 * @Complexity O(V), where V is the number of vertexs.
 */
        void resetGraph();

/**
 * @brief Merges two graphs into one.
 * @param graph
 * @param graph1
 * @return
 * @Complexity O(V1*E1*(V+E)), where V is the number of vertexs and E is the number of edges of graph and V1 is the number of vertexs and E1 is the number of edges of graph1.
 */
        Graph mergeGraphs(Graph graph, Graph graph1);
};

#endif
