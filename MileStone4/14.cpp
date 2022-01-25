// Smallest range in K lists


class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int l, m, i;
          set<pair<int, pair<int, int>>>st;
          for(i=0; i<k; i++)
          st.insert({KSortedArray[i][0], {i,0}});
          pair<int,int> ans{0, INT_MAX};
          while(!st.empty())
          {
              int mini=st.begin()->first;
              int maxi=st.rbegin()->first;
              if(ans.second-ans.first > maxi-mini)
              {
                  ans.first=mini;
                  ans.second=maxi;
              }
              l=st.begin()->second.first;
              m=st.begin()->second.second;
              st.erase(st.begin());
              if(m+1==n)
              break;
              st.insert({KSortedArray[l][m+1], {l,m+1}});
          }
          return ans;
    }
};