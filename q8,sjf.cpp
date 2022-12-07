 #include <iostream>

using namespace std;
#define max 30

int main()
{
    int i,j,n,t,p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    cout<<"enter the number of process :"<<endl;
    cin>>n;
    cout<<"Enter the number of the process : "<<endl;
    for(i=0;i<n;i++)
      cin>>p[i];
    cout<<"enter the burst time of the process: "<<endl;
     for(i=0;i<n;i++)
        cin>>bt[i];
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
                
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
                
            }
        }
    }
    cout<<"process"<<"\t"<<"burst time"<<"\t"<<"turn around time"<<"\t"<<"waiting time"<<endl;
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<p[i]<<"\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<endl;
    }
  awt=awt/n;
  atat=atat/n;
  cout<<"average waiting time is: "<<awt<<endl;
  cout<<"average turn around time is: "<<atat<<endl;
    return 0;
}
