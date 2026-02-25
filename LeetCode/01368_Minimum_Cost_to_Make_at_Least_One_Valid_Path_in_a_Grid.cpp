// This solution hits TLE on LeetCode.
// TODO - find better solution


#include <bits/stdc++.h>

using namespace std;

void propagate(vector<vector<int>>& grid, vector<vector<int>>& min_cost, int cost, int r, int c){
    if (cost < min_cost[r][c]) {
        min_cost[r][c] = cost;
        // right
        if(c != grid[r].size() - 1) {
            int newCost = cost + (grid[r][c] != 1);
            propagate(grid, min_cost, newCost, r, c + 1);
        }
        // left
        if(c != 0) {
            int newCost = cost + (grid[r][c] != 2);
            propagate(grid, min_cost, newCost, r, c - 1);
        }
        // down
        if (r != grid.size() - 1) {
            int newCost = cost + (grid[r][c] != 3);
            propagate(grid, min_cost, newCost, r + 1, c);
        }
        //up
        if(r != 0) {
            int newCost = cost + (grid[r][c] != 4);
            propagate(grid, min_cost, newCost, r - 1, c);
        }
    }
}

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> min_cost;
        min_cost.resize(R);
        for (int i = 0; i < R; i++){
            min_cost[i].resize(C, INT_MAX);
        }
        propagate(grid, min_cost, 0, 0, 0);
        return min_cost[R - 1][C - 1];
    }
};