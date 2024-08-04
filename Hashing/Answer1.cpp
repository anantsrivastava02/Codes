#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       unordered_map< char , int > que ;
       for(int i = 0 ; i < S.size() ; i++)que[S[i]] += 1 ;
       for(int i = 0 ; i < S.size() ; i++){
           if(que[S[i]] == 1 )return S[i];
       }
       return '$' ;
    }

};

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
