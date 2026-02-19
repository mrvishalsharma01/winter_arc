class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        bool arr[128]={false};
        for(char ch:jewels){
            arr[ch]=true;
        }
        for(char ch:stones){
            if(arr[ch]){
                count++;
            }
        }
        
        return count;
    }
};