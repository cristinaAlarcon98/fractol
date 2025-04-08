#include "fractol.h"

int main(int nargs, char **args)
{
    t_fractal fractal;
    if ((nargs == 2 && !ft_strcmp(args[1], "mandelbrot", 10)) || (nargs == 4 && !ft_strcmp(args[1], "julia", 10)))
    {
        void *mlx;
        void *mlx_win;
        t_img img;

        mlx = mlx_init();
        mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
        img.img_ptr = mlx_new_image(mlx, 1920, 1080);
        img.img_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pix, &img.line_len,
                                         &img.endian);
        mlx_pixel_put(&img, 5, 5, 0x00FF0000);
        mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
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