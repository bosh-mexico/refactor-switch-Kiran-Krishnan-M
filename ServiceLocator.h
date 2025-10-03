#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include <map>
#include <functional>

template<typename Key, typename Handler>
class ServiceLocator {
public:
    static ServiceLocator& instance() {
        static ServiceLocator locator;
        return locator;
    }

    void registerHandler(Key key, Handler handler) {
        handlers[key] = handler;
    }

    Handler getHandler(Key key, Handler defaultHandler) const {
        auto it = handlers.find(key);
        if (it != handlers.end()) {
            return it->second;
        }
        return defaultHandler;
    }

private:
    std::map<Key, Handler> handlers;
    ServiceLocator() = default;
};

#endif
