#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

// Função para calcular o limite superior (bound) de uma solução parcial
int calculate_bound(vector<int>& partial_solution, vector<vector<int>>& distances) {
    int bound = 0;
    int last_city = partial_solution.back();
    for (int i = 0; i < partial_solution.size() - 1; i++) {
        int current_city = partial_solution[i];
        bound += distances[current_city][last_city];
        last_city = current_city;
    }
    return bound;
}

// Função principal do Branch and Bound
int branch_and_bound(vector<vector<int>>& distances, int num_cities, int initial_city) {
    vector<vector<int>> solutions;
    vector<int> visited;
    stack<vector<int>> node_stack;

    visited.push_back(initial_city);
    node_stack.push({ initial_city });

    int min_cost = numeric_limits<int>::max();

    while (!node_stack.empty()) {
        vector<int> current_node = node_stack.top();
        node_stack.pop();

        if (current_node.size() == num_cities) {
            int total_cost = calculate_bound(current_node, distances);
            solutions.push_back(current_node);
            if (total_cost < min_cost) {
                min_cost = total_cost;
            }
        }
        else {
            for (int i = 0; i < num_cities; i++) {
                if (find(current_node.begin(), current_node.end(), i) == current_node.end()) {
                    vector<int> new_solution = current_node;
                    new_solution.push_back(i);
                    int bound = calculate_bound(new_solution, distances);
                    if (bound < min_cost) {
                        node_stack.push(new_solution);
                    }
                }
            }
        }
    }

    return min_cost;
}

int main() {
    int num_cities = 3;
    int initial_city = 0;

    vector<vector<int>> distances = {
        { 0, 3, 5, 4 },
        { 3, 0, 2, 6 },
        { 5, 2, 0, 1 },
        { 4, 6, 1, 0 }
    };

    int min_cost = branch_and_bound(distances, num_cities, initial_city);
    cout << "Menor custo total encontrado: " << min_cost << endl;

    return 0;
}
