class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            } else {
                string word;
                while(!st.empty()&&st.top()!='['){
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(),word.end());
                st.pop();
                
                string temp;
                while(!st.empty()&&isdigit(st.top())){
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                int k=stoi(temp);
                
                string repeated;
                for(int j=0;j<k;j++){
                    repeated.append(word);
                }
                
                for(char ch:repeated){
                    st.push(ch);
                }
            }
        }
        string word;
        while(!st.empty()){
            word.push_back(st.top());
            st.pop();
        }
        
        reverse(word.begin(),word.end());
        
        return word;
    }
};