#include <SDL2/SDL.h>

#include "timer.hpp"

//The frame rate regulator
Timer timer;





Timer::Timer() {
    //Initialize the variables
    frame=0;
    initTicks = 0;
    loopTicks = 0;
    framelimit = 0;
    last_loop_duration = 0;
}

void Timer::start() {
    //Get the current clock time
    initTicks = SDL_GetTicks();
    loopTicks = SDL_GetTicks();
}

void Timer::tick() {
    //Increment the frame counter
    frame++;

    //If we want to cap the frame rate
    if( ( framelimit > 0 ) && (get_loop_ticks() < 1000 / framelimit) )
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / framelimit ) - get_loop_ticks() );
    }

    last_loop_duration = get_loop_ticks();
    loopTicks = SDL_GetTicks();
}

int Timer::get_start_ticks() {
    //Return the time since start
    return SDL_GetTicks() - initTicks;
}

int Timer::get_loop_ticks() {
    // Get the time since last loop
    return SDL_GetTicks() - loopTicks;
}

float Timer::get_fps () {
    return 1000.0/last_loop_duration;
}

float Timer::per_second_multiplier() {
    return last_loop_duration/1000.0;
}
