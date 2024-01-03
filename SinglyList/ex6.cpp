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

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    if (l0 == nullptr)
        return l1;
    if (l1 == nullptr)
        return l0;
    LLNode *newList = new LLNode();
    LLNode *tmp = newList;
    LLNode *p1 = l0, *p2 = l1;
    int sum = 0, modulo = 0;
    while (p1 && p2){
        sum = (p1->val + p2->val + modulo) %10;
        modulo = (p1->val + p2->val + modulo) / 10;
        LLNode *newNode = new LLNode(sum, nullptr);
        tmp->next = newNode;
        tmp = tmp->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1){
        sum = (p1->val+ modulo) %10;
        modulo = (p1->val+ modulo) / 10;
        LLNode *newNode = new LLNode(sum, nullptr);
        tmp->next = newNode;
        tmp = tmp->next;
        p1 = p1->next;
    }
    while (p2){
        sum = (p2->val + modulo) %10;
        modulo = (p2->val + modulo) / 10;
        LLNode *newNode = new LLNode(sum, nullptr);
        tmp->next = newNode;
        tmp = tmp->next;
        p2 = p2->next;
    }
    if (modulo)
        tmp->next = new LLNode(modulo, nullptr);
    
    return newList->next;
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);

    
    return 0;
}