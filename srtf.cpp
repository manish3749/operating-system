/* THIS PROGRAM IMPLEMENTS SRTF SHEDULING */

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int atime[10],btime[10],temp[10];
	int i,smallest,cnt=0,time,n;
	double wait_time=0,turnaround_time=0 ,endd;
	float average_waiting_time,average_turnaround_time;
	printf("Enter the Total Number of Processes:");
	cin>>n;
	cout<<"Enter the arrival time and waiting time of the processes\n";
	for(i=0;i<n;i++)
 	{
		cin>>atime[i]>>btime[i];
		temp[i]=btime[i];
	}
  	btime[9]=INT_MAX;
 	for(time=0;cnt!=n;time++)
 	{
   		smallest=9;
  		for(i=0;i<n;i++)
  		{
   			if(atime[i]<=time && btime[i]<btime[smallest] && btime[i]>0)
   				smallest=i;
  		}
  		btime[smallest]--;
  		if(btime[smallest] == 0)
  		{
   			cnt++;
   			endd=time+1;
   			wait_time=wait_time+endd-atime[smallest]-temp[smallest];
   			turnaround_time=turnaround_time+endd-atime[smallest];
  		}
 	}
	average_waiting_time=(double)wait_time/n;
	average_turnaround_time=(double)turnaround_time/n;
 	printf("\n\nAverage Waiting Time: %f\n",(double)average_waiting_time);
    printf("Average Turnaround Time: %f\n",(double)average_turnaround_time);
}
