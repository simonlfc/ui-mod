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
			textscale 		0.225 \
			action \
			{ \
				close 		"self"; \
				action_; \
			} \
		}

#define STYLE_WIDGET \
		DEBUG_STYLE_BUTTON( -30, "Refresh Style", close "self"; open "main_text"; ) \
		DEBUG_STYLE_BUTTON( 20, "Restart Menus", exec "snd_restart"; ) \
		DEBUG_STYLE_BUTTON( 70, "Set to IW2", setDvar ui_menustyle "iw2"; close "self"; open "main_text"; ) \
		DEBUG_STYLE_BUTTON( 120, "Set to IW3", setDvar ui_menustyle "iw3"; close "self"; open "main_text"; ) \
		DEBUG_STYLE_BUTTON( 170, "Set to IW4", setDvar ui_menustyle "iw4"; close "self"; open "main_text"; )