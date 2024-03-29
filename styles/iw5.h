#define IW5_CHOICE_X_SIZE						336
#define IW5_CHOICE_Y_SIZE						17.3
#define IW5_CHOICE_X_START						-100
#define IW5_CHOICE_Y_START					    45
#define IW5_CHOICE_X_SPACING					250
#define IW5_CHOICE_Y_COUNT						20
#define IW5_CHOICE_Y_SPACING					( IW5_CHOICE_Y_SIZE + 2.7 )
#define IW5_CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_LEFT
#define IW5_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_TOP
#define IW5_CHOICE_ROW( idx )					( ( idx - 0 ) % IW5_CHOICE_Y_COUNT )
#define IW5_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % IW5_CHOICE_Y_COUNT ) ) / IW5_CHOICE_Y_COUNT )
#define IW5_CHOICE_X( idx ) 					( IW5_CHOICE_X_START + IW5_CHOICE_X_SPACING * IW5_CHOICE_COL( idx ) )
#define IW5_CHOICE_Y( idx ) 					( IW5_CHOICE_Y_START + IW5_CHOICE_Y_SPACING * IW5_CHOICE_ROW( idx ) )
#define IW5_CHOICE_ORIGIN( idx )				IW5_CHOICE_X( idx ) IW5_CHOICE_Y( idx )
#define IW5_CHOICE_RECT( idx )					IW5_CHOICE_ORIGIN( idx ) IW5_CHOICE_X_SIZE IW5_CHOICE_Y_SIZE IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN
#define IW5_CHOICE_X_OFFSET                     -25
#define IW5_TEXTALIGN                           ITEM_ALIGN_MIDDLE_RIGHT

#ifdef POPUP && POPUP == 1
#undef IW5_CHOICE_X_SIZE			#define IW5_CHOICE_X_SIZE					IW5_POPUP_WIDTH
#undef IW5_CHOICE_Y_SIZE			#define IW5_CHOICE_Y_SIZE					20
#undef IW5_CHOICE_Y_SPACING			#define IW5_CHOICE_Y_SPACING				22
#undef IW5_CHOICE_X_START			#define IW5_CHOICE_X_START					( IW5_POPUP_WIDTH - IW5_CHOICE_X_SIZE )
#undef IW5_CHOICE_Y_START			#define IW5_CHOICE_Y_START					( IW5_POPUP_HEIGHT - ( IW5_CHOICE_Y_SPACING * ITEM_COUNT ) - 4 )
#undef IW5_CHOICE_HORIZONTAL_ALIGN	#define IW5_CHOICE_HORIZONTAL_ALIGN			HORIZONTAL_ALIGN_CENTER
#undef IW5_CHOICE_VERTICAL_ALIGN	#define IW5_CHOICE_VERTICAL_ALIGN			VERTICAL_ALIGN_CENTER
#undef IW5_TEXTALIGN				#define IW5_TEXTALIGN						ITEM_ALIGN_MIDDLE_LEFT
#undef IW5_CHOICE_X_OFFSET			#define IW5_CHOICE_X_OFFSET					8
#endif

#define IW5_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           TEXTSIZE_SMALL \
        textstyle           ITEM_TEXTSTYLE_NORMAL \
        textalign           IW5_TEXTALIGN \
        textalignx          IW5_CHOICE_X_OFFSET \
        textaligny          -0.5 \
        forecolor           1 1 1 1

#define IW5_CREATE_SEPARATOR( idx ) \
        CREATE_SHADER_VIS( ( IW5_CHOICE_X( idx ) + 144 ) ( IW5_CHOICE_Y( idx ) - 2.5 ) 192 1 IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN, "gradient_fadein", 1 1 1 0.25, IS_IW5 ) \

