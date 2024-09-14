#pragma once

#include <ctime>
class Game {
    private:
        int status;
        time_t realTime;

    public:
        void set_status();
        int get_status();

        time_t get_realTime();

};

