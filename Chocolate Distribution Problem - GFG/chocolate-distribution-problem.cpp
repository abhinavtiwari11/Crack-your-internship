//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
        long long int ans=0;
        long long int minus=0;
        long long int k=m;
          ans=(a[k-1]-a[0]);
          k++;
        for(int i=1;i<a.size();i++){
             if(k>n){
                 break;
             }
              minus=(a[k-1]-a[i]);
            ans=min(minus,ans);
            k++;
        }
      return ans;
    }  
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends