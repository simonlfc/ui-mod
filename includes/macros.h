#define CREATE_SHADER( position, texture, colour ) \
		CREATE_SHADER_VIS( position, texture, colour, 1 )

#define CREATE_SHADER_VIS( position, texture, colour, visibility ) \
		CREATE_SHADER_EX( position, texture, colour, visibility, ; )

#define CREATE_SHADER_EX( position, texture, colour, visibility, extra ) \
		itemDef \
		{ \
			style 			WINDOW_STYLE_SHADER \
			rect 			position \
			forecolor 		colour \
			exp 			material ( texture ) \
			visible 		when ( visibility ) \
			decoration 		\
			extra			\
		}

#define CREATE_SHADER_ALT( position, texture, colour, visibility, extra ) \
		itemDef \
		{ \
			style 			WINDOW_STYLE_FILLED \
			rect 			position \
			backcolor 		colour \
			background		texture \
			visible 		when ( visibility ) \
			decoration 		\
			extra			\
		}

#define CREATE_TEXT( pos, string, color, visibility, extras ) \
		itemDef \
		{ \
			rect 			pos \
			style 			1 \
			forecolor 		color \
			exp 			text ( string ) \
			visible 		when ( visibility ) \
			decoration \
			extras \
		}

#define DEBUG_STYLE_BUTTON( x, string, action_ ) \
		itemDef \
		{ \
			rect 			x -10 50 16 1 1 \
			style 			1 \
			visible 		1 \
			forecolor 		1 1 1 1 \
			backcolor		1 1 1 0.1 \
			type 			1 \
			text 			string \
			textfont 		UI_FONT_SMALL \
			textalign 		ITEM_ALIGN_MIDDLE_CENTER \
			textscale 		0.2 \
			border 			1 \
			bordersize		0.1 \
			bordercolor		1 1 1 0.1 \
			action \
			{ \
				close 		"self"; \
				action_; \
			} \
		}

// Because different games use a different focusColor, these are useless (...unless?)
#define CREATE_BUTTON( idx, string, action_ ) \
		IW2_CREATE_BUTTON( idx, string, action_ ) \
		IW3_CREATE_BUTTON( idx, string, action_ ) \
		IW4_CREATE_BUTTON( idx, string, action_ ) \
		IW5_CREATE_BUTTON( idx, string, action_ )

#define CREATE_SEPARATOR( idx ) \
		IW4_CREATE_SEPARATOR( idx ) \
		IW5_CREATE_SEPARATOR( idx )

#define STYLE_WIDGET \
		DEBUG_STYLE_BUTTON( -30, "Refresh Style", close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 20, "Restart Menus", exec "snd_restart"; ) \
		DEBUG_STYLE_BUTTON( 70, "Rust Devmap", exec "devmap mp_rust"; ) \
		DEBUG_STYLE_BUTTON( 120, "connect", close "self"; open "connect"; ) \
		DEBUG_STYLE_BUTTON( 170, "main_text", close "self"; open "main_text"; ) \
		DEBUG_STYLE_BUTTON( 220, "quit_popmenu", open "quit_popmenu"; ) \
		DEBUG_STYLE_BUTTON( 270, "Set to IW2", setDvar ui_menustyle "iw2"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 320, "Set to IW3", setDvar ui_menustyle "iw3"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 370, "Set to IW4", setDvar ui_menustyle "iw4"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 420, "Set to IW5", setDvar ui_menustyle "iw5"; close "self"; open MENU_NAME; )