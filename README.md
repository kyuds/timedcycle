# timedcycle
C++ Library for Periodic, Resettable Events

There are situations when a timed event needs to happen, cyclically. Consider a scenario where a machine receives regular ping messages from another machine, and if the machine doesn't receive a ping message for 10 seconds, then they should prompt a message. In this case, there is a regular task, which is alerting that it wasn't pinged, that occurs every 10 seconds (every new round). Also, this regular task needs to be "reset", that is whenever a new ping message comes, the timer needs to be reset. 

```cpp
class TimedCycle {
    public:
        TimedCycle(int _interval);
        virtual ~TimedCycle();

        virtual void task() = 0;
        void reset();
    ...
};
```
The `TimedCycle` api basically provides a way to "reset" the timer on a periodic task. Inherit the `TimedCycle` class and override the `task` virtual function. 
