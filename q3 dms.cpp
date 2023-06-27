#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate permutations with repetition
void generatePermutationsWithRepetition(vector<int>& digits, vector<int>& permutation, int length) {
    if (length == 0) {
        // Print the generated permutation
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        permutation.push_back(digits[i]);
        generatePermutationsWithRepetition(digits, permutation, length - 1);
        permutation.pop_back();
    }
}

// Function to generate permutations without repetition
void generatePermutationsWithoutRepetition(vector<int>& digits, vector<bool>& used, vector<int>& permutation, int length) {
    if (length == 0) {
        // Print the generated permutation
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            permutation.push_back(digits[i]);
            generatePermutationsWithoutRepetition(digits, used, permutation, length - 1);
            permutation.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    cout << "Permutations with repetition:" << endl;
    vector<int> permutation;
    generatePermutationsWithRepetition(digits, permutation, n);

    cout << "\nPermutations without repetition:" << endl;
    vector<bool> used(n, false);
    generatePermutationsWithoutRepetition(digits, used, permutation, n);

    return 0;
}
