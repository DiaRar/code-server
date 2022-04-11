#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF=1000000000;
const int NMAX=10000;

vector<ii> G[NMAX+5];   

int main() {
  freopen("dijkstra.in","r",stdin);
  freopen("dijsktra.out","w",stdout);
  int n, s, u, v, w, m=0;

  scanf("%d%d", &n, &s);

    while (scanf("%d%d%d", &u, &v, &w) != EOF) { 
    G[u].push_back(ii(v, w));
    m++;
     }

  // Dijkstra

  vi dist(n+1, INF); dist[s] = 0;

  priority_queue< ii, vector<ii>, greater<ii> > pq;
 pq.push(ii(0, s));
//  printf("*0 %d\n",s );

  while (!pq.empty())
 {
    ii front = pq.top(); pq.pop();
    // for (int i=0;i<n;i++)
    //      printf("%d ",dist[i]);
    // printf("\n");    
    int d = front.first, u = front.second;
    if (d > dist[u])
            continue;

     for (int j = 0; j < (int)G[u].size(); j++)
    {
        int v = G[u][j].first, duv = G[u][j].second;
        if (dist[u] + duv < dist[v])
        {
          dist[v] = dist[u] + duv;
          pq.push(ii(dist[v], v));
        //   printf("*%d %d\n",dist[v],v);
       }
    }
}

    for (int i = 1; i <= n; i++){
      if(dist[i] == INF ) dist[i] = -1;
    printf("%d ", dist[i]);
    }
  return 0;
}
