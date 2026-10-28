#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "manager.h"

using namespace std;

void MainMenu(Manager &manager);
void TspBacktrackingMenu(Manager &manager);
void TspApproximationMenu(Manager &manager);
void TspChristofidesMenu(Manager &manager);

void TspBacktracking(Manager &manager);

void TspApproximation(Manager &manager);

void TspApproximationMedium(Manager &manager);
void TspApproximationRealWorld(Manager &manager);

void TspChristofides(Manager &manager);

void TspChristofidesMedium(Manager &manager);
void TspChristofidesRealWorld(Manager &manager);

int main() {
    Manager manager;
    MainMenu(manager);
    return 0;
}

void MainMenu(Manager &manager) {
    while (true) {
        string input;
        do {
            cout << "Main Menu" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Traveling salesman problem with Backtracking" << endl;
            cout << " 2. Traveling salesman problem with Approximation" << endl;
            cout << " 3. Traveling salesman problem with Christofides" << endl;
            cout << " 9. Close program" << endl;
            cout << "Type option: ";
            cin >> input;
            cout << endl;
            if (!(input == "1" || input == "2" || input == "3" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while (!(input == "1" || input == "2" || input == "3" || input == "9"));

        //Menu options
        if (input == "1")
            TspBacktrackingMenu(manager);
        else if (input == "2")
            TspApproximationMenu(manager);
        else if (input == "3")
            TspChristofidesMenu(manager);
        else if (input == "9") {
            cout << "Program successfully closed" << endl;
            return;
        }
    }
}

void TspBacktrackingMenu(Manager &manager) {
    while (true) {
        string input;
        do {
            cout << "Travelling Salesman Problem with Backtracking Menu" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Apply to Tourism." << endl;
            cout << " 2. Apply to Shipping." << endl;
            cout << " 3. Apply to Stadiums." << endl;
            cout << " 9. Go back to previous menu." << endl;
            cout << "Type option: ";
            cin >> input;
            cout << endl;
            if (!(input == "1" || input == "2" || input == "3" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while (!(input == "1" || input == "2" || input == "3" || input == "9"));

        //Menu options
        if (input == "1") {
            manager.ReadFileToyGraphTourism();
            TspBacktracking(manager);
        }
        else if (input == "2") {
            manager.ReadFileToyGraphShipping();
            TspBacktracking(manager);
        }
        else if (input == "3") {
            manager.ReadFileToyGraphStadiums();
            TspBacktracking(manager);
        }
        else if (input == "9")
            return;
    }
}

void TspApproximationMenu(Manager &manager){
    while (true) {
        string input;
        do {
            cout << "Travelling Salesman Problem with Approximation Menu" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Apply to Tourism." << endl;
            cout << " 2. Apply to Shipping." << endl;
            cout << " 3. Apply to Stadiums." << endl;
            cout << " 4. Apply to Medium Graphs." << endl;
            cout << " 5. Apply to Real World Graphs." << endl;
            cout << " 9. Go back to previous menu." << endl;
            cout << "Type option: ";
            cin >> input;
            cout << endl;
            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "9"));

        //Menu options
        if (input == "1") {
            manager.ReadFileToyGraphTourism();
            TspApproximation(manager);
        }
        else if (input == "2") {
            manager.ReadFileToyGraphShipping();
            TspApproximation(manager);
        }
        else if (input == "3") {
            manager.ReadFileToyGraphStadiums();
            TspApproximation(manager);
        }
        else if (input == "4") {
            TspApproximationMedium(manager);
        }
        else if (input == "5") {
            TspApproximationRealWorld(manager);
        }
        else if (input == "9")
            return;
    }
}

void TspChristofidesMenu(Manager &manager){
    while (true) {
        string input;
        do {
            cout << "Travelling Salesman Problem with Christofides Menu" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Apply to Tourism." << endl;
            cout << " 2. Apply to Stadiums." << endl;
            cout << " 3. Apply to Medium Graphs." << endl;
            cout << " 4. Apply to Real World Graphs." << endl;
            cout << " 9. Go back to previous menu." << endl;
            cout << "Type option: ";
            cin >> input;
            cout << endl;
            if (!(input == "1" || input == "2" || input == "3" || input == "4"  || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "9"));

        //Menu options
        if (input == "1") {
            manager.ReadFileToyGraphTourism();
            TspChristofides(manager);
        }
        else if (input == "2") {
            manager.ReadFileToyGraphStadiums();
            TspChristofides(manager);
        }
        else if (input == "3")
            TspChristofidesMedium(manager);
        else if (input == "4")
            TspChristofidesRealWorld(manager);
        else if (input == "9")
            return;
    }
}

void TspBacktracking(Manager &manager){
    auto [bestPath, bestCost, duration] = manager.tspBacktracking();

    cout << "Best Path: ";
    for (int vertex : bestPath) {
        cout << vertex << " ";
    }
    cout << "0" << endl;
    cout << "Best Cost: " << bestCost << endl;
    cout << "Execution time: " << duration << " seconds" << endl;
}

void TspApproximation(Manager &manager){
    auto [totalDistance, duration] = manager.tspApproximation();

    cout << endl;
    cout << "Total Distance: " << totalDistance << endl;
    cout << "Execution time: " << duration << " seconds" << endl;
    cout << endl;
}


void TspApproximationMedium(Manager &manager){
    string input;
    do {
        cout << "Which medium graph you want to select?" << endl;
        cout << " 25. 25." << endl;
        cout << " 50. 50." << endl;
        cout << " 75. 75." << endl;
        cout << " 100. 100." << endl;
        cout << " 200. 200." << endl;
        cout << " 300. 300." << endl;
        cout << " 400. 400." << endl;
        cout << " 500. 500." << endl;
        cout << " 600. 600." << endl;
        cout << " 700. 700." << endl;
        cout << " 800. 800." << endl;
        cout << " 900. 900." << endl;
        cout << " 9. Go back to previous menu." << endl;
        cout << "Type option: ";
        cin >> input;
        cout << endl;
        if (!(input == "25" || input == "50" || input == "75" || input == "100" || input == "200" || input == "300" || input == "400" || input == "500" || input == "600" || input == "700" || input == "800" || input == "900" || input == "9" ))
            cout << "File " + input + " doesn't exist! Try again!";
    } while (!(input == "25" || input == "50" || input == "75" || input == "100" || input == "200" || input == "300" || input == "400" || input == "500" || input == "600" || input == "700" || input == "800" || input == "900" || input == "9" ));

    if (input != "9") {
        manager.ReadMediumGraphs(input);
        TspApproximation(manager);
    }
    else {
        return;
    }
}

void TspApproximationRealWorld(Manager &manager){
    string input;
    do {
        cout << "Which Real World Graph you want to select?" << endl;
        cout << " 1. Graph 1." << endl;
        cout << " 2. Graph 2." << endl;
        cout << " 3. Graph 3." << endl;
        cout << " 9. Go back to previous menu." << endl;
        cout << "Type option: ";
        cin >> input;
        cout << endl;
        if (!(input == "1" || input == "2" || input == "3" || input == "9" ))
            cout << "File " + input + " doesn't exist! Try again!";
    } while (!(input == "1" || input == "2" || input == "3" || input == "9"));

    if (input != "9") {
        manager.ReadRealWorldGraphs(input);
        TspApproximation(manager);
    }
    else {
        return;
    }
}

void TspChristofides(Manager &manager) {
    auto [totalDistance, duration] = manager.christofides();

    cout << endl;
    cout << "Total cost: " << totalDistance  << endl;
    cout << "Execution time: " << duration << " seconds" << endl;
    cout << endl;
}

void TspChristofidesMedium(Manager &manager){
    string input;
    do {
        cout << "Which medium graph you want to select?" << endl;
        cout << " 25. 25." << endl;
        cout << " 50. 50." << endl;
        cout << " 75. 75." << endl;
        cout << " 100. 100." << endl;
        cout << " 200. 200." << endl;
        cout << " 300. 300." << endl;
        cout << " 400. 400." << endl;
        cout << " 500. 500." << endl;
        cout << " 600. 600." << endl;
        cout << " 700. 700." << endl;
        cout << " 800. 800." << endl;
        cout << " 900. 900." << endl;
        cout << " 9. Go back to previous menu." << endl;
        cout << "Type option: ";
        cin >> input;
        cout << endl;
        if (!(input == "25" || input == "50" || input == "75" || input == "100" || input == "200" || input == "300" || input == "400" || input == "500" || input == "600" || input == "700" || input == "800" || input == "900" || input == "9" ))
            cout << "File " + input + " doesn't exist! Try again!";
    } while (!(input == "25" || input == "50" || input == "75" || input == "100" || input == "200" || input == "300" || input == "400" || input == "500" || input == "600" || input == "700" || input == "800" || input == "900" || input == "9" ));

    if(input != "9") {
        manager.ReadMediumGraphs(input);
        TspChristofides(manager);
    }
    else {
        return;
    }
}

void TspChristofidesRealWorld(Manager &manager){
    string input;
    do {
        cout << "Which Real World Graph you want to select?" << endl;
        cout << " 1. Graph 1." << endl;
        cout << " 9. Go back to previous menu." << endl;
        cout << "Type option: ";
        cin >> input;
        cout << endl;
        if (!(input == "1" || input == "9" ))
            cout << "File " + input + " doesn't exist! Try again!";
    } while (!(input == "1"  || input == "9"));

    if (input != "9") {
        manager.ReadRealWorldGraphs(input);
        TspChristofides(manager);
    }
    else {
        return;
    }
}
