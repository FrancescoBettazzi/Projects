//
// Created by francesco on 30/08/19.
//

#ifndef LABORATORYEXERCISE_CHAT_H
#define LABORATORYEXERCISE_CHAT_H


#include "Subject.h"
#include "Message.h"
#include "User.h"

class User;
class Chat : public Subject {
public:
    Chat(User* u1, User* u2);
    ~Chat();

    void addMessage(const Message& newMsg);

    const Message& lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    void subscribe(Observer *obj) override;

    void unsubscribe(Observer *obj) override;

    void notify() override;

    User *getMyName() const;

    void setMyName(User *myName);

    User *getOtherName() const;

    void setOtherName(User *otherName);

private:
    std::list<Observer*> observers;
    std::vector<Message> messages;
    User* myName;
    User* otherName;
};


#endif //LABORATORYEXERCISE_CHAT_H
