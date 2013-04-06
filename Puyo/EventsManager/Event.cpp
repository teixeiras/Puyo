//
//  Event.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Event.h"
template<class t> Event<t>::Event(int identifier)
{
    this->identifier = identifier;
}

template<class t> void Event<t>::addObserver(EventCallback<t> obs)
{
    this->observers.push_back(obs);
}

template<class t> void Event<t>::execute()
{
    typename std::vector<EventCallback<t>>::iterator observersIt =observers.begin();
    for (;observersIt != observers.end(); observersIt++) {
        EventCallback<t> ev = * observersIt;
        ev.call();
    }
}
