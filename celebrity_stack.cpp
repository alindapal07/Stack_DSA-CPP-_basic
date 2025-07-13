#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int findcelebrity(vector<vector<int>> &mat,int n)
{
    stack<int>s;

    for (int  i = 0; i < n; i++)
    {
       s.push(i);
    }
    while (s.size()>1)
    {
       int A=s.top();s.pop();
       int B=s.top();s.pop();

       if (mat[A][B]==1)
       {
        s.push(B);
       }
       else s.push(A);
    }

    int candidate=s.top();s.pop();

    for (int  i = 0; i < n; i++)
    {
    if (i!=candidate)
    {
        if (mat[candidate][i]==1)
        {
           return -1;
        }
        if (mat[i][candidate]==0)
        {
           return -1;
        }
    }
    }
    return candidate;
}

int main(){
    vector<vector<int>> mat=
    {
         {1,1,0},
         {0,1,0},
         {1,1,1}
    };
    int n=mat.size();

    int celebrity=findcelebrity(mat,n);
    if (celebrity==-1){
        cout<<"Celebrity not found:"<<endl;
    }
    else{
        cout<<"Celebrity found: "<< celebrity;
    }
    return 0;
}