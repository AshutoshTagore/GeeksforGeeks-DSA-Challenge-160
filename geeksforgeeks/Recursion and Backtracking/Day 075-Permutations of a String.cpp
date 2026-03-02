/* Que.75) Permutations of a String  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<string> findPermutation(string s) {
          vector<string> ans;
          
          sort(s.begin(), s.end());
          
          do {
              ans.push_back(s);
          } while (next_permutation(s.begin(), s.end()));
          
          return ans;
      }
  };


int main() {
    Solution obj;
    string s = "ABSG";
    
    vector<string> result = obj.findPermutation(s);
    
    cout << "Total unique permutations: " << result.size() << endl;
    for(string str : result) {
        cout << str << " ";
    }
    cout << endl;
    
    return 0;
}