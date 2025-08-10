//Project Title: City Map Navigation using Graphs
/*
Objective:
To build a simple navigation system that finds the shortest path between a source city 
and all other cities using Dijkstra's Algorithm — one of the most efficient ways to compute 
shortest paths in a weighted graph.

Data Structures Used:

Graph (Adjacency Matrix):
Stores the map as a 2D array where each cell adjMatrix[i][j] 
represents the distance between city i and city j.
If there is no direct road, the distance is set to a high value (INF).
Arrays:

dist[]: To hold the minimum distances from the source city.
visited[]: To keep track of cities already included in the shortest path tree.
prev[]: To reconstruct the path (stores the previous city for each destination).

Project Work Flow:

1. City and Road Input:
The user first inputs how many cities are in the map.
For each city, a name is provided (e.g., "Indore", "Pune").
The user then enters how many roads exist and the distance between city pairs using their indices.

Option 1: Show Adjacency Matrix

Displays a table of all city-to-city distances.
Useful for visualizing the city graph.

Option 2: Find Shortest Paths

User selects a source city.
The program uses Dijkstra’s algorithm to calculate the shortest distances from the 
source to all other cities.
It also prints the actual path taken from the source to each city.

Option 3: Exit
*/

#include <iostream>
#include <climits>
#include <cstring>
#include <windows.h>
using namespace std;

#define MAX 100 
#define INF 99999

class Graph 
{
private:
    int numCities;
    int adjMatrix[MAX][MAX];
    char cityNames[MAX][50];

public:
    Graph(int n)   
    {
        numCities = n;
        for (int i = 0; i < numCities; i++)
            for (int j = 0; j < numCities; j++)
                adjMatrix[i][j] = (i == j) ? 0 : INF;  
    }

    void addCity(int index, const char* name) 
    {
        strcpy(cityNames[index], name);
    }
                             //0        3           500
    void addRoad(int src, int dest, int distance) 
    {
        adjMatrix[src][dest] = distance;
        adjMatrix[dest][src] = distance; // for undirected graph
    }

    void displayMatrix() 
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numCities; i++) 
        {
            for (int j = 0; j < numCities; j++) 
            {
                if (adjMatrix[i][j] == INF)
                    cout << "INF\t";
                else
                    cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void dijkstra(int start)        // Indore   0
    {
        int dist[MAX], visited[MAX], prev[MAX];

        for (int i = 0; i < numCities; i++) 
        {
            dist[i] = INF;  
            visited[i] = 0;
            prev[i] = -1;
        }

        dist[start] = 0;

        for (int count = 0; count < numCities - 1; count++) 
        {
            int min = INF, u = -1;    

            for (int v = 0; v < numCities; v++) 
            {
                if (!visited[v] && dist[v] <= min) 
                {
                    min = dist[v];        //  min =0
                    u = v;                    // u =0 
                }
            }

            if (u == -1) break;
            visited[u] = 1;

            for (int v = 0; v < numCities; v++) 
            {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INF &&
                    dist[u] + adjMatrix[u][v] < dist[v]) 
                    {
                        dist[v] = dist[u] + adjMatrix[u][v];
                        prev[v] = u;
                }
            }
        }

        cout << "\nShortest paths from: " << cityNames[start] << endl;
        for (int i = 0; i < numCities; i++) {
            if (i != start) {
                cout << "To " << cityNames[i] << " - Distance: " << dist[i] << " - Path: ";
                printPath(prev, i);
                cout << cityNames[i] << endl;
            }
        }
    }

    void printPath(int prev[], int j) 
    {
        if (prev[j] == -1)
            return;
        printPath(prev, prev[j]);
        cout << cityNames[prev[j]] << " -> ";
    }
};

int main() 
{
     SetConsoleOutputCP(CP_UTF8);   // For Emojies
    int n, choice;
    cout << "Enter number of cities: ";
    cin >> n;              

    Graph g(n);      
    cin.ignore();

    for (int i = 0; i < n; i++) 
    {
        char name[50];
        cout << "Enter name for city " << i << ": ";
        cin.getline(name, 50);
        g.addCity(i, name);
    }

    int roads;
    cout << "Enter number of roads: ";
    cin >> roads;   //4

    for (int i = 0; i < roads; i++)    //4 
    {
        int src, dest, dist;
        cout << "Enter road " << i + 1 << " (src_index dest_index distance): ";
        cin >> src >> dest >> dist;
        g.addRoad(src, dest, dist);
    }

    do
     {
        cout << "\n==== City Navigation Menu ====\n";
        cout << "1. Show Adjacency Matrix\n";
        cout << "2. Find Shortest Paths from City\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            g.displayMatrix();
            break;
        case 2:
            int src;
            cout << "Enter source city index: ";
            cin >> src; // Indore     
            g.dijkstra(src);  // Indore
            break;
        case 3:
            cout << "Exiting. \n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
