#include <napi.h>

namespace addon {

Napi::Object init(Napi::Env env, Napi::Object exports) {
	exports.Set("hello", Napi::String::New(env, "world"));
	return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init)
}
