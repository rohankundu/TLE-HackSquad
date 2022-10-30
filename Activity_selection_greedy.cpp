#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int,int>arr[n];
        for(int i=0;i<n;i++){
            arr[i]={start[i],end[i]};
        }
        sort(arr,arr+n,comp);
        
        int c=1;
        pair<int,int>curr=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i].first<=curr.second){
                continue;
            }else{
                c+=1;
                curr=arr[i];
            }
        }
        return c;
        
        
        
        
        // Your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
