# Fractol
One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

```shell
make && ./fractol <type> <options>
```

Types are :
* ```1```: Mandelbrot fractal
* ```2```: Julia fractal
* ```3```: Celtic Mandelbrot fractal
* ```4```: Burning Ship fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol J 0.285 -0.01
```
