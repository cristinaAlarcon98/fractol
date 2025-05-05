#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\n"
#define WIDTH 700
#define HEIGHT 700

// Basic colors
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x020765

// Psychedelic colors
#define NEON_PINK 0xFF1493
#define ELECTRIC_LIME 0xCCFF00
#define ACID_PURPLE 0xBF00FF
#define LASER_BLUE 0x00FFFF
#define PSY_RED 0xFF2400
#define GLOW_ORANGE 0xFF6600
#define HYPER_TEAL 0x00FFC8
#define ULTRA_VIOLET 0x6F00FF
#define FUNKY_YELLOW 0xFFFF66
#define DREAM_GREEN 0x66FF66

typedef struct s_img
{
    void *img_ptr;    // Pointer to the image object (used by the graphics library, e.g., MLX).
    char *pixel_ptr;  // Pointer to the actual pixel data of the image.
    int bits_per_pix; // Bits Per Pixel: how many bits are used to represent each pixel (e.g., 32 for RGBA).
    int endian;       // Endian-ness of the image data (0 for little-endian, 1 for big-endian).
    int line_len;     // Length of a single line of pixels in bytes.
} t_img;

typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_img img;
    double scape_value;
    int ilterations;
    double shift_x;
    double shift_y;
    double zoom;
    double julia_x;
    double julia_y;
} t_fractal;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

int ft_strcmp(char *str1, char *str2, int n);
void putstr_fd(char *str, int fd);
void fractal_init(t_fractal *fractal);
void fractal_render(t_fractal *fractal);
double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex square_complex(t_complex z);
t_complex sum_complex(t_complex z1, t_complex z2);
int key_handler(int keysym, t_fractal *fractal);
int close_handler(t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);
double alphtodoubl(char *s);

#endif
