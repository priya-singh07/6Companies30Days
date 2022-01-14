// Generate and print all binary numbers with decimal values from 1 to N. 

string dcb(int n)
{
    string s="";
    while(n)
    {
        int x=n%2;
        n/=2;
        s+=to_string(x);
    }
    reverse(s.begin(), s.end());
    return s;
}
//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string>v;
	for(int i=1; i<=N; i++)
	v.push_back(dcb(i));
	return v;
}
