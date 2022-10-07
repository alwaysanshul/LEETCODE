#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int x=0,y=0;
        int prevX,prevY;
        while(x+y<=n)
        {
            prevX = x;
            prevY = y;
            if(a*pow(x+1,2)+b*pow(y,2) < a*pow(x,2)+b*pow(y+1,2))
            {   
                prevX = x;
                x++;
            }
            else{
                prevY = y;
                y++;
            }
        }
        cout<<prevX<<" "<<prevY<<endl;  
        cout<<a*pow(prevX,2)+b*pow(prevY,2)<<endl; 
    }
    return 0;
}