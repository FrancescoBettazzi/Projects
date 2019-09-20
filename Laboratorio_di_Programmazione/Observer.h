//
// Created by francesco on 30/08/19.
//
#include <iostream>
#include <vector>
#include <list>

#ifndef LABORATORYEXERCISE_OBSERVER_H
#define LABORATORYEXERCISE_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};


#endif //LABORATORYEXERCISE_OBSERVER_H
