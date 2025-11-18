#include <iostream>
#include <vector>
#include <map>



using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}

	
int MaxLevel(TREE r) {
    vector <TREE> a; 
    a.push_back(r); 
    int level = -1, maxSumKey = 0, maxlevel = 0; 
    while (true) {
        int sumKey = 0; 
        level++; 
        vector <TREE> b; 
        for (int i = 0; i < (int)a.size(); i++) {
            sumKey += a[i]->key; 
            if (a[i]->left != NULL) b.push_back(a[i]->left); 
            if (a[i]->right != NULL) b.push_back(a[i]->right); 
        }
        if (sumKey > maxSumKey) {
            maxSumKey = sumKey; 
            maxlevel = level; 
        }
        if (!(int)b.size()) break; 
        a.clear(); 
        for (int i = 0; i < (int)b.size(); i++) a.push_back(b[i]); 
    }
    return maxlevel; 
}