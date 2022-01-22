// Minimum operations to convert array A to B


class Solution {
  public:
    int solve(vector<int>v){
        vector<int>res;
        for(int i=0; i<v.size(); i++){
            auto it = lower_bound(res.begin(),res.end(),v[i]);
            if(it == res.end()){
                res.push_back(v[i]);
            }
            else{
                *it = v[i];
            }
        }
        return res.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0; i<M; i++){
            mp[B[i]]++;
        }
        vector<int>v;
        for(int i=0; i<N; i++){
            if(mp.find(A[i]) != mp.end()){
                v.push_back(A[i]);
            }
        }
        return (N+M) - 2*solve(v);
    }
};