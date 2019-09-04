#include "./bits/stdc++.h"
using namespace std;

template<class GridType>
auto gridBFS(const GridType &grid, int H, int W, pair<int,int> startYX) -> vector<vector<int>>
{
    constexpr array<int, 4> dy {1, 0, -1, 0};
    constexpr array<int, 4> dx {0, 1, 0, -1};
    static_assert(dy.size() == dx.size(), "Length of dy[], dx[] is different!");
    const int startY = startYX.first;
    const int startX = startYX.second;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int,int>> que;

    dist[startY][startX] = 0;
    que.emplace(startY, startX);
    while(!que.empty()) {
        const int nowY = que.front().first;
        const int nowX = que.front().second;
        que.pop();
        for (int i = 0; i < dy.size(); ++i) {
            const int ny = nowY + dy[i];
            const int nx = nowX + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (grid[ny][nx] != -1) continue;
            dist[ny][nx] = dist[nowY][nowX] + 1;
            que.emplace(ny, nx);
        }
    }

    return dist;
}
