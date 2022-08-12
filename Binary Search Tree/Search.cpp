#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (x > root->val)
    {
        root->right = insert(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = insert(root->left, x);
    }
    return root;
}
bool recurssive_search(Node *root, int x)
{
    if (root == NULL)
        return false;
    else if (root->val == x)
        return true;
    else if (x > root->val)
        return recurssive_search(root->right, x);
    else
        return recurssive_search(root->left, x);
}
bool iterative_search(Node *root, int x)
{

    Node *i = root;
    while (i != NULL)
    {
        if (i->val == x)
            return true;
        else if (i->val < x)
            i = i->right;
        else
            i = i->left;
    }
    return false;
}
void print(Node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
int main()
{
    Node *root = new Node(50);
    root->right = new Node(32);
    vector<int> vec = {40, 30, 10, 20, 80, 70, 69, 55, 90};
    for (int i = 0; i < 9; i++)
        insert(root, vec[i]);

    print(root);
    cout << endl;

    bool k = recurssive_search(root, 40);
    cout << k << endl;
    // cout << root->val;
    // cout<<root->right->val<<" "<<root->left->val;
}
