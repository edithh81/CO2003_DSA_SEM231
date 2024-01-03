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
class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
vector<int> levelAlterTraverse(BSTNode* root){
    if (root == nullptr)    return {};
    vector<int> res;
    stack<BSTNode *> s1, s2;
    s1.push(root);
    res.push_back(root->val);
    while (!s1.empty() || !s2.empty()){
        while (!s1.empty()){
            auto t = s1.top(); s1.pop();
            if (t->right) {res.push_back(t->right->val); s2.push(t->right);}
            if (t->left) {res.push_back(t->left->val);s2.push(t->left);}
        }
        while (!s2.empty()){
            auto t = s2.top(); s2.pop();
            if (t->left) {res.push_back(t->left->val);s1.push(t->left);}
            if (t->right) {res.push_back(t->right->val);s1.push(t->right);}
        }
    }
    return res;
}
int singleChild(BSTNode* root){
    if (root == nullptr)    return 0;
    int ans = 0;
    if (root->left == nullptr && root->right || root->right == nullptr && root->left)   ++ans;
    ans += singleChild(root->left) + singleChild(root->right);
    return ans;
}
int kthSmallest(BSTNode* root, int &k) {
    if (root == nullptr)    return -1;
    int left = kthSmallest(root->left, k);
    if (left != -1) return left; 
    --k;
    if (!k && root) return root->val;
    return kthSmallest(root->right, k);
}
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (root == nullptr)    return root;
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    if (root->val < lo){
        BSTNode *temp = root->right;
        delete root;
        return temp;
    }
    if (root->val > hi){
        BSTNode *temp = root->left;
        delete root;
        return temp;
    } 
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);

    

    return 0;
}