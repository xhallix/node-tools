// myobject.h
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include <node_object_wrap.h>

namespace datachecks {

class CheckType : public node::ObjectWrap {
 public:

  static void IsFloat(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void IsInteger(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void InArray(const v8::FunctionCallbackInfo<v8::Value>& args);
  static bool CompareObjects(v8::Isolate *isolate, v8::Local<v8::Value> val, v8::Local<v8::Object> valToCompare);

 private:
  CheckType();
  ~CheckType();

};

} 

#endif
