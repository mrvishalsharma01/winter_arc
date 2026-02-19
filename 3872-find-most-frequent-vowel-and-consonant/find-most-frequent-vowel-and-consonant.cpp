class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u';

    }
    int maxFreqSum(string s) {
        int freq[26]={0};
        for(char ch:s){
            freq[ch-'a']++;
        }
        int maxVowel=0;
        int maxConsonant=0;

        for(int i=0;i<26; i++){
            if(freq[i]>0){
                char ch=i+'a';
                if(isVowel(ch)){
                    maxVowel=max(maxVowel, freq[i]);
                }else{
                    maxConsonant=max(maxConsonant, freq[i]);
                }
            }
        }
        return maxVowel+maxConsonant;
    }
};