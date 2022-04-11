#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 105;

struct MUCHIE
{
    int inceput, nod;
};

vector <int> G[MAX];
vector <vector <int> > con;
stack <MUCHIE> st;

int n, x, viz[MAX];
int nrcc;
///int extra[MAX*2];
///int maxi;
int fr[MAX];

int bfs(int nod, int cc)
{
    queue <int> q;
    q.push(nod);
    viz[nod] = cc;
    con[cc].push_back(nod);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int it : G[u])
        {
            if (!viz[it])
            {
                viz[it] = cc;
                con[cc].push_back(it);
                q.push(it);
            }
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    bool ok;
    char idfk = '1';
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!viz[i])
        {
            ++nrcc;
            bfs(i, nrcc);
        }
    }
    cout << nrcc-1<<'\n';
    std::vector <std::vector <int> > :: iterator b = con.begin(), e = con.end();
    std::vector <int> :: iterator b1, e1, b2, e2;
    for (std::vector <std::vector <int> > :: iterator it = b; it != e; ++it)
    {
        if (it == b - 1)
        {
            continue;
        }
        ok = 0;
        b1 = it->begin();
        e1 = it->end();
        for (std::vector <int> :: iterator it1 = b1; it1 != e1; ++it1)
        {
            if (!fr[*it1])
            {
                ++fr[*it1];
                b2 = (it + 1)->begin();
                e2 = (it + 1)->end();
                for (std::vector <int> :: iterator it2 = b2; it2 != e2; ++it2)
                {
                    if (!fr[*it2])
                    {
                        ++fr[*it2];
                        st.push({*it1, *it2});
                        it2->insert(e2, b1, e1);
                        ok = 1;
                        goto A;
                    }
                }
            }
        }
        if (!ok)
        {
            idfk = '2';
            b1 = it->begin();
            e1 = it->end();
            for (std::vector <int> :: iterator it1 = b1; it1 != e1; ++it1)
            {
                if (!fr[*it1])
                {
                    ++fr[*it1];
                    b2 = (it + 1)->begin();
                    e2 = (it + 1)->end();
                    for (std::vector <int> :: iterator it2 = b2; it2 != e2; ++it2)
                    {
                        if (fr[*it2] <= 1)
                        {
                            ++fr[*it2];
                            st.push({*it1, *it2});
                            it2->insert(e2, b1, e1);
                            goto A;
                        }
                    }
                }
            }
            for (std::vector <int> :: iterator it1 = b1; it1 != e1; ++it1)
            {
                if (fr[*it1] == 1)
                {
                    ++fr[*it1];
                    b2 = (it + 1)->begin();
                    e2 = (it + 1)->end();
                    for (std::vector <int> :: iterator it2 = b2; it2 != e2; ++it2)
                    {
                        if (fr[*it2] <= 1)
                        {
                            ++fr[*it2];
                            st.push({*it1, *it2});
                            it2->insert(e2, b1, e1);
                            goto A;
                        }
                    }
                }
            }
        }
A:;
    }
    cout << idfk << '\n' << nrcc - 1 << '\n';
    while (!st.empty())
    {
        cout << st.top().inceput << ' ' << st.top().nod;
        st.pop();
    }
    return 0;
}