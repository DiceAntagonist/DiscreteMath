#include<iostream>
#include <vector>
using namespace std;

void computeDegrees(const vector<vector<int>>& graph, vector<int>& inDegrees, vector<int>& outDegrees) {
    int numVertices = graph.size();

    for (int i = 0; i < numVertices; i++) {
        outDegrees[i] = graph[i].size();

        for (int j : graph[i]) {
            inDegrees[j]++;
        }
    }
}

int main() {
    int numVertices = 4;

    vector<vector<int>> graph(numVertices);

    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};

    vector<int> inDegrees(numVertices, 0);
    vector<int> outDegrees(numVertices, 0);

    computeDegrees(graph, inDegrees, outDegrees);

    cout << "Vertex\tIn-Degree\tOut-Degree" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << "\t" << inDegrees[i] << "\t\t" << outDegrees[i] << endl;
    }

    return 0;
}
