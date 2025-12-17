
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
    if (x.MSHS > 0)
        getline(cin>>ws, x.HoTen);
    else {
        x.HoTen = "";
    }

    cin >> x.Namsinh; 
    if (x.MSHS > 0)
        cin >> x.Gioitinh;
    else
        x.Gioitinh = ' ';

    cin >> x.Toan; 
    cin >> x.Ly; 
    cin >> x.Hoa; 
    cin >> x.Anh; 
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

int Delete(Hashtable &, int);

int main()
{
    Hashtable ht;
    int m, n;

    cin >> m >> n;
    ht.n = n;
    ht.M = m;
    for (int i = 0; i < m; i++) {
        InputElement(ht.table[i]);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << m << ' ' << Delete(ht, m) << endl;
    }

    cout << ht.n << endl;
    for (int i = 0; i <ht.M; i++) {
        cout << ht.table[i].MSHS << endl;
    }
    return 0;
}

int Delete(Hashtable &ht, int m) {
    int ind = m % ht.M; 
    int cnt = 0; 
    
    while (cnt < ht.M) {
        if (ht.table[ind].MSHS == m) {
            ht.n--; 
            ht.table[ind].MSHS = DELETED;
            return cnt + 1; 
        }
        
        if (ht.table[ind].MSHS == EMPTY) {
            return -(cnt + 1);
        }
        
        cnt++; 
        ind = (m % ht.M + cnt * cnt) % ht.M; 
    }
    
    return -(cnt); 
}