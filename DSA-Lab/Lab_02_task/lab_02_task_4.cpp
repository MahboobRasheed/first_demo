#include<iostream>
using namespace std;
int main()
{
    int orders[15] , n;   
    cout<<"Enter the number of orders :"<<endl;
    cin>>n;
    int ID_number;
    cout<<"Enter the ID number of order :"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>orders[i];
    }
    cout<<"Enter the ID number of order to search :";
    cin>>ID_number;
    int position = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(orders[i] == ID_number)
        {
            position = i;
            break;
        }
    }
    if(position != 0)
    {
        cout<<"Order ID found at position "<< position <<"."<<endl;
    }
    else
        cout<<"Order ID not found."<<endl;
    return 0;
}                                                           