#include <v8.h>
#include <node.h>

#include "../externals/RCSwitchHE.h"

using namespace v8;

class RCSwitchHENode : node::ObjectWrap {
  private:
    RCSwitchHE rcswitch;

    #define switchOp(p1) { if(switchOn) thiz->rcswitch.switchOn((p1)); else thiz->rcswitch.switchOff((p1)); }
    static v8::Handle<Value> SwitchOp(const Arguments& args, bool switchOn) {
      v8::HandleScope scope;
      RCSwitchHENode* thiz = node::ObjectWrap::Unwrap<RCSwitchHENode>(args.This());
      
      v8::Handle<Value> result = v8::Boolean::New(false);
      if(args.Length() == 1) {
        v8::Handle<v8::Value> swtch = args[0];

        if(swtch->IsInt32()) {
          switchOp(swtch->Int32Value());
          result = v8::Boolean::New(true);
        } 
      } 

      return result;
    }

  public:
    RCSwitchHENode() { }
    ~RCSwitchHENode() {}
    
    static v8::Persistent<FunctionTemplate> persistent_function_template;

    static void Init(Handle<Object> target) {
      if( wiringPiSetup() == -1 ) {
        ThrowException( Exception::TypeError( String::New( "rcswitch: GPIO initialization failed" ) ) );
        return;
      }
      v8::HandleScope scope;

      v8::Local<FunctionTemplate> local_function_template = v8::FunctionTemplate::New(New);
      RCSwitchHENode::persistent_function_template = v8::Persistent<FunctionTemplate>::New(local_function_template);
      RCSwitchHENode::persistent_function_template->InstanceTemplate()->SetInternalFieldCount(1); // 1 since this is a constructor function
      RCSwitchHENode::persistent_function_template->SetClassName(v8::String::NewSymbol("RCSwitchHE"));
      
      NODE_SET_PROTOTYPE_METHOD(RCSwitchHENode::persistent_function_template, "setRemoteCode", SetRemoteCode);
      NODE_SET_PROTOTYPE_METHOD(RCSwitchHENode::persistent_function_template, "enableTransmit", EnableTransmit);
      NODE_SET_PROTOTYPE_METHOD(RCSwitchHENode::persistent_function_template, "switchOn", SwitchOn);
      NODE_SET_PROTOTYPE_METHOD(RCSwitchHENode::persistent_function_template, "switchOff", SwitchOff);
      
      target->Set(String::NewSymbol("RCSwitchHE"), RCSwitchHENode::persistent_function_template->GetFunction());
    }

    static Handle<Value> New(const Arguments& args) {
      HandleScope scope;
      
      RCSwitchHENode* RCSwitchHENode_instance = new RCSwitchHENode();
      RCSwitchHENode_instance->Wrap(args.This());
      
      return args.This();
    }

    // notification.enableTransmit();
    static v8::Handle<Value> EnableTransmit(const Arguments& args) {
      v8::HandleScope scope;
      RCSwitchHENode* thiz = node::ObjectWrap::Unwrap<RCSwitchHENode>(args.This());
      
      v8::Handle<v8::Value> pinNr = args[0];
      if(pinNr->IsInt32()) {
        thiz->rcswitch.enableTransmit(pinNr->Int32Value());
        return v8::Boolean::New(true);
      } else {
        return v8::Boolean::New(false);
      }
    }

    static v8::Handle<Value> SwitchOn(const Arguments& args) {
      return SwitchOp(args, true);
    }
    static v8::Handle<Value> SwitchOff(const Arguments& args) {
      return SwitchOp(args, false);
    }
    static v8::Handle<Value> SetRemoteCode(const Arguments& args) {
      v8::HandleScope scope;
      RCSwitchHENode* thiz = node::ObjectWrap::Unwrap<RCSwitchHENode>(args.This());
      
      v8::Handle<Value> result = v8::Boolean::New(false);
      if(args.Length() == 1) {
        v8::Handle<v8::Value> remoteCode = args[0];

        if(remoteCode->IsInt32()) {
          thiz->rcswitch.setRemoteCode(remoteCode->Int32Value());
          return v8::Boolean::New(true);
        } else {
          return v8::Boolean::New(false);
        }
      } 

      return result;
    }

};

v8::Persistent<FunctionTemplate> RCSwitchHENode::persistent_function_template;
extern "C" {
  static void init(Handle<Object> target) {
    RCSwitchHENode::Init(target);
  }
  NODE_MODULE(rcswitch, init);
}
