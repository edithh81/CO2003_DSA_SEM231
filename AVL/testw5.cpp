#include <bits/stdc++.h>
using namespace std;
#define EDITH81
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using pii = pair<int, int>;
#define piii pair<int,pii>
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data << ' ' << temp->freq << ' ' << temp->count;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    #define value data

Node* rotateLeft(Node* subroot)
{
//TODO: Rotate and return new root after rotate
    Node *temp = subroot->pRight;
    int tR = temp->count;
    temp->count = subroot->count;
    subroot->count -= tR;
    if (temp->pLeft) subroot->count += temp->pLeft->count; 
    subroot->pRight = temp->pLeft;
    temp->pLeft = subroot;
    subroot = temp;
    return subroot;
}
Node* rotateRight(Node* subroot)
{
//TODO: Rotate and return new root after rotate
    Node *temp = subroot->pLeft;
    int tL = temp->count;
    temp->count = subroot->count;
    subroot->count -= tL;
    if (temp->pRight) subroot->count += temp->pRight->count;  
    subroot->pLeft = temp->pRight;
    temp->pRight = subroot;
    subroot = temp;
    return subroot;
}
bool balanceLeft(Node *&root){
        if (root->balance == EH){
            root->balance = LH;
            return true;
        }
        if (root->balance == RH){
            root->balance = EH;
            return false;
        }
        if (root->pLeft->balance == EH){
            root = rotateRight(root);
            root->balance = RH;
            root->pRight->balance = LH;
            return true;
        }
        if (root->pLeft->balance == LH){
            root = rotateRight(root);
            root->balance = root->pRight->balance = EH;
            return false;
        }
        root->pLeft = rotateLeft(root->pLeft);
        root = rotateRight(root);
        if (root->balance == EH) root->pLeft->balance = root->pRight->balance = EH;
        else if (root->balance == LH)   {root->pRight->balance = RH; root->balance = root->pLeft->balance = EH;}
        else{
            root->pLeft->balance = LH;   
            root->pRight->balance = root->balance = EH;
        }
        return false;
    }
    bool balanceRight(Node *&root){
        if (root->balance == EH){
            root->balance = RH;
            return true;
        }
        if (root->balance == LH){
            root->balance = EH;
            return false;
        }
        if (root->pRight->balance == EH){
            root = rotateLeft(root);
            root->balance = LH;
            root->pLeft->balance = RH;
            return true;
        }
        if (root->pRight->balance == RH){
            root = rotateLeft(root);
            root->balance = root->pLeft->balance = EH;
            return false;
        }
        root->pRight = rotateRight(root->pRight);
        root = rotateLeft(root);
        if (root->balance == EH) root->pRight->balance = root->pLeft->balance = EH;
        else if (root->balance == RH)   {root->pLeft->balance = LH; root->balance = root->pRight->balance = EH;}
        else{
            root->pRight->balance = RH;
            root->pLeft->balance = root->balance = EH;
        }
        return false;
    }
    bool insert(Node *&root, const T &value){
        if (root == nullptr){
            root = new Node(value);
            return true;
        }
        else{
            if (root->value == value ){root->count++; root->freq++; return false;}
            if (root->value > value){
                root->count++;
                if (insert(root->pLeft, value)){
                    return balanceLeft(root);
                }
                return false;
            }
            else{root->count++;
                if (insert(root->pRight, value)){
                        return balanceRight(root);
                }
                return false;
            }
        }
    }
    void insert(const T &value)
    {
        //TODO
        insert(this->root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        int count, freq;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH), count(1), freq(1) {}
        ~Node() {}
    };
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    srand(45);
    AVLTree<int> avl;
for (int i = 10; i >= 0; i--){
    int x = rand() % 20;
    cout << x << ' ';
	avl.insert(x);
}
cout << endl;
avl.printTreeStructure();
    return 0;
}