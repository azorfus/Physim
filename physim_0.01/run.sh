g++ -g -lfltk -fsanitize=address -L/usr/X11/lib -lX11 ./src/*.cpp  -o ./build/physim && ./build/physim
