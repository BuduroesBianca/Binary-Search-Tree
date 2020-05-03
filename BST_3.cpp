/*3. (1p) Pentru un arbore binar de cautare si doi intregi k1 si k2,
sa se afiseze toate cheile din intervalul deschis (k1,k2).
Sa se omita parcurgerea subarborilor care nu pot contine solutii.*/

#include<iostream>
using namespace std;

struct BinarySearchTree{
    int key;
    BinarySearchTree *left, *right;
    }*root;

void GetKeys(BinarySearchTree *root, int k1, int k2)
{
	if (root != NULL) {
		if (root->key > k1 and root->key < k2)
        {
			GetKeys(root->left, k1, k2);
			cout << root->key << " ";
			GetKeys(root->right, k1, k2);
		}
		else if (root->key <= k1)
			GetKeys(root->right, k1, k2);
		else
			GetKeys(root->left, k1, k2);
	}
}

BinarySearchTree* InsertKey(BinarySearchTree* root, int info)
{
    if (root == NULL)
    {
        BinarySearchTree* aux = new BinarySearchTree;
        aux->key = info;
        aux->left = aux->right = NULL;
        return aux;
        root = aux;
    }
    else
    {
        BinarySearchTree* x = root;
        if (info < x->key)
            x->left = InsertKey(x->left, info);
        else if (info > x->key)
            x->right = InsertKey(x->right, info);
    }
    return root;
}

int main()
{
     int n, x;
    cout << "Introduceti numarul de noduri al arborelui: ";
    cin >> n;
    cout << "Introduceti cheile arborelui: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
            root = InsertKey(root, x);
        else InsertKey(root, x);
    }
    int k1,k2;
    cout<<"Introduceti capetele intervalului pentru care se vor afisa cheile arborelui incluse in acesta: " << endl;
    cout << "k1 = "; cin>>k1;
    cout << "k2 = ";cin >> k2;
    if(k1 > k2)
        swap(k1, k2);
    cout << "Cheile arborelui incluse in interval sunt: ";
    GetKeys(root, k1,k2);
    cout << endl;
    return 0;
}
