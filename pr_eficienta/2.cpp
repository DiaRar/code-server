#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("DATE.txt");
int v[3005], t[3005];

int main() {
    int n, m, k = 0, i, j, nf, mf;
    fin >> n >> m;
    nf = n;
    mf = m;
    for(i = 1; i<=n; ++i)
        {
            fin >> k;
            if(k%2) {
                n--;
                i--;
                continue;
            }
            v[i] = k;
        }
    for(i = 1; i<=m; ++i)
    {
            fin >> k;
            if(k%2) {
                m--;
                i--;
                continue;
            }
            t[i] = k;
    }
    i = 1;
    j = m;
    while(i<=n&&j>=1) {
        if(v[i] <= t[j])
            {
                cout << v[i] << ' ';
                i++;
            } else {
                cout << t[j] << ' ';
                j--;
            }
    }
    for(i; i<=n; ++i) cout << v[i] << ' ';
    for(j; j>=1;j--) cout << t[j] << ' ';
}