class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u';

    }
    int maxFreqSum(string s) {
        int n=s.length();
        int maxVowel=0;
        int maxConsonant=0;

        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(s[i]==s[j]){
                    count++;
                }
            }
            if(isVowel(s[i])){
                maxVowel=max(maxVowel, count);
            }else{
                maxConsonant=max(maxConsonant, count);
            }
        }
        return maxVowel+maxConsonant;
    }
};