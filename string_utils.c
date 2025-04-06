#include "fractol.h"

int ft_strcmp(char *str1, char *str2, int n)
{
    int i;

    i = 0;
    if (str1 == NULL || str2 == NULL || n < 0)
        return (0);
    while (str1[i] && str2[i] && i < n)
    {
        if (str1[i] != str2[i])
            return (1);
        i++;
    }
    if (i < n)
        return (1);
    return (0);
}

void putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}

int main()
{
    char *str1 = "abcde";
    char *str2 = "hello";

    int result = ft_strcmp(str1, str2, 5);
    putstr_fd(str1, 1);

    // printf("%d\n", result);
}