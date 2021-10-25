class Solution {
public:
    int isFine(int mid, vector<int>& weights, int days)
    {
        int d=0,curr=0;
        for(int i=0;i<weights.size();i++)
        {
            curr+=weights[i];
            if(curr>mid)
            {    d++;
            curr=weights[i];
            }
            else if(curr==mid)
            {
               d++; curr=0; 
            }
        }
        if(curr) d++;
        if(d<=days) return 1;
        else return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0, mid,right=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>=left)
                left=weights[i];
            right+=weights[i];
        }
        int res=right;
        while(left<=right)
        {
            mid=(right+left)/2;
            if(isFine(mid,weights,days)==1) 
            {right=mid-1; res=mid;}
            else 
                left=mid+1;
        }
        return res;
    }
};
