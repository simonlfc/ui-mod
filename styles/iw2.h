#ifndef CHOICE_X_SIZE	
#define CHOICE_X_SIZE						210
#endif	

#ifndef CHOICE_Y_SIZE	
#define CHOICE_Y_SIZE						20
#endif	

#ifndef CHOICE_X_START	
#define CHOICE_X_START						385
#endif	

#ifndef CHOICE_Y_START	
#define CHOICE_Y_START						190
#endif	

#ifndef CHOICE_X_SPACING	
#define CHOICE_X_SPACING					( CHOICE_X_SIZE + 5 )
#endif	

#ifndef CHOICE_Y_COUNT	
#define CHOICE_Y_COUNT						20
#endif	

#ifndef CHOICE_Y_SPACING	
#define CHOICE_Y_SPACING					( CHOICE_Y_SIZE + 10 )
#endif	

#ifndef CHOICE_HORIZONTAL_ALIGN	
#define CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_DEFAULT
#endif	

#ifndef CHOICE_VERTICAL_ALIGN	
#define CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_DEFAULT
#endif

#define CHOICE_ROW( idx )					( ( idx - 0 ) % CHOICE_Y_COUNT )
#define CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % CHOICE_Y_COUNT ) ) / CHOICE_Y_COUNT )
#define CHOICE_X( idx ) 					( CHOICE_X_START + CHOICE_X_SPACING * CHOICE_COL( idx ) )
#define CHOICE_Y( idx ) 					( CHOICE_Y_START + CHOICE_Y_SPACING * CHOICE_ROW( idx ) )
#define CHOICE_ORIGIN( idx )				CHOICE_X( idx ) CHOICE_Y( idx )
#define CHOICE_RECT( idx )					CHOICE_ORIGIN( idx ) CHOICE_X_SIZE CHOICE_Y_SIZE CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN

#define IW2_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           0.4 \
        textstyle           ITEM_TEXTSTYLE_SHADOWED \
        textalign           ITEM_ALIGN_LEGACY_LEFT \
        forecolor           0.9 0.9 0.9 0.9 

#define IW2_CREATE_BUTTON( idx, string, action_ ) \
		itemDef \
		{ \
			rect 			CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_EMPTY \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility && IS_IW2 ) \
            IW2_TEMPLATE_TEXT_MENU \
            onFocus \
			{ \
				play "mouse_over"; \
			} \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define IW2_BG \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "mw2_main_co_image", 0 0.45 1 0.5, IS_IW2 ) \
        CREATE_SHADER_EX( -10 0 660 75 4 4, "white", 0 0 0 0.85, IS_IW2, border 1; bordersize 1; bordercolor 1 1 1 0.55 )