# Fractol
One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

```shell
make && ./fractol <names> <options>  || ./fractol <names> <options>
```
Names are:
* mandelbrot, julia, celtic_mandelbrot, burning_ship

You can use these keys after execute :
* ```1```: for Mandelbrot fractal
* ```2```: for Julia fractal
* ```3```: for Celtic Mandelbrot fractal
* ```4```: for Burning Ship fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol julia 0.87 -0.13
```


New fractals in progress...
