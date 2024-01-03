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

class LLNode{
public:
    int val;
    LLNode* next;
    LLNode(){}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next): val(val), next(next){
    }; // Constructor with customized data
};
LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr)
        return head;
    LLNode *cur = head;
    LLNode *pR=nullptr;
    while(cur != nullptr){
        LLNode *next = cur->next;
        cur->next = pR;
        pR = cur;
        cur = next;
    }
    return pR;
}
LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (head==nullptr || k==0)
        return head;
    int len = 1;
    LLNode *cur = head;
    while (cur->next){
        ++len;
        cur = cur->next;
    }
    if (k%len == 0)
        return head;
    k = len - (k%len);
    cur->next = head;
    while(k>0){
        cur = cur->next;
        k--;
    }
    head = cur->next;
    cur->next = nullptr;
    return head;
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);

    
    return 0;
}