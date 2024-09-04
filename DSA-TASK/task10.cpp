#include<iostream>
using namespace std;
int main(){
    int array[2][2];
     int x;
    bool found = false;
    cout<<"Enter the elements of 2*2 matrix :"<<endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<"Enter elements at position "<<"("<<i<<","<<j<<"):"<<endl;
            cin>>array[i][j];
    }
        
    }
    cout<<"enter the element of array"<<endl;
    for(int i=0; i<2; ++i){
        for(int j=i+1; j<2;++j)
        {
         int temp = array[i][j];
         array[i][j] = array[j][i];
         array[j][i] = temp;
    }
        
    }
    cout<<"after transpose the element of array"<<endl;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
        cout<<array[i][j]<<" ";
    }
     cout<<endl;
    }
        return 0;
    }   