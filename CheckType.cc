
#include "CheckType.h"
#include <cmath>
#include <iostream>

namespace datachecks {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Exception;
using v8::Array;

  CheckType::CheckType() {}
  CheckType::~CheckType() {}

  //
  //  Checks if a value is float
  //
  void CheckType::IsFloat(const FunctionCallbackInfo<Value>& args) 
  {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() > 1) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Function accepts only 1 argument")
      ));
      return;
    }
    auto val = args[0];
    if(!val->IsNumber()) {
      args.GetReturnValue().Set(False(isolate));
      return;
    }  
    double dVal = val->NumberValue();
    if(dVal == floor(dVal)) {
      args.GetReturnValue().Set(False(isolate));
      return; 
    } 
    args.GetReturnValue().Set(True(isolate));
  }

  //
  //  Checks if a value is integer
  //
  void CheckType::IsInteger(const FunctionCallbackInfo<Value>& args) 
  {
    Isolate* isolate = args.GetIsolate();
      if(args.Length() > 1) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Function accepts only 1 argument")
      ));
      return;
    }

    if(args[0]->IsInt32()) {
      args.GetReturnValue().Set(True(isolate)); 
      return;
    } 
    args.GetReturnValue().Set(False(isolate));  
  }

  void CheckType::InArray(const FunctionCallbackInfo<Value>& args) 
  {
    Isolate* isolate = args.GetIsolate();
    if(args.Length() < 2) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Expected 2 arguments - haystack | needle")
      ));
      return;
    }

    if(!args[0]->IsArray()) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Expected Type array as first argument")
      ));
      return;
    }


    Local<Array> jArray = args[0].As<Array>();

    for(uint i=0; i < jArray->Length(); i++) {
       Local<Value> val = jArray->Get(i);
       if(val == args[1]) {
        args.GetReturnValue().Set(True(isolate));
        return;
       }
    }
    args.GetReturnValue().Set(False(isolate));
    return;

  }

} 