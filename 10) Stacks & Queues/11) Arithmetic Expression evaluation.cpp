#include<bits/stdc++.h>
using namespace std;

int getPrecedence(char optor) {
    if(optor == '+') return 1;
    else if(optor == '-') return 1;
    else if(optor == '*') return 2;
    else return 2;
}

int operations(int val1, int val2, char optor) {
    if(optor == '+') return (val1 + val2);
    else if(optor == '-') return (val1 - val2);
    else if(optor == '*') return (val1 * val2);
    else return (val1 / val2);
}

int arithmeticEcpressionEvaluation(string &exp) {
    int result = 0;
    stack<int> opnds; // Stack for Operands;
    stack<char> optors; // Stack for Operators;
    for(int i=0; i<exp.size(); i++) {
        char ch = exp[i];
        if(ch == '(') {
            optors.push(ch);
        }
        else if(ch >= '0' && ch <= '9') {
            opnds.push(ch-'0');
        }
        else if(ch == ')') {
            while(optors.top() != '(') {
                char op = optors.top();
                optors.pop();
                int val2 = opnds.top();
                opnds.pop();
                int val1 = opnds.top();
                opnds.pop();
                int result = operations(val1, val2, op);
                opnds.push(result);
            }
            optors.pop(); // For removing the '(' breacket.
        }
        else if(ch == '+' || ch =='-' || ch =='*' || ch =='/') {
            // ch is wanting to solve higher Priority Operators first.
            while(optors.size() > 0 && optors.top() != '(' && getPrecedence(ch) <= getPrecedence(optors.top())) {
                char op = optors.top();
                optors.pop();
                int val2 = opnds.top();
                opnds.pop();
                int val1 = opnds.top();
                opnds.pop();
                int result = operations(val1, val2, op);
                opnds.push(result);
            }
            optors.push(ch);    // Now, we will have to push the ch in Operators Stack.
        }
    }
    
    // If all the elements of the Stacks are not processed. Eg: 2+3*6
    while(!optors.empty()) {
        char op = optors.top();
        optors.pop();
        int val2 = opnds.top();
        opnds.pop();
        int val1 = opnds.top();
        opnds.pop();
        int result = operations(val1, val2, op);
        opnds.push(result);
    }
    result = opnds.top();
    return result;
}

int main() {
    string exp = "2*3+6*(5-1)"; // Ans: 30
    cout<<"Arithmetic Expression Evaluation: "<<arithmeticEcpressionEvaluation(exp);
    return 0;
}