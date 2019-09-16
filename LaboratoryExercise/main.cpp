#include <iostream>
#include "Chat.h"
#include "MessageNotifier.h"
#include "IconBadgeMonitor.h"

int main() {
    /*Chat Lorenzo_Luca("Lorenzo", "Luca");
    Message foo("Lorenzo", "Luca", "FOO"), bar("Luca", "Lorenzo", "BAR"), fooBar("Luca", "Lorenzo", "foo bar");
    MessageNotifier messageNotifier(true, &Lorenzo_Luca);
    IconBadgeMonitor iconBadgeMonitor(&Lorenzo_Luca);
    messageNotifier.attach();
    iconBadgeMonitor.attach();
    Lorenzo_Luca.addMessage(foo);
    Lorenzo_Luca.addMessage(bar);
    Lorenzo_Luca.addMessage(fooBar);
    try {
        Lorenzo_Luca.readMessage(2);
        Lorenzo_Luca.readMessage(5);
    }
    catch (std::out_of_range& e) {
        std::cerr << "Out of range error:" << e.what() << std::endl;
    }*/

    auto a = new User("Annalisa");
    auto f = new User("Francesco");
    auto b = new User("Benedetta");
    auto l = new User("Lorenzo");
    //
    auto ch = new Chat(a,b);
    a->addChat(ch);
    auto foo=Message(a,b,"I ragazzi stasera escono, andiamo con loro?"), bar = Message(b,a,"Volentieri!"), fooBar=Message(f,l,"Stasera alle 21?"), barFoo=Message(f,l,"Vengono anche le ragazze.");
    ch->addMessage(foo);
    foo.setRead(true);
    ch->addMessage(bar);
    ch->getUnreadMessages();
    bar.setRead(true);
    ch->getUnreadMessages();

    auto ch1 = new Chat(f,l);
    ch1->addMessage(fooBar);
    ch1->addMessage(barFoo);
    ch1->getUnreadMessages();
    fooBar.setRead(true);
    barFoo.setText("Stasera le ragazze non vengono");
    barFoo.setRead(true);
    ch1->lastMessage();
    ch1->getUnreadMessages();
    delete ch1;
    delete ch;
}