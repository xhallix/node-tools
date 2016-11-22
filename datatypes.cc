// datatypes.cc
#include <node.h>
#include <cmath>
#include "CheckType.h"


namespace datachecks {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Exception;



void init(Local<Object> exports) {

  
  NODE_SET_METHOD(exports, "isInteger", CheckType::IsInteger);  
  NODE_SET_METHOD(exports, "isFloat", CheckType::IsFloat);
  NODE_SET_METHOD(exports, "inArray", CheckType::InArray);
}

  NODE_MODULE(datachecks, init)
}