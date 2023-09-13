//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string ans;
        while (S > 0 and N > 0){
            if (S >= 9){
                ans.push_back('9');
                S -= 9;
            }
            else{
                ans.push_back(S + '0');
                S = 0;
            }
            N--;
        }

        if (S != 0 and N == 0)
            return "-1";

        while (N > 0){
            ans.push_back('0');
            N--;
        }

        if (ans.size() > 1 and ans[0] == '0')
            return "-1";

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
