#include "fractol.h"

int main(int nargs, char **args)
{
    t_fractal fractal;
    if ((nargs == 2 && !ft_strcmp(args[1], "mandelbrot", 10)) || (nargs == 4 && !ft_strcmp(args[1], "julia", 10)))
    {
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, 1);
        exit(EXIT_FAILURE);
    }
}