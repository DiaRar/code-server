#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF=1000000000;
const int NMAX=10000;

vector<ii> G[NMAX+5];   

int main() {
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int n, s, u, v, w, m;
  scanf("%d%d", &n);
    for(int i = 1; i<=6; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(ii(v, w));
    }

  // Dijkstra

  vi dist(n+1, INF); dist[4] = 0;

  priority_queue< ii, vector<ii>, greater<ii> > pq;
 pq.push(ii(0, 4));
//  printf("*0 %d\n",s );

  while (!pq.empty())
 {
    ii front = pq.top(); pq.pop(); 
    int d = front.first, u = front.second;
    if (d > dist[u])
            continue;

     for (int j = 0; j < (int)G[u].size(); j++)
    {
        int v = G[u][j].first, duv = G[u][j].second;
        if (dist[u] + duv < dist[v])
        {
          dist[v] = dist[u] + duv;
          
          printf("%d", *t);
          pq.push(ii(dist[v], v));
       }
    }
}

    for (int i = 1; i <= n; i++){
      if(dist[i] == INF ) dist[i] = -1;
    printf("%d ", dist[i]);
    }
  return 0;
}