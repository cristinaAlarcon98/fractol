# Fractol - Fractal Visualization in C

Welcome to **Fractol**, a graphical project where I implemented fractal generation and visualization in C.  
This project allowed me to explore mathematical concepts, graphical rendering, and event handling using the MiniLibX graphical library.

## Description

**Fractol** is a program that renders and displays different types of fractals, such as the **Mandelbrot set** and the **Julia set**.  
By zooming, moving, and modifying parameters in real time, the user can explore the infinite complexity of these mathematical patterns.  
This project combines mathematical formulas with pixel-level manipulation to create dynamic and interactive graphics.

## List of Implemented Features

### Fractal Sets
- **Mandelbrot Set**: Classic fractal defined by complex numbers iterated over a quadratic function.  
- **Julia Set**: Similar to Mandelbrot but allows variation of the complex constant for unique patterns.  

### User Interactions
- **Zoom**: Scroll to zoom in and out of the fractal.  
- **Move**: Use arrow keys to navigate around the fractal plane.  
- **Color Change**: Change color palettes dynamically.  
- **Parameter Adjustment**: Modify Julia set parameters with keyboard input.

### Technical Details
- Uses **MiniLibX** for graphical display.  
- Implements **complex number arithmetic** manually.  
- Supports real-time event handling for user interaction.

## Usage

Compile the project using the provided Makefile and run the program with a fractal name as an argument.

### Compilation

```bash
make
```

### Execution

```bash
./fractol mandelbrot
```
or
```bash
./fractol julia
```

### Example

Below is an example of the rendered output:


## File Structure

- **`main.c`** – Entry point, argument parsing, and program loop.  
- **`fractol.h`** – Header file with function prototypes and structures.  
- **`render.c`** – Handles drawing pixels and color calculations.  
- **`events.c`** – Manages keyboard and mouse events.  
- **`init.c`** – Initializes data and sets up the graphical window.  
- **`math_utils.c`** – Contains fractal computation functions.  
- **`string_utils.c`** – Utility functions for input parsing and strings.

## Learning Outcomes

Through this project, I learned to:
- Implement mathematical formulas to generate visual patterns.  
- Work with graphical libraries like **MiniLibX**.  
- Manage real-time events and user input in C.  
- Optimize computations for performance in recursive mathematical systems.

## Author

Developed by **Cristina Alarcón**  
[cristinaalarcon.com](https://cristinaalarcon.com)
