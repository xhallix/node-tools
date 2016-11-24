
#include "StringUtils.h"
#include <iostream>
#include <ctype.h>

using v8::FunctionCallbackInfo;
using v8::Value;
using v8::Isolate;
using v8::Local;
using v8::String;
using v8::Exception;
using v8::Context;

namespace stringutils {

  StringUtils::StringUtils() {}
  StringUtils::~StringUtils() {}

  // converts a string to snakeCase like string
  void StringUtils::SnakeCase(const FunctionCallbackInfo<Value>& args)
  {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    if(args.Length() > 1) {
       isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Function accepts only 1 argument")));
      return;
    }
    Local<Value> arg = args[0];
    if(!arg->IsString()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Argument expects to be typeof String")));
      return;
    }
    Local<String> str = arg->ToString(context).ToLocalChecked();
    std::string stdString = *String::Utf8Value(str);
    std::string transformedString = StringUtils::MakeSnakeCase(stdString);
    Local<String> resultString = String::NewFromUtf8(isolate, transformedString.c_str());
    args.GetReturnValue().Set(resultString);
  }

  //
  // Make the actual transformation
  // 
  std::string StringUtils::MakeSnakeCase(std::string originString)
  {
    std::string transformedString = "";
     for(uint i=0; i < originString.size(); i++) { 
      if(isupper(originString[i])) {
       transformedString += "_";
       transformedString += tolower(originString[i]);
      } else {
        transformedString += originString[i];
      }
    }
    return transformedString;
  }

} 