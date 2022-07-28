SHELL=/bin/sh
DEFAULT: it

clean:
	rm -f *.o mc-receiver

it:
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o status.o -c status.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o alloc.o -c alloc.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o array.o -c array.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o strerr.o -c strerr.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o scan.o -c scan.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o ipv4.o -c ipv4.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o socket.o -c socket.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o slurpclose.o -c slurpclose.c
	cc -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o interface.o -c interface.c
	cc -s -Wall -Wno-misleading-indentation -O3 -fomit-frame-pointer -march=native -o mc-receiver mc-receiver.c socket.o ipv4.o scan.o strerr.o interface.o array.o alloc.o status.o slurpclose.o
