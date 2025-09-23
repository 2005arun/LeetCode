class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream iss1(version1);
        stringstream iss2(version2);
        vector<int> vec1,vec2;
        string n;
        while(getline(iss1,n,'.')){
            int a=stoi(n);
            vec1.push_back(a);
        }
        while(getline(iss2,n,'.')){
            int a=stoi(n);
            vec2.push_back(a);
        }
        int i=0,j=0;
        while(i<vec1.size() && j<vec2.size()){
            if(vec1[i]<vec2[j]) return -1;
            if(vec1[i]>vec2[j]) return 1;
            i++,j++;
        }
        while(i<vec1.size()){
            if(vec1[i]>0) return 1;
            i++;
        }
        while(j<vec2.size()){
            if(vec2[j]>0) return -1;
            j++;
        }
        return 0;
    }
};