Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Solution:

Using extra space(hash map)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m1;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto i:nums1)
            m1[i]++;
        for(int i=0;i<nums2.size();i++)
        {
            if(i>0 && nums2[i]==nums2[i-1])
                continue;
            if(m1[nums2[i]]>0)
                ans.push_back(nums2[i]);
        }
        return ans;
        
    }
};

Without extra space (using binary search)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n2;i++)
        {
            if(i>0 && nums2[i]==nums2[i-1])
                continue;
            int n=nums2[i];
            int j=0,k=n1-1;
            
            while(j<=k)
            {
                int mid=(j+k)/2;
                if(nums1[mid]==n)
                {
                    ans.push_back(n);
                    break;
                }  
                else if(nums1[mid]>n)
                    k=mid-1;
                else
                    j=mid+1;
            }
          
        }
        return ans;
    }
};
