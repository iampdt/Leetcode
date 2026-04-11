class Solution {
public:
    long long power(long long base, long long exp)
    {
        long long res = 1;
        long long mod = 1e9+7;
        base %= mod;
        while(exp > 0)
            {
                if(exp % 2 == 1) res = (res * base) % mod;
                base = (base * base) % mod;
                exp/=2;
            }
        return res;
    }

    struct Block
    {
        int val,len;
    };
    int maxValue(vector<int>& nums1, vector<int>& nums0) {

        int n= nums1.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;

        auto cmp = [&](int i,int j)
        {
            int a1 = nums1[i], a0=nums0[i];
            int b1 = nums1[j], b0=nums0[j];

            int val1[4],len1[4];
            int sz1=0;
            if(a1>0) {val1[sz1] = 1; len1[sz1++] = a1;}
            if(a0>0) {val1[sz1]=0; len1[sz1++] =a0;}
            if(b1>0)
            {
                if(sz1 > 0 && val1[sz1-1] == 1) len1[sz1-1]+=b1;
                else {val1[sz1] =1; len1[sz1++] = b1;}
                
            }
            if(b0 > 0)
            {
                if(sz1 > 0 && val1[sz1-1]==0) len1[sz1-1]+=b0;
                else {val1[sz1]=0; len1[sz1++]=b0;}
            }

            int val2[4],len2[4];
            int sz2=0;
            if(b1>0){val2[sz2]=1; len2[sz2++] = b1;}
            if(b0>0){val2[sz2]=0; len2[sz2++]=b0;}
            if(a1>0)
            {
                if(sz2>0 && val2[sz2-1]==1) len2[sz2-1] += a1;
                else {val2[sz2]=1; len2[sz2++]=a1;}
            }
            if(a0>0)
            {
                if(sz2 > 0 && val2[sz2-1]==0) len2[sz2-1]+=a0;
                else {val2[sz2]=0; len2[sz2++]=a0;}
            }

            int p1=0,p2=0;
            int r1 = len1[0],r2=len2[0];

            while(p1<sz1 && p2<sz2)
                {
                    if(val1[p1] != val2[p2]) return val1[p1] > val2[p2];
                    if(r1 < r2)
                    {
                        r2-=r1;
                        p1++;
                        if(p1<sz1) r1=len1[p1];
                        
                    }
                    else if(r1>r2)
                    {
                        r1-=r2;
                        p2++;
                        if(p2<sz2) r2 = len2[p2];
                    }
                    else
                    {
                        p1++;
                        p2++;
                        if(p1<sz1) r1 = len1[p1];
                        if(p2<sz2) r2 = len2[p2];
                    }
                }
            return false;
        };

        sort(idx.begin(),idx.end(),cmp);
        long long mod = 1e9 + 7;
        long long ans = 0;

        for(int i=0;i<n;i++)
            {
                int id = idx[i];
                int a1 = nums1[id];
                int a0 = nums0[id];

                ans = (ans*power(2,a1+a0)) % mod;
                long long ones_val = (power(2,a1)-1 + mod)%mod;
                long long seg_val = (ones_val * power(2,a0))%mod;
            ans = (ans + seg_val)%mod;
            }
        return ans;

        
        
    }
};