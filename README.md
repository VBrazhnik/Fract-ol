# Fract'ol

![Fract'ol](/images/fract-ol.svg)

Fract'ol is a School 42 project. The purpose of this project is to create fractal renderer.

Note that **macOS is only supported**.

[`fract_ol.en.pdf`](/fract_ol.en.pdf) is the task file.

## Wiki

You can check [wiki-pages](../../wiki/) if you want to read detailed explanations and tips. Wiki-pages were written **in Russian**.

## How to clone?

This repository includes submodule. So if you want to clone it, you can use the following command:

```
git clone --recurse-submodules <repository url>
```

If you will use `git clone <repository url>` instead of, you will get the empty `libft` folder.

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## How to run program?

You can run the project with the following command:

```
./fractol <name>
```

For example, you can specify Mandelbrot fractal:

```
./fractol Mandelbrot
```

![Mandelbrot](/images/mandelbrot.png)

Multi-window mode is also supported. For example, you can run the following command to launch two windows:

```
./fractol <name> <name>
```

You can specify up to 10 fractal names for one launch.

There are available the following fractals:

* Mandelbrot
* Julia
* Burning Ship
* Mandelbar
* Celtic Mandelbrot
* Celtic Mandelbar
* Celtic Perpendicular
* Perpendicular Mandelbrot
* Perpendicular Burning Ship
* Perpendicular Buffalo

Note that for a-few-word names you must use quotes:

```
./fractol "Perpendicular Burning Ship"
```

## Controls

You can use H key for the help menu which contains a list of controls.

![Controls](/images/controls.png)
