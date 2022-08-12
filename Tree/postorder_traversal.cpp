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

void postorder_recurrsive(Node *root)
{
    // Left Right Node
    if (root == NULL)
        return;

    postorder_recurrsive(root->left);
    postorder_recurrsive(root->right);
    cout << root->val << " ";
}

void postorder_iterative_using_two_stack(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty tree " << endl;
        return;
    }
    Node *i = root;
    stack<Node *> st, ans;
    st.push(i);
    while (!st.empty())
    {
        i = st.top();
        ans.push(st.top());
        st.pop();
        if (i->left != NULL)
            st.push(i->left);
        if (i->right != NULL)
            st.push(i->right);
    }
    while (!ans.empty())
    {
        cout << ans.top()->val << " ";
        ans.pop();
    }
}
void postorder_iterative_using_one_stack(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty tree " << endl;
        return;
    }
    Node *i = root, *tmp;
    stack<Node *> st;
    while (!st.empty() || i != NULL)
    {
        if (i != NULL)
        {
            st.push(i);
            i = i->left;
        }
        else
        {
            tmp = st.top()->right;
            if (tmp == NULL)
            {
                tmp = st.top();
                st.pop();
                cout << tmp->val << " ";
                while (!st.empty() && st.top()->right == tmp)
                {
                    tmp = st.top();
                    st.pop();
                    cout << tmp->val << " ";
                }
            }
            else
                i = tmp;
        }
    }
}

int main()
{
    // POST ORDER = Left Right Node(LRN)
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->left = new Node(6);
    cout << "Iterative Postorder:: ";
    postorder_iterative_using_one_stack(root);
    cout << endl
         << "Recurrsive Postorder:: ";
    postorder_recurrsive(root);
}