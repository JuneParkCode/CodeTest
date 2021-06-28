#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

using namespace std;
const int CASES[][3]=
{
    {0,1,2},
    {0,2,1},
    {1,2,0},
    {1,0,2},
    {2,1,0},
    {2,0,1}
};
const int CASE_SIZE = 7;
long long calculator(const long long l, const long long r, const char OPERATOR)
{
    switch(OPERATOR)
    {
    case '*':
        return l * r;
    case '+':
        return l + r;
    case '-':
        return l - r;
    };
}
long long get_maximum(stack<long long> &operands,stack<char> &operators,map<char,int> &orderMap,const string expression)
{
    long long result = 0;
    string num ="";
    for(char c :expression)
    {
        switch (c)
        {
        case '*':   
        case '+':
        case '-':
            //cout<<num<<c<<endl;
            operands.push(stoll(num));
            num = "";
            if(operators.empty())
            {
                operators.push(c);
            }
            else
            {
                // 다음 연산자가 이전 연산자보다 순위가 낮을 경우 앞선 연산을 수행
                if(orderMap[c] < orderMap[operators.top()])
                {
                    while(operands.size() > 1 && !operators.empty() && orderMap[c] <= orderMap[operators.top()])
                    {
                        long long r = operands.top(); operands.pop();
                        long long l = operands.top(); operands.pop();
                        long long temp = calculator(l,r,operators.top());
                        cout<<l<<operators.top()<<r<<"="<<temp<<endl;
                        operators.pop();
                        operands.push(temp);
                    }
                    operators.push(c);
                }
                else if(orderMap[c] == orderMap[operators.top()])
                {
                    long long r = operands.top(); operands.pop();
                    long long l = operands.top(); operands.pop();
                    long long temp = calculator(l,r,c);
                    cout<<l<<operators.top()<<r<<"="<<temp<<endl;
                    operators.pop();
                    operands.push(temp);
                    operators.push(c);
                }
                // 순위가 더 높을 경우 다음 연산을 위해 push
                else
                {
                    operators.push(c);
                }
            }
            break;
        default:
            num += c;   // 숫자가 들어올 때 
            break;
        }
    }
    operands.push(stoi(num));
    while(!operators.empty())
    {
        long long r = operands.top(); operands.pop();
        long long l = operands.top(); operands.pop();
        long long temp = calculator(l,r,operators.top());
        cout<<l<<operators.top()<<r<<"="<<temp<<endl;
        operators.pop();
        operands.push(temp);
    }
    return operands.top();
}
long long solution(string expression) {
    long long answer = 0;
    map<char,int> orderMap;
    stack<long long> operands;
    stack<char> operators;
    for(int i=0; i<CASE_SIZE; ++i)
    {
        cout<<"CASE "<<i<<endl;
        orderMap['+'] = CASES[i][0];
        orderMap['-'] = CASES[i][1];
        orderMap['*'] = CASES[i][2];
        long long res = get_maximum(operands,operators,orderMap,expression);
        res = res<0?-res:res;
        answer = res > answer ? res : answer;
    }
    return answer;
}

int main()
{
    string expression = "100-200*300-500+20";
    cout << solution(expression);
}
