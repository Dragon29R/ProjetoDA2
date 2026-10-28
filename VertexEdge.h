#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "MutablePriorityQueue.h"
#include <string>
#include <unordered_map>

using namespace std;
class Edge;

#define INF std::numeric_limits<double>::max()

/**
 * @class Vertex
 * @brief Represents an station.
 *
 * The Vertex class represents a vertex in a graph, with its ID, adjacent edges, visited status, processing status, indegree, distance, path, incoming edges..

 */
class Vertex {
public:
    /**

    *@brief Constructs a new Vertex object with the given ID.
    *@param id The ID of the vertex.
    */
    Vertex(int id);
    /**

    *@brief Overloads the less-than operator for vertices, required by MutablePriorityQueue.
    *@param vertex The vertex to compare with.
    *@return True if this vertex has a lower ID than the given vertex, false otherwise.
    */
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    /**

    *@brief Returns the ID of the vertex.
    *@return The ID of the vertex.
    */
    int getId() const;
    /**

    *@brief Returns the adjacent edges of the vertex.
    *@return The adjacent edges of the vertex.
    */
    vector<Edge *> getAdj() const;
    /**

    *@brief Returns the visited status of the vertex.
    *@return True if the vertex has been visited, false otherwise.
    */
    bool isVisited() const;
    /**

    *@brief Returns the processing status of the vertex.
    *@return True if the vertex is currently being processed, false otherwise.
    */
    bool isProcessing() const;
    /**

    *@brief Returns the indegree of the vertex.
    *@return The indegree of the vertex.
    */
    unsigned int getIndegree() const;
    /**

    *@brief Returns the distance of the vertex.
    *@return The distance of the vertex.
    */
    double getDist() const;
    /**

    *@brief Returns the path of the vertex.
    *@return The path of the vertex.
    */
    Edge *getPath() const;
    /**

    *@brief Returns the incoming edges of the vertex.
    *@return The incoming edges of the vertex.
    */
    vector<Edge *> getIncoming() const;

    string getName();
    double getLongitude();
    double getLatitude();
    /**

    *@brief Sets the ID of the vertex.
    *@param info The new ID of the vertex.
    */
    void setId(int info);
    /**

    *@brief Sets the visited status of the vertex.
    *@param visited The new visited status of the vertex.
    */
    void setVisited(bool visited);
    /**

    *@brief Sets the processing status of the vertex.
    *@param processing The new processing status of the vertex.
    */
    void setProcesssing(bool processing);
    /**

    *@brief Sets the indegree of the vertex.
    *@param indegree The new indegree of the vertex.
    */
    void setIndegree(unsigned int indegree);
    /**

    *@brief Sets the distance of the vertex.
    *@param dist The new distance of the vertex.
    */
    void setDist(double dist);
    /**

    *@brief Sets the path of the vertex.
    *@param path The new path of the vertex.
    */
    void setPath(Edge *path);

    void setName(string name);
    void setLongitude(double longitude);
    void setLatitude(double latitude);
    /**

    *@brief Adds a new outgoing edge from this vertex to the given destination vertex.
    *@param dest The destination vertex of the edge.
    *@param w The weight of the edge.
    *@return A pointer to the newly created edge.
    */
    Edge * addEdge(Vertex *dest, double w);
    /**

    *@brief Removes the outgoing edge with the given destination vertex ID from this vertex.
    *@param destID The ID of the destination vertex of the edge to remove.
    *@return True if the edge was successfully removed, false otherwise.
    *@complexity O(E), where E is the number of edges
    */
    bool removeEdge(int destID);
    /**

    *@brief Removes all outgoing edges from this vertex.
    *@complexity O(E), where E is the number of edges
    */
    void removeOutgoingEdges();

    friend class MutablePriorityQueue<Vertex>;


protected:
    /**
     * @brief The identifier of the vertex.
     */
    int id;
    /**
     * @brief The list of outgoing edges from the vertex.
     */
    std::unordered_map<int, Edge*> adj;
    /**
     * @brief A boolean flag to indicate if the vertex has been visited.
     * @details This is used by DFS, BFS, Prim algorithms, and other graph traversals.
     */
    bool visited = false;
    /**
     * @brief A boolean flag to indicate if the vertex is currently being processed.
     * @details This is used by the isDAG algorithm, in addition to the visited attribute.
     */
    bool processing = false;
    /**
     * @brief The number of incoming edges to the vertex.
     * @details This is used by the topsort algorithm.
     */
    unsigned int indegree;
    /**
    * @brief The shortest known distance from the start vertex to this vertex.
    * @details This is used by various shortest path algorithms.
    */
    double dist = 0;
    /**
     * @brief The path taken from the start vertex to this vertex.
     * @details This is used by various shortest path algorithms.
     */
    Edge *path = nullptr;
    /**
     * @brief The list of incoming edges to the vertex.
     */
    std::vector<Edge *> incoming;
    /**
     * @brief The index of the vertex in the queue of a mutable priority queue or a UFDS.
     * @details This is required by the MutablePriorityQueue and UFDS classes.
     */
    int queueIndex = 0;
    /**
     * @brief Deletes the given edge from the vertex's list of outgoing edges.
     * @param edge A pointer to the edge to be deleted.
     * @complexity O(E) , where E is the number of edges
     */
    void deleteEdge(Edge *edge);

    string name;
    double longitude;
    double latitude;
};


/**
 * @class Edge
 * @brief Represents an line between 2 vertexs.
 *
 * The Edge class represents a line in a graph, with its origin vertex , dest vertex , weight.

 */
class Edge {
public:
    /**
    * @brief Constructs a new edge with the given origin, destination, and weight.
    * @param orig The origin vertex.
    * @param dest The destination vertex.
    * @param w The weight of the edge.
    */
    Edge(Vertex *orig, Vertex *dest, double w);
    /**
    * @brief Gets the destination vertex of the edge.
    * @return The destination vertex of the edge.
    */
    Vertex * getDest() const;
    /**
    * @brief Gets the weight of the edge.
    * @return The weight of the edge.
    */
    double getWeight() const;
    /**
    * @brief Gets whether the edge is selected or not.
    * @return Whether the edge is selected or not.
    */
    bool isSelected() const;
    /**
    * @brief Gets the origin vertex of the edge.
    * @return The origin vertex of the edge.
    */
    Vertex * getOrig() const;
    /**
    * @brief Gets the reverse edge of the current edge.
    * @return The reverse edge of the current edge.
    */
    Edge *getReverse() const;
    /**
    * @brief Gets the flow of the edge.
    * @return The flow of the edge.
    */
    double getFlow() const;
    /**
    * @brief Sets whether the edge is selected.
    * @param selected Whether the edge should be selected.
    */
    void setSelected(bool selected);
    /**
    * @brief Sets the reverse edge of the current edge.
    * @param reverse The reverse edge to set.
    */
    void setReverse(Edge *reverse);
    /**
    * @brief Sets the flow of the edge.
    * @param flow The flow to set.
    */
    void setFlow(double flow);

protected:
    /**
    * @brief The destination vertex.
    */
    Vertex * dest;
    /**
    * @brief The weight of the edge.
    */
    double weight;
    /**
    * @brief The selection of the edge.
    */
    bool selected = false;

    Vertex *orig;
    Edge *reverse = nullptr;
    /**
    * @brief The flow of the edge.
    */
    double flow;

};
