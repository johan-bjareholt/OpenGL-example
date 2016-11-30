#pragma once

class Timer;

//The frame rate regulator
extern Timer timer;

class Timer {
    private:
    //
    int frame;
    // The clock time since timer started
    int initTicks;
    // The clock time since last game loop
    int loopTicks;
    //
    int last_loop_duration;
    // Framecap
    int framelimit;

    public:
        //Initializes variables
        Timer();

        //The various clock actions
        void start();
        void tick();

        //Gets the timer's time since start
        int get_start_ticks();
        int get_loop_ticks();

        // Gets the fps
        float get_fps();

        float per_second_multiplier();
};
