// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#import <UIKit/UIKit.h>
#include "ApplicationIOS.h"
#import "AppDelegate.h"

namespace ouzel
{
    ApplicationIOS::ApplicationIOS(int pArgc, char* pArgv[]):
        Application(pArgc, pArgv)
    {
        mainQueue = dispatch_get_main_queue();
    }

    bool ApplicationIOS::run()
    {
        @autoreleasepool
        {
            return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
        }

        return true;
    }

    void ApplicationIOS::execute(const std::function<void(void)>& func)
    {
        dispatch_async(mainQueue, ^{
            func();
        });
    }
}
