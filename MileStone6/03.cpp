// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color (Similar to Card Game Question)

class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int>a,b;
        int bob=0, alice=0;
        for(int i=0; colors[i]; i++)
        {
            if(colors[i]=='A')
            {
                if(bob)
                {
                    b.push_back(bob);
                    bob=0;
                }
                alice++;
            }
            else
            {
                if(alice)
                {
                    a.push_back(alice);
                    alice=0;
                }
                bob++;
            }
        }
        if(bob)
        {
            b.push_back(bob);
            bob=0;
        }
        if(alice)
        {
            a.push_back(alice);
            alice=0;
        }
        for(int i=0; i<a.size(); i++)
        {
            if(a[i]>=3)
                alice+=(a[i]-2);
        }
        for(int i=0; i<b.size(); i++)
        {
            if(b[i]>=3)
                bob+=(b[i]-2);
        }
        return alice>bob;
    }
};