#pragma once

// AI GENERATED !!!!
#define MAKE_SINGLETON(classname)                    \
public:                                              \
    static classname& get() {                        \
        static classname instance;                   \
        return instance;                             \
    }                                                 \
private:                                             \
    classname() = default;                           \
    classname(const classname&) = delete;            \
    classname& operator=(const classname&) = delete; \
    classname(classname&&) = delete;                 \
    classname& operator=(classname&&) = delete;
