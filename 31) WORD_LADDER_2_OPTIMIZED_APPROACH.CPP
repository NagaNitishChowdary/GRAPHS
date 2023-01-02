// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
// PROBLEM LINK --- https://leetcode.com/problems/word-ladder-ii/

#include<bits/stdc++.h>
using namespace std;
   
unordered_map<string,int> mpp ;
vector<vector<string>> ans ;
string b ;

void dfs(string word , vector<string> &seq){
    if(word == b){
        reverse(seq.begin() , seq.end()) ;
        ans.emplace_back(seq) ;
        reverse(seq.begin() , seq.end()) ;
        return ;
    }
    int steps = mpp[word] ;
    for(int i=0 ; i<word.size() ; i++){
        char original = word[i] ;
        for(char c='a' ; c<='z' ; c++){
            word[i] = c ;
            if(mpp.find(word) != mpp.end() && mpp[word] +1 == steps){
                seq.emplace_back(word) ;
                dfs(word,seq) ;
                seq.pop_back() ;
            }
        }
        word[i] = original ;
    }
}

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin() , wordList.end()) ;
    queue<string> q ;
    b = beginWord ;
    q.push({beginWord}) ;
    mpp[beginWord] = 1 ;
    int size = beginWord.size() ;
    st.erase(beginWord) ;
    while(!q.empty()){ 
        string word = q.front() ;
        q.pop() ;
        int steps = mpp[word] ;
        if(word == endWord) break ;
        for(int i=0 ; i<size ; i++){
            char original = word[i] ;
            for(char c='a' ; c<='z' ; c++){
                word[i] = c ;
                if(st.count(word)){
                    mpp[word] = steps+1 ;
                    st.erase(word) ;
                    q.push(word) ;
                }
            }
            word[i] = original ;
        }
    }
    if(mpp.find(endWord) != mpp.end()){
        vector<string> seq ;
        seq.push_back(endWord) ;
        dfs(endWord,seq) ;
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
