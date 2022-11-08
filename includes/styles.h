#include "ui_mp/styles/iw2.h"
#include "ui_mp/styles/iw3.h"
#include "ui_mp/styles/iw4.h"
#include "ui_mp/styles/iw5.h"

#define IS_IW2  dvarString( "ui_menustyle" ) == "iw2"
#define IS_IW3  dvarString( "ui_menustyle" ) == "iw3"
#define IS_IW4  dvarString( "ui_menustyle" ) == "iw4"
#define IS_IW5  dvarString( "ui_menustyle" ) == "iw5"

#define DEBUG 	1

#define STYLE_OPEN \
		close "self"; \
		if ( IS_IW2 ) { setDvar "ui_bigFont" 0.4; setDvar "ui_extraBigFont" 0.55; setDvar "ui_smallFont" 0.25; open MENU_NAME"_iw2"; } \
		if ( IS_IW3 ) { setDvar "ui_bigFont" 0.4; setDvar "ui_extraBigFont" 0.55; setDvar "ui_smallFont" 0.25; open MENU_NAME"_iw3"; } \
		if ( IS_IW4 ) { setDvar "ui_bigFont" 0.688; setDvar "ui_extraBigFont" 1; setDvar "ui_smallFont" 0.563; open MENU_NAME"_iw4"; } \
		if ( IS_IW5 ) { setDvar "ui_bigFont" 0.688; setDvar "ui_extraBigFont" 1; setDvar "ui_smallFont" 0.563; open MENU_NAME"_iw5"; }

#define ADD_BASE_MENU \
		name 				MENU_NAME \
		rect 				0 0 640 480 0 0; \
		onOpen \
		{ \
			STYLE_OPEN; \
		}