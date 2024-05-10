#ifndef STOPWATCH_H
#define STOPWATCH_H
#include<chrono>

namespace Time
{
    typedef std::chrono::steady_clock::time_point reference_point;
    typedef std::chrono::duration<double> duration;

    class Stopwatch
    {
        private:
            reference_point begin, end;
            bool running;
        
        public:
            Stopwatch() : running(false) {}

            void start()
            {
                begin = std::chrono::steady_clock::now();
                running = true;
            }

            void stop()
            {
                end = std::chrono::steady_clock::now();
                running = false;
            }

            double getRuntime()
            {
                if(running) return -1.0;

                duration elapsed_seconds = end - begin;
                return elapsed_seconds.count();
            }
    };
}
#endif