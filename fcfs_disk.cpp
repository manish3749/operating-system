/* THIS PROGRAM IMPLEMENTS THE FCFS DISK SHEDULING */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of memory cylinders \n";
    cin>>n;
    int a[n];
    cout<<"Enter the addresses of the memory cylinders\n";
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter the value of disk head\n";
    int strt,cnt=0;
    cin>>strt;
    for(int i=0;i<n;i++){
        cnt+=abs(a[i]-strt);
        strt=a[i];
    }
    printf("The total head movement is of %d cylinders\n",cnt);
}

