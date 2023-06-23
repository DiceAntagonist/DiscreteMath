#include <iostream>
#include <vector>
using namespace std;

class RELATION {
private:
    vector<vector<int>> matrix;
    int size;

public:
    RELATION(int n) {
        size = n;
        matrix.resize(n, vector<int>(n, 0));
    }

    void setElement(int i, int j, int value) {
        matrix[i][j] = value;
    }

    bool isReflexive() {
        for (int i = 0; i < size; ++i) {
            if (matrix[i][i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < size; ++k) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void checkRelationType() {
        bool isEquivalence = isReflexive() && isSymmetric() && isTransitive();
        bool isPartialOrder = isReflexive() && isAntiSymmetric() && isTransitive();

        if (isEquivalence) {
            cout << "The given relation is an Equivalence relation." << endl;
        } else if (isPartialOrder) {
            cout << "The given relation is a Partial Order relation." << endl;
        } else {
            cout << "The given relation is neither an Equivalence relation nor a Partial Order relation." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the relation matrix: ";
    cin >> n;

    RELATION relation(n);

    cout << "Enter the relation matrix (1 for true, 0 for false):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> relation.setElement(i, j);
        }
    }

    cout << "Checking relation properties..." << endl;
    cout << "Reflexive: " << (relation.isReflexive() ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (relation.isSymmetric() ? "Yes" : "No") << endl;
    cout << "Anti-symmetric: " << (relation.isAntiSymmetric() ? "Yes" : "No") << endl;
    cout << "Transitive: " << (relation.isTransitive() ? "Yes" : "No") << endl;

    relation.checkRelationType();

    return 0;
}
