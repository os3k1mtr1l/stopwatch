#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP
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
            Stopwatch() : running(false), begin(reference_point::min()), end(reference_point::min()) {}

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
                if(running || begin == reference_point::min()) return -1.0;

                duration elapsed_seconds = end - begin;

                end = reference_point::min();
                begin = reference_point::min();
                
                return elapsed_seconds.count();
            }
    };
}
#endif
