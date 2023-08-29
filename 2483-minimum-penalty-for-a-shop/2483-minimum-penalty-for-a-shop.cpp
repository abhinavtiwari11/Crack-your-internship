class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int prefix[n+1];

        int cnt=0;
        for(auto i:customers){
            if(i=='N') cnt++;
        }

        prefix[n]=cnt;
        int ans=n;
        int cnt_yes=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                cnt_yes++;
                prefix[i]=cnt+cnt_yes;
            }else{
                cnt--;
                prefix[i]=cnt+cnt_yes;
            }

            if(prefix[i]<=prefix[ans]) ans=i;
        }
        return ans;
    }
};
