#include "fractol.h"

int main(int nargs, char **args)
{
    t_fractal fractal;

    printf("nargs: %d\n", nargs);
    printf("args[1]: %s\n", args[1]);
    printf("ft_strcmp result: %d\n", !ft_strcmp(args[1], "julia", 10));

    if ((nargs == 2 && !ft_strcmp(args[1], "mandelbrot", 10)) || (nargs == 4 && !ft_strcmp(args[1], "julia", 10)))
    {
        fractal.name = args[1];
        fractal.julia_x = alphtodoubl(args[2]);
        fractal.julia_y = alphtodoubl(args[3]);
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}