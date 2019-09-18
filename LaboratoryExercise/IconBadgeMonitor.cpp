//
// Created by francesco on 02/09/19.
//

#include "IconBadgeMonitor.h"

IconBadgeMonitor::IconBadgeMonitor(Chat* sub) : subject(sub) {

}

IconBadgeMonitor::~IconBadgeMonitor() {

}

void IconBadgeMonitor::attach() {
    subject->subscribe(this);
}

void IconBadgeMonitor::detach() {
    subject->unsubscribe(this);
}

void IconBadgeMonitor::update() {
    this->draw(subject->getUnreadMessages());
}

void IconBadgeMonitor::draw(int um) {
    std::cout << "Hai " << um << " messaggi non letti" << std::endl;
}
