/*2. (1p) Folositi un arbore binar de cautare ca sa sortati n siruri de caractere.
 Puteti folosi strcmp din string.h pentru comparare lexicografica intre siruri de caractere.*/

 #include<iostream>
 #include<string.h>
 using namespace std;

 struct BinarySearchTree{
    char key[100];
    BinarySearchTree *left, *right;
    }*root;

void SRD(struct BinarySearchTree* root)
{
    if( root != NULL )
    {
        SRD( root->left );
        cout << root->key << " ";
        SRD( root->right );
    }
}

void RSD(struct BinarySearchTree* root)
{
    if( root != NULL)
    {
        cout << root->key << " ";
        RSD( root-> left );
        RSD( root-> right );
    }
}

 BinarySearchTree* InsertKey(BinarySearchTree* root, char str[100])
{
    if (root == NULL)
    {
        BinarySearchTree* aux = new BinarySearchTree;
        strcpy(aux->key, str);
        aux->left = aux->right = NULL;
        return aux;
        root = aux;
    }
    else
    {
        BinarySearchTree* x = root;
        if (strcmp(str, x->key) <= 0 )
            x->left = InsertKey(x->left, str);
        else if (strcmp(str, x->key) > 0)
            x->right = InsertKey(x->right, str);
    }
    return root;
}

 int main()
 {
     int n; char str[100];
    cout << "Introduceti numarul de siruri: ";
    cin >> n;
    cout << "Introduceti cele " << n << " siruri de caractere: ";
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (i == 0)
            root = InsertKey(root, str);
        else InsertKey(root, str);
    }
    cout << "Afisare Binary Search Tree in inordine: ";
    SRD(root);
    cout << endl;

    cout << "Afisare Binary Search Tree in preordine: ";
    RSD(root);
    cout << endl;
    return 0;
 }
