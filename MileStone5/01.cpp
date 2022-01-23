// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/


class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int i,j,sum=0;
	    for(i=0;i<n;i++)
	    sum+=arr[i];
	    bool t[n+1][sum+1];
	    for(i=0;i<sum+1;i++)
            t[0][i]=false;
            for(j=0;j<n+1;j++)
            t[j][0]=true;
	    for(i=1;i<n+1;i++)
	    for(j=1;j<sum+1;j++)
	    {
	        if(arr[i-1]<=j)
	        t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
	        else
	        t[i][j]=t[i-1][j];
	    }
	    vector<int>v;
	    for(i=0;i<sum+1;i++)
	    if(t[n][i]==true)
	    v.push_back(i);
	    int mn=INT_MAX;
	    for(i=0;i<v.size();i++)
	    if(v[i]<=sum/2)
	    mn=min(mn, sum-2*v[i]);
	    return mn;
	} 
};

