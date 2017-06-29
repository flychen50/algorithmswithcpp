#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> index(256,-1);
    int max_len = 0,start = 0;
    for(int i = 0;i<s.length();i++){
      if(index[s[i]]>=start){
        start = index[s[i]]+1;
      }
      index[s[i]] = i;
      max_len = max(max_len,i-start+1);
     cout<<i<<" "<<start<<" "<<max_len<<endl;
    }
    return max_len;
  }

};

int main(){
  Solution sol;
  string s = "abcabcbb";
  int ret = sol.lengthOfLongestSubstring(s);
  cout<<ret<<endl;
}
