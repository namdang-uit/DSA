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
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int compare(Hocsinh x, Hocsinh y) {
    if (x.Ten < y.Ten) return -1; 
    if (x.Ten > y.Ten) return 1; 
    if (x.Hodem < y.Hodem) return -1; 
    if (x.Hodem > y.Hodem) return 1;
    return 0; 
}

void InsertTree(TREE &tree, Hocsinh x) {
    bool c = 0; 
    if (tree == NULL) {
        tree = CreateTNode(x); 
        return; 
    }
    if (compare(tree->data, x) == 1) InsertTree(tree->left, x); 
    else if (compare(tree->data, x) == -1) InsertTree(tree->right, x); 
    else return; 
}

void inorder(TREE tree) {
    if (tree == NULL) return; 
    inorder(tree->left); 
    OutputElement(tree->data); 
    inorder(tree->right); 
}

int main() {
    int n;
    cin >> n; 
    TREE tree; 
    CreateTree(tree); 
    Hocsinh x; 
    while (n--) {
        InputElement(x); 
        InsertTree(tree, x);    
    }
    inorder(tree); 
}