//
// Created by francesco on 02/09/19.
//

#include "IconBadgeMonitor.h"

IconBadgeMonitor::IconBadgeMonitor(std::shared_ptr<Chat> sub) : subject(sub) {

}

IconBadgeMonitor::~IconBadgeMonitor() {

}

void IconBadgeMonitor::attach() {
    subject->subscribe(std::make_shared<IconBadgeMonitor>(*this));
}

void IconBadgeMonitor::detach() {
    subject->unsubscribe(std::make_shared<IconBadgeMonitor>(*this));
}

void IconBadgeMonitor::update() {
    this->draw(subject->getUnreadMessages());
}

void IconBadgeMonitor::draw(int num) {
    std::cout << "Hai " << num << " messaggi non letti" << std::endl;
}
