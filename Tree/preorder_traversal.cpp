#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *right, *left;
    Node(int x)
    {
        val = x;
        right = left = NULL;
    }
};

void preorder_recurrsive(Node *root)
{
    // Node Left Right
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder_recurrsive(root->left);
    preorder_recurrsive(root->right);
}

void preorder_iterative(Node *root)
{
    Node *i = root;
    stack<Node *> st;
    while (i != NULL || !st.empty())
    {
        while (i != NULL)
        {
            cout << i->val << " ";
            st.push(i);
            i = i->left;
        }
        i = st.top();
        st.pop();
        i = i->right;
    }
}

int main()
{
    // PRE ORDER = Node Left Right(NLR)
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->left = new Node(6);
    cout << "Iterative Preorder:: ";
    preorder_iterative(root);
    cout << endl
         << "Recurrsive Preorder:: ";
    preorder_recurrsive(root);
}