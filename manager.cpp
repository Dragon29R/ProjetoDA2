#include "manager.h"
#include <chrono>
#include <iomanip>

using namespace std;



void Manager::ReadFileToyGraphTourism() {
    ifstream file;
    file.open("../docs/Toy-Graphs/tourism.csv");

    if(!file.is_open()){
        cerr << "Error opening the file" << endl;
    }

    string line, origemtemp, destinotemp, distancia , origem_name , destino_name;
    int origem, destino;
    double dist;

    getline(file,line,'\n'); //skip the first line

    while(file.good()){

        getline(file,line,'\n');
        if(line==""){
            break;
        }
        stringstream partition(line);

        getline(partition,origemtemp,',');
        origem = stod(origemtemp);
        getline(partition,destinotemp,',');
        destino = stod(destinotemp);

        getline(partition,distancia,',');
        dist = stod(distancia);

        getline(partition,origem_name,',');
        getline(partition,destino_name,',');

        if(network.findVertex(origem)== nullptr){
            network.addVertex(origem);
            Vertex* v =network.getVertexSet()[origem];
            v->setName(origem_name);
            v->setLatitude(0);
            v->setLongitude(0);
        }
        if(network.findVertex(destino)== nullptr){
            network.addVertex(destino);
            Vertex* v =network.getVertexSet()[destino];
            v->setName(destino_name);
            v->setLatitude(0);
            v->setLongitude(0);
        }

        network.addBidirectionalEdge(origem,destino,dist);
    }
}

void Manager::ReadFileToyGraphShipping() {
    ifstream file;
    file.open("../docs/Toy-Graphs/shipping.csv");

    if(!file.is_open()){
        cerr << "Error opening the file" << endl;
    }

    string line, origemtemp, destinotemp, distanciatemp ;
    int origem, destino;
    double dist;

    getline(file,line,'\n'); //skip the first line

    while(file.good()){

        getline(file,line,'\n');
        if(line==""){
            break;
        }
        stringstream partition(line);

        getline(partition,origemtemp,',');
        origem = stoi(origemtemp);
        getline(partition,destinotemp,',');
        destino = stoi(destinotemp);

        getline(partition,distanciatemp,',');
        dist = stod(distanciatemp);

        if(network.findVertex(origem)== nullptr){
            network.addVertex(origem);
            Vertex* v =network.getVertexSet()[origem];
            v->setLatitude(0);
            v->setLongitude(0);
        }
        if(network.findVertex(destino)== nullptr){
            network.addVertex(destino);
            Vertex* v =network.getVertexSet()[destino];
            v->setLatitude(0);
            v->setLongitude(0);
        }
        network.addBidirectionalEdge(origem,destino,dist);
    }

}

void Manager::ReadFileToyGraphStadiums(){
    ifstream file;
    file.open("../docs/Toy-Graphs/stadiums.csv");

    if(!file.is_open()){
        cerr << "Error opening the file" << endl;
    }

    string line, origemtemp, destinotemp, distancia ;
    int origem, destino;
    double dist;

    getline(file,line,'\n'); //skip the first line

    while(file.good()){

        getline(file,line,'\n');
        if(line==""){
            break;
        }
        stringstream partition(line);

        getline(partition,origemtemp,',');
        origem = stod(origemtemp);
        getline(partition,destinotemp,',');
        destino = stod(destinotemp);

        getline(partition,distancia,',');
        dist = stod(distancia);

        if(network.findVertex(origem)== nullptr){
            network.addVertex(origem);
            Vertex* v =network.getVertexSet()[origem];
            v->setLatitude(0);
            v->setLongitude(0);
        }
        if(network.findVertex(destino)== nullptr){
            network.addVertex(destino);
            Vertex* v =network.getVertexSet()[destino];
            v->setLatitude(0);
            v->setLongitude(0);
        }

        network.addBidirectionalEdge(origem,destino,dist);
    }

}

