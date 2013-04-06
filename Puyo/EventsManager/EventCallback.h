//
//  EventObserver.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef Puyo_EventObserver_h
#define Puyo_EventObserver_h

template<class type>
class EventCallback
{
    void * arg;
    void * thisPointer;
public:
    EventCallback(void * other_arg, void * this_pointer);
    void call() {
        type * obj = static_cast<type*>(thisPointer);
        obj->RedundencyManagerCallBack(arg);
    }
};

#endif
