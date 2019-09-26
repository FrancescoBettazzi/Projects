//
// Created by francesco on 25/09/19.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Message.h"
#include "../User.h"

TEST(User, TestUser) {
    auto a = std::make_shared<User>(User("Francesco"));
    auto b = std::make_shared<User>(User("Benedetta"));
    auto c = std::make_shared<User>(User("Lorenzo"));

    ASSERT_EQ(a->getName(), "Francesco");
    b->addChat(std::make_shared<Chat>(Chat(b->getName(), a->getName())));
    a->addChat(b->findChat(a));
    b->sendMessage(a,std::make_shared<Message>(Message(b->getName(),a->getName(),"Ciao come va?")));
    a->sendMessage(b,std::make_shared<Message>(Message(b->getName(),a->getName(),"Tutto bene, tu?")));
    b->sendMessage(a,std::make_shared<Message>(Message(b->getName(),a->getName(),"Bene grazie, volevo invitarti al mio diciottesimo")));
    a->sendMessage(b,std::make_shared<Message>(Message(b->getName(),a->getName(),"Sarò presente!")));
    a->setReadByPosition(b,0);
    b->setReadByPosition(a,1);
    a->setTextByPosition(b,3,"Ti faccio sapere al più presto");
    ASSERT_EQ(b->getTextByPosition(b,3), "Ti faccio sapere al più presto");
    a->setTextByPosition(b,7,"Ciao");
    a->sendMessage(c,std::make_shared<Message>(Message(b->getName(),a->getName(),"Ciao come va?")));
}