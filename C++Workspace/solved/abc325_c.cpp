#include <iostream>
#include <string>
#include <queue>
using namespace std;

int H, W;
string grid[1000];
bool visited[1000][1000];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void BFS(int x, int y) {
queue<pair<int,int>> q;
q.push({x,y});
visited[x][y] = true;

while(!q.empty()) {
int currx = q.front().first;
int curry = q.front().second;
q.pop();

for(int i=0; i<8; i++) {
  int nextx = currx + dx[i];
  int nexty = curry + dy[i]; 

  if(nextx < 0 || nextx >= H || nexty < 0 || nexty >= W) continue;
  if(grid[nextx][nexty] == '#' && !visited[nextx][nexty]) {
    q.push({nextx, nexty});
    visited[nextx][nexty] = true;
  }
}
}
}

int main() {

cin >> H >> W;

for(int i=0; i<H; i++)
cin >> grid[i];

for(int i=0; i<H; i++)
for(int j=0; j<W; j++)
visited[i][j] = false;

int numSensors = 0;

for(int i=0; i<H; i++) {
for(int j=0; j<W; j++) {
if(grid[i][j]=='#' && !visited[i][j]) {
BFS(i,j);
numSensors++;
}
}
}

cout << numSensors << endl;

return 0;
}