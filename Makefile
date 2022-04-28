NAME = adm
CC = gcc
SRC = $(shell find ./ -name "*.c")
OBJ = $(SRC:.c=.o)

#INCLUDE
INCLUDE = ./include
# SUB_DIR_INCLUDE = -I$(INCLUDE)
SUB_DIR_INCLUDE = $(shell find $(INCLUDE) -type d -printf "-I%h/%f/ ")

#FLAGS
CFLAG = -g3 -std=c11
ERRFLAG = -Wextra -Wall -Werror
# BUNNYFLAG =
BUNNYFLAG = -llapin -lsfml-graphics -lsfml-audio -lsfml-window \
-lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc \
-lopencv_objdetect -lopencv_video -lopencv_core -lavcall -lusb

#LIBRARY VARIABLE
# Don't leave LIBPATH variable content blank or the compilation goes wrong.
LIBPATH = temp_unused/
LIBFLAG =
# LIBFLAG = -L $(LIBPATH)

#DON'T TOUCH
ECHO = /bin/echo -e
LIBSDIRECTORIES = $(shell find $(LIBPATH)*/ -maxdepth 0 -type d -printf "$(LIBPATH)%f ")

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED		=	"\033[0;31m"
BLUE	=	"\033[34m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"
INVERT  =	"\033[7m"

all:$(NAME)

%.o : %.c
	@if [ "$(findstring $(LIBPATH),$@)" != $(LIBPATH) ]; then \
	$(CC) -o $@ -c $< $(SUB_DIR_INCLUDE) $(CFLAG) $(ERRFLAG) \
	$(LIBFLAG) $(BUNNYFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT); fi;

$(NAME):$(OBJ)
	@ $(CC) $(shell find ./ -name "*.o") -o $(NAME) \
	$(SUB_DIR_INCLUDE) $(CFLAG) $(ERRFLAG) $(LIBFLAG) $(BUNNYFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $(NAME) $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFLT) \

clean:
	@ find -name "*.o" -delete && find -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT)

fclean:
	@find . -name "*.o" -not -path "./$(LIBPATH)*" -delete \
			-name "*.a" -not -path "./$(LIBPATH)*" -delete \
			-or -name "*.exe" -delete \
        	-or -name "a.out" -delete \
			-or -name "*.so" -delete  \
        	-or -name "*~" -delete \
			-or -name "vgcore*" -delete
	@$(ECHO) $(GREEN) "All temporal file deleted!" $(DEFLT)
	@find -name $(NAME) -delete
	@$(ECHO) $(GREEN) "Executable deleted!" $(DEFLT)

re: 		fclean all

install:	all
	@sudo mv $(NAME) /usr/bin/
	@$(ECHO) $(GREEN) "Program installed!" $(DEFLT)

uninstall:
	@sudo rm -i /usr/bin/$(NAME)
	@$(ECHO) $(GREEN) "Program deleted!" $(DEFLT)


lib: FORCE
	@for path in $(LIBSDIRECTORIES); do \
		$(ECHO) $(BLINK)$(BLUE)" [COMPILING LIBRARY : $$path]"$(DEFLT); \
		cd $$path && make re && mv *.a ../ && \
		cp $(INCLUDE)/*.h ../../include && cd ../../; \
	done

libclean:
	@rm -f $(LIBPATH)*.a
	@$(ECHO) $(GREEN) "[.a static libraries files deleted.]" $(DEFLT)
	@for path in $(LIBSDIRECTORIES); do \
		$(ECHO) $(BLINK)$(BLUE)" [CLEANING LIBRARY : $$path]"$(DEFLT); \
		cd $$path && make fclean && cd ../../; \
	done

libupdate:
	@for path in $(LIBSDIRECTORIES); do \
		$(ECHO) $(BLINK)$(BLUE)" [CHECKING UPDATE OF : $$path]"$(DEFLT); \
		cd $$path && git pull && cd ../../; \
	done
	@make lib

FORCE: