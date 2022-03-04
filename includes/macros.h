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
			rect 			x 0 50 16 1 1 \
			origin			-57 -30 \
			style 			1 \
			visible 		when ( DEBUG ) \
			forecolor 		1 1 1 1 \
			backcolor		0.8 0.8 1 0.1 \
			type 			1 \
			text 			string \
			textfont 		UI_FONT_SMALL \
			textalign 		ITEM_ALIGN_MIDDLE_CENTER \
			textalignx		-0.5 \
			textscale 		0.2 \
			border 			WINDOW_BORDER_KCGRADIENT \
			bordersize		0.5 \
			bordercolor		1 1 1 0.25 \
			onFocus \
			{ \
				setItemColor self backcolor 0.8 0.8 1 0.25; \
			} \
			leaveFocus \
			{ \
				setItemColor self backcolor 0.8 0.8 1 0.1; \
			} \
			action \
			{ \
				close 		"self"; \
				action_; \
			} \
		}

#define STYLE_WIDGET \
		DEBUG_STYLE_BUTTON( 0, "Restart Menus", if ( dvarBool( "cl_ingame" ) ) { exec "map_restart"; } else { exec "snd_restart"; } ) \
		DEBUG_STYLE_BUTTON( 50, "Rust Devmap", exec "devmap mp_rust"; ) \
		DEBUG_STYLE_BUTTON( 100, "connect", close "self"; open "connect"; ) \
		DEBUG_STYLE_BUTTON( 150, "main_text", close "self"; open "main_text"; ) \
		DEBUG_STYLE_BUTTON( 200, "quit_popmenu", open "quit_popmenu"; ) \
		DEBUG_STYLE_BUTTON( 250, "Set to IW2", setDvar ui_menustyle "iw2"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 300, "Set to IW3", setDvar ui_menustyle "iw3"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 350, "Set to IW4", setDvar ui_menustyle "iw4"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 400, "Set to IW5", setDvar ui_menustyle "iw5"; close "self"; open MENU_NAME; ) \
		DEBUG_STYLE_BUTTON( 450, "Set to T4", setDvar ui_menustyle "t4"; close "self"; open MENU_NAME; )

#define INGAME_FACTION_ICON( pos, alpha ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, localvarstring( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, localvarstring( "ui_team" ) == "opfor" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Allies" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "marines" ) \
		CREATE_SHADER_VIS( pos, dvarstring( "g_TeamIcon_Axis" ), 1 1 1 alpha, team( "name" ) == "TEAM_FREE" && localvarstring( "ui_team" ) == "opfor" )