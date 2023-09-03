#include<bits/stdc++.h>
using namespace std;

const int d=1001;
int t[d][d];
bool ispalindrome(string x, int i, int j){
    while(i<=j){
        if(x[i]!=x[j]){
            return false;
        }
            i++,j--;
    }
    return true;

}

int solve(string x, int i, int j){
    if(i>=j || ispalindrome(x,i,j)){
        t[i][j]=0;
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int ans=INT_MAX;
    for(int k=i; k<j; k++){
        int tempans=solve(x,i,k)+solve(x,k+1,j)+1;
        ans=min(ans,tempans);
    }
    return t[i][j]=ans;
}

int main(){
    string x= "recar";
    memset(t,-1,sizeof(t));
    cout<<solve(x,0,x.length()-1)<<endl;
    return 0;
}