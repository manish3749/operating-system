/* THIS PROGRAM IMPLEMENTS THE ROBIN ROUND SCHEDULING */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter the number of the jobs and the quantum\n";
    int n,q,t=0;
    cin>>n>>q;
    int bt[n],ttime[n+1],wtime[n+1];
    for(int i=0;i<=n;i++) ttime[i]=0,wtime[i]=0;
    cout<<"enter the burst time of the jobs\n";
    for(int i=0;i<n;i++)
        cin>>bt[i];
    while(true){
        bool flag=false;
        for(int i=0;i<n;i++){
            if(bt[i]!=0){
                flag=true;
                cout<<t<<" "<<i+1<<endl;
                wtime[i+1]+=t;
                t+=min(bt[i],q);
                bt[i]=max(0,bt[i]-q);
            }
        }
        if(!flag) break;
    }
    int wt=0,tt=0;
    for(int i=1;i<=n;i++){
        ttime[i]=wtime[i]+bt[i-1];
        wt+=wtime[i];
        tt+=ttime[i];
    }
    for(int i=0;i<=n;i++) cout<<wtime[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++) cout<<ttime[i]<<" ";
    cout<<endl;
    cout<<"average waiting time = "<<(double)wt/n<<endl;
    cout<<"average turn around time = "<<(double)tt/n<<endl;
}
