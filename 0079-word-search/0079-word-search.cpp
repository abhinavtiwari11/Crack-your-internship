class Solution {
public:
        
      int dr[4]={0,1,0,-1};

    int dc[4]={1,0,-1,0}; 

    int v[7][7]; 

    bool help (int i , int j ,  string word , int index , vector<vector<char>>& board , int m , int n  )
    {  
        if( index == word.size() ) return true ; 

         for( int k = 0 ; k < 4 ;k++ )
         {
            if ( i+dr[k]>=0 && i+dr[k]<m && j+dc[k]>=0 && j+dc[k]<n )
            {
                 if( board[i+dr[k]][j+dc[k]] == word[index] )
             {
                if( !v[i+dr[k]][j+dc[k]] ){ 

                     v[i+dr[k]][j+dc[k]] = 1 ; 

                     if( help(i+dr[k],j+dc[k],word,index+1,board,m,n)  ) return true;

                    v[i+dr[k]][j+dc[k]] = 0 ;
                }
            }
            }
     }

     return false ;
     

    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();

        int n = board[0].size();

        memset(v,0,sizeof(v));

        for( int i = 0 ; i< m ; i++ )
        {
            for( int j = 0;j<n;j++ )
            {
                 if(board[i][j]==word[0]){
                    v[i][j]=1;
                    if(help(i,j,word,1,board,m,n)) return true;
                    v[i][j]=0;
                }
            }
        }

        return false ;

    }
};
