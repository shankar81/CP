// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// O(N^3)
// Calculate shortest path from all sources to every other sources

#include<iostream>

using namespace std;

void findShortestDistance(vector<vector<int>> &matrix) {
	int n = matrix.size();

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][k] == -1 || matrix[k][j] == -1) continue;
				int dist = matrix[i][k] + matrix[k][j];
				if (matrix[i][j] == -1 || dist < matrix[i][j]) matrix[i][j] = dist;
			}
		}	
	}
}

int main() {
	return 0;
}