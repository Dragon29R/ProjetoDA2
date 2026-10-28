#include "VertexEdge.h"

/************************* Vertex  **************************/

Vertex::Vertex(int id): id(id) {}

Edge * Vertex::addEdge(Vertex *d, double w) {
    auto newEdge = new Edge(this, d, w);
    adj[d->getId()] = newEdge;
    d->incoming.push_back(newEdge);

    return newEdge;
}

bool Vertex::removeEdge(int destID) {
    bool removedEdge = false;
    auto it = adj.find(destID);
    if (it != adj.end()) {
        Edge* edge = it->second;
        adj.erase(it);
        deleteEdge(edge);
        removedEdge = true;
    }
    return removedEdge;
}

void Vertex::removeOutgoingEdges() {
    for (auto& entry : adj) {
        Edge* edge = entry.second;
        deleteEdge(edge);
    }
    adj.clear();
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

int Vertex::getId() const {
    return this->id;
}

std::vector<Edge*> Vertex::getAdj() const {
    std::vector<Edge*> adjacencyList;
    for (const auto& entry : adj) {
        adjacencyList.push_back(entry.second);
    }
    return adjacencyList;
}

bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}
string Vertex::getName(){
    return this->name;
}
double Vertex::getLongitude() {
    return this->longitude;
}
double Vertex::getLatitude() {
    return this->latitude;
}
void Vertex::setId(int id) {
    this->id = id;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}
void Vertex::setName(string name){
    this->name = name;
}
void Vertex::setLongitude(double longitude) {
    this->longitude = longitude;
}
void Vertex::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Vertex::deleteEdge(Edge *edge) {
    Vertex *dest = edge->getDest();
    // Remove the corresponding edge from the incoming list
    auto it = dest->incoming.begin();
    while (it != dest->incoming.end()) {
        if ((*it)->getOrig()->getId() == id) {
            it = dest->incoming.erase(it);
        }
        else {
            it++;
        }
    }
    delete edge;
}



/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double w): orig(orig), dest(dest), weight(w) {}


Vertex * Edge::getDest() const {
    return this->dest;
}


double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}


Edge *Edge::getReverse() const {
    return this->reverse;
}


bool Edge::isSelected() const {
    return this->selected;
}


double Edge::getFlow() const {
    return flow;
}


void Edge::setSelected(bool selected) {
    this->selected = selected;
}


void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}


void Edge::setFlow(double flow) {
    this->flow = flow;
}
