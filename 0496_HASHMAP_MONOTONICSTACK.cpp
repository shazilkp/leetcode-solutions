class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>res1;
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i = n2 -1 ; i >= 0 ; --i){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i = 0 ; i < n1 ; i ++){
            res1.push_back(mp[nums1[i]]);
        }
        return res1;
    }
};
