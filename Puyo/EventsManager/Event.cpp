//
//  Event.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Event.h"
Event::Event(int identifier, std::vector<void *> arguments)
{
    this->identifier = identifier;
    this->arguments = arguments;
}