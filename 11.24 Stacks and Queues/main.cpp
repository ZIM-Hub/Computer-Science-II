#include <fstream>
#include <iostream>
#include <time.h>
#include <stack>
#include <queue>

using namespace std;
int evalPostfix(std::queue<char> expression) {
   std::stack<int> operands;
    while (!expression.empty()) {
        char c = expression.front();
        expression.pop();
        if (isdigit(c)) { 
            operands.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') { 
            if (operands.size() < 2) { 
                return -1;
            }
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            int result;
            if (c == '+') {
                result = op1 + op2;
            } else if (c == '-') {
                result = op1 - op2;
            } else if (c == '*') {
                result = op1 * op2;
            } else if (c == '/') {
                if (op2 == 0) { 
                    return -1;
                }
                result = op1 / op2;
            }
            operands.push(result);
        } else { 
            return -1;
        }
    }
    if (operands.size() != 1) { 
        return -1;
    }
    return operands.top();
}


int main() {
	std::queue<char> queue1, queue2;
	//basic simple addition
	queue1.push('1');
	queue1.push('2');
	queue1.push('+');
	cout<<"Queue1 evaluates to "<<evalPostfix(queue1)<<std::endl;
	queue2.push('5');
	queue2.push('6');
	queue2.push('7');
	queue2.push('+');
	queue2.push('1');
	queue2.push('2');
	queue2.push('+');
	queue2.push('-');
	queue2.push('*');
	queue2.push('4');
	queue2.push('/');
	cout<<"Queue2 evaluates to "<<evalPostfix(queue2)<<std::endl;
	return 0;
}

