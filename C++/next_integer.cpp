#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename t>
class treenode
{
public:
    t data;
    vector<treenode<t> *> children;
    treenode(t data)
    {
        this->data = data;
    }
    ~treenode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
treenode<int> *takeinput()
{
    int data;
    cout << "enter the root data" << endl;
    cin >> data;
    treenode<int> *root = new treenode<int>(data);
    queue<treenode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        treenode<int> *front = q.front();
        q.pop();
        int x;
        cout << "how many children of " << front->data << endl;
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            cout << "enter the data of " << i << "th child" << endl;
            cin >> data;
            treenode<int> *child = new treenode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
int nextinteger(treenode<int> *root, int x)
{
    int next;
    if (root == NULL)
    {
        return -1;
    }
    if(root->data>x)
    {
        return root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        next = nextinteger(root->children[i], x);
    }
    return -1;
}
int main()
{
    treenode<int>*root=takeinput();
    cout<<nextinteger(root,2);
}