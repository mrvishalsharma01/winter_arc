class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int x : nums) freq[x]++;

    int n = nums.size();
    vector<vector<int>> bucket(n + 1);

    // push numbers into buckets based on their frequency
    for(auto &p : freq) {
        bucket[p.second].push_back(p.first);
    }

    vector<int> ans;

    // traverse buckets from highest freq
    for (int i = n; i >= 1 && ans.size() < k; i--) {
        for (int num : bucket[i]) {
            ans.push_back(num);
            if(ans.size() == k) break;
        }
    }

    return ans;
}

};