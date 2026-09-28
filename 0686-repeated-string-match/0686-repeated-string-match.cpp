class Solution {
public:
    void computeLPS(string &b, vector<int> &LPS)
    {
        LPS[0] = 0;
        int len = 0;
        int i = 1;
        
           while(i < b.length())
           {
             if(b[i] == b[len]) // matched, increase max. LPS
             {
                len++;
                LPS[i] = len;
                i++;
             }
             else // not matched
             {
                if(len != 0)
                {
                    len = len - 1;
                }
                else 
                {
                    LPS[i] = 0;
                    i++;
                }

             }
           }
    }
    int repeatedStringMatch(string a, string b) {
        int count = 0; 
        string temp = a;
        while(a.length() < b.length()) { count++; a += temp;}
        // construction of LPS
        vector<int> LPS(b.length(),0);
        computeLPS(b,LPS);

        // checkig for the Pattern
        int i = 0;
        int j = 0;
        while(i < a.length())
        {
            if(a[i] == b[j]) 
            {
                // cout<<i<<": "<<j<<endl;
                j++;
                i++;
               
            }
            if(j == b.length()) {return count+1;}
            else if(i < a.length() && a[i] != b[j])
            {
               if(j!=0) j = LPS[j-1];
               else i++;
            }
        }
        a+=temp;
        count++;
        while(i < a.length())
        {
            if(a[i] == b[j]) 
            {
                i++;
                j++;
            }
            if(j == b.length()) return count+1;
            else if(i < a.length() && a[i] != b[j])
            {
               if(j!=0) j = LPS[j-1];
               else i++;
            }
        }
       return -1;
    }
};