//
// Created by francesco on 30/08/19.
//
#include <iostream>
#include "Schedule.h"
#include "User.h"

#ifndef LABORATORYEXERCISE_MESSAGE_H
#define LABORATORYEXERCISE_MESSAGE_H

class Message {
public:
    explicit Message(User* se, User* re, std::string te, bool r=false) : sender(se->getName()), receiver(re->getName()), text(te), read(r), schedule(Schedule(0,0,0)) {}

    bool isRead() const {
        return read;
    }

    void setRead(bool read) {
        Message::read = read;
    }

    const std::string &getSender() const {
        return sender;
    }

    void setSender(const std::string &sender) {
        Message::sender = sender;
    }

    const std::string &getReceiver() const {
        return receiver;
    }

    void setReceiver(const std::string &receiver) {
        Message::receiver = receiver;
    }

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        Message::text = text;
    }

private:
    bool read;
    std::string sender;
    std::string receiver;
    std::string text;
    Schedule schedule;
};


#endif //LABORATORYEXERCISE_MESSAGE_H
