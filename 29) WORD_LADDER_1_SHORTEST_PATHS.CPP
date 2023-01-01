// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
// PROBLEM LINK --- https://leetcode.com/problems/word-ladder/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/word-ladder_1102319

#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    // Code here
    queue< pair<string,int> > q ;
    q.push({startWord , 1}) ;
    unordered_set<string> st(wordList.begin() , wordList.end()) ;
    st.erase(startWord) ;
    while(!q.empty()){
        string word = q.front().first ;
        int steps = q.front().second ;
        q.pop() ;
        if(word == targetWord) return steps ;
        
        for(int i=0 ; i<word.size() ; i++){
            char original = word[i] ;
            for(char c = 'a' ; c <= 'z' ; c++){
                word[i] = c ;
                // if it exists in the set
                if(st.find(word) != st.end()){
                    st.erase(word) ;
                    q.push({word,steps+1}) ;
                }
            }
            word[i] = original ;
        }
    }
    return 0 ;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<string>wordList(n);
        for(int i = 0; i < n; i++)cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        int ans = wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
