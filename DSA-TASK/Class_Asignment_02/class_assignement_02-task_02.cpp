#include <iostream>
#include <cmath>

using namespace std;

class Progression {
public:
    virtual double firstValue() = 0;
    virtual double nextValue() = 0;
};

class DiffProgression : public Progression {
private:
    double prev;
    double cur;

public:
    DiffProgression() : prev(2), cur(200) {}
    DiffProgression(double first, double second) : prev(first), cur(second) {}

    double firstValue() override {
        double temp = prev;  
        prev = cur;         
        cur = temp;
        return temp;       
    }

    double nextValue() override {
        double next = fabs(cur - prev); 
        prev = cur;                     
        cur = next;                     
        return cur;                  
    }
};

int main() {
    int n = 10;  
    DiffProgression prog;
    cout << prog.firstValue() << " "<<endl;
    for (int i = 1; i < n; ++i) {
        cout << prog.nextValue() << " "<<endl;
    }

    cout << endl;
    return 0;
}
