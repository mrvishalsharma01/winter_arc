class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int countBalanced=0;
        for(char ch:s){
            if(ch=='R')
              balance++;
            else
               balance--;

            if(balance==0){
                countBalanced++;
            }     
        }
        return countBalanced;
        
    }
};