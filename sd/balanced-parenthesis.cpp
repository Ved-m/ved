#include<bits/stdc++.h>
using namespace std;

bool ispar(const string &s){
	stack<char> stk;
	
	for(int i=0; i<s.length(); i++){
		
		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
			stk.push(s[i]);
		}
		else{
			
			if(!stk.empty() &&
			(stk.top() == '(' && s[i] == ')')||
			(stk.top() == '{' && s[i] == '}')||
			(stk.top() == '[' && s[i] == ']')){
				stk.pop();
			}
			else{
				return false;
			}
		}
	}
	return stk.empty();
}

/*-----------------------------------------------------------------------------------------*/
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; 
}


void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        
        else if (c == '(')
            st.push('(');

        
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }

        else {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                   !st.empty() && prec(s[i]) == prec(st.top()) &&
                   associativity(s[i]) == 'L') {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}
/*-------------------------------------------------------------------------------------------*/

int evaluatePostfix(string exp)
{
	
	stack<int> st;

	for (int i = 0; i < exp.size(); ++i) {
		
		
		if (isdigit(exp[i]))
			st.push(exp[i] - '0');

		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}
	}
	return st.top();
}


int main(){
	
	int choice;
	string s;
	
	do {
        cout << "\nMenu\n";
        cout << "1. Balanced Parenthesis \n";
        cout << "2. Infix To Postfix \n";
        cout << "3. Postfix Evaluation \n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	case 1:
        		cout<<"Enter string : ";
        		cin>>s;
        		ispar(s);
        		cout << "Is the given string a balanced parenthesis : "<<(ispar(s) ? "true" : "false") << endl;
        		break;
        	
            case 2:
            	cout<<"Enter string : ";
        		cin>>s;
                infixToPostfix(s);
                break;
            
            case 3:
            	cout<<"Enter string : ";
        		cin>>s;
        		int res = evaluatePostfix(s);
        		cout<<endl<<res;
        		break;
	
		}
	}while(choice!=0);
	return 0;
}
