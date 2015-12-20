// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "Engine.h"
#include "CompileConfig.h"

#ifdef OUZEL_PLATFORM_OSX
#include "RendererOGL.h"
#endif

#ifdef OUZEL_PLATFORM_WINDOWS
#include "RendererD3D11.h"
#endif

#include "Renderer.h"
#include "Scene.h"

namespace ouzel
{
    Engine::Engine(Renderer::Driver driver, uint32_t width, uint32_t height, bool fullscreen)
    {
        switch (driver)
        {
            case Renderer::Driver::OPENGL:
                _renderer = new RendererOGL(this);
                break;
            case Renderer::Driver::DIRECT3D11:
#ifdef OUZEL_PLATFORM_WINDOWS
                _renderer = new RendererD3D11(this);
#endif
                break;
            default:
                _renderer = new Renderer(this);
                break;
        }
        
        _scene = new Scene(this);
        _scene->init();
    }
    
    Engine::~Engine()
    {
        if (_renderer) _renderer->release();
        if (_scene) _scene->release();
    }
    
    void Engine::run()
    {
        _renderer->clear();
        _scene->drawAll();
        _renderer->flush();
        
        for (EventHandler* eventHandler : _eventHandlers)
        {
            eventHandler->update();
        }
    }
    
    void Engine::addEventHandler(EventHandler* eventHandler)
    {
        std::vector<EventHandler*>::iterator i = std::find(_eventHandlers.begin(), _eventHandlers.end(), eventHandler);
        
        if (i == _eventHandlers.end())
        {
            _eventHandlers.push_back(eventHandler);
        }
    }
    
    void Engine::removeEventHandler(EventHandler* eventHandler)
    {
        std::vector<EventHandler*>::iterator i = std::find(_eventHandlers.begin(), _eventHandlers.end(), eventHandler);
        
        if (i != _eventHandlers.end())
        {
            _eventHandlers.erase(i);
        }
    }
    
    void Engine::handleEvent(const Event& event)
    {
        for (EventHandler* eventHandler : _eventHandlers)
        {
            if (!eventHandler->handleEvent(event))
            {
                break;
            }
        }
    }
}
