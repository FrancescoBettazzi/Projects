//
// Created by francesco on 02/09/19.
//

#include "MessageNotifier.h"

MessageNotifier::MessageNotifier(bool a, Chat *sub) : active(a), subject(sub) {

}

MessageNotifier::~MessageNotifier() {

}

void MessageNotifier::attach() {
    subject->subscribe(this);
}

void MessageNotifier::detach() {
    subject->unsubscribe(this);
}

void MessageNotifier::update() {
    if(active)
        this->draw(subject->lastMessage().getSender(), subject->lastMessage().getText().substr(0,100));
}

void MessageNotifier::draw(std::string x, std::string y) {
    std::cout << "Ultimo messaggio da parte di" << x << ": " << y << "..." << std::endl;
}
