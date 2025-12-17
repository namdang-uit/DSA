![alt text](../problems/bai4.png)

``` c++ 
    int ind = Hash(ht, maso); 
    Node* p = ht.table[ind].head; 
    while (p != NULL && p->data.Maso != maso) p = p->next; 
    return p;
```