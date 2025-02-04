//
// Created by francesco on 14/09/19.
//

#include "gtest/gtest.h"
#include "../Chat.h"

auto ch = std::make_shared<Chat>(Chat("Francesco", "Annalisa"));

TEST(Chat, Chat_GetterSetter_Test) {

    ASSERT_EQ(ch->getMyName(), "Francesco");
    ASSERT_EQ(ch->getOtherName(), "Annalisa");
    ch->setMyName("Lorenzo");
    ch->setOtherName("Benedetta");
    ASSERT_EQ(ch->getMyName(), "Lorenzo");
    ASSERT_EQ(ch->getOtherName(), "Benedetta");
}

TEST (Chat, Chat_Func_Test) {
    ASSERT_NO_THROW(ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Lorenzo", "Ciao come va?"))));
    ASSERT_NO_THROW(ch->addMessage(std::make_shared<Message>(Message("Lorenzo", "Benedetta", "Tutto bene, te?"))));

    ASSERT_EQ(ch->getTextByPosition(0), "Ciao come va?");
    ASSERT_EQ(ch->getTextByPosition(1), "Tutto bene, te?");

    ASSERT_NO_THROW(ch->setReadByPosition(0));
    ASSERT_NO_THROW(ch->setTextByPosition(1, "Potrebbe andare meglio."));
    ASSERT_NE(ch->getTextByPosition(1), "Tutto bene, te?");
    ASSERT_EQ(ch->getTextByPosition(1), "Potrebbe andare meglio.");
}

TEST (Chat, Chat_Ecx_Test) {
    ASSERT_THROW(ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Annalisa", "Come va?"))), std::runtime_error);
    ASSERT_THROW(ch->setReadByPosition(5), std::out_of_range);
    ASSERT_THROW(ch->setTextByPosition(5, "Chiudiamo la conversazione qui"), std::out_of_range);
}