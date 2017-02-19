#include <nan.h>
#include "RCSwitchHENode.h"

void InitAll(v8::Local<v8::Object> exports) {
  RCSwitchHENode::Init(exports);
}

NODE_MODULE(rcswitchhe, InitAll)