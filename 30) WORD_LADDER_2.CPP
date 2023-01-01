// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
// PROBLEM LINK --- https://leetcode.com/problems/word-ladder-ii/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // code here
    unordered_set<string> st(wordList.begin() , wordList.end()) ;
    st.insert(beginWord) ;
    queue<vector<string>> q ;
    q.push({beginWord}) ;
    vector<vector<string>> ans ;
    vector<string> usedOnLevel ;
    usedOnLevel.emplace_back(beginWord) ;
    int level = 0 ;
    while(!q.empty()){
        vector<string> vec = q.front() ;
        q.pop() ;
        
        // ERASE ALL WORDS THAT HAS BEEN USED 
        // IN THE PREVIOUS LEVELS TO TRANSFORM 
        if(vec.size() > level){
            level++ ;
            for(auto it:usedOnLevel){
                st.erase(it) ;
            }
            usedOnLevel.clear() ;
        }
        
        string word = vec.back() ;
        
        if(word == endWord){
            // THE FIRST SEQUENCE WHERE WE REACHED END
            if(ans.size() == 0){
                ans.emplace_back(vec) ;
            }
            else if(ans[0].size() == vec.size()){
                ans.emplace_back(vec) ;
            }
        }
        
        for(int i=0 ; i<word.size() ; i++){
            char original = word[i] ;
            for(char c='a' ; c<='z' ; c++){
                word[i] = c ;
                if(st.count(word) > 0){
                    vec.push_back(word) ;
                    q.push(vec) ;
                    // mark as visited on the level 
                    usedOnLevel.emplace_back(word) ;
                    vec.pop_back() ;
                }
                
            }
            word[i] = original ;
        }
    }
    return ans ;
}

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
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
        vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);
        if(ans.size()==0)
            cout<<-1<<endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
