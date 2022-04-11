#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
ifstream cin("cartite.in");
ofstream cout("cartite.out");
int a[205][205], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int drmin, xmin, ymin, n, m;
struct VAL {
    int x, y, dr;
};
void lee(int xc, int yc) {
    if(a[xc][yc] == -2) {
        drmin = 0;
        xmin = xc;
        ymin = yc;
        return;
    }
    queue<VAL> q;
    q.push({xc, yc, 0});
    while(!q.empty()) {
        VAL u = q.front();
        q.pop();
        for(int k = 0; k < 4; ++k) {
            int xn = u.x + dx[k],
                yn = u.y + dy[k];
            if(!xn || xn > n || !yn || yn > m || a[xn][yn] == 1 || a[xn][yn] == -1) continue;
            if(a[xn][yn] < 0 && a[xn][yn]%2 == 0) {
                xmin = xn;
                ymin = yn;
                drmin = u.dr+1;
                return;
            }
            a[xn][yn] = 1;
            q.push({xn, yn, u.dr+1});
        }
    }
}
bool solve1()
{
    int xc, yc, k, g;
    cin >> n >> m 
    >> xc >> yc
    >> k;
    for(int i= 1, xv, yv, val; i <= k; ++i) 
    {
        cin >> xv >> yv >> val;
        a[xv][yv] = -1;
        if(val == 0) continue;
        if(yv > val && yv < m)
            for(int j=yv-val;j<=yv+val;j++)
                a[xv][j]=1;
        if(xv > val && xv < n)
            for(int j=xv-val;j<=xv+val;j++)
                a[j][xv]=1;
        if(val == 1) continue;
        a[xv-1][yv-1] = 1;
        a[xv-1][yv+1] = 1;
        a[xv+1][yv-1] = 1;
        a[xv+1][yv+1] = 1;
    }
    cin >> g;
    for(int i = 1, x1, y1, x2, y2; i <= g; ++i) 
    {
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] -= 2;
        a[x2][y2] -= 2;
    }
    lee(xc, yc);
    cout << xmin << ' ' << ymin << ' ' << drmin;
    return 0;
}
bool solve2()
{
return 0;
}
int main() {
    int t;
    cin >> t;
    if(t == 1)
        return solve1();
    return solve2(); 
}