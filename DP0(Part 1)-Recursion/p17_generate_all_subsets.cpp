
//hoi nai

#include <bits/stdc++.h>
using namespace std;

void func(vector<int>&v, vector<vector<int>>&res,vector<int>&t,int n,int i){
    
    //if(i==v.size())return;

    if(t.size()<=i){
        //cout<<"i = "<<i<<endl;
        res.push_back(t);
        return;
    }
    
    int c = v[i];
    t.push_back(c);
    func(v,res,t,n,i+1);

    t.pop_back();
    func(v,res,t,n,i+1);
}



vector<vector<int>> gas(vector<int>&v, int n){
    vector<vector<int>>res;
    vector<int>t;
    func(v,res,t,n,0);

    return res;
}


int main() {
	
	vector<int>v;
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
	    int x;
	    cin>>x;
	    
	    v.push_back(x);
	}
	
	vector<vector<int>>a = gas(v,n);
	
	for(int i=0;i<a.size();i++){
	    
	    for(int j=0;j<a[i].size();j++){
	        cout<<a[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
