#include<iostream>
using namespace std;
int main() {
	cout << "data structure and algorithm lab 03:c++ pointre" << endl;
	int alpha = 5;
	int beta = 20;
	int* alphaptr = &beta;
	int* betaptr = &alpha;
	cout << alpha << endl;
	cout << beta << endl;
	cout << &beta << endl;
	cout << &alpha << endl;
	cout << "hellow word" << endl;
    cout<<"address of beta"<<&beta<<endl;;
    cout<<"address of alpha"<<&alpha<<endl;
	return 0;
}