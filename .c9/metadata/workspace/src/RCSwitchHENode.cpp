{"filter":false,"title":"RCSwitchHENode.cpp","tooltip":"/src/RCSwitchHENode.cpp","undoManager":{"mark":73,"position":73,"stack":[[{"start":{"row":50,"column":1},"end":{"row":51,"column":0},"action":"insert","lines":["",""],"id":2}],[{"start":{"row":51,"column":0},"end":{"row":52,"column":0},"action":"insert","lines":["",""],"id":3}],[{"start":{"row":52,"column":0},"end":{"row":86,"column":1},"action":"insert","lines":["void RCSwitchNode::SwitchOp(const Nan::FunctionCallbackInfo<v8::Value>& info, bool switchOn) {","  Nan::HandleScope scope;","  RCSwitchNode* thiz = ObjectWrap::Unwrap<RCSwitchNode>(info.Holder());","","  info.GetReturnValue().Set(false);","  if(info.Length() == 2) {","    v8::Local<v8::Value> group = info[0];","    v8::Local<v8::Value> swtch = info[1];","","    if(group->IsInt32() && swtch->IsInt32()) {","      switchOp2(group->Int32Value(), swtch->Int32Value());","      info.GetReturnValue().Set(true);","    } else if(group->IsString() && swtch->IsInt32()) {","      Nan::Utf8String sGroup(group);","","      if(sGroup.length() >= 5) {","        switchOp2(*sGroup, swtch->Int32Value());","        info.GetReturnValue().Set(true);","      }","    }","  } else if(info.Length() == 3) {","    v8::Local<v8::Value> famly = info[0];","    v8::Local<v8::Value> group = info[1];","    v8::Local<v8::Value> devce = info[2];","","    if(famly->IsString() && group->IsInt32() && devce->IsInt32()) {","      Nan::Utf8String v8str(famly);","","      if(v8str.length() > 0) {","        switchOp3(*(*v8str), group->Int32Value(), devce->Int32Value());","        info.GetReturnValue().Set(true);","      }","    }","  }","}"],"id":4}],[{"start":{"row":52,"column":5},"end":{"row":52,"column":17},"action":"remove","lines":["RCSwitchNode"],"id":5},{"start":{"row":52,"column":5},"end":{"row":52,"column":19},"action":"insert","lines":["RCSwitchHENode"]}],[{"start":{"row":54,"column":2},"end":{"row":54,"column":14},"action":"remove","lines":["RCSwitchNode"],"id":6},{"start":{"row":54,"column":2},"end":{"row":54,"column":16},"action":"insert","lines":["RCSwitchHENode"]}],[{"start":{"row":54,"column":44},"end":{"row":54,"column":56},"action":"remove","lines":["RCSwitchNode"],"id":7},{"start":{"row":54,"column":44},"end":{"row":54,"column":58},"action":"insert","lines":["RCSwitchHENode"]}],[{"start":{"row":129,"column":25},"end":{"row":129,"column":26},"action":"remove","lines":["f"],"id":8}],[{"start":{"row":129,"column":25},"end":{"row":129,"column":26},"action":"remove","lines":["f"],"id":9}],[{"start":{"row":129,"column":25},"end":{"row":129,"column":26},"action":"insert","lines":["p"],"id":10}],[{"start":{"row":120,"column":18},"end":{"row":120,"column":26},"action":"remove","lines":["switchOn"],"id":11},{"start":{"row":120,"column":18},"end":{"row":120,"column":26},"action":"insert","lines":["switchOp"]}],[{"start":{"row":125,"column":1},"end":{"row":129,"column":48},"action":"remove","lines":[" RCSwitchHENode* obj = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());","","  v8::Local<v8::Value> pinNr = info[0];","  if(pinNr->IsInt32()) {","    obj->rcswitch.switchOp(pinNr->Int32Value());"],"id":12},{"start":{"row":125,"column":1},"end":{"row":125,"column":31},"action":"insert","lines":[" return SwitchOp(args, false);"]}],[{"start":{"row":126,"column":2},"end":{"row":126,"column":3},"action":"remove","lines":["}"],"id":13},{"start":{"row":126,"column":2},"end":{"row":127,"column":0},"action":"insert","lines":["",""]},{"start":{"row":127,"column":0},"end":{"row":127,"column":2},"action":"insert","lines":["  "]}],[{"start":{"row":124,"column":0},"end":{"row":125,"column":0},"action":"remove","lines":["Nan::HandleScope scope;",""],"id":14}],[{"start":{"row":124,"column":18},"end":{"row":124,"column":22},"action":"remove","lines":["args"],"id":15},{"start":{"row":124,"column":18},"end":{"row":124,"column":22},"action":"insert","lines":["info"]}],[{"start":{"row":116,"column":0},"end":{"row":121,"column":0},"action":"remove","lines":["  RCSwitchHENode* obj = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());","","  v8::Local<v8::Value> pinNr = info[0];","  if(pinNr->IsInt32()) {","    obj->rcswitch.switchOp(pinNr->Int32Value());",""],"id":16},{"start":{"row":116,"column":0},"end":{"row":117,"column":0},"action":"insert","lines":["  return SwitchOp(info, false);",""]}],[{"start":{"row":117,"column":2},"end":{"row":117,"column":3},"action":"remove","lines":["}"],"id":17}],[{"start":{"row":116,"column":24},"end":{"row":116,"column":29},"action":"remove","lines":["false"],"id":18},{"start":{"row":116,"column":24},"end":{"row":116,"column":25},"action":"insert","lines":["t"]}],[{"start":{"row":116,"column":25},"end":{"row":116,"column":26},"action":"insert","lines":["r"],"id":19}],[{"start":{"row":116,"column":26},"end":{"row":116,"column":27},"action":"insert","lines":["u"],"id":20}],[{"start":{"row":116,"column":27},"end":{"row":116,"column":28},"action":"insert","lines":["e"],"id":21}],[{"start":{"row":77,"column":0},"end":{"row":85,"column":0},"action":"remove","lines":["    if(famly->IsString() && group->IsInt32() && devce->IsInt32()) {","      Nan::Utf8String v8str(famly);","","      if(v8str.length() > 0) {","        switchOp3(*(*v8str), group->Int32Value(), devce->Int32Value());","        info.GetReturnValue().Set(true);","      }","    }",""],"id":22}],[{"start":{"row":72,"column":4},"end":{"row":77,"column":3},"action":"remove","lines":["else if(info.Length() == 3) {","    v8::Local<v8::Value> famly = info[0];","    v8::Local<v8::Value> group = info[1];","    v8::Local<v8::Value> devce = info[2];","","  }"],"id":23}],[{"start":{"row":62,"column":58},"end":{"row":63,"column":0},"action":"insert","lines":["",""],"id":24},{"start":{"row":63,"column":0},"end":{"row":63,"column":6},"action":"insert","lines":["      "]}],[{"start":{"row":63,"column":6},"end":{"row":63,"column":36},"action":"insert","lines":["switchOp(swtch->Int32Value());"],"id":25}],[{"start":{"row":63,"column":0},"end":{"row":64,"column":0},"action":"remove","lines":["      switchOp(swtch->Int32Value());",""],"id":26}],[{"start":{"row":52,"column":30},"end":{"row":52,"column":80},"action":"remove","lines":["const Nan::FunctionCallbackInfo<v8::Value>& info, "],"id":27}],[{"start":{"row":62,"column":14},"end":{"row":62,"column":15},"action":"remove","lines":["2"],"id":28}],[{"start":{"row":62,"column":15},"end":{"row":62,"column":36},"action":"remove","lines":["group->Int32Value(), "],"id":29}],[{"start":{"row":57,"column":22},"end":{"row":57,"column":23},"action":"remove","lines":["2"],"id":30}],[{"start":{"row":57,"column":22},"end":{"row":57,"column":23},"action":"insert","lines":["1"],"id":31}],[{"start":{"row":58,"column":0},"end":{"row":59,"column":0},"action":"remove","lines":["    v8::Local<v8::Value> group = info[0];",""],"id":32}],[{"start":{"row":58,"column":38},"end":{"row":58,"column":39},"action":"remove","lines":["1"],"id":33}],[{"start":{"row":58,"column":38},"end":{"row":58,"column":39},"action":"insert","lines":["0"],"id":34}],[{"start":{"row":60,"column":7},"end":{"row":60,"column":27},"action":"remove","lines":["group->IsInt32() && "],"id":35}],[{"start":{"row":63,"column":6},"end":{"row":70,"column":5},"action":"remove","lines":["else if(group->IsString() && swtch->IsInt32()) {","      Nan::Utf8String sGroup(group);","","      if(sGroup.length() >= 5) {","        switchOp2(*sGroup, swtch->Int32Value());","        info.GetReturnValue().Set(true);","      }","    }"],"id":36}],[{"start":{"row":67,"column":0},"end":{"row":77,"column":0},"action":"remove","lines":["void RCSwitchHENode::Transmit(const Nan::FunctionCallbackInfo<v8::Value>& info) {","  Nan::HandleScope scope;","","  RCSwitchHENode* obj = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());","","  Nan::Utf8String v8str(info[0]);","  obj->rcswitch.send(*v8str);","","  info.GetReturnValue().Set(true);","}",""],"id":37}],[{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["  Nan::SetPrototypeMethod(tpl, \"transmit\", Transmit);",""],"id":38}],[{"start":{"row":51,"column":30},"end":{"row":51,"column":78},"action":"insert","lines":["const Nan::FunctionCallbackInfo<v8::Value>& info"],"id":45}],[{"start":{"row":51,"column":78},"end":{"row":51,"column":79},"action":"insert","lines":[","],"id":46}],[{"start":{"row":51,"column":79},"end":{"row":51,"column":80},"action":"insert","lines":[" "],"id":47}],[{"start":{"row":60,"column":14},"end":{"row":60,"column":15},"action":"insert","lines":["2"],"id":51}],[{"start":{"row":68,"column":0},"end":{"row":68,"column":1},"action":"insert","lines":["/"],"id":52}],[{"start":{"row":68,"column":1},"end":{"row":68,"column":2},"action":"insert","lines":["*"],"id":53}],[{"start":{"row":68,"column":2},"end":{"row":69,"column":0},"action":"insert","lines":["",""],"id":54}],[{"start":{"row":81,"column":0},"end":{"row":81,"column":1},"action":"insert","lines":["*"],"id":55}],[{"start":{"row":81,"column":1},"end":{"row":81,"column":2},"action":"insert","lines":["/"],"id":56}],[{"start":{"row":85,"column":0},"end":{"row":86,"column":0},"action":"insert","lines":["    v8::Local<v8::Value> swtch = info[0];",""],"id":57}],[{"start":{"row":85,"column":0},"end":{"row":85,"column":2},"action":"remove","lines":["  "],"id":58}],[{"start":{"row":85,"column":0},"end":{"row":85,"column":2},"action":"remove","lines":["  "],"id":59}],[{"start":{"row":85,"column":0},"end":{"row":85,"column":1},"action":"insert","lines":[" "],"id":60}],[{"start":{"row":85,"column":1},"end":{"row":85,"column":2},"action":"insert","lines":[" "],"id":61}],[{"start":{"row":85,"column":39},"end":{"row":86,"column":0},"action":"insert","lines":["",""],"id":62},{"start":{"row":86,"column":0},"end":{"row":86,"column":2},"action":"insert","lines":["  "]}],[{"start":{"row":86,"column":2},"end":{"row":86,"column":33},"action":"insert","lines":["switchOp2(swtch->Int32Value());"],"id":63}],[{"start":{"row":86,"column":9},"end":{"row":86,"column":10},"action":"remove","lines":["p"],"id":64}],[{"start":{"row":86,"column":9},"end":{"row":86,"column":10},"action":"remove","lines":["2"],"id":65}],[{"start":{"row":86,"column":9},"end":{"row":86,"column":10},"action":"insert","lines":["n"],"id":66}],[{"start":{"row":86,"column":2},"end":{"row":86,"column":8},"action":"insert","lines":["return"],"id":67}],[{"start":{"row":86,"column":8},"end":{"row":86,"column":9},"action":"insert","lines":[" "],"id":68}],[{"start":{"row":87,"column":0},"end":{"row":88,"column":0},"action":"remove","lines":["  return SwitchOp(info, true);",""],"id":69}],[{"start":{"row":90,"column":0},"end":{"row":92,"column":0},"action":"remove","lines":["  return SwitchOp(info, false);","  ",""],"id":70},{"start":{"row":90,"column":0},"end":{"row":92,"column":0},"action":"insert","lines":["  v8::Local<v8::Value> swtch = info[0];","  return switchOn(swtch->Int32Value());",""]}],[{"start":{"row":91,"column":16},"end":{"row":91,"column":17},"action":"remove","lines":["n"],"id":71}],[{"start":{"row":91,"column":16},"end":{"row":91,"column":17},"action":"insert","lines":["f"],"id":72}],[{"start":{"row":91,"column":17},"end":{"row":91,"column":18},"action":"insert","lines":["f"],"id":73}],[{"start":{"row":50,"column":0},"end":{"row":51,"column":0},"action":"insert","lines":["",""],"id":74}],[{"start":{"row":51,"column":0},"end":{"row":51,"column":1},"action":"insert","lines":["/"],"id":75}],[{"start":{"row":51,"column":1},"end":{"row":51,"column":2},"action":"insert","lines":["*"],"id":76}],[{"start":{"row":66,"column":0},"end":{"row":66,"column":1},"action":"insert","lines":["*"],"id":77}],[{"start":{"row":66,"column":1},"end":{"row":66,"column":2},"action":"insert","lines":["/"],"id":78}],[{"start":{"row":92,"column":9},"end":{"row":92,"column":24},"action":"insert","lines":["thiz->rcswitch."],"id":79}],[{"start":{"row":87,"column":9},"end":{"row":87,"column":24},"action":"insert","lines":["thiz->rcswitch."],"id":80}],[{"start":{"row":91,"column":0},"end":{"row":92,"column":0},"action":"insert","lines":["  RCSwitchHENode* thiz = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());",""],"id":81}],[{"start":{"row":86,"column":2},"end":{"row":87,"column":0},"action":"insert","lines":["  RCSwitchHENode* thiz = ObjectWrap::Unwrap<RCSwitchHENode>(info.Holder());",""],"id":82}],[{"start":{"row":22,"column":2},"end":{"row":22,"column":3},"action":"insert","lines":["/"],"id":83}],[{"start":{"row":22,"column":3},"end":{"row":22,"column":4},"action":"insert","lines":["/"],"id":84}]]},"ace":{"folds":[],"scrolltop":514.7272644042969,"scrollleft":0,"selection":{"start":{"row":47,"column":61},"end":{"row":47,"column":61},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":27,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1487512902935,"hash":"62dd2c616561c69fb748e14ad4282958336100ad"}