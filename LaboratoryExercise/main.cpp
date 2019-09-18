#include <iostream>
#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotifier.h"
#include "IconBadgeMonitor.h"

int main() {

    auto a = new User("Annalisa");
    auto f = new User("Francesco");
    auto b = new User("Benedetta");
    auto l = new User("Lorenzo");

    auto ch = new Chat(a,b);

    a->addChat(ch);

    auto foo=Message(a,b,"I ragazzi stasera escono, andiamo con loro?"), bar = Message(b,a,"Volentieri!"), fooBar=Message(f,l,"Stasera alle 21?"), barFoo=Message(f,l,"Vengono anche le ragazze.");

    MessageNotifier messageNotifier = MessageNotifier(true, ch);
    IconBadgeMonitor iconBadgeMonitor = IconBadgeMonitor(ch);
    messageNotifier.attach();
    iconBadgeMonitor.attach();

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

    delete a;
    delete b;
    delete f;
    delete l;
    delete ch;
    delete ch1;
}
