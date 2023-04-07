/*
Problem Link  : Aditya Verma - Allocate Minimum Number Of Pages( https://youtu.be/2JSQIhPcHQg )
About Problem : A very tricky & important question
Tags          : 
Notes         : -> not a conventional binary search

        
 */


#include<bits/stdc++.h>
using namespace std;



bool is_valid(int p[], int n, int m, long long int max){
    /*max = maximum possible number of pages apportioned to a student so that the condition remains satisfied 
      st = minimum number of student needed to allocate pages which does not cross max
    
    */

    int st=1;
    long long int x=0;

    for(int i=0;i<n;i++){
        
        if(x+p[i]>max){
            //cout<<x<<" "<<st<<endl;
            st++;
            x = p[i];

            if(st>m){
                return false;
            }
        }
        else{
            x += p[i];
        }

    }

    if(st==m){
        return true;
    }
    else{
        return false;
    }
}



int ameliorated_binary_search(int p[], long long int sum, int n, int m){

    long long int low,high,res,mid;

    low=0; //to make it more efficient, max number of pages can be assigned to low as it is the lowest possible potential outcome
    high=sum;
    res= -1;

    while(low<=high){

        mid = low + (high-low)/2;

        //cout<<res<<endl;

        if(is_valid(p,n,m,mid)==true){
            high=mid-1;
            res = mid;
        }
        else{
            low = mid + 1;
        }

    }

    return res;
}




void view_output( int n,int a[]){
    int i,j;

    for(i=0;i<n;i++){
        
        cout<<a[i]<<" ";
        
    }
    
    cout<<endl;

    return;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,j,min,m;
    
    scanf("%d",&n);
    /*
    n = number of books
    m = number of students
    pages[] = an array denoting the number of pages in each book
    min = minimum of the max number of pages assigned to a student

    PS: -> Pages from a single book cannot be split among students, the whole book needs to be apportioned
        -> No books can remain unallocated
        -> Books are needed to be distributed in a continuous manner
    */

    int pages[n];

    long long int sum=0;

    //int sum_pages[n+1];

    //sum_pages[0]=0;
    

    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);

        sum += pages[i];

        //sum_pages[i+1]=sum;
    }

    scanf("%d",&m);


    // view_output(n,pages);

    if(m<=n){
        min = ameliorated_binary_search(pages,sum,n,m);
        cout<<min<<endl;
    }
    else{
        cout<<"no valid answer\n"; /* If the number of students is greater than the number of books (i.e, m > n),
         In this case at least 1 student will be left to which no book has been assigned. */
    }
    
    return 0;
}