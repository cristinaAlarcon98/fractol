#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\n"

typedef struct s_img
{
    void *img_ptr;    // Pointer to the image object (used by the graphics library, e.g., MLX).
    char *img_addr;   // Pointer to the actual pixel data of the image.
    int bits_per_pix; // Bits Per Pixel: how many bits are used to represent each pixel (e.g., 32 for RGBA).
    int endian;       // Endian-ness of the image data (0 for little-endian, 1 for big-endian).
    int line_len;     // Length of a single line of pixels in bytes.
} t_img;

typedef struct s_fractal
{
    void *mlx_connection;
    void *mlx_window;
    t_img img;
} t_fractal;

int ft_strcmp(char *str1, char *str2, int n);
void putstr_fd(char *str, int fd);

#endif
