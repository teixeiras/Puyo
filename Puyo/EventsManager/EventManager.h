//
//  EventManager.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__EventManager__
#define __Puyo__EventManager__

#include <iostream>
#include <vector>
#include "EventObserver.h"
#include "Event.h"

class EventManager
{
    std::vector<EventObserver *> *observers;
public:
    EventManager();
    void addObserver(EventObserver * observer);
    void sendEvent(Event * event);
};
#endif /* defined(__Puyo__EventManager__) */
