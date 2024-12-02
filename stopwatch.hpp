#pragma once
#include<chrono>

namespace Time
{
    template<typename ClockType = std::chrono::steady_clock>
    class Stopwatch
    {
        using time_point = typename ClockType::time_point;

        public:
            Stopwatch();

            void start();
            void stop();
            void pause();
            void resume();
            void reset();

            double getTime() const;
        
        private:
            time_point m_begin;
            time_point m_end;
            double m_pause_mod;

            bool m_running, m_paused;
    };

    template<typename ClockType>
    Stopwatch<ClockType>::Stopwatch() : m_begin(time_point::min()),
                                        m_end(time_point::min()),
                                        m_pause_mod(0.0f),
                                        m_running(false), m_paused(false) {}

    template<typename ClockType>
    void Stopwatch<ClockType>::start()
    {
        m_begin = ClockType::now();
        m_running = true;
    }

    template<typename ClockType>
    void Stopwatch<ClockType>::stop()
    {
        resume();

        m_end = ClockType::now();

        m_running = false;
    }

    template<typename ClockType>
    void Stopwatch<ClockType>::pause()
    {
        if(m_running && !m_paused)
        {
            m_end = ClockType::now();
            m_paused = true;
        }
    }

    template<typename ClockType>
    void Stopwatch<ClockType>::resume()
    {
        if(m_running && m_paused)
        {
            std::chrono::duration<double> pause_elapsed = ClockType::now() - m_end;
            m_pause_mod += pause_elapsed.count();

            m_paused = false;
        }
    }

    template<typename ClockType>
    void Stopwatch<ClockType>::reset()
    {
        m_begin = time_point::min();
        m_end = time_point::min();
        m_pause_mod = 0.0f;
        m_running = false;
        m_paused = false;
    }

    template<typename ClockType>
    double Stopwatch<ClockType>::getTime() const
    {
        std::chrono::duration<double> elapsed = (m_running && !m_paused? ClockType::now() : m_end) - m_begin;

        return elapsed.count() - m_pause_mod;
    }
}
