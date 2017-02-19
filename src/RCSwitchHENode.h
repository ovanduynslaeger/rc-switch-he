#ifndef RCSWITCHHENODE_H
#define RCSWITCHHENODE_H

#include <nan.h>

#include "../externals/RCSwitchHE.h"

class RCSwitchHENode : public Nan::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);

 private:
  RCSwitchHE rcswitch;
  static Nan::Persistent<v8::Function> constructor;
  explicit RCSwitchHENode();
  ~RCSwitchHENode();
  
  //static void SwitchOp(const Nan::FunctionCallbackInfo<v8::Value>& info, bool switchOn);
  //#define switchOp(p1) { if(switchOn) thiz->rcswitch.switchOn((p1)); else thiz->rcswitch.switchOff((p1)); }
  //#define switchOp3(p1, p2, p3) { if(switchOn) thiz->rcswitch.switchOn((p1), (p2), (p3)); else thiz->rcswitch.switchOff((p1), (p2), (p3)); }
  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  //static void Send(const Nan::FunctionCallbackInfo<v8::Value>& info);
  //static void SendTriState(const Nan::FunctionCallbackInfo<v8::Value>& info);
  //static void EnableTransmit(const Nan::FunctionCallbackInfo<v8::Value>& info);
  //static void DisableTransmit(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void SwitchOn(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void SwitchOff(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void SetRemoteCode(const Nan::FunctionCallbackInfo<v8::Value>& info);
  
    //unsigned long power2(int power);

    /*
    static void itob(const Nan::FunctionCallbackInfo<v8::Value>& info, const Nan::FunctionCallbackInfo<v8::Value>& length);
    static void itobInterruptor(const Nan::FunctionCallbackInfo<v8::Value>& info, const Nan::FunctionCallbackInfo<v8::Value>& length);
    static void SendPair(bool b);
    static void SendBit(bool b);
    */
    //static void Transmit(const Nan::FunctionCallbackInfo<v8::Value>& info);
  
  //static void SetProtocol(v8::Local<v8::String> property, v8::Local<v8::Value> value, const Nan::PropertyCallbackInfo<v8::Value>& info);
  //static void GetProtocol(v8::Local<v8::String> property, const Nan::PropertyCallbackInfo<v8::Value>& info);
};

#endif