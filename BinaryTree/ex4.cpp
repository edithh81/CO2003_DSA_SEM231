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
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
    #define pnii pair<BTNode *, pii>
    int longestPathSum(BTNode* root){
        if (root == nullptr)    return 0;
        queue<pnii> q;
        q.push({root, {root->val, 0}});
        int ans = root->val;
        int max_length = 0;
        while (!q.empty()){
            auto f = q.front(); q.pop();
            if (f.first->left){
                q.push({f.first->left, {f.second.first+f.first->left->val, f.second.second+1}});
                if (!f.first->left->left && !f.first->left->right && ( max_length<= f.second.second+1)){
                    if (max_length == f.second.second+1) ans = max(ans, f.second.first+f.first->left->val);
                    else                                 {ans = f.second.first+f.first->left->val; max_length = f.second.second+1;}
                }
            }
            if (f.first->right){
                q.push({f.first->right, {f.second.first+f.first->right->val, f.second.second+1}});
                if (!f.first->right->left && !f.first->right->right && ( max_length <= f.second.second+1)){
                    if (max_length == f.second.second+1) ans = max(ans, f.second.first+f.first->right->val);
                    else                                 {ans = f.second.first+f.first->right->val; max_length = f.second.second+1;}
                }
            }
        }
        return ans;
    }
    #define MOD 27022001
    #define pni pair<BTNode *, int> 
    int sumDigitPath(BTNode* root) {
        if (root == nullptr)    return 0;
        queue<pni> q;
        q.push({root, root->val});
        int ans = 0;
        while (!q.empty()){
            auto f = q.front(); q.pop();
            if (f.first->left){
                q.push({f.first->left,(f.second*10%MOD + f.first->left->val%MOD)%MOD });
                if (!f.first->left->left && !f.first->left->right) { ans += f.second*10%MOD + f.first->left->val%MOD; ans%=MOD;}
            }
            if (f.first->right){
                q.push({f.first->right,(f.second*10%MOD + f.first->right->val%MOD)%MOD });
                if (!f.first->right->left && !f.first->right->right)  {ans += f.second*10%MOD + f.first->right->val%MOD; ans%=MOD;}
            }
        }
        return ans;
    }
    int lowestAncestor(BTNode* root, int a, int b) {
        if (root == nullptr)    return -1;
        if (root->val == a || root->val == b)   return root->val;
        int l = lowestAncestor(root->left, a, b);
        int r = lowestAncestor(root->right, a, b);
        if (l == -1)    return r;
        if (r == -1)    return l;
        return root->val;
    }
};
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
      
    

    return 0;
}