#include <napi.h>
#include <node_api.h>
#include <iostream>
#include "./decoder.h"
#include "./err.h"
#include "./darklint/lint.h"

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	std::string code;
	try {
		code = decoder::decodeString(info[0]);
	} catch (...) {
		throwErr(env, "Expected string, found other type");
		return Napi::String::New(env, "0");
	}
	lint(code);
  return Napi::String::New(env, "0"); // we return 0 for now
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "lint"),
    Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init);