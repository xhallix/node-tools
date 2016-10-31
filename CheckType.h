// myobject.h
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include <node_object_wrap.h>

namespace datachecks {

class CheckType : public node::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);
  static void IsFloat(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void IsInteger(const v8::FunctionCallbackInfo<v8::Value>& args);

 private:
  CheckType(double value = 0);
  ~CheckType();

  double value_;

};

} 

#endif
