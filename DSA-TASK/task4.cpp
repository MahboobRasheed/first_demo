#include<iostream>
using namespace std;
int main()
{
    int arr[3][3];
    int x;
    bool found = false;
    cout<<"Enter the elements of 4*4 matrix :"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            cout<<"Enter elements at position "<<"("<<i<<","<<j<<"):"<<endl;
            cin>>arr[i][j];
        }
    }
    cout<<"Enter value to search:";
    cin>>x;
    for(int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        
            
    if(found)
    {
        break;
    }
    }
    if(!found)
    {
       cout<<"Value not found at any position"<<endl;
    }
    return 0;
}
            
