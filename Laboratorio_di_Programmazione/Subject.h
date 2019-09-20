//
// Created by francesco on 30/08/19.
//
#include <iostream>
#include <vector>
#include <list>
#include "Observer.h"
#include <memory>

#ifndef LABORATORYEXERCISE_SUBJECT_H
#define LABORATORYEXERCISE_SUBJECT_H


class Subject {
public:
    virtual ~Subject() {}

    virtual void subscribe(std::shared_ptr<Observer> obj) = 0;

    virtual void unsubscribe(std::shared_ptr<Observer> obj) = 0;

    virtual void notify() = 0;
};


#endif //LABORATORYEXERCISE_SUBJECT_H
