#pragma once

#include <napi.h>

#include "task.hpp"

namespace tasks_addon {

using namespace std;
using namespace tasks;

class TaskWrapper : public Napi::ObjectWrap<TaskWrapper> {
public:
    static Napi::Function buildConstructor(Napi::Env);

    TaskWrapper(const Napi::CallbackInfo& info);

    Napi::Value getTitle(const Napi::CallbackInfo& info);
    void setTitle(const Napi::CallbackInfo& info, const Napi::Value& value);

    Napi::Value getDetails(const Napi::CallbackInfo& info);
    void setDetails(const Napi::CallbackInfo& info, const Napi::Value& value);

    Napi::Value isCompleted(const Napi::CallbackInfo& info);
    void setIsCompleted(const Napi::CallbackInfo& info, const Napi::Value& value);
    
    Napi::Value toString(const Napi::CallbackInfo& info);

private:
    unique_ptr<Task> m_task;
};
}