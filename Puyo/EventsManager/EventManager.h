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
#include "EventCallback.h"
#include "Event.h"

#define END_OF_GAME 1

class EventManager
{
    std::vector<Event<class t>> events;
public:
    EventManager();
    void sendEvent(int identifier);
    Event<class t> * getEvent(int identifier);
};
#endif /* defined(__Puyo__EventManager__) */
