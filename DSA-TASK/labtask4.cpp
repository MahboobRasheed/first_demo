#include<iostream>
using namespace std;
int main(){
    int searchValue;
    cout<<"Enter search value:";
    cin>>searchValue;
    bool found=false;
    int numbers[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        if(numbers[i]==searchValue){
            found=true;
            cout<<"***search found on***"<<i<<" index"<<endl;
            break;
        }
    }
        if(!found){
        cout<<" search not found";
        }
            
    return 0;

}