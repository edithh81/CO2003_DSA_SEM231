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
class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
         this->x = x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
         this->y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this->x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
         return sqrt(pow(abs(this->x-pointA.x), 2) + pow(abs(this->y-pointA.y), 2));
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle(): radius(0)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
         this->center.setX(0);
         this->center.setY(0);
         
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
         this->center = Point(center.getX(), center.getY());
         this->radius=radius;
    }

    Circle(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
         this->center = circle.getCenter();
         this->radius = circle.getRadius();
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
         this->center.setX(point.getX());
         this->center.setY(point.getY());
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
         this->radius = radius;
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
         return this->center;
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
         return this->radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    Circle A;
    A.printCircle();    
    

    return 0;
}