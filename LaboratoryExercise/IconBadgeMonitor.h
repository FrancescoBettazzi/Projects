//
// Created by francesco on 02/09/19.
//

#ifndef LABORATORYEXERCISE_ICONBADGEMONITOR_H
#define LABORATORYEXERCISE_ICONBADGEMONITOR_H


#include "Observer.h"
#include "Chat.h"

class IconBadgeMonitor : public Observer {
public:
    IconBadgeMonitor(Chat* sub);
    virtual ~IconBadgeMonitor();

    void attach() override;

    void detach() override;

    void update() override;

    void draw(int um);

private:
    Chat* subject;
};


#endif //LABORATORYEXERCISE_ICONBADGEMONITOR_H
