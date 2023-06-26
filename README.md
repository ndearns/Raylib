# Raylib
---
A C++ class that provides an object-oriented facade for the raylib library.

`#include <Raylib.h>` in the the <domain.name>Provided.h file for any client domains that want to use a raylib gui.

Add `object Raylib [archetypes='provided';];` to the <domain.name>.dml file for your domain.

Create an instance of the Raylib object in your model code: `let ui : Raylib = new Raylib;`

Link it to the object that owns the UI: `call the_harness.ui_link( ui );`

Thereafter, access raylib capabilities thru the link: `Call self.ui().turn_logging_off();`

Here's an extract from the TileUI domain's Harness object:

```
object Harness
{
...
    relation ui             : Harness -> Raylib;
...
    proc    main( argc : ArgCount, arg_string : ArgStrings ) : ExitCode
    {
    ...
        let harness     : Harness       = new Harness;
        let the_ui      : Raylib        = new Raylib;
    ...
        call harness.ui_link( the_ui );
    ...
        call harness.start();
    ...
    }

    proc start()
    {
        call self.ui().turn_logging_off();
        call self.ui().init_window( mdx()*tdx(), mdy()*tdy(), 'Harness' );
        call self.ui().set_target_fps( 200 );
    ...
    }
...
}
```
# makefile

Note the dependencies on raylib and other graphical libraries:

```
CC       = g++
CCFLAGS  = -std=c++2a -g -Wall -Ofast
GEN_MODE = async
DOM_NAME = TileUI
DML_DOM  = TileUI.dml
DML_OBJS = Mosaic.dml TileSet.dml Tile.dml PlacedTile.dml Harness.dml 
CPP_OBJS = $(DML_OBJS:.dml=.cpp)
H_OBJS   = $(DML_OBJS:.dml=.h)
LIB_OBJS = $(CPP_OBJS:.cpp=.o)
#--------------------------------------------------------------------------- 
INC_DIRS = -I${DML}/SWA \
		   -I${DML}/Raylib
LIBS     = -L${DML}/SWA -lSWA\
		   -L${DML}/Raylib -lRaylib\
		   -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
#--------------------------------------------------------------------------- 
lib: $(filter-out Harness.o,$(LIB_OBJS)) $(DOM_NAME)Provided.h
	ar -rcs lib$(DOM_NAME).a $(filter-out Harness.o,$(LIB_OBJS))

run: $(LIB_OBJS) $(DOM_NAME)Provided.h
	$(CC) $(CCFLAGS) $(LIB_OBJS) -o run $(LIBS)

gen: *.dml
	dml $(DOM_NAME) $(GEN_MODE)

$(LIB_OBJS): $(CPP_OBJS)
...
```
