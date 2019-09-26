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

void IconBadgeMonitor::update2() {
    this->draw2(subject->getUnreadMessages2());
}

void IconBadgeMonitor::draw(int num) {
    std::cout <<"Per " << subject->getMyName() << ": Hai " << num << " messaggi non letti" << std::endl;
}

void IconBadgeMonitor::draw2(int num) {
    std::cout <<"Per " << subject->getOtherName() << ": Hai " << num << " messaggi non letti" << std::endl;
}