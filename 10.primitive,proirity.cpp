 #include <iostream>

using namespace std;
#define max 30

int main()
{
    int i,j,n,k=1,t,b=0,min,bt[max],wt[max],tat[max],at[max],pr[max],temp[max];
    float awt=0,atat=0;
    cout<<"enter the number of process:"<<endl;
    cin>>n;
    cout<<"enter the burst time,arrival time,priority"<<endl;
    for(i=0;i<n;i++){
        cin>>bt[i];
        cin>>at[i];
        cin>>pr[i];
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(at[i]<at[j]){
                t=at[j];
                at[j]=at[i];
                at[i]=t;
                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }
    for(j=0;j<n;j++){
        b=b+bt[j];
        min=bt[k];
        for(i=k;i<n;i++){
          min=pr[k];  
          
          if(b>=at[i]){
              
              if(pr[i]<min){
                  t=at[k];
                  at[k]=at[i];
                  at[i]=t;
                  
                  t=bt[k];
                  bt[k]=bt[i];
                  bt[i]=t;
                  
                  t=pr[k];
                  pr[k]=pr[i];
                  pr[i]=t;
              }
          }
        }
        k++;
    }
    temp[0]=0;
    cout<<"process"<<"\t"<<"burst time"<<"\t"<<"priority"<<"\t"<<"waiting time"<<"\t"<<"turnaround time"<<endl;
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<i+1<<"\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
        }
        awt=awt/n;
        atat=atat/n;
        cout<<"average waiting time is: "<<awt<<endl;
         cout<<"average turnaround time is: "<<atat<<endl;
    return 0;
}
