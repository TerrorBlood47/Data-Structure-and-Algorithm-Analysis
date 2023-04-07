
#include <bits/stdc++.h>
using namespace std;

void generate_combination(vector<int>&v, vector<vector<int>>&res,vector<int>t,int n,int i,int x,int target){
    if(i==v.size()){
        x = 0;
        t.clear();
        return;
    }

    if(x > target){
        x = 0;
        t.clear();
        return;
    }

    if(x==target){
        x =0;
        res.push_back(t);
        t.clear();
        return;
    }
    x += v[i];
    t.push_back(v[i]);
    generate_combination(v,res,t,n,i,x,target);

    x -= v[i];
    i++;
    x += v[i];
    t.push_back(v[i]);
    generate_combination(v,res,t,n,i,x,target);
}



vector<vector<int>> combination_sum(vector<int>&v, int n,int target){
    vector<vector<int>>res;
    vector<int>t;
    generate_combination(v,res,t,n,0,0,target);

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

    int target;

    cin>>target;
	
	vector<vector<int>>a = combination_sum(v,n,target);
	
	for(int i=0;i<a.size();i++){
	    
	    for(int j=0;j<a[i].size();j++){
	        cout<<a[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}

    
	
	return 0;
}
