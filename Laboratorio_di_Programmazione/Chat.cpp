//
// Created by francesco on 30/08/19.
//

#include "Chat.h"

Chat::Chat(std::shared_ptr<User> u1, std::shared_ptr<User> u2) : myName(u1), otherName(u2) {

}

Chat::~Chat() {
    for (auto obs:observers)
        unsubscribe(obs);
}

void Chat::addMessage(const Message &newMsg) {
    if ((myName->getName() == newMsg.getReceiver() || myName->getName() == newMsg.getSender()) &&
        (otherName->getName() == newMsg.getSender() || otherName->getName() == newMsg.getReceiver()))
        messages.push_back(newMsg);
    if (myName->getName() == newMsg.getReceiver())
        this->notify();
}

const Message Chat::lastMessage() const {
    return messages.back();
}

void Chat::readMessage(int i) {
    if (i > 0 && i < messages.size()) {
        if (messages[i].getSender() == myName->getName()) {
            messages[i].setRead(true);
            this->notify();
        }
    } else
        throw std::out_of_range("out of range");
}

int Chat::getUnreadMessages() const {
    int i = 0;
    for (const auto &message:messages) {
        if (message.getReceiver() == myName->getName()) {
            if (!message.isRead())
                i++;
        }
    }
    return i;
}

void Chat::notify() {
    for (const auto observer:observers)
        observer->update();
}

void Chat::subscribe(std::shared_ptr<Observer> obj) {
    observers.push_back(obj);
}

void Chat::unsubscribe(std::shared_ptr<Observer> obj) {
    observers.remove(obj);
}

const std::shared_ptr<User> &Chat::getMyName() const {
    return myName;
}

void Chat::setMyName(const std::shared_ptr<User> &myName) {
    Chat::myName = myName;
}

const std::shared_ptr<User> &Chat::getOtherName() const {
    return otherName;
}

void Chat::setOtherName(const std::shared_ptr<User> &otherName) {
    Chat::otherName = otherName;
}
