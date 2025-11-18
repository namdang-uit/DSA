#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void Sum(List a, List b, List &c) {
    List rev_a; 
    CreateList(rev_a); 
    Node* ind_a = a.head; 
    while (ind_a != NULL) {
        AddHead(rev_a, ind_a->num); 
        ind_a = ind_a->next; 
    }
    ind_a = rev_a.head; 

    List rev_b; 
    CreateList(rev_b); 
    Node* ind_b = b.head; 
    while (ind_b != NULL) {
        AddHead(rev_b, ind_b->num); 
        ind_b = ind_b->next; 
    }
    ind_b = rev_b.head; 

    bool n = 0; 
    while (ind_a != NULL && ind_b != NULL) {
        int s = ind_a->num + ind_b->num + n; 
        if (s > 9) {
            s -= 10; 
            n = 1; 
        }
        else n = 0; 
        AddHead(c, s); 
        ind_a = ind_a->next; 
        ind_b = ind_b->next; 
    }
    while (ind_a != NULL) {
        int s = ind_a->num + n; 
        if (s > 9) {
            s -= 10; 
            n = 1; 
        }
        else n = 0; 
        AddHead(c, s); 
        ind_a = ind_a->next; 
    }
    while (ind_b != NULL) {
        int s = ind_b->num + n; 
        if (s > 9) {
            s -= 10; 
            n = 1; 
        }
        else n = 0; 
        AddHead(c, s); 
        ind_b = ind_b->next; 
    }
}