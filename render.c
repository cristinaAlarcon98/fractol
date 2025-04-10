#include "fractol.h"

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;

    z.x = 0.0;
    z.y = 0.0;

    c.x = scale(x, -2, +2, 0, WIDTH);
    c.y = scale(y, -2, +2, 0, HEIGHT);

    while (condition)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
        {
            my_pixel_put();
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
}