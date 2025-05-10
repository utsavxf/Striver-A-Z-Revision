class Solution {
public:
    
    int f(int i,int j,string s,vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return f(i+1,j-1,s,dp);
        else return dp[i][j]=1+min(f(i+1,j,s,dp),f(i,j-1,s,dp));
    }


    int minInsertions(string s) {
      int n=s.size();
    //   vector<vector<int>>dp(n,vector<int>(n,-1));
    //   return f(0,n-1,s,dp);
    // vector<vector<int>>dp(n,vector<int>(n,0));
    //SPACE OPTIMIZATION
    vector<int>prev(n,0),curr(n,0);
    
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
           if(s[i]==s[j])curr[j]=prev[j-1];
           else curr[j]=1+min(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[n-1];
    }
};
