#include <iostream>
#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotifier.h"
#include "IconBadgeMonitor.h"

int main() {
    auto a = std::make_shared<User>(User("Francesco"));
    auto b = std::make_shared<User>(User("Benedetta"));

    try {
        a->addChat(std::make_shared<Chat>(Chat(a->getName(), b->getName())));
        b->addChat(a->findChat(b));
    } catch(std::runtime_error &e) {
        std::cerr << "Messaggio di errore: runtime_error\n" << e.what() << std::endl;
    }

    auto iconBadgeMonitor = std::make_shared<IconBadgeMonitor>(IconBadgeMonitor(a->findChat(b)));
    auto messageNotifier = std::make_shared<MessageNotifier>(MessageNotifier(true, a->findChat(b)));

    iconBadgeMonitor->attach();
    messageNotifier->attach();

    try {
        a->sendMessage(b,std::make_shared<Message>(Message(a->getName(),b->getName(),"Stasera c'è la partita di calcetto, vuoi venire a fare il tifo?")));
        b->sendMessage(a,std::make_shared<Message>(Message(b->getName(), a->getName(),"Vengo molto volentieri!")));
        b->setReadByPosition(a,0);
        a->sendMessage(b,std::make_shared<Message>(a->getName(),b->getName(),"Allora ti aspetto!"));
        a->setReadByPosition(b,1);
        a->setReadByPosition(b,2);
    } catch(std::runtime_error&e) {
        std::cerr << "Messaggio di errore2: runtime_error\n" << e.what() << std::endl;
    }
}
