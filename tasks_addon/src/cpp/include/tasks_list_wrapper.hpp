#pragma once

#include <napi.h>

#include "task_wrapper.hpp"

namespace tasks_addon {

class TasksListWrapper : public Napi::ObjectWrap<TasksListWrapper> {
public:
    static Napi::Function buildConstructor(Napi::Env);

    TasksListWrapper(const Napi::CallbackInfo& info);

    // JS Property Accessors
    Napi::Value getLength(const Napi::CallbackInfo& info);

    // JS Methods
    Napi::Value at(const Napi::CallbackInfo& info);
    void add(const Napi::CallbackInfo& info);
    void swap(const Napi::CallbackInfo& info);
    Napi::Value toJSON(const Napi::CallbackInfo& info);

private:
    vector<Napi::ObjectReference> m_tasksList;
};
}