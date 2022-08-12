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

Node *insertBST(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (x > root->val)
    {
        root->right = insertBST(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = insertBST(root->left, x);
    }
    return root;
}
Node *insertBST_iteravtive(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    Node *i = root;
    while (i != NULL)
    {
        if (x > i->val)
        {
            if (i->right == NULL)
            {
                i->right = new Node(x);
                break;
            }
            i = i->right;
        }
        else if (x < i->val)
        {
            if (i->left == NULL)
            {
                i->left = new Node(x);
                break;
            }
            i = i->left;
        }
    }
    return root;
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
    Node *root = NULL;
    root = insertBST_iteravtive(root, 50);
    vector<int> vec = {40, 30, 10, 20, 80, 70, 69, 55, 90};

    for (int i = 0; i < vec.size(); i++)
    {
        insertBST(root, vec[i]);
        // insertBST_iteravtive(root, vec[i]);
    }

    // print(root);
    // cout << endl;
    print(root);
    cout << endl;

    // cout << root->val;
    // cout<<root->right->val<<" "<<root->left->val;
}
