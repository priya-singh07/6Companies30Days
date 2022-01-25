// Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.


#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>v;
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    int m=v.size();
    cout<<v[m-1];
    return 0;
}