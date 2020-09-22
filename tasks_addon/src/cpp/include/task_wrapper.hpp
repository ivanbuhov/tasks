#pragma once

#include <napi.h>

#include "task.hpp"

namespace tasks_addon {

using namespace std;
using namespace tasks;

class TaskWrapper : public Napi::ObjectWrap<TaskWrapper> {
public:
    static Napi::Function buildConstructor(Napi::Env);

    // TODO: Bad. Avoid storing static state. This way the addon will not work properly in more than one VM.
    static Napi::FunctionReference constructorRef;

    TaskWrapper(const Napi::CallbackInfo& info);

    Napi::Value getTitle(const Napi::CallbackInfo& info);
    void setTitle(const Napi::CallbackInfo& info, const Napi::Value& value);

    Napi::Value getDetails(const Napi::CallbackInfo& info);
    void setDetails(const Napi::CallbackInfo& info, const Napi::Value& value);

    Napi::Value isCompleted(const Napi::CallbackInfo& info);
    void setIsCompleted(const Napi::CallbackInfo& info, const Napi::Value& value);
    
    Napi::Value toString(const Napi::CallbackInfo& info);
    Napi::Value toJSON(const Napi::CallbackInfo& info);

private:
    Task m_task;
};
}