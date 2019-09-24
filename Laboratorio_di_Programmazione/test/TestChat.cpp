//
// Created by francesco on 14/09/19.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Message.h"

TEST(Chat, Message) {
    auto ch = std::make_shared<Chat>(Chat("Francesco", "Annalisa"));

    ch->getMyName();
    ch->getOtherName();
    ch->setMyName("Lorenzo");
    ch->setOtherName("Benedetta");
    ch->getMyName();
    ch->getOtherName();

    ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Lorenzo", "Ciao come va?")));
    ch->addMessage(std::make_shared<Message>(Message("Lorenzo", "Benedetta", "Tutto bene, te?")));

    ch->setReadByPosition(0);
    ch->setTextByPosition(1,"Potrebbe andare meglio...");
    ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Annalisa", "Come va?")));
    ch->setReadByPosition(5);
    ch->setTextByPosition(5, "Chiudiamo la conversazione qui");
}