cmd_Release/obj.target/rcswitchhe.node := g++ -shared -pthread -rdynamic -m64 -lwiringPi  -Wl,-soname=rcswitchhe.node -o Release/obj.target/rcswitchhe.node -Wl,--start-group Release/obj.target/rcswitchhe/src/rcswitchhe.o Release/obj.target/rcswitchhe/src/RCSwitchHENode.o Release/obj.target/rcswitchhe/externals/RCSwitchHE.o -Wl,--end-group 