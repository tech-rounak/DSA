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
void inorder_iterative(Node *root)
{
    Node *i = root;
    stack<Node *> st;
    while (i != NULL || !st.empty())
    {
        while (i != NULL)
        {
            st.push(i);
            i = i->left;
        }
        i = st.top();
        st.pop();
        cout << i->val << " ";
        i = i->right;
    }
}
void inorder_recurrsive(Node *root)
{
    // Left Node Right
    if (root == NULL)
        return;

    inorder_recurrsive(root->left);
    cout << root->val << " ";
    inorder_recurrsive(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->left = new Node(6);
    cout << "Inorder (LNR): ";
    inorder_iterative(root);
    cout << endl;
}