#include<iostream>
using namespace std;
int main() {
	int array[5], n, x;
	
	cout << "enter the size of an array:"<<endl;
	cin >> n;
	cout << "enter the element"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> array[i];}
	cout << "insert  the  element in gidninning:"<<endl;
	cin >> x;
	for (int i = n; i > 0; i--) {
		array[i] = array[i - 1];}
	array[0] = x;
	n++;
		cout << "array element are:"<<endl;;
	for (int i = 0; i < n; i++) {
		cout << array[i] << endl;}
	cout<<endl;
	return 0;

}