class Solution {
public:
    double cosine(int a, int b,int c)
    {
        double CosA = (b*b + c*c - a*a)/(2.0*b*c);
        double angleA = acos(CosA)*180/M_PI;
        return angleA;
    }
    vector<double> internalAngles(vector<int>& sides) {
      
      int a = sides[0];
      int b = sides[1];
      int c = sides[2];

      if(a+b<=c || b+c<=a || a+c<=b) return {};

      vector<double> ans;
      ans.push_back(cosine(a,b,c));
      ans.push_back(cosine(b,a,c));
      ans.push_back(cosine(c,a,b));

      sort(ans.begin(),ans.end());

      return ans;

        
    }
};