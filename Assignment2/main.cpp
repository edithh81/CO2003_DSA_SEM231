#include "main.h"
#include "restaurant.cpp"
int main(int argc, char* argv[]) {
    string fileName = "test.txt";
    freopen("output.txt", "w", stdout);
    // string fileName = "test/test";
    // string path = fileName + to_string(i) + ".txt";
    simulate(fileName);
    //printMemoryUsage();
    return 0;
}
