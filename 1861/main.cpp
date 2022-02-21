#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

const int NMAX = 100000;
vector <int> G[NMAX + 5];
stack <int> st;
vector <bool> viz;

void dfs(int nod)
{
    vector <int> :: iterator it;
    int v;
    viz[nod] = 1;
    for(it = G[nod].begin(); it != G[nod].end(); it++)
    {
        v = *it;
        if(viz[v] == 0)
            dfs(v);
    }
    st.push(nod);
}
int main()
{
    int n, m, u, v;
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> u >> v;
        G[u].push_back(v);
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j < G[i].size(); j++)
    //     {
    //         fout << G[i][j] << " ";
    //     }
    //     fout << "\n";
    // }

    viz.assign(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        if(viz[i] == 0)
            dfs(i);
    }
    while(!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
    // for(int i = 0; i < viz.size(); i++)
    // {
    //     fout << viz[i] << " ";
    // }
    return 0;
}