void Manager::ReadMediumGraphs(string node_number) {
    ifstream file;
    string file_ = "../docs/Extra_Fully_Connected_Graphs/edges_" + node_number + ".csv";
    file.open(file_);

    if(!file.is_open()){
        cerr << "Error opening the file" << endl;
    }
    string line, origem, destino, distancia;
    while(file.good()){

        getline(file,line,'\n');
        if(line==""){
            break;
        }
        stringstream partition(line);

        getline(partition,origem,',');

        getline(partition,destino,',');


        getline(partition,distancia,',');


        if(network.findVertex(stoi(origem))== nullptr){
            network.addVertex(stoi(origem));
        }
        if(network.findVertex(stoi(destino))== nullptr){
            network.addVertex(stoi(destino));
        }
        network.addBidirectionalEdge(stoi(origem),stoi(destino),stod(distancia));
    }
}

void Manager::ReadRealWorldGraphs(string file_number) {
    ifstream file;
    string file_nodes = "../docs/Real-world-Graphs/graph" + file_number + "/nodes.csv";
    string file_edges = "../docs/Real-world-Graphs/graph" + file_number + "/edges.csv";

    file.open(file_nodes);

    if (!file.is_open()) {
        cerr << "Error opening the file" << endl;
    }

    string line, id, latitude, longitude;

    getline(file,line,'\n');
    while(file.good()) {
        getline(file,line,'\n');
        if(line=="") {
            break;
        }
        stringstream partition(line);

        getline(partition,id,',');
        Vertex* vertex = network.addVertex(stoi(id));

        getline(partition,longitude,',');
        vertex->setLongitude(stod(longitude));
        getline(partition,latitude,',');
        vertex->setLatitude(stod(latitude));
    }

    file.close();

    file.open(file_edges);

    if (!file.is_open()) {
        cerr << "Error opening the file" << endl;
    }

    string origem, destino , distancia;
    getline(file,line,'\n');
    while(file.good()){

        getline(file,line,'\n');
        if(line=="") {
            break;
        }

        stringstream partition(line);

        getline(partition,origem,',');
        getline(partition,destino,',');
        getline(partition,distancia,',');

        network.addBidirectionalEdge(stoi(origem),stoi(destino),stod(distancia));
    }
}

