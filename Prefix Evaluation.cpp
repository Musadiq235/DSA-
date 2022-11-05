#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int prefixevaluation(string s) {

	stack<int> st;  // We will create and stack and store the operators

	for (int i = s.length() - 1; i >= 0; i--) {

		if (s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
		}
		else {
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();

			switch (s[i])
			{
			case '+':
				st.push(op1 + op2);
				break;
			case '-':
				st.push(op1 - op2);
				break;
			case '*':
				st.push(op1 * op2);
				break;
			case '/':
				st.push(op1 / op2);
				break;
			case '^':
				st.push(pow(op1, op2));

			}

		}
	}
	return st.top();
}

int main() {

	cout << prefixevaluation("-+7*45+20") << endl;

	system("pause>0");
	return 0;
}
//"-+7*45+20"
