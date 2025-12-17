
#include <iostream>


#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh {
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};


struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x) {
    cin >> x.MSHS; 
    getline(cin>>ws, x.HoTen);
    cin >> x.Namsinh; 
    cin >> x.Gioitinh; 
    cin >> x.Toan; 
    cin >> x.Ly; 
    cin >> x.Hoa; 
    cin >> x.Anh; 
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

void CreateHashtable(Hashtable &, int, Hocsinh[], int);

int main()
{
    Hashtable ht;
    Hocsinh ds[MAX];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        InputElement(ds[i]);
    }

    CreateHashtable(ht, m, ds, n);

    cout << ht.M << ' ' << ht.n << endl;
    for (int i = 0; i < ht.M; i++) {
        OutputElement(ht.table[i]);
    }

    return 0;
}

void CreateHashtable(Hashtable &ht, int m, Hocsinh ds[], int n) {
    ht.M = m; 
    ht.n = 0; 
    
    for (int i = 0; i < m; i++) {
        ht.table[i].MSHS = EMPTY;
        ht.table[i].HoTen = "";
        ht.table[i].Namsinh = 0;
        ht.table[i].Gioitinh = ' ';
        ht.table[i].Toan = 0.0;
        ht.table[i].Ly = 0.0;
        ht.table[i].Hoa = 0.0;
        ht.table[i].Anh = 0.0;
    }
    
    for (int i = 0; i < n; i++) {
        int mshs = ds[i].MSHS;
        int ind = mshs % ht.M;
        int cnt = 0;
        
        while (cnt < ht.M) {
            if (ht.table[ind].MSHS == EMPTY || ht.table[ind].MSHS == DELETED) {
                ht.table[ind] = ds[i];
                ht.n++;
                break;
            }
            cnt++;
            ind = (mshs % ht.M + cnt * cnt) % ht.M;
        }
    }
}