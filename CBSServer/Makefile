
all:	CBSServer

CC = gcc -Wall -I "include/" 
CPP=g++  
all:prod
CPPFLAGS= -I "include/" `mysql_config --cflags --libs`
LDFLAGS=`mysql_config --cflags --libs`

debug: CC += -g3 -gdwarf-2 -g
#debug: prod
prod: CPP += -g3 -gdwarf-2 -g
prod:
	$(CPP)  CBSServer.cpp $(LDFLAGS) -o cbs_prod.bin

#CBSServer:	$(OBJS)
#	$(CXX) -o $@ $^
#
#%.o:	$(PROJECT_ROOT)%.cpp
#	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) "mysql_config --cflags --libs" -o $@ $<
#
#%.o:	$(PROJECT_ROOT)%.c 
#	$(CC) -c $(CFLAGS) $(CPPFLAGS) "mysql_config --cflags --libs" -o $@ $<

clean:
	rm -fr CBSServer $(OBJS)
