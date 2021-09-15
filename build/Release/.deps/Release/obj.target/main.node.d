cmd_Release/obj.target/main.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=main.node -o Release/obj.target/main.node -Wl,--start-group Release/obj.target/main/lib/main.o -Wl,--end-group 
