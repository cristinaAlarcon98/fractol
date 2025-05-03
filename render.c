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
    c.x = scale(x, -2, +2, 0, WIDTH + fractal->shift_x);
    c.y = scale(y, -2, +2, 0, HEIGHT) + fractal->shift_y;
    i = 0;

    while (i < fractal->ilterations)
    {
        z = sum_complex(square_complex(z), c); // z = z^2 + c
        if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
        {
            color = scale(i, BLACK, WHITE, 0, fractal->ilterations); // Fractal shape color
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, BLACK);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1) // Set background color
                my_pixel_put(x, y, &fractal->img, 0xFFAA33);
            else
                handle_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}