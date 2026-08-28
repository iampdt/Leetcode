class Solution {
public:
    int maximumGap(string sk, string st) {
        int n=sk.length(),m=st.length(),p=0;
        if(n==1) return 0;
        vector<int> x(n,0),y(n,0);
        for(int i=0;i<n;i++){
            while(st[p]!=sk[i]) p++;
            x[i]=p;
            p++;
        }
        p=m-1;
        for(int i=n-1;i>=0;i--){
            while(st[p]!=sk[i]) p--;
            y[i]=p;
            p--;
        }
        int ans=0;
        for(int i=1;i<n;i++) ans=max(ans,y[i]-x[i-1]);
        return ans;
    }
};