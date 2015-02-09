#  Makefile 
#  Auteur : Vincent Boyer
#  Email  : boyer@ai.univ-paris8.fr
#  Date   : October, 2013

CC = gcc
CFLAGS = -Wall  -O3
LDFLAGS = -lm -lGL -lGLU -lglut 
PROGNAME = StarWars
SRC =mainEtcalcul.c bmp.c glm.c collision.c display.c initialiser.c dessine.c
OBJS = $(SRC:.c=.o)

all: $(PROGNAME)

$(PROGNAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	@rm $(PROGNAME) $(OBJS) *~ 

