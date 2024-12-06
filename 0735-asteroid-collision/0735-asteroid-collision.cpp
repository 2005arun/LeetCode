class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0) vec.push_back(asteroids[i]);
            else{
                while(!vec.empty() && vec.back()>0 && vec.back()<abs(asteroids[i])) vec.pop_back();
                if(!vec.empty() && vec.back()==abs(asteroids[i])) vec.pop_back();
                else if(vec.empty() || vec.back()<0) vec.push_back(asteroids[i]);
            }
        }
        return vec;
    }
};