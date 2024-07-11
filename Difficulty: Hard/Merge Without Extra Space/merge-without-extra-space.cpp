//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            //Declare a 3rd array and 2 pointers:
            long long arr3[n + m]; // arr with size n+m
            int left = 0; // pointer at the left of the arr1
            int right = 0;//// pointer at the right of the arr2
            
            int index= 0;
            
            //Insert the element from the 2 arrays into 3rd array using left and right pointer
            
            while(left < n && right < m) {
                if(arr1[left] <= arr2[right]) { // left pointer is less than right pointer
                    arr3[index] = arr1[left]; //if the if condition true then arr3 will add left pointer
                    left++, index++;// after that shift the left pointer by place and also the index pointer at arr 3
                }
                else {
                    arr3[index] = arr2[right];// if the left is not less than right then add right pointer element
                    right++, index++;// after that shift the left pointer by place and also the index pointer at arr3
                }
            }
            
            // If the right pointer reachesthe end:
            while(left < n) {
                arr3[index++] = arr1[left++];
            }
            
            //if the left pointer reaches the end:
            while(right < m) {
                arr3[index++] = arr2[right++];
            }
            //Fill back the element from arr[3] to arr1[] and arr2[]:
            for(int i = 0; i < n+m; i++){
                if(i<n) arr1[i] = arr3[i];
                else arr2[i-n] = arr3[i];
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends