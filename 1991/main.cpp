#include <iostream>
using namespace std;
int k, n;
void dp(int poz, int &d) {
if(poz == n) {
    d++;
    return;
}
for(int i = 1; i<= k; ++i)
    if(poz+i <= n)
        dp(poz+i, d);
}
int main() {
    cin >> n >> k;
    int d = 0;
    dp(1, d);
    cout << d;
    return 0;
}