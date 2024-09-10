#include<iostream>
using namespace std;
    int linearSearch(string inventory[],int size,string target){

    
    for ( int i=0;i<size; i++){
            if(inventory[i]==target){
                return i;
            }

        }
    
    return -1;
}
int main(){
    cout<<"\n\n******DSA Lab 4\n\n";
    string inventory[10];//={3,6,1,6,4,7};
    int size;
    cout<<"enter the size of inventory"<<endl;
    cin>>size;
    for(int i=0; i<size; i++){
        cout<<"\n Enter the  number of productat index: "<<i<<"t";
        cin>>inventory[i];

    }
    size=sizeof(inventory)/sizeof(inventory[0]);
    string target;
    cout<<"enter the product be target"<<"\t";
    cin>>target;
    int result=linearSearch(inventory,size,target);
    if(result!=-1){
        cout<<"product"<<target<<"found at index"<<result<<endl;
    }
    else{
        cout<<"product"<<target<<"not found in the array"<<endl;
    }
    return 0;
}