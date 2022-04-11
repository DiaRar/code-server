#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6+5;
int n, v[N], frecv[N];
// int cvn;
// pair<int, int> cv[N];

int main() {
    int s, minim, t, m, ok;
    cin >> t;
    int cases = t;
    while(t--) {
    ok = 1;
    minim = 1000006;
    cin >> n >> m >> s;
    v[0] = 1, v[1] = 2, v[2] = 3;
    for (int i = 3; i < n; ++i) {
        v[i] = (v[i-1] + v[i-2] + v[i-3]) % m + 1;
    }
    for (int l = 0, r = 0, cnt = 0; r < n; ++r) {
        if(v[r] > s) continue;
        if(!frecv[v[r]]) cnt++;
        frecv[v[r]]++;
        while(cnt == s){
            if(v[l] <= s) {
                    frecv[v[l]]--;
                    if(!frecv[v[l]]) cnt--;
            }
            if((r-l+1) < minim) minim = r-l+1;
            l++;

        }

    }
    fill(begin(frecv), end(frecv), 0);
    cout << "Case "<< cases - t<<": ";
    if(minim==1000006)
        {
            cout << "sequence nai" << '\n';
        }
        else cout << minim << '\n';
    }
    return 0;
}
