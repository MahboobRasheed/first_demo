#include <iostream>
#include <cmath>

using namespace std;

class Progression {
public:
    double firstValue() {
        return 0;
    }
    double nextValue() {
        return 0;
    }
};

class SqrtProg : public Progression {
private:
    double cur;
public:
    SqrtProg(double c = 65536)  { 
        cur=c; 
    }

    // Overriding the firstValue and nextValue functions
    double firstValue() {
        return cur;
    }

    double nextValue() {
        cur = sqrt(cur);  // Update cur with its square root
        return cur;
    }
};

int main() {
    int n = 10;
    cout << "The square root of values is:" << endl;

    SqrtProg prog(65536);  // Create instance directly

    // Print the first value
    cout << prog.firstValue() << " " << endl;
    for (int i = 1; i < n; ++i) {
        cout << prog.nextValue() << " " << endl;
    }

    return 0;
}
