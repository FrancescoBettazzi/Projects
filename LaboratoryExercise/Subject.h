//
// Created by francesco on 30/08/19.
//
#include "Observer.h"

#ifndef LABORATORYEXERCISE_SUBJECT_H
#define LABORATORYEXERCISE_SUBJECT_H


class Subject {
public:
    virtual ~Subject() {}
    virtual void subscribe(Observer* obj) = 0;
    virtual void unsubscribe(Observer* obj) = 0;
    virtual void notify() = 0;
};


#endif //LABORATORYEXERCISE_SUBJECT_H
