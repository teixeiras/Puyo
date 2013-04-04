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
class Event
{
    int identifier;
    std::vector<void *> arguments;
public:
    Event(int identifier, std::vector<void *> arguments);
};
#endif /* defined(__Puyo__Event__) */
