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
// class PrinterQueue
// {
//     // your attributes
//     int count;
//     pair<int,string> *elements;
//     int capacity;
// public:
//     // your methods
//     PrinterQueue(){
//         count = 0;
//         capacity = 10;
//         elements = new pair<int,string>[capacity];
//     }
//     void ensureCapacity(){
//         int new_capacity = capacity * 1.5;
//         pair<int, string> *temp = new pair<int, string>[new_capacity];
//         for (int i=0; i<count; i++) temp[i] = move(elements[i]);
        
//         delete []elements;
//         elements = new pair<int, string> [new_capacity];
//         for (int i=0; i<count; i++) elements[i] = move(temp[i]);
//         capacity = new_capacity;
//         delete []temp;
//     }
//     void reHeapDown(int idx){
//         while(idx < count){
//             int pos = 2*idx+1;
//             if (pos >= count)   return;
//             if (pos + 1 <count && elements[pos+1].first > elements[pos].first) ++pos;
//             if (elements[idx].first >= elements[pos].first) return;
//             pair<int, string> temp = move(elements[idx]);
//             elements[idx] = move(elements[pos]);
//             elements[pos] = move(temp);
//             idx = pos;
//         }
//     }
//     void reHeapUp(int idx){
//         while (idx){
//             int pos = (idx-1) >> 1;
//             if (elements[pos].first >= elements[idx].first) return;
//             pair<int,string> temp(move(elements[idx]));
//             elements[idx] = move(elements[pos]);
//             elements[pos] = move(temp);
//             idx = pos;
//         }
//     }
//     void addNewRequest(int priority, string fileName)
//     {
//         // your code here
//         if (count == capacity)  ensureCapacity();
//         elements[count] = make_pair(priority, fileName);
//         ++count;
//         reHeapUp(count-1);
//     }

//     void print()
//     {
//         // your code here
//         // After some logic code, you have to print fileName with endline 
//         if (count == 0){ cout << "No file to print" << endl; return;}
//         cout << elements[0].second << endl;
//         elements[0] = elements[count-1];
//         --count;
//         reHeapDown(0);
//     }
// };
class PrinterQueue
{
    // your attributes
    struct File{
        int priority;
        string fileName;
        int ord;
        // File(int pri, string f) : priority(pri), fileName(f){};
        bool operator<(const File &other) const{return priority != other.priority ? priority < other.priority : ord > other.ord;}
    };
    int order = 0;
    priority_queue<File> f;
public:
    // your methods
    
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        File nFile;
        nFile.priority = priority;
        nFile.fileName = fileName;
        nFile.ord = ++order;
        f.push(nFile);
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        if (f.empty()){cout << "No file to print\n";}
        else{
            cout << f.top().fileName << endl;
            f.pop();
        }
    }
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->addNewRequest(2, "goodbye.pdf");
myPrinterQueue->addNewRequest(2, "goodnight.pdf");
myPrinterQueue->addNewRequest(1, "hello2.pdf");
myPrinterQueue->addNewRequest(2, "goodmorning.pdf");
myPrinterQueue->addNewRequest(1, "hello1.pdf");

myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
    return 0;
}