#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};
void inorder(Node *root)
{
    //Left Node Right
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    //Node Left Right
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    //Left Right Node
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int size_of_tree(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + size_of_tree(root->left) + size_of_tree(root->right);
}
int max_of_tree(Node *root)
{
    if (root == NULL)
        return -1;
    return max(root->data, max(max_of_tree(root->left), max_of_tree(root->right)));
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int main()
{
    Node *root = new Node(43);
    root->left = new Node(85);
    root->right = new Node(13);
    root->right->left = new Node(20);
    root->right->right = new Node(53);
    root->left->right = new Node(132);
    root->left->left = new Node(42);
    cout << "Inorder (LNR): ";
    inorder(root);
    cout << endl;
    cout << "Preorder (NLR): ";
    preorder(root);
    cout << endl;
    cout << "Postorder (LRN): ";
    postorder(root);
    cout << endl;

    int sz = size_of_tree(root);
    cout << sz << endl;
    int mx = max_of_tree(root);
    cout << mx << endl;
    int h = height(root);
    cout << h << endl;
}