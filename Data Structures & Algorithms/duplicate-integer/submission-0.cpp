class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> numsB;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int checkNum = nums.at(i);
        
            for(int j = 0; j < numsB.size(); j++)
            {
                if(checkNum == numsB.at(j))
                    return true;   
            }

            numsB.push_back(checkNum);
        }

        return false;
    }
};