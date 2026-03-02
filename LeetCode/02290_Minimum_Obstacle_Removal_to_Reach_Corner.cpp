#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        const int INF = INT_MAX;
        vector<vector<int>> minObstacles(R, vector<int>(C, INF));
        minObstacles[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});

        int dir_r[4] = {0, 0, 1, -1};
        int dir_c[4] = {1, -1, 0, 0};

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();

            int cur_obst = minObstacles[r][c];

            for(int d = 0; d < 4; d++) {
                int next_r = r + dir_r[d];
                int next_c = c + dir_c[d];
                if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;

                int next_obst = cur_obst + grid[next_r][next_c];
                if (minObstacles[next_r][next_c] > next_obst) {
                    minObstacles[next_r][next_c] = next_obst;

                    if (grid[next_r][next_c]) {
                        dq.push_back({next_r, next_c});
                    }
                    else {
                        dq.push_front({next_r, next_c});
                    }
                }
            }
        }
        return minObstacles[R - 1][C - 1];
    }
};