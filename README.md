# Stopwatch
Simple tool for count time between two points in time used standard library chrono to get value in seconds of 2 reference points.

## Instalation
Throw it in your code folder and include on top of your code:
```cpp
#include"stopwatch.hpp"
```
## Usage
stopwatch header has class Stopwatch in Time namespace which you need to declare first to use it
```cpp
Time::Stopwatch myStopwatch;
```
After you can use .start() and .stop() methods to create an reference points in time of execution code.
And after stop the stopwatch execute .getRuntime() method to get double value of delta time of reference points. If you not stop or started the stopwatch it returns -1 for your time execution.

It clears off begin and end to zero after giving you delta of time. So it can be reused multiple times.

## Example
```cpp
void fun()
{
  Time::Stopwatch myStopwatch;

  myStopwatch.start();
  //code to execute

  //...

  myStopwatch.stop();

  std::cout<<"Function executed in "<<myStopwatch.getRuntime()<<" s.\n";
}
```
