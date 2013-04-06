//
//  EventCallback.cpp
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/6/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "EventCallback.h"
template<class t> EventCallback<t>::EventCallback(void * other_arg, void * this_pointer):arg(other_arg),thisPointer(this_pointer)
{
}
