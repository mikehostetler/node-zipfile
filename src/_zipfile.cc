// v8
#include <v8.h>

// node
#include <node.h>
#include <node_version.h>

using namespace node;
using namespace v8;

#define TOSTR(obj) (*String::Utf8Value((obj)->ToString()))

extern "C" {

  static void init (Handle<Object> target)
  {

    // node-zipfile version
    target->Set(String::NewSymbol("version"), String::New("0.1.0"));

    // versions of deps
    Local<Object> versions = Object::New();
    versions->Set(String::NewSymbol("node"), String::New(NODE_VERSION+1));
    versions->Set(String::NewSymbol("v8"), String::New(V8::GetVersion()));
    target->Set(String::NewSymbol("versions"), versions);

  }

  NODE_MODULE(_zipfile, init);
}