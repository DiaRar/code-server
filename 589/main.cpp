#include <iostream>
using namespace std;

constexpr int INF = 1e9;
constexpr int NMAX = 100;
int c[NMAX+5][NMAX+5];

int main() {
    int n, i, j, k, cost, m, u, v;
    cin >> n >> m;
    for(i = 1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            if(i==j)
                c[i][j] = 0;
            else
                c[i][j] = INF;
    for(i=1; i<=m; ++i)
    {
        cin >> u >> v >> cost;
        c[u][v] = cost;
    }
    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                if(c[i][k]+c[k][j]<c[i][j])
                    c[i][j] = c[i][k]+c[k][j];
    for(i = 1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
        {
            if(c[i][j] >= INF) c[i][j] = -1;
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
}