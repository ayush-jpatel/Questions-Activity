class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vec(n,vector<int>(m,INT_MAX-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                    vec[i][j] = 0;
                if(i != 0)
                    vec[i][j] = min(vec[i][j],1+ vec[i-1][j]);
                if(j != 0)
                    vec[i][j] = min(vec[i][j],1+ vec[i][j-1]);
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i!=n-1)
                    vec[i][j] = min(vec[i][j],1+ vec[i+1][j]);
                if(j!=m-1)
                    vec[i][j] = min(vec[i][j],1+ vec[i][j+1]);
            }
        }

        return vec;
    }
};



// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size(); //m is width, n is height
//         vector<vector<int>> vec(m,vector<int>(n,-1));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(mat[i][j] == 0)
//                     vec[i][j] = 0;
//             }
//         }

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(mat[i][j] == 0)
//                 {
//                     vec[i][j] = 0;
//                 }
//                 if(i == 0 && j==0)
//                 {
//                 }
//                 else if(i == 0)
//                 {
//                     if(vec[i][j] != -1)
//                     {
//                         if(vec[i][j-1] != -1)
//                             vec[i][j] = min(vec[i][j],vec[i][j-1]);
//                     }
//                     else
//                         vec[i][j] = vec[i][j-1];
//                 }
//                 else if(j == 0)
//                 {
//                     if(vec[i][j] != -1)
//                     {
//                         if(vec[i-1][j] != -1)
//                             vec[i][j] = min(vec[i][j],vec[i-1][j]);
//                     }
//                     else
//                         vec[i][j] = vec[i-1][j];
//                 }
//                 else
//                 {
//                     if(vec[i][j] != -1)
//                     {
                        
//                     }
//                 }
//             }
//         }

//     }