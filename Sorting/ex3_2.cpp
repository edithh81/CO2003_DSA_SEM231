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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (a == nullptr)   return b;
    if (b == nullptr)   return a;
    ListNode *ans = new ListNode();
    ListNode *res = ans;
    while (a && b){
        if (a->val <= b->val){
            res->next = a;
            a = a->next;
        }
        else{
            res->next = b; 
            b = b->next;
        }
        res = res->next;
    }
    if (a) res->next = a;
    if (b) res->next = b;
    return ans->next;
}
// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head){
    if (head == nullptr || head->next == nullptr)    return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    ListNode *left = mergeSortList(head);
    ListNode *right = mergeSortList(mid);
    return mergeLists(left, right);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    	
    
    return 0;
}