//
// Created by francesco on 14/09/19.
//

#include "gtest/gtest.h"
#include "../Chat.h"

TEST(Chat, Message) {
    auto f = new User("Francesco");
    auto a = new User("Annalisa");
    auto c = new Chat(f,a);
    c->addMessage(Message(f,a,"Per capodanno andiamo al mare, vieni?"));
    c->addMessage(Message(a,f,"Ti faccio sapere"));
    c->getUnreadMessages();
    c->readMessage(1);
    c->getUnreadMessages();
    c->lastMessage();

    delete c;
}