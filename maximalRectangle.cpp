class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> heights(n,vector<int>(m));
        for(int k=0; k<n; k++){
        for(int i=0; i<m; i++){
            int cnt=0;
            for(int j=k; j<n; j++){
                if(matrix[j][i]=='0') break;
                cnt++;
            }
            heights[k][i]=cnt;
        }
    }
    vector<vector<int>> PSE(n,vector<int>(m));
    vector<vector<int>> NSE(n,vector<int>(m));
    for(int i=0; i<n; i++){
        stack<int> st1; 
        
        for(int j=0; j<m; j++){
            while(!st1.empty()&&heights[i][st1.top()]>=heights[i][j]){
                st1.pop();
            }
            PSE[i][j]=st1.empty()?-1:st1.top();
            st1.push(j);
        }
    }
    for(int i=0; i<n; i++){
        stack<int> st2; 
        
        for(int j=m-1; j>=0; j--){
            while(!st2.empty()&&heights[i][st2.top()]>=heights[i][j]){
                st2.pop();
            }
            NSE[i][j]=st2.empty()?m:st2.top();
            st2.push(j);
        }
    }
    int maxrectangle=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int left=j-PSE[i][j];
            int right=NSE[i][j]-j-1;
            int height=(left+right)*heights[i][j];
            maxrectangle=max(maxrectangle,height);
        }
    }
    return maxrectangle;
    }
};
