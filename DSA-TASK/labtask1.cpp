#include<iostream>
using namespace std;
int main(){
    int array[10],size,temp;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    cout<<"the element of array is"<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(array[i]<array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    cout<<"the sorted element are"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<endl;
    }
    
return 0;
}