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
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    //Helping function
    void add(T value){
        //TODO
        Node **p = &root;
        while (*p){
            p = (*p)->value > value ? &((*p)->pLeft) : &((*p)->pRight);
        }
        *p = new Node(value);
    }
    Node *minNode(Node *root){
        Node *temp = root;
        while (temp && temp->pLeft)
            temp = temp->pLeft;
        return temp;
    }
  void remove(Node *&root, const T&value){
        if (root == nullptr)    return;
        if (root->value > value) remove(root->pLeft, value);
        else if (root->value < value)  remove(root->pRight, value);
        else{
            if (root->pLeft && root->pRight){
                Node *minN = minNode(root->pRight);
                root->value = minN->value;
                remove(root->pRight, root->value);
            }
            else if (root->pLeft == nullptr){
                Node *temp = root;
                root = root->pRight;
                delete temp;
            }
            else if (root->pRight == nullptr){
                Node *temp = root;
                root = root->pLeft;
                delete temp;
            }
            else{
                delete root;
                root = nullptr;
            }
        }
    }
    void deleteNode(T value){
        //TODO
        remove(this->root, value);
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    T getMin() {
        //TODO: return the minimum values of nodes in the tree.
        Node *temp = root;
        while (temp && temp->pLeft)
            temp = temp->pLeft;
        
        return temp->value;
    }
    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        Node *temp = root;
        while (temp && temp->pRight)
            temp = temp->pRight;
        
        return temp->value;
    }
    bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
        Node *temp = root;
        while (temp){
            if (i == temp->value)   return true;
            else if (i < temp->value)   temp = temp->pLeft;
            else                        temp = temp->pRight;
        }
        return false;
    }
    T sum(Node *root, T l, T r){
        T ans = 0;
        if (root && root->value>=l && root->value<=r)   ans+=root->value;
        if (root->pLeft)    ans+=sum(root->pLeft, l, r);
        if (root->pRight)   ans+=sum(root->pRight, l, r);
        return ans;
    }
    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return sum(root, l, r);
    }
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int values[] = { 66,60,84,67,21,45,62,1,80,35 };
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }

    cout << bst.find(5) << endl;
    cout << bst.sum(10, 40);
    

    return 0;
}