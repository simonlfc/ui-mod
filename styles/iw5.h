#define IW5_CHOICE_X_SIZE						336
#define IW5_CHOICE_Y_SIZE						17.3
#define IW5_CHOICE_X_START						-100
#define IW5_CHOICE_Y_START					    45
#define IW5_CHOICE_X_SPACING					250
#define IW5_CHOICE_Y_COUNT						20
#define IW5_CHOICE_Y_SPACING					20
#define IW5_CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_LEFT
#define IW5_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_TOP
#define IW5_CHOICE_ROW( idx )					( ( idx - 0 ) % IW5_CHOICE_Y_COUNT )
#define IW5_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % IW5_CHOICE_Y_COUNT ) ) / IW5_CHOICE_Y_COUNT )
#define IW5_CHOICE_X( idx ) 					( IW5_CHOICE_X_START + IW5_CHOICE_X_SPACING * IW5_CHOICE_COL( idx ) )
#define IW5_CHOICE_Y( idx ) 					( IW5_CHOICE_Y_START + IW5_CHOICE_Y_SPACING * IW5_CHOICE_ROW( idx ) )
#define IW5_CHOICE_ORIGIN( idx )				IW5_CHOICE_X( idx ) IW5_CHOICE_Y( idx )
#define IW5_CHOICE_RECT( idx )					IW5_CHOICE_ORIGIN( idx ) IW5_CHOICE_X_SIZE IW5_CHOICE_Y_SIZE IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN

#define IW5_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           TEXTSIZE_SMALL \
        textstyle           ITEM_TEXTSTYLE_NORMAL \
        textalign           ITEM_ALIGN_MIDDLE_RIGHT \
        textalignx          -25 \
        textaligny          -0.5 \
        forecolor           1 1 1 1

#define IW5_CREATE_SEPARATOR( idx ) \
        CREATE_SHADER_VIS( ( IW5_CHOICE_X( idx ) + 144 ) ( IW5_CHOICE_Y( idx ) - 2.5 ) 192 1 IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN, "gradient_fadein", 1 1 1 0.25, IS_IW5 ) \

#define IW5_CREATE_BUTTON( idx, string, action_ ) \
        CREATE_SHADER_EX( IW5_CHOICE_RECT( idx ), "gradient_fadein", 0 0 0 0, IS_IW5, group string ) \
        CREATE_SHADER_ALT( IW5_CHOICE_X( idx ) ( IW5_CHOICE_Y( idx ) + IW5_CHOICE_Y_SIZE ) IW5_CHOICE_X_SIZE 3.6667 IW5_CHOICE_HORIZONTAL_ALIGN IW5_CHOICE_VERTICAL_ALIGN, "gradient_top", 0 0 0 0, IS_IW5, group string ) \
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
                setItemColor string forecolor 0.488 0.520 0.465 1; \
                setItemColor string backcolor 1 1 1 1; \
				play "mouse_over"; \
			} \
            leaveFocus \
            { \
                setItemColor string forecolor 0 0 0 0; \
                setItemColor string backcolor 0 0 0 0; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define IW5_BG \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw5_bg", 1 1 1 1, IS_IW5 ) \
        CREATE_SHADER_VIS( -426.667 -36 853.333 480 2 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_EX( -574.85 0 1708 480 0 0, "uim_iw5_smoke", 0.35 0.35 0.35 1, IS_IW5, exp rect X ( ( -107 ) - ( ( float( milliseconds() % 60000 ) / 60000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_EX( -228.78 0 -1708 -480 0 0, "uim_iw5_smoke", 0.35 0.35 0.35 1, IS_IW5, exp rect X ( ( -107 + 854 ) - ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_VIS( -427 -240 854 480 2 2, "gradient", 0.6 0.65 0.6 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( 237.5 -236 13 680 1 1, "gradient", 1 1 1 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( -64 -36 301.5 480 1 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 236 -36 1 480 1 1, "white", 1 1 1 0.1, IS_IW5 )

#define IW5_INGAME \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 237.5 -236 13 680 1 1, "gradient", 1 1 1 0.75, IS_IW5 ) \
        CREATE_SHADER_VIS( -64 -36 301.5 480 1 1, "white", 0 0 0 0.4, IS_IW5 ) \
        CREATE_SHADER_VIS( 236 -36 1 480 1 1, "white", 1 1 1 0.1, IS_IW5 )