/*
Problem Link  : Aditya Verma - 21 Search in Row wise And Column wise Sorted Array( https://youtu.be/VS0BcOiKaGI )
About Problem : Binary Search Implementation
Tags          : 
Notes         : -> not a conventional binary search
        
 */


#include<bits/stdc++.h>
using namespace std;
int a[100][100];

int binary_search_in_2D_matrix(int r, int c,int a[100][100], int key, int* x, int* y){
    int i,j;
    i=0;     //traverses the rows
    j=c-1;   //traverses the columns

    while(i<=r-1 && j>=0){

        if(a[i][j]==key){
            //cout<<"quit"<<endl;
            *x = i;
            *y = j;
            return true;
        }
        else if(a[i][j]<key){
            //cout<<a[i][j]<<endl;
            i++;
            
        }
        else if(a[i][j]>key){
            //cout<<a[i][j]<<endl;
            j--;
        }
    }
    //cout<<a[i][j]<<endl;
    return false;
}



void view_output( int r, int c,int a[100][100]){
    int i,j;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,j,r,c,key,x,y;
    bool element_exists;

    scanf("%d%d",&r,&c); 

    //vector<int>v;
    //int a[r][c];

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);// cin is not taking inputs - for some unknown reasons
        }
    }

    scanf("%d",&key); //cin>>key; //cin problem kortese


    
    element_exists = binary_search_in_2D_matrix(r,c,a,key,&x,&y);

    if(element_exists)cout<<x<<" "<<y<<endl;
    else cout<<"not found\n";


    //view_output(r,c,a);
    return 0;
}