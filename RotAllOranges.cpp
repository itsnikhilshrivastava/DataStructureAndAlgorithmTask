#include <bits/stdc++.h>
using namespace std;

void rot(vector<vector<int>>&m, int r, int c, int x, int y, queue<pair<int, int>>&q, vector<vector<int>>&visited) {
    if(x+1<r && (m[x+1][y] == 1) && !visited[x+1][y]) {
        m[x+1][y] = 2;
        q.push({x+1, y});
    }
    if(x-1>=0 && m[x-1][y] == 1 && !visited[x-1][y]) {
        m[x-1][y] = 2;
        q.push({x-1, y});
    }
    if(y-1>=0 && m[x][y-1] == 1 && !visited[x][y-1]) {
        m[x][y-1] = 2;
        q.push({x, y-1});
    }
    if(y+1<c && m[x][y+1] == 1 && !visited[x][y+1]) {
        m[x][y+1] = 2;
        q.push({x, y+1});
    }
}

int rotOranges(vector<vector<int> > &m, int r, int c) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] == 2)
                q.push({i, j});
        }
    }
    q.push({-1, -1});
    int ans = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        if(x < 0) {
            ans = max(ans, abs(x));
            if(!q.empty())
                q.push({x-1, y-1});
            continue;
        }
        visited[x][y] = 1;
        rot(m, r, c, x, y, q, visited);
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] == 1)
                return -1;
        }
    }
    return ans-1;
}



int main()
{
    int R,C;
    cin>>R>>C;
    vector<vector<int> > matrix(R);
    for(int i=0;i<R;++i)
    {
        matrix[i].resize(C);
        for(int j=0;j<C;++j)
            cin>>matrix[i][j];
    }
    cout<<rotOranges(matrix,R,C)<<endl;
    return 0;
}
