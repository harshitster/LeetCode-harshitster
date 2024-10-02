class Solution {
private:
    int helper(int num1, int num2, string operation) {
        if(operation == "+") return num1 + num2;
        if(operation == "-") return num1 - num2;
        if(operation == "*") return num1 * num2;
        if(operation == "/") return num1 / num2;
        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(const auto& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                int res = helper(num2, num1, token);
                s.push(res);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};