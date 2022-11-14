#include "ui_mp/styles/iw3.h"
#include "ui_mp/styles/iw4.h"
#include "ui_mp/styles/iw5.h"

#define IS_IW3  dvarString( "ui_menustyle" ) == "iw3"
#define IS_IW4  dvarString( "ui_menustyle" ) == "iw4"
#define IS_IW5  dvarString( "ui_menustyle" ) == "iw5"

#define DEBUG 	1

#define STYLE_OPEN \
		close "self"; \
		if ( IS_IW3 ) { open MENU_NAME"_iw3"; } \
		if ( IS_IW4 ) { open MENU_NAME"_iw4"; } \
		if ( IS_IW5 ) { open MENU_NAME"_iw5"; }

#define ADD_BASE_MENU \
		name 				MENU_NAME \
		rect 				0 0 640 480 0 0; \
		onOpen \
		{ \
			if ( dvarString( "ui_menustyle" ) == "" ) \
			{ \
				setDvar "ui_menustyle" "iw3"; \
			} \
			STYLE_OPEN; \
		}

#define iw3 MENU_NAME"_iw3"
#define iw4 MENU_NAME"_iw4"
#define iw5 MENU_NAME"_iw5"


#define ADD_STYLED_MENU( style ) \
		name 				style \
		rect 				0 0 640 480 0 0; \
		forecolor 			1 1 1 1 \
		focuscolor 			1 1 1 1 \
		fullscreen 			1 \
		soundloop 			"music_mainmenu_mp" \
		onEsc \
		{ \
			MENU_BACK_ACTION; \
		}

#define ADD_STYLED_INGAME_MENU( style ) \
		ADD_STYLED_MENU( style ) \
		fullscreen 			0 \
		blurworld 			7 