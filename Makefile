CPPFLAGS = -D _DEBUG -ggdb3 -std=c++2a -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -fsanitize=address,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,leak,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

CALCULATOR = build/calculator.exe

FOLDERS = obj build

.PHONY: all

all: folders $(CALCULATOR)

clean: 
	find . -name "*.o" -delete

folders:
	mkdir -p $(FOLDERS)


$(CALCULATOR): obj/descent.o obj/file_reading.o obj/main.o auxiliary.o
	g++ obj/main.o obj/descent.o obj/file_reading.o auxiliary.o -o $(CALCULATOR) $(CPPFLAGS)


obj/main.o: main.cpp descent.h auxiliary.h
	g++ -c main.cpp -o obj/main.o


obj/descent.o: descent.cpp descent.h
	g++ -c descent.cpp -o obj/descent.o $(CPPFLAGS)


obj/auxiliary.o: auxiliary.cpp auxiliary.h descent.h Libs/file_reading.h
	g++ -c auxiliary.cpp -o obj/auxiliary.o $(CPPFLAGS)


obj/file_reading.o: Libs/file_reading.cpp Libs/file_reading.h
	g++ -c Libs/file_reading.cpp -o obj/file_reading.o $(CPPFLAGS)
 