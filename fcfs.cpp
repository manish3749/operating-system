/* THIS PROGRAM IMPLEMENTS THE FCFS */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter the number of the jobs\n";
    int n;
    cin>>n;
    int bt[n],wt[n],tt[n];
    cout<<"enter the burst time of the jobs respectively\n";
    for(int i=0;i<n;i++){
        cin>>bt[i];
        wt[i]=0;tt[i]=0;
    }
    int wtime=0,ttime=bt[0];
    wt[0]=0;
    tt[0]=wt[0]+bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tt[i]=wt[i]+bt[i];
        wtime+=wt[i];
        ttime+=tt[i];
    }
    cout<<"jobs\tburst time\twaiting time\tturn around time\n";
    for(int i=0;i<n;i++)
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
    cout<<"average waiting time = "<<(double)wtime/n<<endl;
    cout<<"average turn around time = "<<(double)ttime/n<<endl;
}
