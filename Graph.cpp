#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::unordered_map<int, Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}

Vertex* Graph::findVertex(const int& id) const {
    auto it = vertexSet.find(id);
    if (it != vertexSet.end())
        return it->second;
    return nullptr;
}

Vertex* Graph::addVertex(const int& id) {
    auto vertex = new Vertex(id);
    vertexSet[id] = vertex;
    return vertex;
}

bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    e1->setSelected(false);
    auto e2 = v2->addEdge(v1, w);
    e2->setSelected(false);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}
void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}

bool Graph::removeVertex(const int& id) {
    auto it = vertexSet.find(id);
    if (it != vertexSet.end()) {
        auto v = it->second;
        v->removeOutgoingEdges();
        for (auto& pair : vertexSet) {
            pair.second->removeEdge(id);
        }
        vertexSet.erase(it);
        delete v;
        return true;
    }
    return false;
}



Edge* Graph::findEdge(int orig , int dest){
    Vertex* v = findVertex(orig);
    if(v== nullptr){
        return nullptr;
    }
    for(Edge* e : v->getAdj()){
        if(e->getDest()->getId() == dest ){
            return e;
        }
    }
    return nullptr;
}

void Graph::resetGraph() {
    vertexSet.clear();
}



