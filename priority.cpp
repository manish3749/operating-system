/* THIS PROGRAM IMPLEMENTS THE PRIORITY SCHEDULING(SMALLEST HAS HIGHEST PRIORITY) */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter the number of the jobs\n";
    int n,x,y,wtime=0,ttime=0;
    cin>>n;
    vector< pair< int,pair<int,int> > >v;
    cout<<"enter the priority and burst time of the jobs respectively\n";
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,make_pair(i+1,y)));
    }
    vector< pair< pair<int,int>,int > >t(n);
    sort(v.begin(),v.end());
    t[0].first.first=0,t[0].first.second=v[0].second.second,t[0].second=v[0].second.first;
    ttime=t[0].first.second;
    for(int i=1;i<n;i++){
        t[i].first.first=t[i-1].first.first+v[i-1].second.second;
        t[i].first.second=t[i].first.first+v[i].second.second;
        t[i].second=v[i].second.first;
        wtime+= t[i].first.first;
        ttime+=t[i].first.second;
    }
    cout<<"jobs\tpriority\tburst time\twaiting time\tturn around time\n";
    for(int i=0;i<n;i++)
        cout<<t[i].second<<"\t\t"<<v[i].first<<"\t\t"<<v[i].second.second<<"\t\t"<<t[i].first.first<<"\t\t"<<t[i].first.second<<endl;
    cout<<"average waiting time = "<<(double)wtime/n<<endl;
    cout<<"average turn around time = "<<(double)ttime/n<<endl;
}
