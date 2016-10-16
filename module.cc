#include <node.h>
#include <v8.h>
#include <string>
using namespace v8;
using node::AtExit;
using v8::HandleScope;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

// C++ functions here (or a seperate file)

int hf(std::string const& s) {
	unsigned long hash = 5381;
	for (auto c : s) {
		hash = (hash << 5) + hash + c; // hash * 33 + c
	}
	return hash;
}

// Node wrapper for C++ functions

void Hash(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  // Validate arguments
  if (args.Length() < 1 || !args[0]->IsString()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Invalid argument, Hash() only takes one argument (string)")));
    return;
  }
	// Type conversion
	v8::String::Utf8Value param1(args[0]->ToString());
	std::string str = std::string(*param1);
	// Return results
	args.GetReturnValue().Set(Integer::New(isolate,hf(str)));
}

// Plugin Exports

void init(Local<Object> exports) {
	NODE_SET_METHOD(exports, "hf", Hash);
	NODE_SET_METHOD(exports, "hash", Hash);
}

NODE_MODULE(octoberlibrary, init)
