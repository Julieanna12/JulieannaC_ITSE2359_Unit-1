#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>  // For exception handling
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;                    // Stack to store operands
    stringstream ss(expression);
    string token;

    // Loop through each token in the input string
    while (ss >> token) {
        // Check if token is a number
        if (isdigit(token[0])) {
            s.push(token[0] - '0');  // Convert character to integer and push to stack
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Ensure there are enough operands on the stack
            if (s.size() < 2) {
                throw invalid_argument("Invalid expression: Not enough operands for operation.");
            }

            // Pop the top two operands
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            // Perform the operation
            if (token == "+") {
                s.push(a + b);
            } else if (token == "-") {
                s.push(a - b);
            } else if (token == "*") {
                s.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw runtime_error("Division by zero.");
                }
                s.push(a / b);
            }
        } else {
            throw invalid_argument("Invalid token in expression.");
        }
    }

    // Ensure that only one element remains in the stack (the final result)
    if (s.size() != 1) {
        throw invalid_argument("Invalid expression.");
    }

    return s.top();  // Return the final result
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    try {
        int result = evaluatePostfix(expression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
