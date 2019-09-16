//
// Created by francesco on 31/08/19.
//

#ifndef LABORATORYEXERCISE_SCHEDULE_H
#define LABORATORYEXERCISE_SCHEDULE_H


class Schedule {
public:
    Schedule(int s, int m, int h) : sec(s), min(m), hour(h) {}
private:
    int sec;
    int min;
    int hour;
};


#endif //LABORATORYEXERCISE_SCHEDULE_H
