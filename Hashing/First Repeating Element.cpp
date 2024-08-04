
//https://www.geeksforgeeks.org/problems/first-repeating-element4018/0
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        unordered_map< int , int > que ;
       for(int i = 0 ; i < arr.size() ; i++)que[arr[i]] += 1 ;
       for(int i = 0 ; i < arr.size() ; i++){
           if(que[arr[i]] > 1 )return i+1;
       }
       return -1 ; 
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}
