#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("DATE.txt");
int v[3005], t[3005];
// int v[50], w[50], l, lmax;
// int test(int x, int y) {
//     if(y == 0) 
//         {
//             y = x;
//             fin >> x;
//             if(!x) return 0;
//         }
//     if(x%2 == y%2) return x;
//     l++;
//     fin >> y;
//     if(!y) return 0;
//     v[l] = y;
//     return test(y, x);
// }
// int main() {
//     int x, y=0;
//     while(fin >> x){
//     if(l > lmax) {
//         lmax = l;
//         for(int i = 0; i < lmax; ++i)
//         {
//             w[i] = v[i];
//         }
//     }
//     for(int i = 0; i< l; ++i)
//         v[i] = 0;
//     l = 0;
//     if(y && (x%2 != y%2)) {
//         v[l] = y;
//         l++;
//         v[l] = x;
//         y = test(x, y);
//         continue;
//     }
//     y = test(x, 0);
//     }
//     cout << lmax << '\n';
//     for(int i = 0; i < lmax; ++i) {
//         cout << w[i] << ' ';
//     }
//     return 0;
// }

int main() {
    int n, m, k = 0, i, j, nf, mf;
    fin >> n >> m;
    nf = n;
    mf = m;
    for(i = 1; i<=n; ++i)
        {
            fin >> k;
            if(k%2) v[i] = k;
            else nf--;
        }
    for(i = 1; i<=m; ++i)
    {
            fin >> k;
            if(k%2) v[i] = k;
            else mf--;
    }
    i = 1;
    j = mf;
    while(i<=nf&&j>=1) {
        if(v[i] <= t[j])
            {
                cout << v[i] << ' ';
                i++;
            } else {
                cout << t[j] << ' ';
                j++;
            }
    }
    for(i; i<=nf; ++i) cout << v[i] << ' ';
    for(j; j>=1;j--) cout << t[j] << ' ';
}