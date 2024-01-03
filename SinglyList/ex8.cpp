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

class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	void partition(int k);
};
void LinkedList::partition(int k) {
    if (this->head == nullptr || this->size == 1)
        return;
    LinkedList * newlist = new LinkedList();
    Node *p = this->head;
    while (p){
        if (newlist->head && p->value < k){
            newlist->tail->next = new Node(p->value, nullptr);
            newlist->tail = newlist->tail->next;
        }
        else if (newlist->head == nullptr && p->value < k){
            newlist->head = newlist->tail = new Node(p->value, nullptr);
        }
        p = p->next;
    }
    p = this->head;
    while (p){
        if (newlist->head && p->value == k){
            newlist->tail->next = new Node(p->value, nullptr);
            newlist->tail = newlist->tail->next;
        }
        else if (newlist->head == nullptr && p->value == k){
            newlist->head = newlist->tail = new Node(p->value, nullptr);
        }
        p = p->next;
    }
    p = this->head;
    while (p){
        if (newlist->head && p->value > k){
            newlist->tail->next = new Node(p->value, nullptr);
            newlist->tail = newlist->tail->next;
        }
        else if (newlist->head == nullptr && p->value > k){
            newlist->head = newlist->tail = new Node(p->value, nullptr);
        }
    
        p=p->next;
    }
    Node *old_head = this->head;
    this->head = newlist->head;
    this->tail = newlist->tail;
    p = old_head;
    while (p){
        Node * tmp = p;
        p = p->next;
        delete tmp;
    }
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);

    
    return 0;
}