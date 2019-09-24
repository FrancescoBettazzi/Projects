//
// Created by francesco on 30/08/19.
//


#ifndef LABORATORYEXERCISE_MESSAGE_H
#define LABORATORYEXERCISE_MESSAGE_H

#include <iostream>
#include <memory>
#include "Schedule.h"

class Message {
public:
    explicit Message(std::string se, std::string re, std::string te, bool r = false) : sender(se),
                                                                           receiver(re), text(te), read(r),
                                                                           schedule(Schedule(0, 0, 0)) {

    }

    bool isRead() const {
        return read;
    }

    void setRead(bool read = true) {
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

    bool operator==(const std::shared_ptr<Message> &right) const {
        return (right->getText() == this->getText() && right->getSender() == this->getSender() && right->getReceiver() == this->getReceiver() && right->isRead() == this->isRead());
    }

    bool operator!=(const std::shared_ptr<Message> &right) const {
        return !(right == std::make_shared<Message>(*this));
    }
private:
    bool read;
    std::string sender;
    std::string receiver;
    std::string text;
    Schedule schedule;
};


#endif //LABORATORYEXERCISE_MESSAGE_H
