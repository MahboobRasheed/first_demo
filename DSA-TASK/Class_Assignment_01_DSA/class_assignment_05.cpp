#include<iostream>
using namespace std;
int sttak[10],n=10,top=-1;
void push(int x);{
    if (top==size-1){
        cout<<"sttak is full";
    }
    else{
        top++
        sttak [top]=x;

    }
    vod display(){
        if(top>=0){
cout<<"the sttak element are"endl;
      for(int i=top;i>=0;i--)
      cout<<sttak[i]<<endl;
        }
        else{
            cout<<"sttak is empty";
        }
    }
}
int main(){
    push(8);
    push(7);
    push(4);
    push(6);
    push(3);
    push(2);
    push(6);
    push(3);
    push(4);
    push(1);
    display();
}
