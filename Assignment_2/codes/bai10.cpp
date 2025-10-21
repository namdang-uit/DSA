#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int* b = new int[r];
    int i = l, j = mid + 1;
    int ind = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[ind++] = a[i];
            i++;
        }
        else {
            b[ind++] = a[j];
            j++;
        }
    }
    while (i <= mid) {
        b[ind++] = a[i];
        i++;
    }
    while (j <= r) {
        b[ind++] = a[j];
        j++;
    }
    for (int i = l; i <= r; i++) a[i] = b[i];
    for (int i = 0; i < n; i++) {
        if (i == l) cout << "[ ";
        cout << a[i] << ' ';
        if (i == r) cout << "] ";
    }
    cout << '\n';
    delete[] b;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(0, n-1);
}