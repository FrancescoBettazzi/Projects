//
// Created by francesco on 02/09/19.
//

#include "MessageNotifier.h"

MessageNotifier::MessageNotifier(bool a, std::shared_ptr<Chat> sub) : active(a), subject(sub) {

}

MessageNotifier::~MessageNotifier() {

}

void MessageNotifier::attach() {
    subject->subscribe(std::make_shared<MessageNotifier>(*this));
}

void MessageNotifier::detach() {
    subject->unsubscribe(std::make_shared<MessageNotifier>(*this));
}

void MessageNotifier::update() {
    if(active)
        this->draw(subject->lastMessage()->getSender(), subject->lastMessage()->getText().substr(0,100));
}

void MessageNotifier::update2() {
    update();
}

void MessageNotifier::draw(std::string x, std::string y) {
    std::cout << "Ultimo messaggio da parte di " << x << ": " << y << "...\n" << std::endl;
}

bool MessageNotifier::isActive() const {
    return active;
}

void MessageNotifier::setActive(bool active) {
    MessageNotifier::active = active;
}
