#define T4_CHOICE_X_SIZE						224
#define T4_CHOICE_Y_SIZE						22
#define T4_CHOICE_X_START						-75
#define T4_CHOICE_Y_START					    110
#define T4_CHOICE_X_SPACING					    ( T4_CHOICE_X_SIZE + 5 )
#define T4_CHOICE_Y_COUNT						20
#define T4_CHOICE_Y_SPACING					    ( T4_CHOICE_Y_SIZE + 2 )
#define T4_CHOICE_HORIZONTAL_ALIGN 			    HORIZONTAL_ALIGN_DEFAULT
#define T4_CHOICE_VERTICAL_ALIGN 				VERTICAL_ALIGN_DEFAULT
#define T4_CHOICE_ROW( idx )					( ( idx - 0 ) % T4_CHOICE_Y_COUNT )
#define T4_CHOICE_COL( idx )					( ( idx - 0 - ( ( idx - 0 ) % T4_CHOICE_Y_COUNT ) ) / T4_CHOICE_Y_COUNT )
#define T4_CHOICE_X( idx ) 					    ( T4_CHOICE_X_START + T4_CHOICE_X_SPACING * T4_CHOICE_COL( idx ) )
#define T4_CHOICE_Y( idx ) 					    ( T4_CHOICE_Y_START + T4_CHOICE_Y_SPACING * T4_CHOICE_ROW( idx ) )
#define T4_CHOICE_ORIGIN( idx )				    T4_CHOICE_X( idx ) T4_CHOICE_Y( idx )
#define T4_CHOICE_RECT( idx )					T4_CHOICE_ORIGIN( idx ) T4_CHOICE_X_SIZE T4_CHOICE_Y_SIZE T4_CHOICE_HORIZONTAL_ALIGN T4_CHOICE_VERTICAL_ALIGN

#define T4_TEMPLATE_TEXT_MENU \
        textfont            UI_FONT_DEFAULT \
        textscale           0.4 \
        textstyle           ITEM_TEXTSTYLE_SHADOWED \
        textalign           ITEM_ALIGN_MIDDLE_LEFT \
        textalignx          22 \
        textaligny          -0.5 \
        forecolor           0.9 0.9 0.92 0.75

#define T4_CREATE_SEPARATOR( idx ) \
        CREATE_SHADER_VIS( T4_CHOICE_X( idx ) ( T4_CHOICE_Y( idx ) + 5.5 ) T4_CHOICE_X_SIZE 1 T4_CHOICE_HORIZONTAL_ALIGN T4_CHOICE_VERTICAL_ALIGN, "uim_t4_button", 1 1 1 0.7, IS_T4 ) \

#define T4_CREATE_BUTTON( idx, string, action_ ) \
		itemDef \
		{ \
			rect 			T4_CHOICE_RECT( idx ) \
			exp				text ( string ) \
            style           WINDOW_STYLE_FILLED \
            type            ITEM_TYPE_BUTTON \
			visible 		when ( visibility && IS_T4 ) \
            background      "uim_t4_button" \
            backcolor       0.1 0.1 0.1 0.5; \
            T4_TEMPLATE_TEXT_MENU \
            onFocus \
			{ \
                setBackground "uim_t4_button_highlight"; \
                setItemColor self backcolor 0.9 0.95 1 0.5; \
				play "mouse_over"; \
			} \
            leaveFocus \
            { \
                setBackground "uim_t4_button"; \
                setItemColor self backcolor 0.1 0.1 0.1 0.5; \
            } \
			action \
			{ \
				play "mouse_click"; \
                action_; \
            } \
		}

#define T4_BG \
        CREATE_SHADER_VIS( 0 0 640 480 4 4, "uim_t4_bg", 1 1 1 1, IS_T4 ) \
        CREATE_SHADER_EX( -107 0 1708 480 4 4, "uim_t4_bg_fogscroll_thin", 1 1 1 1, IS_T4, exp rect X ( ( -961 ) - ( ( float( milliseconds() % 50000 ) / 50000 ) * ( 854 ) ) ) ) \
        CREATE_SHADER_VIS( -107 0 854 66 0 0, "white", 0 0 0 1, IS_T4 ) \
        CREATE_SHADER_VIS( -107 420 854 70 0 0, "white", 0 0 0 1, IS_T4 )