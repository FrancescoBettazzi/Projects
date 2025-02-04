//
// Created by francesco on 02/09/19.
//

#ifndef LABORATORYEXERCISE_ICONBADGEMONITOR_H
#define LABORATORYEXERCISE_ICONBADGEMONITOR_H


#include "Observer.h"
#include "Chat.h"
#include <memory>

class IconBadgeMonitor : public Observer {
public:
    IconBadgeMonitor(std::shared_ptr<Chat> sub);
    virtual ~IconBadgeMonitor();

    void attach() override;

    void detach() override;

    void update() override;

    void update2() override;

    void draw(int um);

    void draw2(int num);

private:
    std::shared_ptr<Chat> subject;
};


#endif //LABORATORYEXERCISE_ICONBADGEMONITOR_H
