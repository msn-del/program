#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 4;
    while (i > 3)
    {
        int x = get_int("x: ");
        char answer = get_char("which symbole, ?");

        if (answer == '+')
        {
            int y = get_int("y: ");
            int result = x + y;
        }
        printf("%i\n", result);

        if (answer == '-')
        {
            int y = get_int("y: ");
            int result = x - y;
        }
        printf("%i\n", result);

        if (answer == '*')
        {
            int y = get_int("y: ");
            int result = x * y;
        }
        printf("%i\n", result);

        if (answer == '/')
        {
            int y = get_int("y: ");
            int result = x / y;
        }
        printf("%i\n", result);
    }
}
