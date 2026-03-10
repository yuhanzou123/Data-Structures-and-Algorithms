//#include<iostream>
//#include<string>
//#include<stack>
//#include<unordered_map>
//using std::cout;
//using std::endl;
//using std::cin;
//using std::string;
//string Toend(string s)
//{
//    string m;
//    std::stack<char> p;
//    for (char ch : s)
//    {
//        while (true)
//        {
//            if (ch >= '0' & ch <= '9')
//            {
//                m += ch;
//                break;
//            }
//            if (p.empty())
//            {
//                p.push(ch);
//                break;
//            }
//            if (p.top() == '(')
//            {
//                p.push(ch);
//                break;
//            }
//            if (ch == '(')
//            {
//                p.push(ch);
//                break;
//            }
//            if ((ch == '*' || ch == '/') && (p.top() == '+' || p.top() == '-'))
//            {
//                p.push(ch);
//                break;
//            }
//            else
//            {
//                m += p.top();
//                p.pop();
//            }
//        }
//    }
//    while (!p.empty())
//    {
//        m += p.top();
//        p.pop();
//    }
//    string q;
//    for (char v : m)
//    {
//        if (v != '(' && v != ')')
//        {
//            q += v;
//        }
//    }
//    return q;
//}
//int calculate(string s)
//{
//    int sum=0;
//    std::stack<int> p;
//    for (int i=0;i<s.size();i++)
//    {
//        if(s[i] >= '0' && s[i] <= '9')
//        {
//            p.push(s[i]-'0');
//        }
//        
//        if (s[i] == '+')
//        {
//            sum += p.top();
//            p.pop();
//            sum += p.top();
//            p.pop();
//            p.push(sum);
//            sum = 0;
//        }
//        if (s[i] == '-')
//        {
//            int front = p.top();
//            p.pop();
//            int rear = p.top();
//            p.pop();
//            sum = rear - front;
//            p.push(sum);
//            sum = 0;
//        }
//        if (s[i] == '*')
//        {
//            int front = p.top();
//            p.pop();
//            int rear = p.top();
//            p.pop();
//            sum = rear * front;
//            p.push(sum);
//            sum = 0;
//        }
//        if (s[i] == '/')
//        {
//            int front = p.top();
//            p.pop();
//            int rear = p.top();
//            p.pop();
//            sum = rear / front;
//            p.push(sum);
//            sum = 0;
//        }
//    }
//    return p.top();
//}
//int main()
//{
//    std::unordered_map<char, bool> un =
//    {
//        {'+',true},
//        {'-',true},
//        {'*',true},
//        {'/',true},
//        {'(',true},
//        {')',true},
//    };
//    bool flag = false;
//    string s;
//    cin >> s;
//    size_t t = s.size();
//    string m = s.substr(0, t - 1);
//    for (char ch : m)
//    {
//        if (ch >= '0' & ch <= '9')
//        {
//            continue;
//        }
//        else if (un.find(ch) == un.end())
//        {
//            flag = true;
//            break;
//        }
//    }
//    if(flag)
//    {
//        cout << "NO" << endl;
//        return 0;
//    }
//    else
//    {
//        cout << calculate(Toend(m));
//    }
//    
//}
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
#include<sstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;
using std::unordered_map;
using std::istringstream;

unordered_map<char, int> opPriority = { {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

string toRPN(const string& expr) {
    string rpn;
    stack<char> opStack;
    for (int i = 0; i < expr.size(); ++i) {
        char ch = expr[i];
        if (ch >= '0' && ch <= '9') {
            while (i < expr.size() && expr[i] >= '0' && expr[i] <= '9') {
                rpn += expr[i];
                ++i;
            }
            rpn += ' ';
            --i;
        }
        else if (ch == '(') {
            opStack.push(ch);
        }
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                rpn += opStack.top();
                rpn += ' ';
                opStack.pop();
            }
            opStack.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (ch == '-' && (i == 0 || expr[i - 1] == '(' || expr[i - 1] == '+' || expr[i - 1] == '-' || expr[i - 1] == '*' || expr[i - 1] == '/')) {
                rpn += '0';
                rpn += ' ';
            }
            while (!opStack.empty() && opPriority[opStack.top()] >= opPriority[ch]) {
                rpn += opStack.top();
                rpn += ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
    }
    while (!opStack.empty()) {
        rpn += opStack.top();
        rpn += ' ';
        opStack.pop();
    }
    return rpn;
}

int calculateRPN(const string& rpn) {
    stack<int> numStack;
    istringstream iss(rpn);
    string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = numStack.top();
            numStack.pop();
            int a = numStack.top();
            numStack.pop();
            if (token == "+") numStack.push(a + b);
            else if (token == "-") numStack.push(a - b);
            else if (token == "*") numStack.push(a * b);
            else if (token == "/") numStack.push(a / b);
        }
        else {
            numStack.push(stoi(token));
        }
    }
    return numStack.top();
}

int main() {
    unordered_map<char, bool> validChar = { {'+',true},{'-',true},{'*',true},{'/',true},{'(',true},{')',true} };
    bool isInvalid = false;
    string s;
    cin >> s;
    size_t endPos = s.find('#');
    string expr = s.substr(0, endPos);

    for (char ch : expr) {
        if ((ch >= '0' && ch <= '9') || validChar.count(ch)) continue;
        isInvalid = true;
        break;
    }

    if (isInvalid) {
        cout << "NO" << endl;
        return 0;
    }

    string rpn = toRPN(expr);
    int result = calculateRPN(rpn);
    cout << result << endl;

    return 0;
}