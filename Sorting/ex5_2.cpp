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
int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(all(rooms));
    sort(all(people));
    ll ans = 0;
    int i = 0, j = 0;
    while (i<(int)rooms.size() && j<(int)people.size()){
        if (abs(rooms[i] - people[j]) <= k){
            ++i; ++j;
            ++ans;
        }
        else if (rooms[i]-people[j] > k) ++j;
        else ++i;
    }
    return ans;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for(int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for(int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';
    
    return 0;
}