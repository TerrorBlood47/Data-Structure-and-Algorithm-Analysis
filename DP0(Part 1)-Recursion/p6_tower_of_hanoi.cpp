/*
Problem Link  : Aditya Verma - Tower of Hanoi( https://youtu.be/l45md3RYX7c )
About Problem : Recursion implementation
Tags          : 
Notes         : ->needs to be seen again

 */



#include <bits/stdc++.h>
using namespace std;
/*
long long int count_moves(int n){

    if(n==1){
        return 1;
    }

    return 2*count_moves(n-1) + 1;
}
*/
long long int count_moves_2(int source, int helper, int destination, int n, int count){

    if(n==1){
        printf("move disk %d from rod %d to rod %d\n",n,source,destination);
        return count;
    }
    count = count+n-1;
    count_moves_2(source,destination,helper,n-1,count);
    printf("move disk %d from rod %d to rod %d\n",n,source,destination);
    count = count + 1;
    //count_moves_2(source,helper,destination,n-1,count);
    count = count+n-1;
    count_moves_2(helper,source,destination,n-1,count);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin>>n;
    long long int num_of_moves_needed;

    //num_of_moves_needed = count_moves(n);

    num_of_moves_needed = count_moves_2(1,2,3,n,0);

    cout<<num_of_moves_needed<<endl;

    return 0;
}