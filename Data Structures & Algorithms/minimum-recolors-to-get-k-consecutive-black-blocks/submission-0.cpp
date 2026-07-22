class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolors = 0;
        
        //build first window
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') recolors++;
        }

        int minRecolors = recolors;

        for(int i = k; i < blocks.length(); i++){
            // remove left side
            if(blocks[i-k] == 'W') recolors--;
            
            // add right side
            if(blocks[i] == 'W') recolors++;

            minRecolors = min(minRecolors, recolors);
        }

        return minRecolors;
    }
};