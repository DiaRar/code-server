#include <iostream>
using namespace std;
constexpr int NMAX = 100;
int c[NMAX+5][NMAX+5];

int main() {
    int n, i, j, k, cost, m, u, v;
    cin >> n >> m;
    for(i=1; i<=m; ++i)
    {
        cin >> u >> v;
        c[u][v] = 1;
    }
    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                if(!c[i][j])
                    c[i][j] = c[i][k]*c[k][j];
    for(i = 1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
            cout << c[i][j] << ' ';
        cout << '\n';
    }
}