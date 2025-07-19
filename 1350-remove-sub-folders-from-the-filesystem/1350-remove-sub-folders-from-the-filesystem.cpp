class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        vector<string> vec;
        unordered_map<string,int> hash;
        for(int i=0;i<folder.size();i++){
            int j=1;
            while(j<folder[i].size() && folder[i][j]!='/') j++;
            int f=0;
            while(j<folder[i].size()){
                string str=folder[i].substr(0,j);
                if(hash.find(str)!=hash.end()){
                    f=1;
                    break;
                }
                j++;
                while(j<folder[i].size() && folder[i][j]!='/') j++;
            }
            if(f==0){
                hash[folder[i]]++;
                vec.push_back(folder[i]);
            }
        }
        return vec;
    }
};