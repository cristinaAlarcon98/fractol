#include "fractol.h"

int main(int nargs, char **args)
{
    if ((nargs == 2 && !ft_strcmp(args[1], "mandelbrot", 10)) || (nargs == 4 && !ft_strcmp(args[1], "julia", 10)))
    {
        // do something
    }
    else
    {
        // putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        // exit(EXIT_FAILURE);
    }
}