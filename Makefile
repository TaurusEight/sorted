


cc := /usr/bin/g++
ccflags := -std=c++11 -g
rm := /bin/rm

sorted : sorted.cc ; $(cc) $(ccflags) -o $@ $<

clean : ; $(rm) sorted
