//
// Created by francesco on 30/08/19.
//

#ifndef LABORATORYEXERCISE_CHAT_H
#define LABORATORYEXERCISE_CHAT_H

#include "Subject.h"
#include "Observer.h"
#include "Message.h"
#include "User.h"
#include <list>
#include <vector>
#include <memory>

class Chat : public Subject {
public:
    explicit Chat(std::shared_ptr<User> u1, std::shared_ptr<User> u2);

    ~Chat();

    void addMessage(const Message &newMsg);

    const Message lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    void subscribe(std::shared_ptr<Observer> obj) override;

    void unsubscribe(std::shared_ptr<Observer> obj) override;

    void notify() override;

    const std::shared_ptr<User> &getMyName() const;

    void setMyName(const std::shared_ptr<User> &myName);

    const std::shared_ptr<User> &getOtherName() const;

    void setOtherName(const std::shared_ptr<User> &otherName);

private:
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<Message> messages;  //std::shared_ptr<Message>
    std::shared_ptr<User> myName; //std::shared_ptr<User>
    std::shared_ptr<User> otherName;
};


#endif //LABORATORYEXERCISE_CHAT_H
