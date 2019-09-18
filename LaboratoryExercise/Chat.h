//
// Created by francesco on 30/08/19.
//

#ifndef LABORATORYEXERCISE_CHAT_H
#define LABORATORYEXERCISE_CHAT_H

#include "Subject.h"
#include "Observer.h"
#include "Message.h"
#include "User.h"

class Message;
class User;
class Chat : public Subject {
public:
    explicit Chat(User *u1, User *u2);

    ~Chat();

    void addMessage(const Message &newMsg);

    const Message &lastMessage() const;

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
    std::list<Observer *> observers;
    std::vector<Message> messages;  //std::shared_ptr<Message>
    User *myName; //std::shared_ptr<User>
    User *otherName;
};


#endif //LABORATORYEXERCISE_CHAT_H
