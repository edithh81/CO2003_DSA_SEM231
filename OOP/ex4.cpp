#include <bits/stdc++.h>
using namespace std;
#define EDITH81
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
class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this -> publishingYear = 0;
        this -> title = nullptr;
        this -> authors = nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this -> title = new char[strlen(title)+1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors)+1];
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this -> title = new char[strlen(book.getTitle())+1];
        strcpy(this->title, book.getTitle());
        this->authors = new char[strlen(book.getAuthors())+1];
        strcpy(this->authors, book.getAuthors());
        this->publishingYear = book.getPublishingYear();
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        this->authors = new char[strlen(authors)+1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete []this->title;
        delete []this->authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    book1.printBook();
    cout << endl;
    Book book2 = book1;
    book2.printBook();

    return 0;
}