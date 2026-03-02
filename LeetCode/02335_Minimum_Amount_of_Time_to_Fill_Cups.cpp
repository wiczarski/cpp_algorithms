#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        int counter = 0;
        int g, m; // the greatest and the middle
        while(true) {
            g = pq.top();
            pq.pop();
            m = pq.top();
            pq.pop();

            if (m == 0) {
                counter += g;
                break;
            }
            g--;
            m--;
            counter++;
            pq.push(g);
            pq.push(m);
        }
        return counter;
    }
};