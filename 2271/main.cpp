#include <iostream>
using namespace std;

// Valorile maxime ale numerelor
const int NMAX = 1e5+1;

// Citim elementele si luam 2 numere maxime si 2 minime, comparam produsele si returnam maximul.
long long rez(int n = 0) {
    int nmax1 = NMAX, nmax2 = NMAX, max1 = NMAX*(-1), max2 = NMAX*(-1), nr;
    for(int i=0; i<n; ++i){
        cin >> nr;
        if( nr > max1 ) {
            max2 = max1;
            max1 = nr;
        } else if ( nr > max2 ) max2 = nr; 
        if( nmax1 > nr ) {
            nmax2 = nmax1;
            nmax1 = nr;
        } else if( nmax2 > nr ) nmax2 = nr;
    }
    if( 1LL*nmax1*nmax2 > 1LL*max1*max2 ) return 1LL*nmax1*nmax2;
    return 1LL*max1*max2;
}
// Functia main de start a programului
int main() {
    int n;
    cin >> n;
    cout << rez(n);
    return 0;
}