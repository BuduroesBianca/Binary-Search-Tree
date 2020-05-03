/*1. (3p) Implementati arbore binar de cautare cu operatiile:
- inserarea unei chei x
- cautarea unei chei x (zice 0/1)
- afisarea cheilor din arbore dupa SRD (inordine) si RSD (preordine)
- (+3p) stergerea unei chei x (o aparitie) cu pastrarea proprietatii de arbor binar de cautare */

#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

struct BinarySearchTree{
    int key;
    BinarySearchTree *left, *right;
    }*root;

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

int SearchKey(BinarySearchTree *root, int value)
{
    if (root != NULL)
    {
        if (root->key == value)
            return 1;
        else
            if (root->key > value)
                return SearchKey(root->left, value);
            else
                return SearchKey(root->right,value);
    }
    else
        return 0;
}

void SRD(struct BinarySearchTree* root)
{
    if (root != NULL)
    {
        SRD(root->left);
        cout << root->key << " ";
        SRD(root->right);
    }
}

void RSD(struct BinarySearchTree* root)
{
    if(root != NULL)
    {
        cout<< root->key << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

struct BinarySearchTree* minimum(struct BinarySearchTree* root)
{
    struct BinarySearchTree* aux = root;

    while (aux && aux->left != NULL)  // parcurgem pana gasim cea mai din stanga cheie
        aux = aux->left;

    return aux;
}

struct BinarySearchTree* RemoveKey(struct BinarySearchTree *root, int key)
{
    if(SearchKey(root, key))
    {
        if (root == NULL)
            return root;

        if (key < root->key)    // daca cheia data este mai mica decat cheia radacinii
            root->left = RemoveKey(root->left, key);    // atunci lucram in subarbroele stang

        else if (key > root->key)   // daca cheia data este mai mare decat cheia radacinii
            root->right = RemoveKey(root->right, key);  // atunci lucram in subarbroele drept

        else // in cazul in care cheia e aceeasi cu cheia radacinii
        {
            if (root->left == NULL)  // nodul fara copii sau cu maxim unul
            {
                struct BinarySearchTree *aux = root->right;
                free(root);
                return aux;
            }
            else if (root->right == NULL)
            {
                struct BinarySearchTree *aux = root->left;
                free(root);
                return aux;
            }

            struct BinarySearchTree* aux = minimum(root->right);  // nodul cu 2 copii
            root->key =aux->key;
            root->right = RemoveKey(root->right, aux->key);
        }
        return root;
    }
    else
        throw invalid_argument("Elementul nu se afla in arbore");
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
    cout << "Afisare Binary Search Tree in inordine: ";
    SRD(root);
    cout << endl;

   cout << "Afisare Binary Search Tree in preordine: ";
    RSD(root);
    cout << endl;

    cout << "Introduceti cheia pe care doriti sa o cautati in arbore: ";
    cin >> x;
    if(SearchKey(root, x) == 1)
        cout<< "Valoare cautata se afla in Binary Search Tree" << endl;
    else
         cout<< "Valoare cautata nu se afla in Binary Search Tree" << endl;

    cout << "Introduceti cheia din arbore pe care doriti sa o stergeti: ";
    cin >> x;
    RemoveKey(root,x);
    SRD(root);
    return 0;
}
