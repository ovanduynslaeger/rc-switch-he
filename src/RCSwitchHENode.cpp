#include "RCSwitchHENode.h"

Nan::Persistent<v8::Function> RCSwitchHENode::constructor;

void RCSwitchHENode::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  if( wiringPiSetup() == -1 ) {
    Nan::ThrowTypeError("rcswitchhe: GPIO initialization failed");
    return;
  }

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("RCSwitchHE").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1); // 1 since this is a constructor function

  //Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("protocol").ToLocalChecked(), GetProtocol); //, SetProtocol); TODO <- Error at compile-time... ?
  //Nan::SetPrototypeMethod(tpl, "send", Send);

  // Prototype
    
  Nan::SetPrototypeMethod(tpl, "enableTransmit", EnableTransmit);
  //Nan::SetPrototypeMethod(tpl, "disableTransmit", DisableTransmit);
  Nan::SetPrototypeMethod(tpl, "switchOn", SwitchOn);
  Nan::SetPrototypeMethod(tpl, "switchOff", SwitchOff);
  //Nan::SetPrototypeMethod(tpl, "sendTriState", SendTriState);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("RCSwitchHE").ToLocalChecked(), tpl->GetFunction());
}

 RCSwitchHENode::RCSwitchHENode() {}
 RCSwitchHENode::~RCSwitchHENode() {}


void RCSwitchHENode::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    RCSwitchHENode* obj = new RCSwitchHENode();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `MyObject(...)`, turn into construct call.
    const int argc = 0;
    v8::Local<v8::Value> argv[argc];
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

/*
void RCSwitchHENode::SwitchOp(const Nan::FunctionCallbackInfo<v8::Value>& info, bool switchOn) {
  Nan::HandleScope scope;
  RCSwitchHENode* thiz = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());

  info.GetReturnValue().Set(false);
  if(info.Length() == 1) {
    v8::Local<v8::Value> swtch = info[0];

    if(swtch->IsInt32()) {
      switchOp2(swtch->Int32Value());
      info.GetReturnValue().Set(true);
    } 
  } 
}
*/

// notification.enableTransmit();

void RCSwitchHENode::EnableTransmit(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Nan::HandleScope scope;
  RCSwitchHENode* obj = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());

  v8::Local<v8::Value> pinNr = info[0];
  if(pinNr->IsInt32()) {
    obj->rcswitch.enableTransmit(pinNr->Int32Value());
    info.GetReturnValue().Set(true);
  } else {
    info.GetReturnValue().Set(false);
  }
}


void RCSwitchHENode::SwitchOn(const Nan::FunctionCallbackInfo<v8::Value>& info) {
Nan::HandleScope scope;
    RCSwitchHENode* thiz = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());
v8::Local<v8::Value> swtch = info[0];
  return thiz->rcswitch.switchOn(swtch->Int32Value());
  }

void RCSwitchHENode::SwitchOff(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  RCSwitchHENode* thiz = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());
  v8::Local<v8::Value> swtch = info[0];
  return thiz->rcswitch.switchOff(swtch->Int32Value());
  }
