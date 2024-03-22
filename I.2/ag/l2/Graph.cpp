#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>

Graph::Graph(std::string filename) {
    std::ifstream f(filename);
    f >> n;
    matrix.resize(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            f >> x;
            if (x == 1) {
                matrix[i][j]=1;
                matrix[j][i]=1;
            }
        }
}

void Graph::printGraph() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void Graph::multiply(std::vector<std::vector<int>>& result) {
    int n = matrix.size();
    std::vector<std::vector<int>> temp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                temp[i][j] += matrix[i][k] * result[k][j];
            }
        }
    }
    result = temp;
}

std::vector<std::vector<int>> Graph::power(int exponent) {
    std::vector<std::vector<int>> result(matrix);
    while (exponent > 1) {
        multiply(result);
        exponent--;
    }
    return result;
}

void Graph::printPowerGraph(const std::vector<std::vector<int>>& result) {
    for (int i = 0; i < result.size(); i++)
    {for (int j = 0; j < result.size(); j++)
            std::cout << result[i][j] << " ";
            std::cout << std::endl;
}}

bool Graph::isConnected() {
    std::vector<std::vector<int>> B(matrix.size(), std::vector<int>(matrix.size(), 0));

    for (int i = 1; i < matrix.size(); ++i) {
        std::vector<std::vector<int>> temp = power(i);
        for (int row = 0; row < B.size(); ++row) {
            for (int col = 0; col < B.size(); ++col) {
                B[row][col] += temp[row][col];
            }
        }
    }
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (B[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}