class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> s;

        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int result = 0;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") {
                    // Floor division handling
                    result = (a / b);
                    if ((a ^ b) < 0 && a % b != 0) result--; // Adjust for negative floor
                }
                else if (token == "^") result = pow(a, b);

                s.push(result);
            } else {
                s.push(stoi(token)); // Convert operand string to int
            }
        }

        return s.top();
    }
};