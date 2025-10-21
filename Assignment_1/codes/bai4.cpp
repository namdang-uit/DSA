/// template
#include <iostream>
#include <vector>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

void Output(vector<Hocsinh> ls) {
    for (int i = 0; i < ls.size(); i++) {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ls.push_back(hs);
    }
}

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

/// code 
int check(Hocsinh a, Hocsinh b) {
    double dtb_a = a.Toan + a.Van + a.Anh + a.Sinh + a.Ly + a.Hoa; 
    double dtb_b = b.Toan + b.Van + b.Anh + b.Sinh + b.Ly + b.Hoa;
    if (dtb_a > dtb_b) return -1; 
    if (dtb_a < dtb_b) return 1; 
    if (a.Nam > b.Nam) return -1; 
    if (a.Nam < b.Nam) return 1; 
    if (a.Thang > b.Thang) return -1; 
    if (a.Thang < b.Thang) return 1;
    if (a.Ngay > b.Ngay) return -1; 
    if (a.Ngay < b.Ngay) return 1; 
    return 0; 
}

void mergeSort(vector<Hocsinh> &ls, int size) {
    if (size <= 1) return; 
    vector<Hocsinh> a, b; 
    int i = 0, j = size / 2; 
    while (i < j) a.push_back(ls[i]), i++; 
    while (j < size) b.push_back(ls[j]), j++; 
    mergeSort(a, (int)a.size()); 
    mergeSort(b, (int)b.size()); 
    int ind_a = 0, ind_b = 0; 
    ls.clear(); 
    while (ind_a < (int)a.size() && ind_b < (int)b.size()) {
        if (check(a[ind_a], b[ind_b]) != 1) ls.push_back(a[ind_a]), ind_a++; 
        else ls.push_back(b[ind_b]), ind_b++; 
    }
    while (ind_a < (int)a.size()) ls.push_back(a[ind_a]), ind_a++; 
    while (ind_b < (int)b.size()) ls.push_back(b[ind_b]), ind_b++; 
}

void Sort(vector<Hocsinh> &ls) {
    mergeSort(ls, (int)ls.size()); 
}