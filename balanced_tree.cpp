#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    pair<bool, int> height(struct Node *node)
    {
        if (node == NULL)
            return {true, -1};
        pair<bool, int> l = height(node->left);
        pair<bool, int> r = height(node->right);
        if (l.first == false || r.first == false)
            return {false, max(l.second, r.second) + 1};
        if (abs(l.second - r.second) > 1)
            return {false, max(l.second, r.second) + 1};
        return {true, max(l.second, r.second) + 1};
    }

    pair<int,int> largestPath(struct Node *node){
        if(node == NULL)return {0,-1};
        pair<int , int> l = height(node->left);
        pair<int , int> r = height(node->right);
        return {max(max(l.first,r.first),l.second+r.second+1), max(l.second, r.second) + 1};
    }

    int  childSum(struct Node *node){
        if (node->left == NULL && node->right == NULL)return 0 ;
        if(node == NULL)return 0;
        int l = childSum(node->left);
        int r= childSum(node->right);
        node->data+=l+r;
        return node->data;
    }
};
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.childSum(root) << endl;
    }
    return 0;
}