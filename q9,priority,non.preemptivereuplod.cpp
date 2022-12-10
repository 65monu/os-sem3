 #include <iostream>

using namespace std;
#define max 30

int main()
{
    int i,j,n,t,bt[max],wt[max],pr[max],tat[max],pos;
    float awt=0,atat=0;
    cout<<"enter the the number of process:"<<endl;
    cin>>n;
    cout<<"enter the brust time of process: "<<endl;
    for(i=0;i<n;i++){
        cin>>bt[i];
    }
    cout<<"enter the priority of process: "<<endl;
    for(i=0;i<n;i++){
        cin>>pr[i];
    }
    for(i=0;i<n;i++){
       pos=i;
       for(j=i+1;j<n;j++){
           if(pr[j]<pr[pos]){
               pos=j;
           }
       }
       t=pr[i];
       pr[i]=pr[pos];
       pr[pos]=t;
       
       t=bt[i];
       bt[i]=bt[pos];
       bt[pos]=t;
    }
    
    wt[0]=0;
    cout<<"process"<<"\t"<<"\t"<<"priority"<<"burst time"<<"\t"<<"turnaround time"<<"\t"<<"waiting time"<<endl;
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<i+1<<"\t"<<pr[i]<<"\t\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
        }
        awt=awt/n;
        atat=atat/n;
        cout<<"average waiting time is: "<<awt<<endl;
         cout<<"average waiting time is: "<<atat<<endl;
        
    return 0;
}
