#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1e2;
vector  <int> G[N+5], x;
int de[N+5], di[N+5];

int main() {
    int n, m, u, v, k;
    cin >> n >> m >> k;
    for( int i = 1; i <= m; ++i)
        cin >> u >> v,
        G[u].push_back(v);
    for( int i = 1; i <= n; ++i) {
        for( int j = 0; j < G[i].size(); ++j)
            di[G[i][j]]++;
        de[i] = G[i].size();
    }
    int nod = 0;
    for( int i = 1; i <= n; ++i)
    {
        if(di[i] + de[i] == k)
            nod++,
            x.push_back(i);
    }
    for( int i = 0; i< nod; ++i)
        cout << x[i] << " ";
    if( nod == 0 ) cout << "Nu exista";
    return 0;
 }  