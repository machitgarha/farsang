# Farsang

C++ wrapper for GSL (i.e. GNU Scientific Library).

## Implemented

-   Exception mechanism
-   Random generators
-   Random Distributions
    -   Gamma
    -   Gaussin
    -   Poisson

## Build

### Requirements

-   CMake
-   Makefile
-   C++ Compiler (GCC is recommended)

#### Supported Platforms

-   Linux

### Shared

Prepare CMake:

```
cmake . -B build
```

Make it:

```
make -C build
```

You'll have an `.so` file. Use it wherever you need.

## Documentation?

As you might know, [a comprehensive documentation is available for GSL](https://www.gnu.org/software/gsl/doc/html/index.html). If you are familiar with that, then you should understand how Farsang works in a short time.

Currently, there is no documentation available for Farsang. However, if you are interested in writing one, create an issue or pull request, we will appreciate your effort.

## Contributions?

Great!

You're pretty much welcomed to contribute to this project, either by creating an issue or a pull request.

### Priorities

Consider these as first things to contribute:

-   Adding tests.
-   Improving code documentation.
-   Implementing unimplemented stuff from GSL.
-   Port for other platforms.

## License

Well, just like GSL itself, Farsang is under [GPLv3](./LICENSE.md).
