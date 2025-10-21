#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
vector <pair <int, int>> a;

int cmp(pair <int, int> x, pair <int, int> y) {
    if (x.first < y.first) return -1;
    if (x.first > y.first) return 1;
    if (x.second > y.second) return -1;
    if (x.second < y.second) return 1;
    return 0;
}

void mergeSort(vector<pair <int, int> > &ls, int size) {
    if (size <= 1) return;
    vector <pair <int, int> > a, b;
    int i = 0, j = size / 2;
    while (i < j) a.push_back(ls[i]), i++;
    while (j < size) b.push_back(ls[j]), j++;
    mergeSort(a, (int)a.size());
    mergeSort(b, (int)b.size());
    int ind_a = 0, ind_b = 0;
    ls.clear();
    while (ind_a < (int)a.size() && ind_b < (int)b.size()) {
        if (cmp(a[ind_a], b[ind_b]) != 1) ls.push_back(a[ind_a]), ind_a++;
        else ls.push_back(b[ind_b]), ind_b++;
    }
    while (ind_a < (int)a.size()) ls.push_back(a[ind_a]), ind_a++;
    while (ind_b < (int)b.size()) ls.push_back(b[ind_b]), ind_b++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    mergeSort(a, (int)a.size());
    for (int i = 0; i < n; i++)
        cout << a[i].first << ' ' << a[i].second << '\n';
}

/*
5
1 2
1 3
2 4
2 9
4 1
*/