#define CREATE_SHADER( position, texture, colour ) \
		CREATE_SHADER_VIS( position, texture, colour, 1 )

#define CREATE_SHADER_VIS( position, texture, colour, visibility ) \
		CREATE_SHADER_EX( position, texture, colour, visibility, ; )

#define CREATE_SHADER_EX( position, texture, colour, visibility, extra ) \
		itemDef \
		{ \
			style 			WINDOW_STYLE_SHADER \
			rect 			position; \
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
			rect 			position; \
			backcolor 		colour \
			background		texture \
			visible 		when ( visibility ) \
			decoration 		\
			extra			\
		}

#define CREATE_TEXT( position, string, color, visibility, extras ) \
		itemDef \
		{ \
			rect 			position; \
			style 			1 \
			forecolor 		color \
			exp 			text ( string ) \
			visible 		when ( visibility ) \
			decoration \
			extras \
		}

#define DEBUG_STYLE_BUTTON( idx, string, action_ ) \
		itemDef \
		{ \
			rect 			( 0 + ( 45 * idx ) ) 0 45 15 1 1; \
			origin			-57 -30 \
			style 			WINDOW_STYLE_FILLED \
			visible 		when ( DEBUG ) \
			forecolor 		1 1 1 1 \
			backcolor		0.8 0.8 0.8 0.1 \
			type 			ITEM_TYPE_BUTTON \
			text 			string \
			textfont 		UI_FONT_OBJECTIVE \
			textalign 		ITEM_ALIGN_MIDDLE_CENTER \
			textalignx		-0.5 \
			textscale 		0.2 \
			border 			WINDOW_BORDER_KCGRADIENT \
			bordersize		0.5 \
			bordercolor		1 1 1 0.25 \
			onFocus \
			{ \
				setItemColor self backcolor 0.8 0.8 0.8 0.25; \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0.8 0.8 0.8 0.1; \
			} \
			action \
			{ \
				close 		"self"; \
				action_; \
			} \
		}

#define STYLE_WIDGET \
		DEBUG_STYLE_BUTTON( 0, "RELOAD", if ( dvarBool( "cl_ingame" ) ) { exec "map_restart"; } else { exec "xstopparty;snd_restart"; } ) \
		DEBUG_STYLE_BUTTON( 1, "IW3", setDvar ui_menustyle "iw3"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 2, "IW4", setDvar ui_menustyle "iw4"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 3, "IW5", setDvar ui_menustyle "iw5"; close "self"; open MENU_NAME; )

#define INGAME_FACTION_ICON( pos, alpha ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, localvarstring( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, localvarstring( "ui_team" ) == "opfor" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "opfor" )

#ifndef MENU_BACK_ACTION
#define MENU_BACK_ACTION \
		close "self"; \
		open "main_text";
#endif