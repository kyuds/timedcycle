#ifndef TIMEDCYCLE
#define TIMEDCYCLE

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

class TimedCycle {
    public:
        TimedCycle(int _interval);
        virtual ~TimedCycle();

        virtual void task() = 0;
        void reset();
    
    private:
        static void thread_func(TimedCycle * t);
        bool should_die();

        std::chrono::milliseconds interval;
        std::thread worker;
        std::mutex cv_m;
        std::condition_variable cv_c;
        std::atomic<bool> alive;
};

#endif // TIMEDCYCLE
