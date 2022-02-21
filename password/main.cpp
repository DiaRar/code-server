#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int NMAX = 100;
vector <int> G[NMAX+5];
stack <int> st;
vector <bool> viz;
char f1[65];
char f2[127];
ifstream cin("password.in");
ofstream cout("password.out");
void dfs(int nod) {
    viz[nod]=1;
    for(int v: G[nod])
        if(!viz[v])
            dfs(v);
    st.push(nod);
}
int main(){
    int m, n=0, u[3];
    char linie[4];
    cin >> m;
    for(int i=1; i<=m; ++i){
        cin >> linie;
        for(int j=0; j<3; ++j)
        if(f2[linie[j]]==0)
        {
            n++;
            f2[linie[j]] = n;
            f1[n]=linie[j];
        }
        u[0]=f2[linie[0]];
        u[1]=f2[linie[1]];
        u[2]=f2[linie[2]];
        G[u[0]].push_back(u[1]);
        G[u[1]].push_back(u[2]);
    }
    viz.assign(n+1, 0);
    for(int i = 1; i<=n; ++i)
        if(viz[i] == 0)
            dfs(i);
    cout << n << '\n';
    while(!st.empty())
    {
        cout << f1[st.top()];
        st.pop();
    }
}