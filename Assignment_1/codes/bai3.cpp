/// template 
#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void Output(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}


int InsertionSort(Hocsinh [] , int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    cout << InsertionSort(ls, n) << endl;
    for (int i = 0; i < n; i++) {
        Output(ls[i]);
    }
    delete [] ls;
    return 0;
}

/// code 
int InsertionSort(Hocsinh ls[], int n) {
    int cnt = 0; 
    for (int i = 1; i < n; i++) {
        Hocsinh x = ls[i]; 
        int k = i - 1; 
        while (k >= 0 && x.Hoten < ls[k].Hoten) {
            ls[k + 1] = ls[k]; 
            cnt++; 
            k--; 
        } 
        ls[k + 1] = x; 
    }
    return cnt; 
}