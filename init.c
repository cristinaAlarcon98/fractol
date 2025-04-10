#include "fractol.h"
static void malloc_error(void)
{
    perror("Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal->scape_value = 4;
    fractal->ilterations = 200;
}
void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        malloc_error();

    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);

    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pix,
                                               &fractal->img.line_len, &fractal->img.endian);

    data_init(fractal);
}