#include <iostream>
#include <cstring>
#include <map>
#include <stack>

using namespace std;

int pranthesMatch(char open, char close)
{
    return ((open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')'));
}

// second approach working
//  int isbalanced(char *exp)
//  {

//     stack<char> stk;

//     for (int i = 0; i < strlen(exp); i++)
//     {
//         if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
//         {
//             if (exp[i] == '{')
//             {
//                 stk.push('}');
//             }
//             else if (exp[i] == '[')
//             {
//                 stk.push(']');
//             }
//             else
//             {
//                 stk.push(')');
//             }
//         }
//         else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
//         {
//             if (stk.empty())
//                 return false;
//             char close = stk.top();
//             stk.pop();
//             if (!(close == exp[i]))
//                 return false;
//         }
//     }
//     if (stk.empty())
//         return true;
// }

// secoend approach refined
int isbalanced(char *exp)
{

    stack<char> stk;
    int n = strlen(exp);
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            if (exp[i] == '{')
            {
                stk.push('}');
            }
            else if (exp[i] == '[')
            {
                stk.push(']');
            }
            else
            {
                stk.push(')');
            }
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (stk.empty())
                return false;
            char close = stk.top();

            if (!(close == exp[i]))
                return false;
            stk.pop();
        }
    }

    return stk.empty();
}

// first approach working good
//  int isbalanced(char *exp)
//  {

//     stack<char> stk;

//     for (int i = 0; i < strlen(exp); i++)
//     {
//         if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
//         {
//             stk.push(exp[i]);
//         }
//         else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
//         {
//             if (stk.empty())
//                 return false;
//             char open = stk.top();
//             stk.pop();
//             if (!pranthesMatch(open, exp[i]))
//                 return false;
//         }
//     }
//     if (stk.empty())
//         return true;
// }

int main()
{

    char E[] = "{(a+b)*[(c-d)/d]}";
    cout << isbalanced(E) << endl;

    char F[] = "{(a+b)*[(c-d)/d)}";
    cout << isbalanced(F) << endl;

    char G[] = "([a+b)]";
    cout << isbalanced(G) << endl;
    return 0;
}