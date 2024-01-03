#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using pii = pair<int, int>;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    int countTwoChildrenNode(Node *root){
        if (root == nullptr)    return 0;
        if (root->pLeft && root->pRight)
            return 1+countTwoChildrenNode(root->pLeft)+countTwoChildrenNode(root->pRight);
    }
    int countTwoChildrenNode(){
        return countTwoChildrenNode(root);
    }
    int getHeight(Node *root){
        if (root == nullptr)    return 0;
        int lHeight = 1 + getHeight(root->pLeft);
        int rHeight = 1 + getHeight(root->pRight);
        return max(lHeight, rHeight);
    }
    int getHeight() {
    // TODO: return height of the binary tree.
        return getHeight(root);
    }
    string preOrder(Node *root){
        string res = "";
        if (root){
            res += to_string(root->value);
            res += ' ';
        }
        if (root &&root->pLeft)
            res += preOrder(root->pLeft);
        if (root &&root->pRight)
            res += preOrder(root->pRight);
        return res;
    }
    string preOrder() {
        // TODO: return the sequence of values of nodes in pre-order.
        return preOrder(root);
    }
     string inOrder(Node *root){
        string res = "";
        if (root && root->pLeft)
            res += inOrder(root->pLeft);
        if (root){
            res += to_string(root->value);
            res += ' ';
        }
        if (root && root->pRight)
            res += inOrder(root->pRight);
        return res;
    }
    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        return inOrder(root);
    }
    string postOrder(Node *root){
        string res = "";
        if (root && root->pLeft)
            res += postOrder(root->pLeft);
        if (root && root->pRight)
            res += postOrder(root->pRight);
        if (root){
            res += to_string(root->value);
            res += ' ';
        }
        return res;
    }
    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        return postOrder(root);
    }
    int sumofLeafs(Node *root){
        if (root == nullptr) return 0;
        int ans = sumOfLeafs(root->pLeft) + sumOfLeafs(root->pRight);
        if (root->pLeft == nullptr && root->pRight == nullptr)  return root->value;
        return ans;
    }
    int sumOfLeafs(){
    //TODO
        sumOfLeafs(root);
    
    }
    void BFS()
    {
        if (root == nullptr)    return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            auto f = q.front(); q.pop();
            cout << f->value << ' ';
            if (f->pLeft)
                q.push(f->pLeft);
            if (f->pRight)
                q.push(f->pRight);      
        }
    }
    // STUDENT ANSWER END
};
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
      
    

    return 0;
}