#define IW5_CREATE_BUTTON( idx, string, action_ ) \
        CREATE_SHADER_EX( IW5_CHOICE_RECT( idx ), "white", 0 0 0 0, IS_IW5 && POPUP == 1, name choice_button_fade##idx ) \
        CREATE_SHADER_EX( IW5_CHOICE_RECT( idx ), "gradient_fadein", 0 0 0 0, IS_IW5, group choice_button_##idx ) \
        CREATE_SHADER_ALT( IW5_CHOICE_X( idx ) ( IW5_CHOICE_Y( idx ) + IW5_CHOICE_Y_SIZE ) IW5_CHOICE_X_SIZE 3.6667 IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN, "gradient_top", 0 0 0 0, IS_IW5, group choice_button_##idx ) \
		itemDef \
		{ \
			rect 			IW5_CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_EMPTY \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility && IS_IW5 ) \
            IW5_TEMPLATE_TEXT_MENU \
            onFocus \
			{ \
                setItemColor choice_button_##idx forecolor 0.488 0.520 0.465 1; \
                setItemColor choice_button_fade##idx forecolor 0.488 0.520 0.465 0.4; \
                setItemColor choice_button_##idx backcolor 1 1 1 1; \
				play "mouse_over"; \
			} \
            leaveFocus \
            { \
                setItemColor choice_button_##idx forecolor 0 0 0 0; \
                setItemColor choice_button_fade##idx forecolor 0 0 0 0; \
                setItemColor choice_button_##idx backcolor 0 0 0 0; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define IW5_BG( string, blur ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw5_bg", 1 1 1 1, IS_IW5 && !blur ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw5_bg_blur", 1 1 1 1, IS_IW5 && blur ) \
        CREATE_SHADER_EX( 0 0 1708 480 0 0, "uim_iw5_smoke", 0.35 0.35 0.35 1, IS_IW5, exp rect X ( ( -107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_EX( 0 0 -1708 -480 0 0, "uim_iw5_smoke", 0.35 0.35 0.35 1, IS_IW5, exp rect X ( ( -107 + 854 ) + ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_VIS( -426.667 -36 853.333 480 2 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 237.5 -236 13 680 1 1, "gradient", 1 1 1 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( -64 -36 301.5 480 1 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 236 -36 1 480 1 1, "white", 1 1 1 0.1, IS_IW5 ) \
	    CREATE_TEXT( -63 13 276.667 24.233 1 1, string, 1 1 1 1, IS_IW5,  \
	    		textfont 		UI_FONT_LARGE; \
	    		textalign 		ITEM_ALIGN_BOTTOM_RIGHT; \
	    		textscale 		0.5; \
	    		autowrapped )

#define IW5_INGAME( string ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 237.5 -236 13 680 1 1, "gradient", 1 1 1 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( -64 -36 301.5 480 1 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 236 -36 1 480 1 1, "white", 1 1 1 0.1, IS_IW5 ) \
	    CREATE_TEXT( -63 13 276.667 24.233 1 1, string, 1 1 1 1, IS_IW5,  \
	    		textfont 		UI_FONT_LARGE; \
	    		textalign 		ITEM_ALIGN_BOTTOM_RIGHT; \
	    		textscale 		0.5; \
	    		autowrapped )


#define IW5_POPUP_WIDTH                 ( 260 )
#define IW5_POPUP_HEIGHT                ( 75 + ( IW5_CHOICE_Y_SPACING * ITEM_COUNT ) )

#define IW5_POPUP( title, desc ) \
        CREATE_SHADER_VIS( -1000 -1000 2000 2000 2 2, "white", 0 0 0 0.8, IS_IW5 ) \
        CREATE_SHADER_VIS( 0 0 IW5_POPUP_WIDTH IW5_POPUP_HEIGHT 0 0, "white", 0.3098 0.349 0.2745 1, IS_IW5 ) \
        CREATE_SHADER_VIS( 0 0 IW5_POPUP_WIDTH 24 0 0, "white", 0.1569 0.1725 0.1608 1, IS_IW5 ) \
        CREATE_SHADER_VIS( 0 24 IW5_POPUP_WIDTH 5 0 0, "gradient_top", 1 1 1 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( 0 24 IW5_POPUP_WIDTH 2 0 0, "white", 0 0 0 1, IS_IW5 ) \
        CREATE_SHADER_VIS( 0 IW5_CHOICE_Y_START IW5_POPUP_WIDTH ( IW5_CHOICE_Y_SPACING * ITEM_COUNT ) 0 0, "white", 0.2118 0.2314 0.22 1, IS_IW5 ) \
        CREATE_TEXT( 0 0 IW5_POPUP_WIDTH 24 0 0, title, 1 1 1 1, IS_IW5,    textfont        9 \
			                                                                textscale		TEXTSIZE_SMALL \
			                                                                textalign		ITEM_ALIGN_MIDDLE_LEFT \
                                                                            textalignx      9 ) \
        CREATE_TEXT( 0 24 IW5_POPUP_WIDTH IW5_POPUP_HEIGHT 0 0, desc, 1 1 1 1, IS_IW5,      textfont        UI_FONT_DEFAULT \
			                                                                                textscale		TEXTSIZE_SMALL \
			                                                                                textalign		ITEM_ALIGN_TOP_LEFT \
                                                                                            textalignx      9 \
                                                                                            textaligny      3 )