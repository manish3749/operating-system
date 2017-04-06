/* THIS PROGRAM IMPLEMENTS THE SSTF DISK SHDULING */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cout<<"Enter the number of memory cylinders \n";
    cin>>n;
    vector<int>v(n+1),vis(n+1,0);
    cout<<"Enter the addresses of the memory cylinders\n";
    for(int i=1;i<=n;i++) cin>>v[i];
    cout<<"Enter the value of disk head\n";
    int cnt=0,k=0;
    cin>>v[0];
    for(int i=0;i<=n;i++){
        vis[k]=1;
        int mn=INT_MAX,var,j=0;
        for(;j<=n;j++){
            if(vis[j]==0 && abs(v[j]-v[k])<mn){
                mn=abs(v[j]-v[k]);
                var=j;
            }
        }
        k=var;
        if(mn!=INT_MAX){
            vis[k]=1;
            cnt+=mn;
        }
    }
    printf("The total head movement is of %d cylinders\n",cnt);
}
