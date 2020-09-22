#include <sstream>

#include "include/task_wrapper.hpp"

namespace tasks_addon {

Napi::Function TaskWrapper::buildConstructor(Napi::Env env) {
    return DefineClass(env, "Task", {
        // Properties
        TaskWrapper::InstanceAccessor("title", &TaskWrapper::getTitle, &TaskWrapper::setTitle, napi_property_attributes::napi_default, nullptr),
        TaskWrapper::InstanceAccessor("details", &TaskWrapper::getDetails, &TaskWrapper::setDetails, napi_property_attributes::napi_default, nullptr),
        TaskWrapper::InstanceAccessor("isCompleted", &TaskWrapper::isCompleted, &TaskWrapper::setIsCompleted, napi_property_attributes::napi_default, nullptr),
        // Methods
        TaskWrapper::InstanceMethod("toString", &TaskWrapper::toString)
        });
}

TaskWrapper::TaskWrapper(const Napi::CallbackInfo& info) : ObjectWrap(info) {
    Napi::Env env = info.Env();

    if (info.Length() > 3) {
        Napi::TypeError::New(env, "Maximum of 3 parameters allowed.").ThrowAsJavaScriptException();
        return;
    }

    // Arguments marshalling
    // TODO: Extract types marshalling in a helper functions to be more easily reused.
    string title = "";
    string details = "";
    bool isCompleted = false;

    if (info.Length() > 0) {
        if (!info[0].IsString()) {
            Napi::TypeError::New(info.Env(), "Title must be a string.").ThrowAsJavaScriptException();
            return;
        }
        title = info[0].As<Napi::String>().Utf8Value();
    }

    if (info.Length() > 1) {
        if (!info[1].IsString()) {
            Napi::TypeError::New(info.Env(), "Details must be a string.").ThrowAsJavaScriptException();
            return;
        }
        details = info[1].As<Napi::String>().Utf8Value();
    }

    if (info.Length() > 2) {
        if (!info[2].IsBoolean()) {
            Napi::TypeError::New(info.Env(), "IsCompleted must be a boolean.").ThrowAsJavaScriptException();
            return;
        }
        isCompleted = info[2].As<Napi::Boolean>().Value();
    }

    // Create the underlying native object by calling its constructor
    m_task = make_unique<Task>(title, details, isCompleted);
}

Napi::Value TaskWrapper::getTitle(const Napi::CallbackInfo& info) {
    return Napi::String::New(info.Env(), m_task->getTitle().c_str());
}

void TaskWrapper::setTitle(const Napi::CallbackInfo& info, const Napi::Value& value) {
    if (!value.IsString()) {
        Napi::TypeError::New(info.Env(), "Title must be a string.").ThrowAsJavaScriptException();
        return;
    }

    m_task->setTitle(value.As<Napi::String>().Utf8Value());
}

Napi::Value TaskWrapper::getDetails(const Napi::CallbackInfo& info) {
    return Napi::String::New(info.Env(), m_task->getDetails().c_str());
}

void TaskWrapper::setDetails(const Napi::CallbackInfo& info, const Napi::Value& value) {
    if (!value.IsString()) {
        Napi::TypeError::New(info.Env(), "Details must be a string.").ThrowAsJavaScriptException();
        return;
    }

    m_task->setDetails(value.As<Napi::String>().Utf8Value());
}

Napi::Value TaskWrapper::isCompleted(const Napi::CallbackInfo& info) {
    return Napi::Boolean::New(info.Env(), m_task->isCompleted());
}

void TaskWrapper::setIsCompleted(const Napi::CallbackInfo& info, const Napi::Value& value) {
    if (!value.IsBoolean()) {
        Napi::TypeError::New(info.Env(), "IsCompleted must be a boolean.").ThrowAsJavaScriptException();
        return;
    }

    m_task->setIsCompleted(value.As<Napi::Boolean>().Value());
}

Napi::Value TaskWrapper::toString(const Napi::CallbackInfo& info) {
    std::ostringstream result;
    result << (m_task->isCompleted() ? "[#] " : "[ ] ") << m_task->getTitle() << " (";
    // If the details are too long, strip it to the 30th character
    if (m_task->getDetails().size() > 30) {
        result <<  m_task->getDetails().substr(0, 30) << "...";
    } else {
        result << m_task->getDetails();
    }
    result << ")";

    return Napi::String::New(info.Env(), result.str());
}

}