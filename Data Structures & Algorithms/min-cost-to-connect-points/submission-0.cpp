#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        std::vector<int> minDist(n, INT_MAX);
        std::vector<bool> vis(n, false);
        minDist[0] = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int curr = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (curr == -1 || minDist[j] < minDist[curr])) {
                    curr = j;
                }
            }
            vis[curr] = true;
            res += minDist[curr];
            for (int j = 0; j < n; ++j) {
                if (!vis[j]) {
                    int cost = std::abs(points[curr][0] - points[j][0]) + std::abs(points[curr][1] - points[j][1]);
                    if (cost < minDist[j]) {
                        minDist[j] = cost;
                    }
                }
            }
        }
        return res;
    }
};