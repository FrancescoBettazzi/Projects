//
// Created by francesco on 02/09/19.
//

#ifndef LABORATORYEXERCISE_MESSAGENOTIFIER_H
#define LABORATORYEXERCISE_MESSAGENOTIFIER_H


#include "Observer.h"
#include "Chat.h"

class Chat;
class MessageNotifier : public Observer {
public:
    MessageNotifier(bool a, Chat* sub);
    virtual ~MessageNotifier();

    void attach() override;

    void detach() override;

    void update() override;

    void draw(std::string x, std::string y);

private:
    bool active;
    Chat* subject;
};


#endif //LABORATORYEXERCISE_MESSAGENOTIFIER_H
