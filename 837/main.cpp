#include <fstream>
using namespace std;
ifstream cin("fill.in");
ofstream cout("fill.out");
int a[501][501], ob = 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};
void fill(int x, int y){
    int xn, yn;
    a[x][y] = ob;
    for(int i =0 ; i<4; ++i)
    {
        xn = x + dx[i];
        yn = y + dy[i];
        if(a[xn][yn]==1)
            fill(xn, yn);
    }
}
int main(){
    int n, m, insule = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == 1){
                ob++;
                fill(i, j);
            }
    cout << ob-1;
    return 0;
}