tuple<vector<int>, double, double> Manager::tspBacktracking() {
    auto startTime = chrono::high_resolution_clock::now();
    vector<int> path;
    int startingVertexId = 0;
    double bestCost = numeric_limits<double>::max();
    vector<int> bestPath;

    Vertex* startingVertex = network.findVertex(startingVertexId);
    if (startingVertex != nullptr) {
        startingVertex->setVisited(true);
        path.push_back(startingVertexId);
        tspBacktrackingUtil(startingVertex, path, 0, bestCost, bestPath);
        startingVertex->setVisited(false);
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    resetGraph();

    return {bestPath, bestCost, duration};
}

void Manager::tspBacktrackingUtil(Vertex* currentVertex, vector<int>& path, double cost, double& bestCost, vector<int>& bestPath) {
    int numVertices = network.getNumVertex();
    if (path.size() == numVertices) {
        Edge* returnEdge = network.findEdge(currentVertex->getId(), network.findVertex(0)->getId());
        if (returnEdge != nullptr) {
            float totalCost = cost + returnEdge->getWeight();
            if (totalCost < bestCost) {
                bestCost = totalCost;
                bestPath = path;
            }
        }
        return;
    }

    for (Edge* neighbor : currentVertex->getAdj()) {
        Vertex* neighborVertex = neighbor->getDest();
        if (!neighborVertex->isVisited()) {
            neighborVertex->setVisited(true);
            path.push_back(neighborVertex->getId());
            double edgeCost = neighbor->getWeight();
            tspBacktrackingUtil(neighborVertex, path, cost + edgeCost, bestCost, bestPath);
            path.pop_back();
            neighborVertex->setVisited(false);
        }
    }
}

double Manager::haversine(double lat1, double lon1, double lat2, double lon2) {
    double lat1Rad = lat1 * M_PI / 180.0;
    double lon1Rad = lon1 * M_PI / 180.0;
    double lat2Rad = lat2 * M_PI / 180.0;
    double lon2Rad = lon2 * M_PI / 180.0;

    double dlat = lat2Rad - lat1Rad;
    double dlon = lon2Rad - lon1Rad;
    double a = pow(sin(dlat / 2), 2) + cos(lat1Rad) * cos(lat2Rad) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = RADIUS_OF_EARTH * c;

    return distance;
}

void Manager::prim() {
    MutablePriorityQueue<Vertex> q;
    for (auto v: network.getVertexSet()){
        v.second->setDist(INT32_MAX);
        v.second->setVisited(false);
        q.insert(v.second);
    }
    network.findVertex(0)->setDist(0);
    network.findVertex(0)->setPath(nullptr);
    network.findVertex(0)->setVisited(true);
    q.decreaseKey(network.findVertex(0));
    while (!q.empty()){
        Vertex* u = q.extractMin();
        for (Edge* e:u->getAdj()){
            Vertex* w = e->getDest();
            if (!w->isVisited() && e->getWeight() < w->getDist()){
                w->setPath(e);

                w->setDist(e->getWeight());
                q.decreaseKey(w);
            }
        }
        u->setVisited(true);
    }
    for (const auto v : network.getVertexSet()) {
        v.second->setVisited(false);
        Edge* path = v.second->getPath();
        if (path != nullptr) {
            path->setSelected(true);
            path->getReverse()->setSelected(true);
        }
    }


}

tuple<double, double> Manager::tspApproximation() {
    auto startTime = chrono::high_resolution_clock::now();

    prim();

    Vertex* startVertex = network.findVertex(0);
    for(auto v:network.getVertexSet()) {v.second->setVisited(false);}
    vector<Vertex*> path;
    dfs(startVertex,path);
    path.push_back(network.findVertex(0));
    double totalDistance = ApproximationDistance(path);

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();

    resetGraph();
    return {totalDistance, duration};
}

void Manager::dfs(Vertex* vertex, vector<Vertex*>& path) {
    vertex->setVisited(true);
    path.push_back(vertex);

    vector<Edge*> sortedEdges;

    for (Edge* edge : vertex->getAdj()) {
        if (!edge->getDest()->isVisited() && edge->isSelected()) {
            sortedEdges.push_back(edge);
        }
    }

    sort(sortedEdges.begin(), sortedEdges.end(), [](Edge* a, Edge* b) {
        return a->getWeight() < b->getWeight();
    });

    for (Edge* edge : sortedEdges) {
        Vertex* destVertex = edge->getDest();

        if (!destVertex->isVisited()) {
            dfs(destVertex, path);
        }
    }
}

double Manager::ApproximationDistance(const vector<Vertex*>& path) {
    double totalDistance = 0.0;
    remove("path_result.txt");

    ofstream outputFile("../path_result.txt");
    if (outputFile.is_open()) {
        outputFile << "Approximated Path: \n";

        for (size_t i = 0; i < path.size() - 1; ++i) {
            Vertex* vertex = path[i];
            Vertex* nextVertex = path[i + 1];
            Edge* edge = network.findEdge(vertex->getId(), nextVertex->getId());
            if (edge != nullptr) {
                outputFile << to_string(vertex->getId()) + " -> " + to_string(nextVertex->getId()) << ' ';
                outputFile << "distance: " << fixed << setprecision(1) << edge->getWeight() << " (Direct connection)\n";
                totalDistance += edge->getWeight();
            }
            else {
                double lat1 = vertex->getLatitude();
                double lon1 = vertex->getLongitude();
                double lat2 = nextVertex->getLatitude();
                double lon2 = nextVertex->getLongitude();
                double distance = haversine(lat1, lon1, lat2, lon2);
                outputFile << to_string(vertex->getId()) + " -> " + to_string(nextVertex->getId()) << ' ';
                outputFile << "distance: " << fixed << setprecision(1) << distance << " (Haversine connection)\n";
                totalDistance += distance;
            }
        }

        outputFile.close();
        cout << "Path result saved to 'path_result.txt'" << endl;
    } else {
        cout << "Unable to open output file" << endl;
    }

    return totalDistance;
}

tuple<double, double> Manager::christofides() {
    auto startTime = chrono::high_resolution_clock::now();

    Graph newGraph = createNewGraph(network);

    vector<Vertex*> oddVertices;
    for (const auto& vertex : newGraph.getVertexSet()) {
        vertex.second->setVisited(false);
        if (vertex.second->getAdj().size() % 2 != 0) {
            oddVertices.push_back(vertex.second);
        }
    }

    Graph matching = minimumWeightMatching(oddVertices);

    Graph finalmatching = createNewGraph(matching);

    Graph graphmerged = mergeGraphs(newGraph, finalmatching);

    vector<Vertex*> finalPath;

    for (auto v: graphmerged.getVertexSet())  {
        v.second->setVisited(false);
        for(Edge* e: v.second->getAdj()) {
            e->setSelected(true);
        }
    }

    dfs(graphmerged.findVertex(0), finalPath);

    vector<Vertex*> finalPathFixed;

    for(auto v: finalPath){
        finalPathFixed.push_back(network.findVertex(v->getId()));
    }

    finalPathFixed.push_back(network.findVertex(0));

    double totalDistance = ApproximationDistance(finalPathFixed);

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();

    resetGraph();

    return {totalDistance, duration};
}

Graph Manager::createNewGraph(Graph TemplateGraph) {
    Graph newGraph;
    MutablePriorityQueue<Vertex> q;
    for (const auto& vertex : TemplateGraph.getVertexSet()) {
        Vertex* v = vertex.second;
        newGraph.addVertex(v->getId());
        v->setDist(INT64_MAX);
        v->setVisited(false);
        q.insert(v);
    }

    Vertex* first = TemplateGraph.getVertexSet().begin()->second;
    first->setDist(0);
    q.decreaseKey(first);

    while (!q.empty()) {
        first = q.extractMin();
        first->setVisited(true);

        if (first->getPath() != nullptr) {
            Edge* path = first->getPath();
            newGraph.addBidirectionalEdge(path->getOrig()->getId(), path->getDest()->getId(), path->getWeight());
        }

        for (Edge* edge : first->getAdj()) {
            Vertex* u = edge->getDest();
            if (!u->isVisited() && edge->getWeight() < u->getDist()) {
                u->setPath(edge);
                u->setDist(edge->getWeight());
                q.decreaseKey(u);
            }
        }
    }

    return newGraph;
}

Graph Manager::minimumWeightMatching(const std::vector<Vertex*>& vertices) {
    Graph matching;
    for(int i = 0 ; i <vertices.size();++i){
        matching.addVertex(vertices[i]->getId());
    }
    for(int i = 0 ; i < vertices.size() - 1;++i){
        Vertex* source = vertices[i];
        Vertex* sourceOriginal = network.findVertex(source->getId());
        for(int j = i + 1 ; j < vertices.size();++j){
            Vertex* dest = vertices[j];
            Vertex* destOriginal = network.findVertex(dest->getId());
            double dist = network.findEdge(sourceOriginal->getId(),destOriginal->getId())->getWeight();

            matching.addBidirectionalEdge(source->getId(),dest->getId(),dist);
        }
    }
    return matching;
}

Graph Manager::mergeGraphs(Graph graph, Graph graph1) {
    Graph finalGraph = graph;

    for (const auto& vertex : graph1.getVertexSet()) {
        Vertex* source = vertex.second;

        for (const auto& edge : source->getAdj()) {
            Vertex* dest = edge->getDest();
            double weight = edge->getWeight();

            if (finalGraph.findEdge(source->getId(), dest->getId()) == nullptr)
                finalGraph.addEdge(source->getId(), dest->getId(), weight);
        }
    }

    return finalGraph;
}

void Manager::resetGraph() {
    network.resetGraph();
}


