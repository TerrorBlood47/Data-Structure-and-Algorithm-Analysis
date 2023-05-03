//g4g

#include<bits/stdc++.h>
using namespace std;

class JOB{
public:
    string name;
    int deadline;
    int profit;

    JOB(string name, int deadline, int profit){
        this->name = name;
        this->deadline = deadline;
        this->profit = profit;
    }

};

JOB** bubble_sort(JOB** job, int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(job[j]->profit < job[j+1]->profit){
                swap(job[j], job[j+1]);
            }

        }
    }

    return job;
}

void JobScheduling(JOB**& job, int n){
    
    

    string res[n];
    bool slot[n];
    int total_profit = 0;

    for(int i=0; i<n ;i++) slot[i] = true;

    for(int i=0; i<n; i++){

        for(int j=min(n,job[i]->deadline)-1; j>=0 ; j--){

            if(slot[j]==true){
                res[j] = job[i]->name;
                total_profit += job[i]->profit;
                slot[j] = false;
                break;
            }
        }
    }

    cout<<"total profit = "<<total_profit<<endl;

    for(int i=0; i<n; i++){

        if(slot[i]==false){
            cout<<res[i]<<" ";
        }
    }

}

int main(){

int n;
cin>>n;

JOB** job = new JOB*[n];


for(int i=0; i<n; i++){
    string n;
    int d,p;

    cin>>n>>d>>p;

    job[i] = new JOB(n,d,p);

    
}

job = bubble_sort(job,n);

JobScheduling(job,n);

cout<<endl;

for(int i=0; i<n ;i++){
    cout<<job[i]->name<<" "<<job[i]->profit<<endl;
}

return 0;
}