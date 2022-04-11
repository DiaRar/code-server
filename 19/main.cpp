#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ifstream cin("BFS.in");
// ofstream cout("BFS.out");
vector<int> G[105];
bool viz[105];


void BFS(int root) {
    queue<int> q;
    q.push(root);
    viz[root] = 1;
    cout << root << ' ';
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int nod : G[u])
            if(!viz[nod])
            {
                viz[nod] = 1;
                cout << nod << ' ';
                q.push(nod);
            }
    }
}
int main() {
    int n, m, root;
    cin >> n >> m >> root;
    for(int i = 1, x, y; i<=n; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    BFS(root);
    return 0;
}