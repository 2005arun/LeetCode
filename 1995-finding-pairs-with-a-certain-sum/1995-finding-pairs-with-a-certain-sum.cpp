class FindSumPairs {
public:
    vector<int> num1,num2;
    unordered_map<int,int> hash;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        for(int i=0;i<nums2.size();i++){
            hash[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        hash[num2[index]]--;
        if(hash[num2[index]]==0) hash.erase(num2[index]);

        num2[index]+=val;
        hash[num2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<num1.size();i++){
            cnt+=hash[tot-num1[i]];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */