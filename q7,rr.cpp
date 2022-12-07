 #include <iostream>

using namespace std;

int main()
{
   int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
   float awt=0,atat=0;
   cout<<"enter the number of processes: "<<endl;
   cin>>n;
   cout<<"enter the burst time of the process : "<<endl;
   for(i=0;i<n;i++){
       cin>>bt[i];
       rem_bt[i]=bt[i];
   }
   cout<<"enter the quantum time:"<<endl;
   cin>>qt;
   while(1){
       for(i=0,count=0;i<n;i++){
           temp=qt;
           if(rem_bt[i]==0){
               count++;
               continue;
           }
           if(rem_bt[i]> qt){
               rem_bt[i]=rem_bt[i]-qt;
           }
           else{
               if(rem_bt[i]>=0){
                   temp=rem_bt[i];
                   rem_bt[i]=0;
               }
           }
           sq=sq+temp;
           tat[i]=sq;
       }
       if(n==count){
           break;
       }
   }
   cout<<"process"<<"\t"<<"burst time"<<"\t"<<"turnaround time"<<"\t"<<"waiting time"<<endl;
   for(i=0;i<n;i++){
       wt[i]=tat[i]-bt[i];
       awt=awt+wt[i];
       atat=atat+tat[i];
       cout<<i+1<<"\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
       }
       awt=awt/n;
       atat=atat/n;
    cout<<"average waiting time: "<<awt<<endl;
     cout<<"average turn around time: "<<atat<<endl;
    return 0;
}
