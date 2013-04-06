//
//  EventManager.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "EventManager.h"

EventManager::EventManager()
{
 
}


void EventManager::sendEvent(int identifier)
{
    

}
Event<class t> *EventManager::getEvent(int identifier)
{
    std::vector<Event<class t>>::iterator observersIt = this->events.begin();
    for (;observersIt != events.end(); observersIt++) {
        Event<class t> event = * observersIt;
        if (event.isTypeof(identifier)) {
            return &(*observersIt);
        }
    }
    return NULL;
}