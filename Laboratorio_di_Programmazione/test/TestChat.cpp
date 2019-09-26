//
// Created by francesco on 14/09/19.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Message.h"

TEST(Chat, Message) {
    auto ch = std::make_shared<Chat>(Chat("Francesco", "Annalisa"));

    ASSERT_EQ(ch->getMyName(),"Francesco");
    ASSERT_EQ(ch->getOtherName(),"Annalisa");
    ch->setMyName("Lorenzo");
    ch->setOtherName("Benedetta");
    ASSERT_EQ(ch->getMyName(),"Lorenzo");
    ASSERT_EQ(ch->getOtherName(),"Benedetta");

    ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Lorenzo", "Ciao come va?")));
    ch->addMessage(std::make_shared<Message>(Message("Lorenzo", "Benedetta", "Tutto bene, te?")));

    ASSERT_EQ(ch->getTextByPosition(0),"Ciao come va?");
    ASSERT_EQ(ch->getTextByPosition(1),"Tutto bene, te?");

    ch->setReadByPosition(0);
    ch->setTextByPosition(1,"Potrebbe andare meglio...");
    ASSERT_EQ(ch->getTextByPosition(1),"Tutto bene, te?");
    ASSERT_EQ(ch->getTextByPosition(1),"Potrebbe andare meglio...");
    ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Annalisa", "Come va?")));
    ch->setReadByPosition(5);
    ch->setTextByPosition(5, "Chiudiamo la conversazione qui");
}