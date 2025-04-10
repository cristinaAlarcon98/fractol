#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bits_per_pix / 8));
    *(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0.0;
    z.y = 0.0;
    c.x = scale(x, -2, +2, 0, WIDTH);
    c.y = scale(y, -2, +2, 0, HEIGHT);
    i = 0;

    while (i < fractal->ilterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
        {
            color = scale(i, BLACK, WHITE, 0, fractal->ilterations);
            my_pixel_put(x, y, &fractal->img, GLOW_ORANGE);
            return;
        }
    }
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            my_mlx_pixel_put(&fractal->img, x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}