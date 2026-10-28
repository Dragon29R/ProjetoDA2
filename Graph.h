
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include "MutablePriorityQueue.h"
#include "VertexEdge.h"
/**
 * @brief The Graph class represents a graph, which is a collection of vertices and edges.
 */
class Graph {
public:

    /**
     * @brief Destroys the Graph object and frees its resources.
     */
    ~Graph();
    /**
        * @brief Finds the vertex with the given ID.
        * @param id The ID of the vertex to find.
        * @return A pointer to the vertex if it is found, or nullptr otherwise.
        * @Complexity O(V), where V is the number of vertexs.
        */
    Vertex *findVertex(const int &id) const;
    /**
     * @brief Adds a new vertex with the given ID to the graph.
     * @param id The ID of the vertex to add.
     * @return true if the vertex is added successfully, or false if a vertex with the same ID already exists in the graph.
     */
    Vertex* addVertex(const int &id);


    /**
     * @brief Adds a new edge to the graph.
     * @param sourc The ID of the source vertex.
     * @param dest The ID of the destination vertex.
     * @param w The weight of the edge.
     * @return true if the edge is added successfully, or false if either the source or the destination vertex is not found in the graph.
     * @Complexity O(V), where V is the number of vertexs.
     */
    bool addEdge(const int &sourc, const int &dest, double w);
    /**
     * @brief Adds a new bidirectional edge to the graph.
     * @param sourc The ID of the source vertex.
     * @param dest The ID of the destination vertex.
     * @param w The weight of the edge.
     * @param service The name of the service that operates on the edge.
     * @return true if the edge is added successfully, or false if either the source or the destination vertex is not found in the graph.
     * @Complexity O(V), where V is the number of vertexs.
     */
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);
    /**
     * @brief Gets the number of vertices in the graph.
     * @return The number of vertices in the graph.
     */
    int getNumVertex() const;
    /**
     * @brief Gets the vector of vertices in the graph.
     * @return The vector of vertices in the graph.
     */
    std::unordered_map<int, Vertex*> getVertexSet() const;

    /**
     * @brief Removes the vertex with the given ID from the graph.
     * @param id The ID of the vertex to remove.
     * @return true if the vertex is removed successfully, or false if the vertex is not found in the graph.
     * @Complexity O(V^2), where V is the number of vertexs.
     */
    bool removeVertex(const int &id);

    void resetGraph();

    /**
     * @finds the edge with the given origin and destination.
     * @param orig
     * @param dest
     * @return the edge if it is found, or nullptr otherwise.
     * @Complexity O(E),being E the Edges of the graph .
     */
    Edge *findEdge(int orig, int dest);

protected:
    /**
    * @brief Vector that contains all the vertexs of the graph.
     */
    std::unordered_map<int, Vertex*> vertexSet;    // vertex map

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall




};
/**

@brief Deletes the given integer matrix.
@param m The matrix to delete.
@param n The size of the matrix.
*/
void deleteMatrix(int **m, int n);
/**

@brief Deletes the given double matrix.
@param m The matrix to delete.
@param n The size of the matrix.
*/
void deleteMatrix(double **m, int n);
