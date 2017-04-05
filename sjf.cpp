/* THIS PROGRAM IMPLEMENTS THE SHORTEST JOB FIRST SCHEDULING */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter the number of the jobs\n";
    int n,x,wtime=0,ttime=0;
    cin>>n;
    vector< pair<int,int> >v,wt,tt;
    cout<<"enter the burst time of the jobs respectively\n";
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(make_pair(x,i+1));
    }
    sort(v.begin(),v.end());
    wt.push_back(make_pair(0,v[0].second));
    tt.push_back(make_pair(v[0].first,v[0].second));
    ttime=v[0].first;
    for(int i=1;i<n;i++){
        wt.push_back(make_pair(wt[i-1].first+v[i-1].first,v[i].second));
        tt.push_back(make_pair(v[i].first+wt[i].first,v[i].second));
        wtime+=wt[i].first;
        ttime+=tt[i].first;
    }
    cout<<"jobs\tburst time\twaiting time\tturn around time\n";
    for(int i=0;i<n;i++)
        cout<<v[i].second<<"\t\t"<<v[i].first<<"\t\t"<<wt[i].first<<"\t\t"<<tt[i].first<<endl;
    cout<<"average waiting time = "<<(double)wtime/n<<endl;
    cout<<"average turn around time = "<<(double)ttime/n<<endl;
}
