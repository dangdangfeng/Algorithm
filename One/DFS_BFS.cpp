#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int val;
    Node *pLeft;
    Node *pRight;

    Node(int val, Node *left = NULL, Node *right = NULL):val(val),pLeft(left),pRight(right){};
};

// queue
void BFS(Node *pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        Node *node = Q.front();

        cout<<node->val<<"->";

        Q.pop();

        if(node->pLeft != NULL){
            Q.push(node->pLeft);
        }
        if (node->pRight != NULL)
        {
            Q.push(node->pRight);
        }
    }
    cout << endl;
    
}

// stack
void DFS(Node *pRoot){
    if (pRoot == NULL)
    {
        return;
    }

    stack<Node *> S;
    S.push(pRoot);

    while(!S.empty()){
        Node *node = S.top();
        cout << node->val<<",";

        S.pop();

        if (node->pRight != NULL)
        {
            S.push(node->pRight);
        }

        if (node->pLeft != NULL){
            S.push(node->pLeft);
        }
    }
    
}

// 打印树的信息
void PrintTree(Node *pRoot)
{
    if (pRoot == NULL)
        return;

    cout << pRoot->nVal << " ";

    if (pRoot->pLeft != NULL)
    {
        PrintTree(pRoot->pLeft);
    }

    if (pRoot->pRight != NULL)
    {
        PrintTree(pRoot->pRight);
    }
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(4);
    Node *node2 = new Node(5);
    Node *node3 = new Node(6);

    Node *node4 = new Node(2, node1, node2);
    Node *node5 = new Node(3, node3);
    Node *node6 = new Node(1, node4, node5);

    Node *pRoot = node6;

    PrintTree(pRoot);

    BFS(pRoot);

    return 0;
}
