#include<iostream>
using namespace std;
int main(){
    int array1[5]={4,3,5,6,7};
    int* ipoint=&array1[0];
    for(int i=0; i<100; i++){
        *ipoint=i;
        cout<<ipoint<<endl;
        ipoint=ipoint+1;
    }
    for(int i=0;i<5; i++){
        cout<<array1[i];
        
    }
    return 0;
}