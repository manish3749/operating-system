/* THIS PROGRAM IMPLEMENTS THE FIRST FIT ALGORITHM */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"enter the no. of memory blocks and no. of processes respectively\n";
    cin>>n>>m;
    cout<<"enter the sizes of memory blocks\n";
    int mb[n],pb[m];
    for(int i=0;i<n;i++) cin>>mb[i];
    cout<<"enter the sizes of process blocks\n";
    for(int i=0;i<m;i++) cin>>pb[i];
    vector<int>v(m,-1);
    for(int i=0;i<m;i++){
        int mn=INT_MAX,var=-1;
        for(int j=0;j<n;j++){
            if(mb[j]>=pb[i]){
                mn=mb[j];
                var=j;
                break;
            }
        }
        if(var>=0 && (mb[var]-pb[i])>=0){
            mb[var]-=pb[i];
            v[i]=(var+1);
        }
    }
    cout<<"process\tmemory blocks\n";
    for(int i=0;i<m;i++){
        if(v[i]==-1)
            cout<<i+1<<"\t"<<"Not Allocated"<<endl;
        else
            cout<<i+1<<"\t"<<v[i]<<endl;
    }

}
