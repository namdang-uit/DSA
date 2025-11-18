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

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

int cmp(Hocsinh x, Hocsinh y) {
    if (x.Ten < y.Ten) return -1; 
    if (x.Ten > y.Ten) return 1; 
    if (x.Hodem < y.Hodem) return -1; 
    if (x.Hodem > y.Hodem) return 1; 
    if (x.Nam > y.Nam) return -1; 
    if (x.Nam < y.Nam) return 1; 
    if (x.Thang > y.Thang) return -1; 
    if (x.Thang < y.Thang) return 1; 
    if (x.Ngay > y.Ngay) return -1; 
    if (x.Ngay < y.Ngay) return 1;
    return 0; 
}

void Sort(List &l) {
    List a, b; 
    CreateList(a); 
    CreateList(b);
    Node* p = l.head; 
    int size_a = 0, size_b = 0; 
    while (p != NULL) {
        AddTail(a, p->data); 
        size_a++; 
        p = p->next; 
        if (p != NULL) {
            AddTail(b ,p->data); 
            size_b++; 
            p = p->next; 
        }
    }
    if (size_a > 1) Sort(a); 
    if (size_b > 1) Sort(b); 

    while (l.head != NULL) RemoveHead(l); 

    Node* ind_a = a.head; 
    Node* ind_b = b.head; 

    while (ind_a != NULL && ind_b != NULL) {
        if (cmp(ind_a->data, ind_b->data) == -1) {
            AddTail(l, ind_a->data); 
            ind_a = ind_a->next; 
        }
        else {
            AddTail(l, ind_b->data); 
            ind_b = ind_b->next;
        }
    }
    while (ind_a != NULL) {
        AddTail(l, ind_a->data); 
        ind_a = ind_a->next; 
    }
    while (ind_b != NULL) {
        AddTail(l, ind_b->data); 
        ind_b = ind_b->next; 
    }
}