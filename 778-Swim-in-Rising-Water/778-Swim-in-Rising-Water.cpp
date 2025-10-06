class Solution {
public:
int n ;
int vis[51][51];
int dx[4] = {1,-1,0,0} ;
int dy[4] = {0,0,1,-1} ;
bool is_valid(int i , int j,auto& arr,int mid)
{
    return i>=0 and j>=0 and i<n and j<n and arr[i][j]<=mid and !vis[i][j] ;
}
bool solve(int i , int j,int mid,auto& arr)
{
    if( i == n-1 and j == n-1 )return true ;

    vis[i][j] = 1 ;
   bool ans = false ;
    for(int k = 0 ; k<4;k++)
    {
        int ni = i+dx[k] ;
        int nj = j+dy[k] ;
        if(is_valid(ni,nj,arr,mid))
        {
        ans|=solve(ni,nj,mid,arr);
        
        }
     
    }
    return ans ;

}

bool dfs(int mid , auto& arr)
{
    for(int i = 0 ; i<=50;i++)
    {
        for(int j = 0 ; j<=50;j++)vis[i][j] = 0 ;
    }

    if(is_valid(0,0,arr,mid))
     return solve(0,0,mid,arr) ;
     return false ;
}
    int swimInWater(vector<vector<int>>& arr) {
             n = arr.size() ;
        int low = 0 , high = n*n , ans  = -1 ;
        while(low<=high)
        {
            int mid = low + (high-low)/2 ;
            if(dfs(mid,arr))
            {
                ans = mid ;
                high  = mid -1; 
            }
            else low = mid + 1 ;
        }

        return ans ;
        
    }
};