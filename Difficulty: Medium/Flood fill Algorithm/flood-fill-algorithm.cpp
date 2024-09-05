//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void f(int i, int j, vector<vector<int>> &image, vector<vector<int>> &visited, int n, int m, int newColor, int originalColor) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1 || image[i][j] != originalColor) return;
        
        image[i][j] = newColor;
        visited[i][j] = 1;
        
        f(i + 1, j, image, visited, n, m, newColor, originalColor);
        f(i - 1, j, image, visited, n, m, newColor, originalColor);
        f(i, j - 1, image, visited, n, m, newColor, originalColor);
        f(i, j + 1, image, visited, n, m, newColor, originalColor);
    }  

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int originalColor = image[sr][sc];
        
        if (originalColor != newColor) { // To avoid infinite recursion
            f(sr, sc, image, visited, n, m, newColor, originalColor);
        }
        
        return image;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends