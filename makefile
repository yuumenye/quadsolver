CC=g++
CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat                      \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy      \
-Wempty-body -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op             \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow             \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn                            \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef               \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers                  \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector              \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla     \


all: quadsolver

quadsolver: main.o colors.o compare.o io.o solver.o tests.o
	$(CC) main.o colors.o compare.o io.o solver.o tests.o -o quadsolver

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

colors.o: colors.cpp
	$(CC) -c $(CFLAGS) colors.cpp

compare.o: compare.cpp
	$(CC) -c $(CFLAGS) compare.cpp

io.o: io.cpp
	$(CC) -c $(CFLAGS) io.cpp

solver.o: solver.cpp
	$(CC) -c $(CFLAGS) solver.cpp

tests.o: tests.cpp
	$(CC) -c $(CFLAGS) tests.cpp

clean:
	rm -rf *.o


