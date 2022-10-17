#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// Global variables
int stack[100];
int top = -1;
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int symbol)
{
    if (top > 99)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    else
    {
        top = top + 1;
        stack[top] = symbol;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow \n");
        exit(2);
    }
    return (stack[top--]);
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
int white_space(char symbol)
{
    if (symbol == ' ' || symbol == '\t' || symbol == '\0')
        return 1;
    else
        return 0;
}
void infixToPrefix(char infix[], char prefix[])
{
    int i, j, p, n;
    char next;
    char symbol;
    char temp;
    n = strlen(infix);
    p = 0;

    for (i = n - 1; i >= 0; i--)
    {
        symbol = infix[i];
        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case ')':
                push(symbol);
                break;
            case '(':
                while ((next = pop()) != ')')
                    prefix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isempty() && precedence(stack[top]) > precedence(symbol))
                {
                    prefix[p++] = pop();
                }
                push(symbol);
                break;
            default: 
                prefix[p++] = symbol;
            }
        }
    }
    while (!isempty())
        prefix[p++] = pop();
    prefix[p] = '\0'; 

    for (i = 0, j = p - 1; i < j; i++, j--)
    {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int evalPrefix(char prefix[])
{
    int a, b, temp, result;
    int i;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (prefix[i] <= '9' && prefix[i] >= '0')
            push(prefix[i] - 48);
        else
        {
            b = pop();
            a = pop();
            switch (prefix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
            }
            push(temp);
        }
    }
    result = pop();
    return result;
}
int main()
{
    char expression[100];
    char prefix_exp[100];
    char *p = prefix_exp;
    char *e = expression;
    bool state = false;
    int operation, operation2;
    while (!state)
    {
        printf("Enter Infix Expression : ");
        gets(expression);
        printf("\n--------------------\nConverting to Prefix\n---------------------\n");
        printf("Enter 1 to display prefix\n");
        printf("Enter 2 to d    isplay output\n");
        printf("Enter anything else to exit\n");
        printf("Enter : ");
        scanf("%d", &operation);
        infixToPrefix(e, p);
        switch (operation)
        {
        case 1:
            printf("Prefix : %s\n", p);
            printf("Do you want to evaluate? (1 Yes, Anything else for Re-Input) ");
            scanf("%d", &operation2);
            if (operation2 == 1)
            {
                goto eval;
            }
            else
            {
                scanf("%c");
                continue;
            }
            break;
        case 2:
        eval:
            scanf("%c");
            printf("Evaluated value : %d\n", evalPrefix(p));
            break;
        default:
            state = true;
            break;
        }
    }
    return 0;
}
