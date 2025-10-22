#include <iostream>

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

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}


void CreateEmptyList(List &ds) {
    ds.head = NULL;
    ds.tail = NULL;
}

Node* CreateNode(Hocsinh x) {
    Node* p = new Node; 
    if (p == NULL) exit(1); 
    p->data = x;
    p->next = NULL;
    return p;
}

void AddTail(List &ds, Node* p) {
    if (ds.head == NULL) {
        ds.head = p;
        ds.tail = p;
    } else {
        ds.tail->next = p;
        ds.tail = p;
    }
}

int main() {
    List ds; 
    CreateEmptyList(ds); 
    int n; 
    cin >> n; 
    while (n--) {
        Hocsinh x; 
        InputElement(x); 
        Node* p = CreateNode(x); 
        AddTail(ds, p); 
    }
    List res; 
    CreateEmptyList(res);
    Node* cur = ds.head;
    while (cur != NULL) {
        double dtb = (cur->data.Toan + cur->data.Van + cur->data.Ly + cur->data.Hoa + cur->data.Anh + cur->data.Sinh) / 6.0;
        if (dtb >= 9.0) {
            Node* p = CreateNode(cur->data);
            AddTail(res, p);
        }
        cur = cur->next;
    }
    Output(res);
}