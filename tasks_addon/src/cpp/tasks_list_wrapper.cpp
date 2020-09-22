#include <sstream>

#include "include/tasks_list_wrapper.hpp"

namespace tasks_addon {

 Napi::FunctionReference TaskWrapper::constructorRef;

Napi::Function TasksListWrapper::buildConstructor(Napi::Env env) {
    Napi::Function constructor = DefineClass(env, "TasksList", {
        // Properties
        TasksListWrapper::InstanceAccessor<&TasksListWrapper::getLength>("length"),
        // Methods
        TasksListWrapper::InstanceMethod<&TasksListWrapper::at>("at"),
        TasksListWrapper::InstanceMethod<&TasksListWrapper::add>("add"),
        TasksListWrapper::InstanceMethod<&TasksListWrapper::swap>("swap")
    });

    Napi::FunctionReference constructorRef = Napi::Persistent(constructor);
    constructorRef.SuppressDestruct();
    return constructor;
}

TasksListWrapper::TasksListWrapper(const Napi::CallbackInfo& info) : ObjectWrap(info) {
}

Napi::Value TasksListWrapper::getLength(const Napi::CallbackInfo& info) {
    return Napi::Number::New(info.Env(), m_tasksList.size());
}

Napi::Value TasksListWrapper::at(const Napi::CallbackInfo& info) {
    if (info.Length() != 1) {
        Napi::TypeError::New(info.Env(), "Unsupported number of parameters.").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(info.Env(), "Index must be a number.").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    size_t index = static_cast<size_t>(info[0].As<Napi::Number>().Int64Value());
    
    if (index >= m_tasksList.size()) {
        Napi::TypeError::New(info.Env(), "Invalid index.").ThrowAsJavaScriptException();
        return info.Env().Undefined();
    }

    return m_tasksList.at(index).Value();
}

void TasksListWrapper::add(const Napi::CallbackInfo& info) {
    if (info.Length() != 1) {
        Napi::TypeError::New(info.Env(), "Unsupported number of parameters.").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsObject() || !info[0].As<Napi::Object>().InstanceOf(TaskWrapper::constructorRef.Value().As<Napi::Function>())) {
        Napi::TypeError::New(info.Env(), "The first parameter must be an instance of Task.").ThrowAsJavaScriptException();
        return;
    }

    m_tasksList.push_back(Napi::Persistent(info[0].As<Napi::Object>()));
}

void TasksListWrapper::swap(const Napi::CallbackInfo& info) {
    if (info.Length() != 2) {
        Napi::TypeError::New(info.Env(), "Unsupported number of parameters.").ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(info.Env(), "Index1 must be a number.").ThrowAsJavaScriptException();
        return;
    }

    if (!info[1].IsNumber()) {
        Napi::TypeError::New(info.Env(), "Index2 must be a number.").ThrowAsJavaScriptException();
        return;
    }

    size_t index1 = info[0].As<Napi::Number>().Int64Value();
    size_t index2 = info[1].As<Napi::Number>().Int64Value();

    if (index1 >= m_tasksList.size() || index2 >= m_tasksList.size()) {
        Napi::TypeError::New(info.Env(), "Invalid indexes.").ThrowAsJavaScriptException();
        return;
    }

    Napi::ObjectReference temp = std::move(m_tasksList.at(index1));
    m_tasksList.at(index1) = std::move(m_tasksList.at(index2));
    m_tasksList.at(index2) = std::move(temp);
}

Napi::Value TasksListWrapper::toJSON(const Napi::CallbackInfo& info) {
    Napi::Array array = Napi::Array::New(info.Env());
    for (size_t index = 0; index < m_tasksList.size(); index++) {
        array[index] = m_tasksList[index].Value();
    }

    return array;
}
}