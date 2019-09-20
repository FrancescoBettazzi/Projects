//
// Created by francesco on 14/09/19.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../Chat.h"
#include "../Message.h"

TEST(Chat, Message) {
    auto f = std::make_shared<User>(User("Francesco"));
    auto a = std::make_shared<User>(User("Annalisa"));
    auto c = std::make_shared<Chat>(Chat(f,a));
    c->addMessage(Message(f,a,"Per capodanno andiamo al mare, vieni?"));
    c->addMessage(Message(a,f,"Ti faccio sapere"));
    c->getUnreadMessages();
    c->readMessage(1);
    c->getUnreadMessages();
    c->lastMessage();
}