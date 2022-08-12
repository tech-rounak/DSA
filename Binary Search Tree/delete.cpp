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
Node *getSuccessor(Node *root)
{
    Node *curr = root->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
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
    vector<int> vec = {30, 20, 40, 70, 60, 80};

    for (int i = 0; i < vec.size(); i++)
    {
        insertBST_iteravtive(root, vec[i]);
    }
    root = deleteNode(root, 50);
    print(root);
    cout << endl;

    root = deleteNode(root, 30);
    print(root);
    cout << endl;
}
