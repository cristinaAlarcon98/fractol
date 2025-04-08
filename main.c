#include "fractol.h"

int main(int nargs, char **args)
{
    t_fractal fractal;
    if ((nargs == 2 && !ft_strcmp(args[1], "mandelbrot", 10)) || (nargs == 4 && !ft_strcmp(args[1], "julia", 10)))
    {
        void *mlx;
        void *mlx_win;

        mlx = mlx_init();
        mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
        mlx_loop(mlx);
        // fractal_init(&fractal);
        // fractal_render(&fractal);
        // mlx_loop(fractal.mlx_connection);
    }
    else
    {
        // putstr_fd(ERROR_MESSAGE, 1);
        exit(EXIT_FAILURE);
    }
}