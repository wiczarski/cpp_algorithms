// relaxation approach with 0-1 BFS

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        const int INF = INT_MAX / 4;
        vector<vector<int>> dist(R, vector<int>(C, INF));

        int dir_r[4] = {0, 0, 1, -1};
        int dir_c[4] = {1, -1, 0, 0};

        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();
            int cur_dist = dist[r][c];

            for(int d = 0; d < 4; d++){
                int next_r = r + dir_r[d];
                int next_c = c + dir_c[d];
                if (next_r >= R || next_r < 0 || next_c >= C || next_c < 0) continue;

                int dir_num = d + 1;
                int add_dist = !(grid[r][c] == dir_num);
                int next_dist = cur_dist + add_dist;

                if (next_dist < dist[next_r][next_c]) {
                    dist[next_r][next_c] = next_dist;
                    if (add_dist == 0) dq.push_front({next_r, next_c});
                    else dq.push_back({next_r, next_c});
                }
            }
        }
        return dist[R - 1][C - 1];
    }
};