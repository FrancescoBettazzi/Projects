//
// Created by francesco on 14/09/19.
//

#include <gtest/gtest.h>
#include "../Message.h"

TEST(Message, TestMessage) {
    auto f = std::make_shared<User>(User("Francesco"));
    auto a = std::make_shared<User>(User("Annalisa"));
    auto b = std::make_shared<User>(User("Benedetta"));
    auto m = std::make_shared<Message>(Message(f,a,"Ciao"));
    m->setSender(b->getName());
    m->getSender();
    m->setRead(true);
    m->setReceiver(f->getName());
    m->getReceiver();
    m->setText("Buongiorno!");
    m->getText();
}