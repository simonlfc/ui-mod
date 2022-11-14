#define IW3_CHOICE_X_SIZE						220
#define IW3_CHOICE_Y_SIZE						22
#define IW3_CHOICE_X_START						-60
#define IW3_CHOICE_Y_START					    -80
#define IW3_CHOICE_X_SPACING					( IW3_CHOICE_X_SIZE + 5 )
#define IW3_CHOICE_Y_COUNT						20
#define IW3_CHOICE_Y_SPACING					( IW3_CHOICE_Y_SIZE + 2 )
#define IW3_CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_LEFT
#define IW3_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_CENTER
#define IW3_CHOICE_ROW( idx )					( ( idx - 0 ) % IW3_CHOICE_Y_COUNT )
#define IW3_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % IW3_CHOICE_Y_COUNT ) ) / IW3_CHOICE_Y_COUNT )
#define IW3_CHOICE_X( idx ) 					( IW3_CHOICE_X_START + IW3_CHOICE_X_SPACING * IW3_CHOICE_COL( idx ) )
#define IW3_CHOICE_Y( idx ) 					( IW3_CHOICE_Y_START + IW3_CHOICE_Y_SPACING * IW3_CHOICE_ROW( idx ) )
#define IW3_CHOICE_ORIGIN( idx )				IW3_CHOICE_X( idx ) IW3_CHOICE_Y( idx )
#define IW3_CHOICE_RECT( idx )					IW3_CHOICE_ORIGIN( idx ) IW3_CHOICE_X_SIZE IW3_CHOICE_Y_SIZE IW3_CHOICE_HORIZONTAL_ALIGN IW3_CHOICE_VERTICAL_ALIGN

#define IW3_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           0.4 \
        textstyle           ITEM_TEXTSTYLE_SHADOWEDMORE \
        textalign           ITEM_ALIGN_MIDDLE_RIGHT \
        textalignx          -5 \
        textaligny          -0.5 \
        forecolor           0.9 0.9 0.92 0.75

#define IW3_CREATE_SEPARATOR( idx ) \
        CREATE_SHADER_VIS( IW3_CHOICE_X( idx ) ( IW3_CHOICE_Y( idx ) + 1 ) IW3_CHOICE_X_SIZE 8 IW3_CHOICE_HORIZONTAL_ALIGN IW3_CHOICE_VERTICAL_ALIGN, "gradient_fadein", 0.9 0.9 1 0.07, IS_IW3 ) \

#define IW3_CREATE_BUTTON( idx, string, action_ ) \
        IW3_CREATE_BUTTON_VIS( idx, string, action_, 1 )

#define IW3_CREATE_BUTTON_VIS( idx, string, action_, visibility ) \
        CREATE_SHADER_EX( IW3_CHOICE_RECT( idx ), "gradient_fadein", 0.9 0.9 1 0.07, visibility && IS_IW3, group choice_button_##idx ) \
        CREATE_SHADER_EX( ( IW3_CHOICE_X( idx ) + IW3_CHOICE_X_SIZE ) IW3_CHOICE_Y( idx ) 5 IW3_CHOICE_Y_SIZE IW3_CHOICE_HORIZONTAL_ALIGN IW3_CHOICE_VERTICAL_ALIGN, "button_highlight_end", 0.9 0.9 1 0.07, visibility && IS_IW3, group choice_button_##idx ) \
		itemDef \
		{ \
			rect 			IW3_CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_EMPTY \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility && IS_IW3 ) \
            IW3_TEMPLATE_TEXT_MENU \
            onFocus \
			{ \
                setItemColor choice_button_##idx forecolor 0.9 0.9 1 0.3; \
				play "mouse_over"; \
			} \
            leaveFocus \
            { \
                setItemColor choice_button_##idx forecolor 0.9 0.9 1 0.07; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define FOG_SCROLL_TIME 60000
#define THINFOG_SCROLL_TIME 100000

#define IW3_BG \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw3_bg_back", 1 1 1 1, IS_IW3 ) \
        CREATE_SHADER_EX( -107 0 1708 480 4 4, "uim_iw3_bg_fogscroll", 1 1 1 1, IS_IW3, exp rect X ( ( -107 ) - ( ( float( milliseconds() % FOG_SCROLL_TIME ) / FOG_SCROLL_TIME ) * ( 854 ) ) ) ) \
        CREATE_SHADER_EX( -107 0 1708 480 4 4, "uim_iw3_bg_fogscroll_thin", 1 1 1 1, IS_IW3, exp rect X ( ( -961 ) - ( ( float( milliseconds() % THINFOG_SCROLL_TIME ) / THINFOG_SCROLL_TIME ) * ( 854 ) ) ) ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw3_bg_front", 1 1 1 1, IS_IW3 ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw3_bg_front2", 1 1 1 1, IS_IW3 )

#define IW3_BG_NAV( string ) \
        CREATE_SHADER_VIS( -120 -32 378 64, "white", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( 258 -32 16 -64, "button_highlight_end", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( 56 448 528 40, "white", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( 584 448 16 64, "button_highlight_end", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( 40 448 -16 64, "button_highlight_end", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( -120 464 160 32, "white", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_SHADER_VIS( 600 464 160 32, "white", 0.9 0.9 0.95 0.175, IS_IW3 ) \
        CREATE_TEXT( 12 3.5 0 0, string, 1 0.8 0.4 1, IS_IW3, textfont		UI_FONT_NORMAL \
			                                                textscale		TEXTSIZE_TITLE \
			                                                textstyle		ITEM_TEXTSTYLE_SHADOWED \
			                                                textalign		ITEM_ALIGN_TOP_LEFT ) \
        itemDef \
	    { \
	    	text			"@MENU_BACK" \
	    	type			ITEM_TYPE_BUTTON \
	    	style			WINDOW_STYLE_FILLED \
	    	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	    	rect			-250 10 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM \
	    	textfont		UI_FONT_NORMAL \
	    	textalign		ITEM_ALIGN_LEFT \
	    	textscale		TEXTSIZE_SMALL \
	    	textaligny		18 \
	    	visible			1 \
            onFocus \
            { \
                play "mouse_over"; \
            } \
	    	action \
	    	{ \
	    		play "mouse_click"; \
                MENU_BACK_ACTION; \
	    	} \
	    }

#define IW3_INGAME \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "white", 0 0 0 0.75, IS_IW3 ) \
        CREATE_SHADER_VIS( 0 0 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0, "gradient_top", 1 1 1 1, IS_IW3 ) \
        CREATE_SHADER_VIS( 0 405 854 75 HORIZONTAL_ALIGN_FULLSCREEN 0, "gradient_bottom", 1 1 1 1, IS_IW3 )