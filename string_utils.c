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
            return (0);
        i++;
    }
    if (i < n)
        return (0);
    return (1);
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

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->img_ptr + (y * data->line_len + x * (data->bits_per_pix / 8));
    *(unsigned int *)dst = color;
}

double alphtodoubl(char *s)
{
    long integer_part;
    double fractional_part;
    double pow;
    int sign;

    sign = 1;
    integer_part = 0;
    fractional_part = 0.0;
    pow = 1.0;

    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9')
    {
        integer_part = integer_part * 10 + (*s - '0');
        s++;
    }

    if (*s == '.')
    {
        s++;
        while (*s >= '0' && *s <= '9')
        {
            pow *= 0.1;
            fractional_part += (*s - '0') * pow;
            s++;
        }
    }

    return (sign * (integer_part + fractional_part));
}

/*
int main()
{
    char *str1 = "abcde";
    char *str2 = "hello";

    int result = ft_strcmp(str1, str2, 5);
    putstr_fd(str1, 1);

    // printf("%d\n", result);
}*/