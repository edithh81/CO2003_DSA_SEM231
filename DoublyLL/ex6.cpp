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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    ListNode *tmp = head;
    ListNode *tmp1 = head;
    int range = b-a+1;
    for (int i=1; i<a; i++)
        tmp = tmp->right;
    
    for (int i=1; i<b; i++)
        tmp1 = tmp1->right;
    
    for (int i=0; i<range/2; i++){
        ListNode *rtmp = tmp->right;
        ListNode *ltmp = tmp->left;
        ListNode *ltmp1 = tmp1->left;
        ListNode *rtmp1 = tmp1->right;
        if (ltmp)
            ltmp->right = tmp1;
        if (rtmp1)
            rtmp1->left = tmp;
        tmp1->left = ltmp;
        tmp->right = rtmp1;
        if (rtmp == tmp1){
            tmp->left = tmp1;
            tmp1->right = tmp;
        }
        else if (rtmp == ltmp1){
            rtmp->left = tmp1;
            rtmp->right = tmp;
            tmp1->right = rtmp;
            tmp->left = rtmp;
        }
        else{
            rtmp->left = tmp1;
            tmp1->right = rtmp;
            ltmp1->right = tmp;
            tmp->left = ltmp1;
        }
        if (ltmp == nullptr)
            head = tmp1;
        ListNode *p = tmp;
        tmp = tmp1;
        tmp1 = p;
        tmp1 = tmp1->left;
        tmp = tmp->right;
    }
    return head;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    
    return 0;
}