#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Global variables
char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char item;
    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

void infixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (!white_space(item))
        {
            if (item == '(')
            {
                push(item);
            }
            else if (isdigit(item) || isalpha(item))
            {
                postfix_exp[j] = item;
                j++;
            }
            else if (is_operator(item) == 1)
            {
                x = pop();
                while (is_operator(x) == 1 && precedence(x) >= precedence(item))
                {
                    postfix_exp[j] = x;
                    j++;
                    x = pop();
                }
                push(x);
                push(item);
            }
            else if (item == ')')
            {
                x = pop();
                while (x != '(')
                {
                    postfix_exp[j] = x;
                    j++;
                    x = pop();
                }
            }
            else
            {
                printf("\nInvalid infix Expression.\n");
                getchar();
                exit(1);
            }
        }
        i++;

        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    postfix_exp[j] = '\0';
}

int evalpostfix(char *p)
{
    int n1, n2, n3, num;
    while (*(p) != '\0')
    {
        if (isdigit(*p))
        {
            num = *p - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*p)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n2 * n1;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            case '^':
                n3 = pow(n2, n1);
                break;
            default:
                break;
            }
            push(n3);
        }
        p++;
    }
    return pop();
}
int main()
{
    char expression[100];
    char postfix_exp[100];
    char *p = postfix_exp;
    char *e = expression;
    bool state = false;
    int operation, operation2;
    while (!state)
    {
        printf("Enter Infix Expression : ");
        gets(expression);
        printf("\n--------------------\nConverting to Postfix\n---------------------\n");
        printf("Enter 1 to display postfix\n");
        printf("Enter 2 to display output\n");
        printf("Enter anything else to exit\n");
        printf("Enter : ");
        scanf("%d", &operation);
        infixToPostfix(e, p);
        switch (operation)
        {
        case 1:
            printf("Postfix : %s\n", p);
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
            printf("Evaluated value : %d\n", evalpostfix(p));
            break;
        default:
            state = true;
            break;
        }
    }
    return 0;
}