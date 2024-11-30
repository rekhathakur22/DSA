#include<bits/stdc++.h>
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        int length = 0;
        map<int,int>mpp;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
              sum = sum + arr[i];
              
              if(sum==0)
              {
                  length = max(length,i+1);
              }
              
              else{
              if(mpp.find(sum) != mpp.end())
              {
                  length = max(length, i-mpp[sum]);
                  
              }
              else
              {
                  mpp[sum]=i;
              }
              }
        }
        
        
        return length;
    }
};