# Picture to ASCII converter
Basic picture to ASCII converter.

## Compilation
The programm relies on [_OpenCV_](https://opencv.org/releases/) and can be compiled using the [Makefile](Makefile).

## Usage
The converter takes an input picture and converts it to an output textfile with a predefined width of characters. \
If no arguments are given, the _**input file**_ evaluates to **_"input.png"_**, the _**width**_ stays the same as the _**input files width**_ and the _**output file**_ evaluates to **_"output.txt"_**. \
To use the programm after compialtion run: 
```bash
./main.exe exampleinput.png 600 exampleoutput.txt
```
