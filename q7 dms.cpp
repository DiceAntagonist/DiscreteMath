#include <iostream>
#include <vector>

using namespace std;

bool isCompleteGraph(vector<vector<int>>& adjacencyList) {
    int numVertices = adjacencyList.size();

    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            bool isAdjacent = false;

            for (int k : adjacencyList[i]) {
                if (k == j) {
                    isAdjacent = true;
                    break;
                }
            }

            if (!isAdjacent) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int numVertices = 4;

    vector<vector<int>> adjacencyList(numVertices);

    adjacencyList[0] = {1, 2, 3};
    adjacencyList[1] = {0, 2, 3};
    adjacencyList[2] = {0, 1, 3};
    adjacencyList[3] = {0, 1, 2};

    if (isCompleteGraph(adjacencyList)) {
        cout << "The graph is a complete graph." << endl;
    } else {
        cout << "The graph is not a complete graph." << endl;
    }

    return 0;
}
