
#include <iostream>
#include <vector>
using namespace std;

int n, x, tmp, res; 
vector <int> a; 

void mergeSort(vector <int> &a) {
    if ((int)a.size() <= 1) return;
    int mid = (int)a.size() / 2;
    vector <int> left(a.begin(), a.begin() + mid);
    vector <int> right(a.begin() + mid, a.end());
    mergeSort(left);
    mergeSort(right);
    int i = 0, j = 0;
    a.clear(); 
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) a.push_back(left[i++]);
        else a.push_back(right[j++]); 
    }
    while (i < (int)left.size()) a.push_back(left[i++]);
    while (j < (int)right.size()) a.push_back(right[j++]);
}

int bin(int l, int r, int x, int i) {
    int mid, ans = -1; 
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] <= x) {
            if (mid != i) ans = mid; 
            l = mid + 1; 
        }
        else r = mid - 1; 
    }
    return ans; 
}

int main() {
    cin >> n >> x; 
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    mergeSort(a); 
    for (int i = 0; i < n; i++) {
        int pos = bin(0, n - 1, x - a[i], i);
        if (pos != -1) res = max(res, a[i] + a[pos]);
    }
    cout << res; 
}

/*
6 18
5 3 10 2 4 9
*/