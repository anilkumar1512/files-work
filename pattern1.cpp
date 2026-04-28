#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j = 1;j <= i-1;j++)
        {
            cout<<" ";
        }
        for(int k = 1;k <= n;k++)
        {
            if(i ==1 || i == n || k == 1 || k == n-i+1 || i == k|| k == n)
            {
                cout<<"*";
            }
            else
            {
            cout<<" ";
            }
        }

        cout<<"\n";
    }
}