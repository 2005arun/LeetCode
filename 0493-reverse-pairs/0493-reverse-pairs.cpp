class Solution {
public:
    void merge(vector<int> &skill,int low,int mid,int high,int &cnt){
        int left=low;
        int right=mid+1;
        vector<int> temp;
        for(int i=low;i<=mid;i++){
            while (right <= high) {
                if (skill[right] > INT_MAX / 2) {
                    break; 
                }
                if (skill[i] > 2 * (long long)skill[right]) {
                    right++;
                } else {
                    break; 
                }
            }
            cnt+=(right-(mid+1));
        }
        right=mid+1;
        while(left<=mid && right<=high){
            if (skill[left] > skill[right]) {
                temp.push_back(skill[right]);
                right++;
            }
            else{
                temp.push_back(skill[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(skill[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(skill[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            skill[i]=temp[i-low];
        }
    }
    void mergesort(vector<int> &skill,int low,int high,int &cnt){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergesort(skill,low, mid,cnt);
        mergesort(skill,mid+1,high,cnt);
        merge(skill,low,mid,high,cnt);
    }
    int reversePairs(vector<int>& skill) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         long long a=nums[i];
        //         long long b=2*nums[j];
        //         if(a>b) cnt++;
        //     }
        // }
        // return cnt;
        int n=skill.size();
        int cnt=0;
        mergesort(skill,0,n-1,cnt);
        return cnt;
    }
};