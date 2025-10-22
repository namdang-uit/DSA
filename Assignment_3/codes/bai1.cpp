#include <bits/stdc++.h>
#define fi first 
#define se second
using namespace std; 

const int N = 1e5 + 5; 
int n, q, type, y;
pair <int, int> a[N]; 
string tmp; 

int bin1(int l, int r, int y) {
    int mid, ans = -1; 
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid].se >= y) {
            if (a[mid].se == y) ans = a[mid].fi; 
            r = mid - 1; 
        }
        else l = mid + 1; 
    }
    if (ans != -1) return ans + 1; 
    return ans; 
}

int bin2(int l, int r, int y) {
    int mid, ans = -1; 
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[mid].se <= y) {
            if (a[mid].se == y) ans = a[mid].fi; 
            l = mid + 1; 
        }
        else r = mid - 1; 
    }
    if (ans != -1) return ans + 1; 
    return ans; 
}

bool cmp_value(pair <int, int> x, pair <int, int> y) {
    if (x.se == y.se) return x.fi < y.fi;
    return x.se < y.se; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q; 
    for (int i = 0; i < n; i++) {
        cin >> a[i].se; 
        a[i].fi = i; 
    }
    sort(a, a + n, cmp_value); 
    while (q--) {
        cin >> tmp >> type >> y; 
        if (type == 1) cout << bin1(0, n - 1, y); 
        else cout << bin2(0, n - 1, y); 
        cout << '\n'; 
    }
}