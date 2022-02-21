#include <iostream>
#include <queue>
#include <vector>
constexpr int NMAX = 200;
using namespace std;
int a[NMAX+5][NMAX+5], n, m, viz[NMAX+5][NMAX+5];

void sol1();
void sol2();
struct POINT {
    int x,y;
};
queue<POINT> q;
int main() {
    int sol, k;
    cin >> sol;
    cin >> n >> m;
    if(sol == 1) sol1();
    else sol2();
}
void sol1() {
    int xv, yv, zv, xc, yc, k, g, xg1, yg1, xg2, yg2, ok, xn, yn;
    POINT temp;
    cin >> xc >> yc;
    cin >> k;
    int dx[] = {0, -1, 0, 1, 0, -1, -1, 1, 1, -2, 2, 0, 0};
    int dy[] = {0, 0, -1, 0, 1, -1, 1, -1, 1, 0, 0, 2, -2};
    for(int i = 0; i<= n+1; ++i)
        a[i][0] = a[i][m+1] = -1;
    for(int i = 0; i<= m+1; ++i)
        a[0][i] = a[n+1][i] = -1;
 for(int i = 0; i < k; ++i){
        cin >> xv >> yv >> zv;
        switch(zv) {
            case 0: zv = 0; break;
            case 1: zv = 4; break;
            case 2: zv = 12; break;
        }
        for(int j = 0; j <= zv; ++j) {
            if(xv+dx[j] <= n && xv+dx[j] >= 1 && yv+dy[j] <= m && yv+dy[j] >= 1)
            a[xv+dx[j]][yv+dy[j]] = -1;
        }
    }
    cin >> g;  
    for(int i = 1; i <= g; ++i)
    {
        cin >> xg1 >> yg1 >> xg2 >> yg2;
            if(a[xg1][yg1] != -1)
                a[xg1][yg1] = 1;
            if(a[xg2][yg2]!= -1)
                a[xg2][yg2] = 1;
    }
    if(a[xc][yc]==1)
        cout << xc << ' ' << yc << ' ' << 0 << '\n';
    else {
        temp.x = xc;
        temp.y = yc;
        viz[xc][yc] = 1;
        q.push(temp);
        ok = 0;
        while(!q.empty() && !ok){
            temp = q.front();
            q.pop();
            for(int i = 1; i <= 4; ++i) {
                xn = temp.x + dx[i];
                yn = temp.y + dy[i];
                if(a[xn][yn] == 1){
                    cout << xn << ' ' << yn << ' ' << viz[temp.x][temp.y] << '\n';
                } else if(viz[xn][yn] == 0 && a[xn][yn] == 0) {
                    viz[xn][yn] = viz[temp.x][temp.y] + 1;
                    temp.x = xn;
                    temp.y = yn;
                    q.push(temp);
                }
            }
        }
    }

}
void sol2() {
    return;
}