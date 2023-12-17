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
#define castInt(X) dynamic_cast<IntNode *>(X)
#define castLeaf(X) dynamic_cast<LeafNode *>(X)
using pii = pair<int, int>;
string s;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
map<char, pii> m;
// class Customer{
// 	private:
// 		string name;
// 		HuffTree *HuffT;
// 		int result;
// 		int ID;
// 		int idx;
// 		bool isGojoCus;
// 		bool isSukunaCus;
// 	public:
// 		Customer(const string &name, const int &r, const int &i, HuffTree *t, bool flag):name(name), result(r), ID(i), idx(max_idx++), HuffT(t){(flag) ? isGojoCus = true : isSukunaCus = true;}
// 		~Customer(){
// 			delete HuffT;
// 		}
// 		int getRes(){return result;}
// 		int getID(){return ID;}
// 		void HandFunc(){
// 			HuffT->InOrder();
// 		}
// 		void deleteTree(){
// 			HuffT->clear();
// 		}
// 		bool isGCus(){return isGojoCus;}
// 		bool isSCus(){return isSukunaCus;}
// };
void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}
void CaesarEncrypt(char &x, int num){
	if (x >= 'a' && x <='z'){
		int e = (int)x + num;
		e = e > (int)'z'?e-26:e;
		x = (char)e;
	}
	else if (x >= 'A' && x <='Z'){
		int e = (int)x + num;
		e = e > (int)'Z'?e-26:e;
		x = (char)e;
	}
}
#define pci pair<char, int>
// map<char, pii> m;
class HuffNode {
public:
    virtual ~HuffNode() {};
    virtual int weight() = 0;
    virtual bool isLeaf() = 0;
	virtual void setWeight(const int &c) {};
};
// leaf node
class LeafNode: public HuffNode{
private:
    char key; // value
    int wgt; // weight
public:
    LeafNode(const char& val, int freq) { key = val; wgt = freq; };
    int weight() { return wgt; }
    char val() { return key; }
    bool isLeaf() { return true; }
};    
class IntNode :public HuffNode {
private:
    HuffNode* left;
    HuffNode* right;
    int wgt;
public:
    IntNode(HuffNode* l, HuffNode* r) { wgt = l->weight() + r->weight(); left = l; right = r; };
    int weight() { return wgt; }
	void setWeight(const int &w){wgt = w;}
    bool isLeaf() { return false; }
    HuffNode* leftChild() const{ return left; }
    HuffNode* rightChild() const{ return right; }
    void setLeft(HuffNode* b) { left = (HuffNode*) b; }
    void setRight(HuffNode* b) { right = (HuffNode*) b; }
    HuffNode *getL(){return this->left;}
    HuffNode *getR(){return this->right;}
};
class HuffTree {
private:
    HuffNode* root;
	int ord;
	HuffNode *rotateLeft(HuffNode *root){
		HuffNode *temp = castInt(root)->getR();
		int tempFre = temp->weight();
		temp->setWeight(root->weight());
		root->setWeight(root->weight() - tempFre);
		if (castInt(temp)->getL()) root->setWeight(root->weight() + castInt(temp)->getL()->weight());
		castInt(root)->setRight(castInt(temp)->getL());
		castInt(temp)->setLeft(root);
		root = temp;
		return root;	
	}
	HuffNode *rotateRight(HuffNode *root){
		HuffNode *temp = castInt(root)->getL();
		int tempFre = temp->weight();
		temp->setWeight(root->weight());
		root->setWeight(root->weight()-tempFre);
		if (castInt(temp)->getR()) root->setWeight(root->weight() + castInt(temp)->getR()->weight());
		castInt(root)->setLeft(castInt(temp)->getR());
		castInt(temp)->setRight(root);
		root = temp;
		return root;
	}
	int getBalance(HuffNode *root){
		if (root->isLeaf())	return 0;
		int leftBalance = getHeight(castInt(root)->getL());
		int rightBalance = getHeight(castInt(root)->getR());
		return leftBalance - rightBalance;
	}
	int getHeight(HuffNode *root){
		if (root->isLeaf())	return 0;
		int leftHeight = getHeight(castInt(root)->getL());
		int rightHeight = getHeight(castInt(root)->getR());
		return max(leftHeight, rightHeight) + 1;
	}
	void balanceTree(HuffNode *&root, int count){
		if (count == 3)	return;
		int bfTree = getBalance(root); // get balance factor to decide which case
		// cout << "bf of tree : " << bfTree << endl;
		if (bfTree == 0 || abs(bfTree) == 1) return; // tree has been already balanced yet
		if (bfTree > 1){ // left higher
			int bfTreeLeft = getBalance(castInt(root)->getL()); // get balance factor on left sub tree
			// cout << "bf of left subtree: " << bfTreeLeft << endl;
			if (bfTreeLeft == 0 || bfTreeLeft >= 1){ ++count; 	root = rotateRight(root);}
			else if (bfTreeLeft <= -1){
				castInt(root)->setLeft(rotateLeft(castInt(root)->getL()));
				root = rotateRight(root);
				count += 2;
			}
		}
		else if (bfTree < -1){ // right higher
			int bfTreeRight = getBalance(castInt(root)->getR()); // get balance factor on right sub tree
			// cout << "bf of right subtree: " << bfTreeRight << endl;
			if (bfTreeRight == 0 || bfTreeRight <= -1){ ++count;	root = rotateLeft(root);}
			else if (bfTreeRight >= 1){
				castInt(root)->setRight(rotateRight(castInt(root)->getR()));
				root = rotateLeft(root);
				count += 2;
			}
		}
		balanceTree(root, count);
	}
    void InOrder(HuffNode *root){
        if (root->isLeaf()){ cout << castLeaf(root)->val() << endl; return;}
        InOrder(castInt(root)->getL());
        cout << root->weight() << endl;
        InOrder(castInt(root)->getR());
    }
public:
    HuffTree(const char &val, int freq, int order) {
		ord = order;
        root = new LeafNode(val, freq);
    }
    ~HuffTree() {}
    HuffNode* Root() { return root; }
	int pos(){return ord;}
    int weight() { return root->weight(); }
    HuffTree(HuffTree* l, HuffTree* r, int order) {
		ord = order;
        root = new IntNode(l->Root(), r->Root());
    }
	void balanceTree(int count){
		// if (count == 3)	return;
		balanceTree(this->root, count);
	}
    void BFS(){
        queue<HuffNode*> q;
        q.push(this->root);
        while (!q.empty()){
            HuffNode *temp = q.front();
            q.pop();
            if (temp->isLeaf()){cout <<castLeaf(temp)->val()<<endl;}
            else{        
                cout << temp->weight() << endl;
                q.push(castInt(temp)->getL());
                q.push(castInt(temp)->getR());
            }
        }
    }
    void InOrder(){
        InOrder(this->root);
    }
	void printTreeStructure()
    {
        int height = getHeight(root);
		cout << "height: " << height << endl;
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<pair<int, HuffNode *>> q;
        q.push({1, root});
        HuffNode *temp;
        int count = 2;
        int maxNode = 1;
        int level = 1;
        int space = pow(2, height);
        // printNSpace(space / 2);
        while (!q.empty())
        {	
			auto it = q.front(); q.pop();
			if (level != it.first) {if (level > height) printNSpace(space/2); level = it.first; count *= 2; cout << endl;}
			if (it.second->isLeaf()){printNSpace(space/count);	cout << castLeaf(it.second)->val();}
			else{
				printNSpace(space/count);cout << castInt(it.second)->weight();
				q.push({it.first+1, castInt(it.second)->getL()});
				q.push({it.first+1, castInt(it.second)->getR()});
			}
    	}
	}
};
struct CompareHuffTree{
	bool operator()(HuffTree *a,HuffTree *b){return a->weight() != b->weight() ? a->weight() > b->weight() : a->pos() > b->pos();}
};
HuffTree* buildHuff(const vector<pci>& v) {
    priority_queue<HuffTree*, vector<HuffTree*>, CompareHuffTree> mHT;
	int count = 0;
    for (auto it : v){
        HuffTree *temp = new HuffTree(it.first, it.second, count++);
        mHT.push(temp);
    }
    while((int)mHT.size() > 1){
        HuffTree *left = mHT.top(); mHT.pop();
        HuffTree *right = mHT.top(); mHT.pop();
		// cout << "left \n";
		// left->BFS();
		// cout << "right\n";
		// right->BFS();
        HuffTree *temp = new HuffTree(left, right, count++);
		// int count = 0;
		temp->balanceTree(0);
        mHT.push(temp); 
    }
    return mHT.top();
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++){
        m[s[i]].first++;
        if (m[s[i]].first == 1) m[s[i]].second = i;
    }
    vector<pair<char, int>> v;
    for (auto it : m) v.push_back({it.first, it.second.first});
    for (auto &it : v){
        CaesarEncrypt(it.first, it.second);
    }
    // for (auto it : v)   cout << it.first << ' ' << it.second << endl;
    for (auto it: v){
		if (m[it.first].first == 0) m[it.first].first = it.second;
		else				m[it.first].first+=it.second;
    }
    v.clear();
    for (auto it : m) v.push_back({it.first, it.second.first});
    sort(all(v), [](const pair<char,int> &a, const pair<char,int> &b)->bool{return a.second != b.second ? a.second < b.second : ((a.first >='a' && a.first <='z' && b.first >='a' && b.second <='z') || (a.first >='A' && a.first <='Z' && b.first >='A' && b.first <='Z'))? a.first < b.first : (a.first >= 'a' && a.first <='a' && b.first >='A' && b.first <='Z')?true:a.first > b.first;});
    // cout << "after" << endl;
    for (auto it : v)   cout << it.first << ' ' << it.second << endl;
    HuffTree *ht = buildHuff(v);
    // cout << ht->weight() << endl;
    // ht->printTreeStructure();
	cout << endl;
	ht->InOrder();
    return 0;
}