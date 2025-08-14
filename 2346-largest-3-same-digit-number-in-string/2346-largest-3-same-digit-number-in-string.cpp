class Solution {
public:
    string largestGoodInteger(string num) {
        // int l=0,r=3;
        // int maxm=-1;
        // while(r<=num.size()){
        //     string sub=num.substr(l,r-l);
        //     // cout<<sub<<" ";
        //     set<char> st;
        //     int j=0;
        //     while(j<3){
        //         st.insert(sub[j]);
        //         j++;

        //     }
        //     // cout<<st.size()<<" ";
        //     if(st.size()==1){
        //         maxm=max(maxm,sub[0]-'0');
        //     }
        //     l++,r++;
        // }
        // // cout<<maxm;
        // if(maxm==-1) return "";
        // string res="";
        // for(int i=0;i<3;i++){
        //     res.push_back((maxm+'0'));
        // }
        // return res;

        int maxm=-1;
        char ch=num[0];
        int i=1;
        while(i<num.size()){
            int cnt=1;
            while(i<num.size() && num[i]==ch){
                cnt++;
                if(cnt==3){
                    maxm=max(maxm,num[i]-'0');
                    // cout<<maxm<<" ";
                }
                i++;
            }
            ch=num[i];
            i++;
        }
        // cout<<maxm;
        string res="";
        if(maxm==-1) return res;
        for(int i=0;i<3;i++){
            res+=(maxm+'0');
        }
        return res;
    }
};