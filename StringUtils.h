
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <node.h>
#include <node_object_wrap.h>

namespace stringutils {

  class StringUtils : public node::ObjectWrap {
  
  public:
    static void SnakeCase(const v8::FunctionCallbackInfo<v8::Value>& args);

  private:
    StringUtils();
    ~StringUtils();

    static std::string MakeSnakeCase(std::string originString);

  };

} 

#endif
