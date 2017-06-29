#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m  = nums1.size();
    int n  = nums2.size();
    if(m>n){
      nums1.swap(nums2);
      int temp = m;m=n;n =temp;
    }
    if(n==0)
      return -1;
    int imin = 0;
    int imax = m;
    int half_len = (m+n+1)/2;
    while(imin<= imax){
      int i  = (imin+imax)/2;
      int j  = half_len-i;
      if(nums1[i]<nums2[j-1] && i<m){
        imin = i+1;
      }else if(i>0 && nums1[i-1]>nums2[j]){
        imax = i-1;
      }else{
        int max_of_left;
        if(i==0){
          max_of_left = nums2[j-1];
        }else if(j==0){
          max_of_left = nums1[i-1];
        }else{
          max_of_left = max(nums1[i-1],nums2[j-1]);
        }
        if((m+n)%2==1){
          return max_of_left;
        }
        int min_of_right;
        if(i==m){
          min_of_right = nums2[j];
        }else if (j==n){
          min_of_right = nums1[i];
        }else{
          min_of_right = min(nums1[i],nums2[j]);
        }
        return (max_of_left+min_of_right)/2.0;


      }
    }



  }
};
int main(){
  Solution sol;
  int t1[10] = {1,3,5};
  vector<int> temp1(t1,t1+3);
  int t2[10]  = {2,4,6};
  vector<int> temp2(t2,t2+3);
  double ret = sol.findMedianSortedArrays(temp1,temp2);
  cout<<ret<<endl;
}
