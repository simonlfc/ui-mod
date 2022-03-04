#define IW2_CHOICE_X_SIZE						210
#define IW2_CHOICE_Y_SIZE						20
#define IW2_CHOICE_X_START						385
#define IW2_CHOICE_Y_START						140
#define IW2_CHOICE_X_SPACING					( IW2_CHOICE_X_SIZE + 5 )
#define IW2_CHOICE_Y_COUNT						20
#define IW2_CHOICE_Y_SPACING					( IW2_CHOICE_Y_SIZE + 10 )
#define IW2_CHOICE_HORIZONTAL_ALIGN 			HORIZONTAL_ALIGN_DEFAULT
#define IW2_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_DEFAULT
#define IW2_CHOICE_ROW( idx )					( ( idx - 0 ) % IW2_CHOICE_Y_COUNT )
#define IW2_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % IW2_CHOICE_Y_COUNT ) ) / IW2_CHOICE_Y_COUNT )
#define IW2_CHOICE_X( idx ) 					( IW2_CHOICE_X_START + IW2_CHOICE_X_SPACING * IW2_CHOICE_COL( idx ) )
#define IW2_CHOICE_Y( idx ) 					( IW2_CHOICE_Y_START + IW2_CHOICE_Y_SPACING * IW2_CHOICE_ROW( idx ) )
#define IW2_CHOICE_ORIGIN( idx )				IW2_CHOICE_X( idx ) IW2_CHOICE_Y( idx )
#define IW2_CHOICE_RECT( idx )					IW2_CHOICE_ORIGIN( idx ) IW2_CHOICE_X_SIZE IW2_CHOICE_Y_SIZE IW2_CHOICE_HORIZONTAL_ALIGN IW2_CHOICE_VERTICAL_ALIGN

#define IW2_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           0.4 \
        textstyle           ITEM_TEXTSTYLE_SHADOWED \
        textalign           ITEM_ALIGN_TOP_LEFT \
        forecolor           0.9 0.9 0.9 0.9 

#define IW2_CREATE_BUTTON( idx, string, action_ ) \
		itemDef \
		{ \
			rect 			IW2_CHOICE_RECT( idx ) \
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
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_iw2_bg", 1 1 1 1, IS_IW2 ) \
        CREATE_SHADER_EX( -5 -5 660 65 4 8, "white", 0 0 0 0.85, IS_IW2, border 1; bordersize 1; bordercolor 0.9 0.9 0.9 1 ) \
        CREATE_SHADER_EX( -5 -60 660 65 4 10, "white", 0 0 0 0.85, IS_IW2, border 1; bordersize 1; bordercolor 0.9 0.9 0.9 1 )

#define IW2_INGAME \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "gradient", 1 1 1 1, IS_IW2 ) \
        CREATE_SHADER_EX( -5 -5 660 65 4 8, "white", 0 0 0 0.85, IS_IW2, border 1; bordersize 1; bordercolor 0.9 0.9 0.9 1 ) \
        CREATE_SHADER_EX( -5 -60 660 65 4 10, "white", 0 0 0 0.85, IS_IW2, border 1; bordersize 1; bordercolor 0.9 0.9 0.9 1 )