//
// Created by francesco on 30/08/19.
//

#include "Chat.h"

Chat::Chat(std::string se, std::string re) : myName(se), otherName(re) {

}

Chat::~Chat() {
    for (auto obs:observers)
        unsubscribe(obs);
}

void Chat::addMessage(const std::shared_ptr<Message> newMsg) {
    if ((myName == newMsg->getReceiver() || myName == newMsg->getSender()) && (otherName == newMsg->getSender() || otherName == newMsg->getReceiver())) {
        messages.push_back(newMsg);
        if (myName == newMsg->getReceiver())
            this->notify();
        else if (otherName == newMsg->getReceiver())
            this->notify2();
    }
    else
        throw std::runtime_error("Error in sender or receiver");
}

const std::shared_ptr<Message> &Chat::lastMessage() const {
    return messages.back();
}

void Chat::setReadByPosition(int i) {
    if (i >= 0 && i < messages.size()) {
        if (messages[i]->getSender() == otherName) {
            std::cout << "Sender: " << messages[i]->getSender() << ", Receiver : " << messages[i]->getReceiver() << std::endl;
            std::cout << "Text: " << messages[i]->getText() << "\n" << std::endl;
            messages[i]->setRead(true);
            this->notify();
        }
        else if(messages[i]->getSender() == myName) {
            std::cout << "Sender: " << messages[i]->getSender() << ", Receiver : " << messages[i]->getReceiver() << std::endl;
            std::cout << "Text: " << messages[i]->getText() << "\n" << std::endl;
            messages[i]->setRead(true);
            this->notify2();
        }
    } else
        throw std::out_of_range("The message is not present");
}

int Chat::getUnreadMessages() const {
    int i = 0;
    for (const auto &message:messages) {
        if (message->getReceiver() == myName) {
            if (!message->isRead())
                i++;
        }
    }
    return i;
}

int Chat::getUnreadMessages2() const {
    int i = 0;
    for (const auto &message:messages) {
        if (message->getReceiver() == otherName) {
            if (!message->isRead())
                i++;
        }
    }
    return i;
}

void Chat::notify() {
    for (const auto &observer:observers)
        observer->update();
}


void Chat::notify2() {
    for (const auto &observer:observers)
        observer->update2();
}

void Chat::subscribe(std::shared_ptr<Observer> obj) {
    observers.push_back(obj);
}

void Chat::unsubscribe(std::shared_ptr<Observer> obj) {
    observers.remove(obj);
}

void Chat::setTextByPosition(int pos, std::string text) {
    this->messages[pos]->setText(text);
}

const std::string &Chat::getMyName() const {
    return myName;
}

void Chat::setMyName(const std::string &myName) {
    Chat::myName = myName;
}

const std::string &Chat::getOtherName() const {
    return otherName;
}

void Chat::setOtherName(const std::string &otherName) {
    Chat::otherName = otherName;
}

const std::string &Chat::getTextByPosition(int pos) {
    return messages[pos]->getText();
}


