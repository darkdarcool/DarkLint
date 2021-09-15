#include <napi.h>
#include <node_api.h>
#include <iostream>

void throwErr(Napi::Env env, std::string message) {
	Napi::Error::New(env, message).ThrowAsJavaScriptException();
}