# Stopwatch

A high-precision, flexible stopwatch utility for measuring time intervals in C++ using `std::chrono`. This implementation supports starting, stopping, pausing, resuming, and resetting the timer, making it ideal for benchmarking and profiling tasks in various applications.

---

## Features

- High-Precision Timing: Built on `std::chrono` for accurate time measurements.
- Full Control: Start, stop, pause, resume, and reset the stopwatch.
- Customizable Clock: Supports clocks from `<chrono>` library, such as `system_clock`, `steady_clock`, or any compatible clock type. By default using `steady_clock`.
- Simple Interface: Easy to integrate and use in your C++ projects.
- Pause Handling: Includes support for accurate timing even during pauses.

---

## Usage

### Requirements
- C++17 or later
- Compatible compilers (e.g., g++, MSVC)

### Including the Stopwatch in Your Project

Clone/download it, paste to your codebase include folder and include to your code:

```cpp
#include "stopwatch.hpp"
```

## Basic Example

```cpp
#include "stopwatch.hpp"
#include <iostream>
#include <thread>

int main() {
    using namespace std::chrono_literals;

    Time::Stopwatch<> stopwatch; // Default to steady_clock

    stopwatch.start();

    std::this_thread::sleep_for(2s);

    stopwatch.pause();

    std::this_thread::sleep_for(5s);

    stopwatch.resume();

    std::this_thread::sleep_for(1s);

    stopwatch.stop();

    std::cout << "Elapsed time: " << stopwatch.getTime() << " seconds" << std::endl;

    return 0;
}
```

---

### License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
