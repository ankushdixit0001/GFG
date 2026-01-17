class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                // Pop until matching '('
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();

                    // Check if there is any operator inside
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                }

                // Pop the opening bracket '('
                if (!st.empty()) st.pop();

                // If no operator was found inside, it's redundant
                if (!hasOperator) return true;
            } 
            else {
                // Push everything except closing bracket
                st.push(ch);
            }
        }

        return false; // No redundancy found
    }
};