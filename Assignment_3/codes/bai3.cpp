#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5 + 5; 
int n, cnt; 
string x; 
vector <string> a;

void mergeSort(vector<string> &a) {
    if (a.size() <= 1) return;
    int mid = a.size() / 2;
    vector<string> left(a.begin(), a.begin() + mid);
    vector<string> right(a.begin() + mid, a.end());
    mergeSort(left);
    mergeSort(right);
    a.clear();
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) a.push_back(left[i++]);
        else a.push_back(right[j++]);
    }
    while (i < left.size()) a.push_back(left[i++]);
    while (j < right.size()) a.push_back(right[j++]);
}

int main() {
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x); 
    }
    mergeSort(a); 
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << (int)a.size(); 
}