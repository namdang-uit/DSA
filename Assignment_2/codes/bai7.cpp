#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int mi = i;
        for (int j = i; j < n; j++)
            if (a[mi] > a[j]) swap(mi, j);
        if (i != mi) {
            swap(a[i], a[mi]);
            for (int j = 0; j < n; j++) cout << a[j] << ' ';
            cout << '\n';
        }
    }
}