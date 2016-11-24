// datatypes.cc
#include <node.h>
#include "StringUtils.h"


namespace stringutils {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Exception;

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "snakeCase", StringUtils::SnakeCase);  
}
  NODE_MODULE(stringutils, init)
}