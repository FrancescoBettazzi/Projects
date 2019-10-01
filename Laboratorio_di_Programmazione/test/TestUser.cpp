//
// Created by francesco on 25/09/19.
//

#include "gtest/gtest.h"
#include "../User.h"


TEST(User, User_GetterSetter_Test) {
    auto a = std::make_shared<User>(User("Francesco"));
    auto b = std::make_shared<User>(User("Benedetta"));
    auto c = std::make_shared<User>(User("Lorenzo"));

    ASSERT_EQ(a->getName(), "Francesco");
    ASSERT_EQ(b->getName(), "Benedetta");
    ASSERT_NO_THROW(b->addChat(std::make_shared<Chat>(Chat(b->getName(), a->getName()))));
    ASSERT_NO_THROW(a->addChat(b->findChat(a)));
    ASSERT_NO_THROW(b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "Ciao come va?"))));
    ASSERT_NO_THROW(a->sendMessage(b, std::make_shared<Message>(Message(b->getName(), a->getName(), "Tutto bene, tu?"))));
    ASSERT_NO_THROW(b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "Bene grazie, volevo invitarti al mio diciottesimo"))));
    ASSERT_NO_THROW(a->sendMessage(b, std::make_shared<Message>(Message(b->getName(), a->getName(), "Sarò presente!"))));
    ASSERT_NO_THROW(a->setReadByPosition(b, 0));
    ASSERT_NO_THROW(b->setReadByPosition(a, 1));
    ASSERT_NO_THROW(a->setTextByPosition(b, 3, "Ti faccio sapere al più presto"));
    ASSERT_EQ(b->getTextByPosition(b, 3), "Ti faccio sapere al più presto");
    ASSERT_THROW(a->setTextByPosition(b, 7, "Ciao"), std::out_of_range);
    ASSERT_THROW(a->sendMessage(c, std::make_shared<Message>(Message(b->getName(), a->getName(), "Ciao come va?"))), std::runtime_error);
};