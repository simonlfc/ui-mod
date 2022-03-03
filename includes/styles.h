#include "ui_mp/styles/iw2.h"
#include "ui_mp/styles/iw3.h"

#define IS_IW2  dvarString( "ui_menustyle" ) == "iw2"
#define IS_IW3  dvarString( "ui_menustyle" ) == "iw3"
#define IS_IW4  dvarString( "ui_menustyle" ) == "iw4"
#define IS_IW5  dvarString( "ui_menustyle" ) == "iw5"

#define STYLE_OPEN( iw2, iw3, iw4, iw5 ) \
		close "self"; \
		if ( IS_IW2 ) { open iw2; ) } \
		if ( IS_IW3 ) { open iw3; ) } \
		if ( IS_IW4 ) { open iw4; ) } \
		if ( IS_IW5 ) { open iw5; ) } 