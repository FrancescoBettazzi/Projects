#include <iostream>
#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotifier.h"
#include "IconBadgeMonitor.h"

int main() {

    auto a = std::make_shared<User>(User("Annalisa"));
    auto f = std::make_shared<User>(User("Francesco"));
    auto b = std::make_shared<User>(User("Benedetta"));
    auto l = std::make_shared<User>(User("Lorenzo"));

    auto ch = std::make_shared<Chat>(Chat(a,b));

    a->addChat(ch);

    auto foo=Message(a,b,"I ragazzi stasera escono, andiamo con loro?"), bar = Message(b,a,"Volentieri!"), fooBar=Message(f,l,"Stasera alle 21?"), barFoo=Message(f,l,"Vengono anche le ragazze.");

    MessageNotifier messageNotifier = MessageNotifier(true, ch);
    IconBadgeMonitor iconBadgeMonitor = IconBadgeMonitor(ch);
    messageNotifier.attach();
    iconBadgeMonitor.attach();

    ch->addMessage(foo);
    foo.setRead(true);
    ch->addMessage(bar);
    ch->getUnreadMessages();  //Hai 1 messaggi non letti
    bar.setRead(true);
    ch->getUnreadMessages();  //Hai 0 messaggi non letti

    auto ch1 = std::make_shared<Chat>(Chat(f,l));

    messageNotifier = MessageNotifier(true, ch1);
    iconBadgeMonitor = IconBadgeMonitor(ch1);
    messageNotifier.attach();
    iconBadgeMonitor.attach();

    ch1->addMessage(fooBar);
    ch1->addMessage(barFoo);
    ch1->getUnreadMessages();

    fooBar.setRead(true);
    barFoo.setText("Stasera le ragazze non vengono");
    barFoo.setRead(true);
    ch1->lastMessage();
    ch1->getUnreadMessages();
}
