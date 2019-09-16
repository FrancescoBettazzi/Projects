//
// Created by francesco on 14/09/19.
//

#include <gtest/gtest.h>
#include "../Message.h"

TEST(Message, TestMessage) {
    auto f = new User("Francesco");
    auto a = new User("Annalisa");
    auto b = new User("Benedetta");
    auto m = new Message(f,a,"Ciao");
    m->setSender(b->getName());
    m->getSender();
    m->setRead(true);
    m->setReceiver(f->getName());
    m->getReceiver();
    m->setText("Buongiorno!");
    m->getText();

    delete m;
    delete f;
    delete a;
    delete b;
}