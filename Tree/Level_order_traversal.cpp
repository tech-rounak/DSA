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
void level_order_traversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> qu;
    vector<vector<int>> ans;
    Node *i = root, *tmp;
    qu.push(i);
    while (!qu.empty())
    {
        int k = qu.size();
        vector<int> level;
        while (k--)
        {
            i = qu.front();
            qu.pop();
            level.push_back(i->val);
            cout << i->val << " ";
            if (i->left != NULL)
                qu.push(i->left);
            if (i->right != NULL)
                qu.push(i->right);
        }
        ans.push_back(level);
    }
    cout << endl;
    for (auto &it : ans)
    {
        for (auto &it1 : it)
            cout << it1 << " ";
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(43);
    root->left = new Node(85);
    root->right = new Node(13);
    root->right->left = new Node(20);
    root->right->right = new Node(53);
    root->left->right = new Node(32);
    root->left->left = new Node(42);
    cout << "Inorder (LNR): ";
    level_order_traversal(root);

    cout << endl;
}