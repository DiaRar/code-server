#include <fstream>
#include <string>
#include <iostream>
using namespace std;
string path = "/393/";
ifstream fin(path+"cladire.in");
ofstream fout(path+"cladire.out");
int a[1001][1001];
int minim(int a, int b){
    if(a>b) return b;
    return a;
}
int main()
{
    cout<< path+"cladire.in";
    int n , m, i, j;
    fin >> n >> m;
    cout << n<< m;
    for(i = 0 ; i<=n+1 ; ++i) a[i][0]=2e5;
    for(i = 0 ; i<=n+1 ; ++i) a[i][m+1]=2e5;
    for(i = 0 ; i<=m+1 ; ++i) a[0][i]=2e5;
    for(i = 0 ; i<=m+1 ; ++i) a[n+1][i]=2e5;
    for(i = 1 ; i<=n; ++i)
        for(j = 1; j<=m; ++j) cin >> a[i][j];
    for(i = n ; i; --i)
        for(j = 1 ; j <= m ; ++j){
            if(i!=n || j!=1) a[i][j]+=minim(a[i+1][j], a[i][j-1]);
        }
    fout << a[1][m];

    return 0;
}