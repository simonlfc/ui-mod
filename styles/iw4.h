#define IW4_CHOICE_X_SIZE						336
#define IW4_CHOICE_Y_SIZE						20
#define IW4_CHOICE_X_START						-64
#define IW4_CHOICE_Y_START					    48
#define IW4_CHOICE_X_SPACING					250
#define IW4_CHOICE_Y_COUNT						20
#define IW4_CHOICE_Y_SPACING					IW4_CHOICE_Y_SIZE
#define IW4_CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_LEFT
#define IW4_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_TOP
#define IW4_CHOICE_ROW( idx )					( ( idx - 0 ) % IW4_CHOICE_Y_COUNT )
#define IW4_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % IW4_CHOICE_Y_COUNT ) ) / IW4_CHOICE_Y_COUNT )
#define IW4_CHOICE_X( idx ) 					( IW4_CHOICE_X_START + IW4_CHOICE_X_SPACING * IW4_CHOICE_COL( idx ) )
#define IW4_CHOICE_Y( idx ) 					( IW4_CHOICE_Y_START + IW4_CHOICE_Y_SPACING * IW4_CHOICE_ROW( idx ) )
#define IW4_CHOICE_ORIGIN( idx )				IW4_CHOICE_X( idx ) IW4_CHOICE_Y( idx )
#define IW4_CHOICE_RECT( idx )					IW4_CHOICE_ORIGIN( idx ) IW4_CHOICE_X_SIZE IW4_CHOICE_Y_SIZE IW4_CHOICE_HORIZONTAL_ALIGN IW4_CHOICE_VERTICAL_ALIGN

#define IW4_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           TEXTSIZE_SMALL \
        textstyle           ITEM_TEXTSTYLE_NORMAL \
        textalign           ITEM_ALIGN_MIDDLE_RIGHT \
        textalignx          -60 \
        textaligny          -0.5 \
        forecolor           1 1 1 1

#define IW4_CREATE_SEPARATOR( idx ) \
        CREATE_SHADER_VIS( ( IW4_CHOICE_X( idx ) + 40 ) IW4_CHOICE_Y( idx ) 240 1 IW4_CHOICE_HORIZONTAL_ALIGN IW4_CHOICE_VERTICAL_ALIGN, "gradient_fadein", 1 1 1 0.65, IS_IW4 ) \

#define IW4_CREATE_BUTTON( idx, string, action_ ) \
        CREATE_SHADER_EX( IW4_CHOICE_RECT( idx ), "menu_button_selection_bar", 0 0 0 0, IS_IW4, group choice_button_##idx ) \
		itemDef \
		{ \
			rect 			IW4_CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_EMPTY \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility && IS_IW4 ) \
            IW4_TEMPLATE_TEXT_MENU \
            onFocus \
			{ \
                setItemColor choice_button_##idx forecolor 0 0 0 1; \
				play "mouse_over"; \
			} \
            leaveFocus \
            { \
                setItemColor choice_button_##idx forecolor 0 0 0 0; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define IW4_BG( string ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw4_bg", 1 1 1 1, IS_IW4 ) \
        CREATE_SHADER_EX( 0 0 1708 480 0 0, "uim_iw4_smoke", 1 1 1 0.5, IS_IW4, exp rect X ( ( -107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_EX( 0 0 -1708 -480 0 0, "uim_iw4_smoke", 1 1 1 0.5, IS_IW4, exp rect X ( ( -107 + 854 ) - ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_VIS( -427 -240 854 480 2 2, "uim_iw4_bg_front", 1 1 1 1, IS_IW4 ) \
        CREATE_SHADER_EX( 0 0 640 480 4 4, "uim_iw4_glow", 1 1 1 0, IS_IW4, exp forecolor a ( ( ( sin( milliseconds( ) / 1500 ) + 1 ) * 0.25 ) + 0.25 ) ) \
        CREATE_SHADER_EX( 0 0 640 480 4 4, "uim_iw4_glow", 1 1 1 0, IS_IW4, exp forecolor a ( ( ( sin( milliseconds( ) / 480 ) + 1 ) * 0.25 ) + 0.25 ) ) \
        CREATE_SHADER_VIS( -64 0 280 480 1 0, "gradient_fadein_fadebottom", 1 1 1 0.1, IS_IW4 ) \
        CREATE_TEXT( -60 0 272 28 1 1, string, 1 1 1 1, IS_IW4,  \
                textfont 		UI_FONT_LARGE; \
                textalign 		ITEM_ALIGN_TOP_RIGHT; \
                textscale 		0.5; \
                autowrapped )

#define IW4_INGAME( string ) \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "white", 0 0 0 0.4, IS_IW4 ) \
        CREATE_SHADER_EX( 0 0 640 480 4 4, "uim_iw4_glow", 1 1 1 0, IS_IW4, exp forecolor a ( ( ( sin( milliseconds( ) / 1500 ) + 1 ) * 0.25 ) + 0.25 ) ) \
        CREATE_SHADER_EX( 0 0 640 480 4 4, "uim_iw4_glow", 1 1 1 0, IS_IW4, exp forecolor a ( ( ( sin( milliseconds( ) / 480 ) + 1 ) * 0.25 ) + 0.25 ) ) \
        CREATE_SHADER_VIS( -64 0 280 480 1 0, "gradient_fadein_fadebottom", 0 0 0 0.25, IS_IW4 ) \
        CREATE_TEXT( -60 0 272 28 1 1, string, 1 1 1 1, IS_IW4,  \
                textfont 		UI_FONT_LARGE; \
                textalign 		ITEM_ALIGN_TOP_RIGHT; \
                textscale 		0.5; \
                autowrapped )