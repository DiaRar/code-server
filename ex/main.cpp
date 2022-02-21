#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
 
using namespace std;

vector <int> g[205];
stack <int> st;
vector <int> sol;

void euler(int u){
  int v;
  while(g[u].size()){
    st.push(u);
    v = g[u].back();
    g[u].pop_back();
    g[v].erase(find(g[v].begin(), g[v].end(), u));
    u = v;
  }
}

int main()
{
    freopen("euler.in", "r", stdin);
    freopen("euler.out", "w", stdout);
    int n, x, a, b;
    scanf("%d", &n);
    while(scanf("%d%d", &a, &b) != EOF){
      g[a].push_back(b);
      g[b].push_back(a);
    }

    x = 1;
    sol.push_back(x);
    do{
      euler(x);
      x = st.top();
      sol.push_back(x);
      st.pop();
    }
    while(!st.empty());
    printf("%d\n", (int)sol.size());
    for(int i = 0;i < (int)sol.size();i++){
      printf("%d ", sol[i]);
    }
    return 0;
}
