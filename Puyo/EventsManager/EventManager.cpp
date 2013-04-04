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
    observers = new std::vector<EventObserver *>();
}

void EventManager::addObserver(EventObserver * observer)
{
    observers->push_back(observer);
}

void EventManager::sendEvent(Event * event)
{
    std::vector<EventObserver *>::iterator observersIt = observers->begin();
    for (;observersIt != observers->end(); observersIt++) {
        
    }
}