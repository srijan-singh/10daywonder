#include<bits/stdc++.h>

using namespace std;

class Solution
{
    class cord
    {
        public:
        int i=0;
        int j=0;

        cord(int row, int col)
        {
            i=row;
            j=col;
        }
        
        //Row
        void inc_row()
        {
            i++;
        }

        void dec_row()
        {
            i--;
        }

        //Col
        void inc_col()
        {
            j++;
        }

        void dec_col()
        {
            j--;
        }
    };

    public:

    bool all_rotten(vector<vector<int>> box)
    {
        // Convert fresh to rotten which are near rotten
        for(int i=0; i<box[0].size(); i++)
        {
            for(int j=0; j<box[1].size(); j++)
            {
                auto elm = box[i][j];

                if(elm != 1)
                {
                    continue;
                }

                // dec
                cord l(i,j);
                l.dec_col();

                cord u(i,j);
                u.dec_row();

                // inc
                cord r(i,j);
                r.inc_col();

                cord d(i,j);
                d.inc_row();

                if(l.j >=0)
                {
                    if(box[l.i][l.j] == 2)
                    {
                        box[i][j]=2;
                    }
                }

                if(u.i >=0)
                {
                    if(box[u.i][u.j] == 2)
                    {
                        box[i][j]=2;
                    }
                }

                if(r.j <box[1].size()) 
                {
                    if(box[r.i][r.j] == 2)
                    {
                        box[i][j]=2;
                    }
                }
                
                if(d.i < box[0].size())
                {
                    if(box[d.i][d.j] == 2)
                    {
                        box[i][j]=2;
                    }
                }

            }
        }

        // Check if any fresh is present
        for(int i=0; i<box[0].size(); i++)
        {
            for(int j=0; j<box[0].size(); j++)
            {
                if(box[i][j]==1)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> box = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    Solution s;

    cout<<boolalpha<<s.all_rotten(box);

    return 0;
}