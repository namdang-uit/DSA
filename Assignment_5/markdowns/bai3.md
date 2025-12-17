![alt text](../problems/bai3.png)

``` c++ 
#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Node {
    int key; 
    Node *next;
};

struct List {
    Node * head, *tail;
};

Node * CreateNode(int);
void CreateList(List &);
void AddTail(List&, int);
int RemoveHead(List &);
int RemoveAfter(List &, Node *);
void DeleteList(List &);

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

void CreateHashtable(Hashtable &, int);
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
Node * Search(Hashtable, int, int&);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(int x) {
    cin >> x; 
}
int main()
{
    Hashtable hashtable;

    int m, n, k;
    double load; 

    cin >> m >> load >> n;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i + 1 <= load * m) 
            AddTail(hashtable.table[Hash(hashtable, k)], k);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        int cnt = 1; 
        Node * p = Search(hashtable, k, cnt);

        if (p == NULL)
            cout << "KHONG\n";
        else 
            cout << cnt << '\n'; 
    }
    DeleteHashtable(hashtable);
    return 0;
}
void CreateList(List &l) {
    l.head = l.tail = NULL;
}

Node * CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->key = x;
    return p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

int RemoveHead(List &l) {
    if (l.head == NULL)
        return 0;
    Node *p = l.head;
    l.head = p->next;
    if (l.tail == p)
        l.tail = NULL;
	delete p;
    return 1;
}

int RemoveAfter(List &l, Node *q) {
    if (l.head == NULL)
        return 0;

    if (q == NULL)
        return RemoveHead(l);

    Node *p = q->next;
    q->next = p->next;
    if (l.tail == p)
        l.tail = q;
    delete p;
    return 1;
}

void DeleteList(List &l) {
    while (l.head) {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int Hash(Hashtable ht, int maso) {
    return maso % ht.M;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Node *p = ht.table[i].head;
        while (p) {
            cout << p->key << ' '; 
            p = p->next;
        }
        cout << '\n';
    }
}

void DeleteHashtable(Hashtable &ht) {
    for (int i = 0; i < ht.M; i++) {
        DeleteList(ht.table[i]);
    }
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

Node * Search(Hashtable ht, int maso, int &cnt) {
    int ind = Hash(ht, maso); 
    Node* p = ht.table[ind].head; 
    while (p != NULL && p->key != maso) {
        p = p->next; 
        cnt++; 
    }
    return p; 
}
```