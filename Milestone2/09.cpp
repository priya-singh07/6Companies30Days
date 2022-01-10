// Which among them forms a perfect Sudoku Pattern ?

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0; i<9; i++)
        {
            int mp[10]={0};
            for(int j=0; j<9; j++)
            {
                mp[mat[i][j]]++;
            }
            for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return 0;
        }
        for(int i=0; i<9; i++)
        {
            int mp[10]={0};
            for(int j=0; j<9; j++)
            {
                mp[mat[j][i]]++;
            }
            for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return 0;
        }
        for(int i=0; i<9; i+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                int mp[10]={0};
                for(int k=i; k<3+i; k++)
                {
                    for(int l=j; l<3+j; l++)
                    {
                        mp[mat[k][l]]++;
                    }
                }
                for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return 0;
            }
        }
        return 1;
    }
};