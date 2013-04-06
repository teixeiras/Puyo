//
//  Event.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__Event__
#define __Puyo__Event__

#include <iostream>
#include <vector>
#include "EventCallback.h"

template <class t>
class Event
{
    int identifier;
    std::vector<EventCallback<t>> observers;
public:
    Event(int ident);
    void addObserver(EventCallback<t> obs);
    void execute();
    bool isTypeof(int identifier){
        if (this->identifier == identifier) {
            return true;
        }
        return false;
    }
    std::vector<EventCallback<t>> * getObservers(){return &observers;};
};
#endif /* defined(__Puyo__Event__) */
