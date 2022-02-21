#include <iostream>
using namespace std;

int main() {
    int n, nr, nrcif, aux;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> nr;
        aux = nr;
        if(nr%2) continue;
        nrcif = 1;
        nr/=10;
        while(nr) {
            nrcif += (!nr%2);
            nr /= 10;
        }
        if(nrcif%2) cout << aux;
    }
    return 0;
}