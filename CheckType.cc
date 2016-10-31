
#include "CheckType.h"
#include <cmath>

namespace datachecks {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Exception;



  CheckType::CheckType(double value) : value_(value) {
  }

  CheckType::~CheckType() {
  }

  void CheckType::Init(Local<Object> exports) {
    Isolate* isolate = exports->GetIsolate();
  }


  void CheckType::IsFloat(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    
    if(args.Length() > 1) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Function accepts only 1 argument")
      ));
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


  void CheckType::IsInteger(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
      if(args.Length() > 1) {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Function accepts only 1 argument")
      ));
    }
    auto val = args[0];
    if(val->IsInt32()) {
      args.GetReturnValue().Set(True(isolate)); 
      return;
    } 
    args.GetReturnValue().Set(False(isolate));
      
  }

} 