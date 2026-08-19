class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int n = num1.length()-1;
        int m = num2.length()-1;
        
        string str = "";
        int idx = 0;
        int carry = 0;

        while(n>=0 && m>=0)
        {
            int sum = (num1[n] - '0') + (num2[m] - '0') + carry;
            carry = sum/10;
            char temp =  (sum%10 + '0');
            str+=temp;
            n--;
            m--;
        }
        while(n>=0) 
        {
            int sum = num1[n] - '0' + carry;
            carry = sum/10;
            str += (sum%10 + '0');
            n--;
        }
        while(m>=0) 
        {
            int sum = num2[m] - '0' + carry;
            carry = sum/10;
            char temp = (sum%10 + '0');
            str+=temp;
            m--;
        }
        if(carry > 0) str += carry + '0';
        reverse(str.begin(),str.end());
        return str;
    }
};