/**
* For decoding napi values
* V8 gives encoded values, to decode them, napi has an api
* We simplify them here, so it can be used everywhere
*/

#include <iostream>
#include <napi.h>
#include <node_api.h>

namespace decoder {

std::string decodeString(Napi::Value arg) {
	if (arg.IsNumber()) {
		  throw std::invalid_argument("Arg is not a string");
	}
	return arg.ToString().Utf8Value();
}

int decodeNumber(Napi::Value arg) {
	if (arg.IsString()) {
		throw std::invalid_argument("Arg is not a number");
	}
	return arg.As<Napi::Number>().DoubleValue();
}
}
// Add other types later, but string and int are the major ones