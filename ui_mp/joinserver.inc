		#define OPTIONS_HEADING_JOIN_COLOR	0.9 0.9 0.95 0.175
		
		#define FILTER_Y_SPACING	20
		#define FILTER_WIDTH		254
		#define X_FILTER			-30 //300
		#define X_FILTERB			( X_FILTER + FILTER_WIDTH )
		#define Y_FILTER			-35
		#define ORIGIN_FILTER1		X_FILTER Y_FILTER
		#define ORIGIN_FILTER2		X_FILTER ( Y_FILTER + FILTER_Y_SPACING )
		#define ORIGIN_FILTER3		X_FILTER ( Y_FILTER + ( FILTER_Y_SPACING * 2 ) )
		#define ORIGIN_FILTER4		8 ( Y_FILTER + ( FILTER_Y_SPACING * 2 ) )

		#define ORIGIN_FILTER1B		X_FILTERB Y_FILTER
		#define ORIGIN_FILTER2B		X_FILTERB ( Y_FILTER+FILTER_Y_SPACING )
		#define ORIGIN_FILTER3B		X_FILTERB ( Y_FILTER + ( FILTER_Y_SPACING * 2 ) )
		#define ORIGIN_FILTER4B		X_FILTERB ( Y_FILTER + ( FILTER_Y_SPACING * 3 ) )

		#define TAB_NAME_Y			68

		#define TAB_BG_COLOR		OPTIONS_HEADING_JOIN_COLOR
		#define TAB_BORDER_COLOR	0.1 0.1 0.12 0.5

		#define CUSTOM_BUTTON_TEXT_SIZE	0.33

		#undef CHOICE_HORIZONTAL_ALIGN 
		#define CHOICE_HORIZONTAL_ALIGN HORIZONTAL_ALIGN_CENTER 

		#undef CHOICE_VERTICAL_ALIGN
		#define CHOICE_VERTICAL_ALIGN VERTICAL_ALIGN_TOP			
		// custom button highlights
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), Y_FILTER, (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 1 ); )
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), (Y_FILTER+FILTER_Y_SPACING), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 2 ); )
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTER-10), (Y_FILTER+(FILTER_Y_SPACING*2)), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 3 ); )
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), Y_FILTER, (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( ui_choicegroup ) == "CHOICE_GROUP" && localVarInt( ui_highlight ) == 4 ); )
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), (Y_FILTER+FILTER_Y_SPACING), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 5 ); )
		CHOICE_HIGHLIGHT_CUSTOM_2( (X_FILTERB-10), (Y_FILTER+(FILTER_Y_SPACING*2)), (FILTER_WIDTH-20), (FILTER_Y_SPACING-2), when( localVarString( "ui_choicegroup" ) == CHOICE_GROUP && localVarInt( "ui_highlight" ) == 6 ); )

		itemDef	
		{
			name 			"sourcefield"
			style			WINDOW_STYLE_FILLED
			textFont		UI_FONT_NORMAL
			ownerdraw 		UI_NETSOURCE
			rect 			ORIGIN_FILTER1 170 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textstyle 		3
			textAlign 		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny 		16
			textstyle 		3
			textScale 		CUSTOM_BUTTON_TEXT_SIZE
			foreColor 		1 1 1 1
			backColor 		0 0 0 0
			visible 		1
			onFocus
			{ 
				setLocalVarInt "ui_highlight" ( 1 ); 
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
			}
			leaveFocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 ); 
				setLocalVarString "ui_choicegroup" ( "" );
			}
			action
			{ 
				play "mouse_click";
			}
			mouseEnter 
			{ 
				show "message_source"; 
				play "mouse_over";
			}
			mouseExit
			{
				hide "message_source";
			}
		}
		itemDef	
		{
			name 			gametypefield
			style 			WINDOW_STYLE_FILLED
			textstyle 		3
			text 			"@MENU_GAME_TYPE"
			ownerdraw 		UI_JOINGAMETYPE
			textFont		UI_FONT_NORMAL
			rect 			ORIGIN_FILTER2 170 15 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign 		ITEM_ALIGN_LEFT
			textAlignx 		0
			textAligny 		16
			textScale 		CUSTOM_BUTTON_TEXT_SIZE
			foreColor 		1 1 1 1
			border 			0
			borderColor 	0 0 0 0
			backColor 		0 0 0 0
			visible 		1
			onfocus
			{ 
				setLocalVarInt "ui_highlight" ( 2 );
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
			}
			leavefocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 );
				setLocalVarString "ui_choicegroup" ( "" );
			}
			action
			{ 
				play "mouse_click" 
			}
			mouseEnter 
			{ 
				show "message_typefilter"; 
				play "mouse_over";
			}
			mouseExit
			{ 
				hide "message_typefilter"; 
			}
		}
		itemDef 
		{
			name			"filterServers"
			text			"@MENU_FILTER_SERVERS"
			type			ITEM_TYPE_BUTTON
			textFont		UI_FONT_NORMAL
			textScale		CUSTOM_BUTTON_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			style			WINDOW_STYLE_FILLED
			rect			ORIGIN_FILTER3 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny		16
			foreColor		.9 .9 .95 1
			visible			1
			onfocus
			{ 
				setLocalVarInt "ui_highlight" ( 3 );
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP );
			}
			leavefocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 );
				setLocalVarString "ui_choicegroup" ( "" );
			}
			action
			{ 
				play "mouse_click";
				open "filter_popmenu";
			}
			mouseEnter
			{ 
				show "message_filterServers";
				play "mouse_over"; 
			}
			mouseExit
			{ 
				hide "message_filterServers"; 
			}
		}
		itemDef	
		{
			name 			"refreshdate"
			ownerdraw 		UI_SERVERREFRESHDATE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			textFont		UI_FONT_NORMAL
			textScale 		0.25
			rect 			ORIGIN_FILTER4 265 18
			textAlign 		ITEM_ALIGN_LEFT
			textAlignx 		0
			textAligny 		16
			foreColor 		1 1 1 1
			visible 		1
			decoration
		}
		itemDef 
		{
			name			"refreshSource"
			text			"@MENU_REFRESH_LIST"
			type			ITEM_TYPE_BUTTON
			textScale		CUSTOM_BUTTON_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			style			WINDOW_STYLE_FILLED
			rect			ORIGIN_FILTER1B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny		16
			textFont		UI_FONT_NORMAL
			foreColor		.9 .9 .95 1
			visible			1
			onfocus
			{ 
				setLocalVarInt "ui_highlight" ( 4 ); 
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP )
			}
			leavefocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 ); 
				setLocalVarString "ui_choicegroup" ( "" )
			}
			action
			{ 
				play "mouse_click"; 
				uiScript "RefreshServers";
			}
			mouseEnter 
			{ 
				show "message_refreshSource";
				play "mouse_over"; 
			}
			mouseExit 
			{ 
				hide "message_refreshSource"; 
			}
		}
		itemDef
		{
			name			"refreshFilter"
			text			"@MENU_QUICK_REFRESH"
			textScale		CUSTOM_BUTTON_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			style			WINDOW_STYLE_FILLED
			textFont		UI_FONT_NORMAL
			type			ITEM_TYPE_BUTTON
			rect			ORIGIN_FILTER2B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny		16
			foreColor		.9 .9 .95 1
			visible			1
			onfocus
			{ 
				setLocalVarInt "ui_highlight" ( 5 ); 
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP )
			}
			leavefocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 ); 
				setLocalVarString "ui_choicegroup" ( "" )
			}
			action 
			{ 
				play "mouse_click";
				uiScript "RefreshFilter";
			}	
			mouseEnter
			{
				show "message_refreshFilter"; 
				play "mouse_over"; 
			}
			mouseExit
			{ 
				hide "message_refreshFilter"; 
			}
		}

		itemDef 
		{
			text			"@MENU_NEW_FAVORITE"
			type			ITEM_TYPE_BUTTON
			textFont		UI_FONT_NORMAL
			textScale		CUSTOM_BUTTON_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			style			WINDOW_STYLE_FILLED
			rect			ORIGIN_FILTER3B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny		16
			foreColor		CHOICE_TEXTCOLOR_DISABLED
			visible			when( dvarint( "ui_netSource" ) != 2 )
			decoration
		}
		itemDef 
		{
			name			createFavorite
			text			"@MENU_NEW_FAVORITE"
			type			ITEM_TYPE_BUTTON
			textFont		UI_FONT_NORMAL
			textScale		CUSTOM_BUTTON_TEXT_SIZE
			textstyle		ITEM_TEXTSTYLE_SHADOWED
			style			WINDOW_STYLE_FILLED
			rect			ORIGIN_FILTER3B 130 15  CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN
			textAlign		ITEM_ALIGN_LEFT
			textAlignx		0
			textAligny		16
			foreColor		.9 .9 .95 1
			visible			1
			// Only show when view favorite servers list
			dvarTest "ui_netSource"
			showDvar { "2" }
			onfocus
			{ 
				setLocalVarInt "ui_highlight" ( 6 ); 
				setLocalVarString "ui_choicegroup" ( CHOICE_GROUP )
			}
			leavefocus
			{ 
				setLocalVarInt "ui_highlight" ( 0 ); 
				setLocalVarString "ui_choicegroup" ( "" )
			}	
			action 
			{
				play "mouse_click";
				open "createfavorite_popmenu";
			}
			mouseEnter 
			{ 
				show "message_createFavorite"; 
				play "mouse_over"; 
			}
			mouseExit 
			{ 
				hide "message_createFavorite"; 
			}
		}

#define PASSWORD_WIDTH		30
#define MATCHTYPE_WIDTH		20
#define AIMASSIST_WIDTH		20
#define VOICECHAT_WIDTH		20
#define SERVER_WIDTH		208
#define MAP_WIDTH			70
#define PLAYERS_WIDTH		50
#define TYPE_WIDTH			102
#define MOD_WIDTH			100
#define PING_WIDTH			40

#define TAB_LABEL_OFFSET \
		textAlignX 2 \
		textAlignY TAB_HEIGHT

#define TAB_HEIGHT			16

#define TABLE_POS_X			0
#define TABLE_POS_Y			42

#define PASSWORD_POS_X		(TABLE_POS_X)
#define MATCHTYPE_POS_X		(TABLE_POS_X + PASSWORD_WIDTH + 2)
#define AIMASSIST_POS_X		(MATCHTYPE_POS_X + MATCHTYPE_WIDTH + 2)
#define VOICECHAT_POS_X		(AIMASSIST_POS_X + AIMASSIST_WIDTH + 2)
#define SERVER_POS_X		(VOICECHAT_POS_X + VOICECHAT_WIDTH + 2)
#define MAP_POS_X			(SERVER_POS_X + SERVER_WIDTH + 2)
#define PLAYERS_POS_X		(MAP_POS_X + MAP_WIDTH + 2)
#define TYPE_POS_X			(PLAYERS_POS_X + PLAYERS_WIDTH + 2)
#define MOD_POS_X			(TYPE_POS_X + TYPE_WIDTH + 2)
#define PING_POS_X			(MOD_POS_X + MOD_WIDTH + 2)

#define TABLE_HEIGHT		338
#define TABLE_WIDTH			(PING_POS_X + PING_WIDTH + 10)

#define MAPIMAGE_WIDTH		91
#define MAPIMAGE_HEIGHT		60

#define MAPIMAGE_FRAME_SIZE											1

#define MAPIMAGE_POS_X		(MOD_POS_X + 4)
#define MAPIMAGE_POS_Y		(TABLE_POS_Y - (TAB_HEIGHT * 2))

#define MAPIMAGE_RECT		MAPIMAGE_POS_X MAPIMAGE_POS_Y MAPIMAGE_WIDTH MAPIMAGE_HEIGHT HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_SUBTOP
#define MAPIMAGE_FRAME_RECT	(MAPIMAGE_POS_X - MAPIMAGE_FRAME_SIZE) (MAPIMAGE_POS_Y - MAPIMAGE_FRAME_SIZE) (MAPIMAGE_WIDTH + (MAPIMAGE_FRAME_SIZE * 2)) (MAPIMAGE_HEIGHT + (MAPIMAGE_FRAME_SIZE * 2))

/*
		itemDef
		{
			name					"mapimageFrame"
			rect					MAPIMAGE_FRAME_RECT
			style					WINDOW_STYLE_FILLED
			backColor				0 0 0 0.5
			background				"black"
			decoration
			visible					when(dvarBool("ui_serverSelected") && dvarBool("wideScreen"))
		}
		itemDef
		{
			name					"mapimage"
			rect					MAPIMAGE_RECT
			style					WINDOW_STYLE_SHADER
			background				"black"
			decoration
			visible					when(dvarBool("ui_serverSelected") && dvarBool("wideScreen"))
			exp						material("preview_" + dvarString("ui_serverSelectedMap"))
		}
*/
		itemDef
		{
			name					"window"
			rect					TABLE_POS_X TABLE_POS_Y TABLE_WIDTH TABLE_HEIGHT HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_TOP
			style					WINDOW_STYLE_FILLED
			foreColor				1 1 1 1
			backColor				0 0 0 .3
			visible					1
			border 					1
			borderColor 			TAB_BORDER_COLOR
			decoration
		}

#define PASSWORD_ORIGIN		PASSWORD_POS_X			(TABLE_POS_Y + 2)
#define MATCHTYPE_ORIGIN	MATCHTYPE_POS_X			(TABLE_POS_Y + 2)
#define AIMASSIST_ORIGIN	AIMASSIST_POS_X			(TABLE_POS_Y + 2)
#define VOICECHAT_ORIGIN	VOICECHAT_POS_X			(TABLE_POS_Y + 2)
#define SERVER_ORIGIN		SERVER_POS_X			(TABLE_POS_Y + 2)
#define MAP_ORIGIN			MAP_POS_X				(TABLE_POS_Y + 2)
#define PLAYERS_ORIGIN		PLAYERS_POS_X			(TABLE_POS_Y + 2)
#define TYPE_ORIGIN			TYPE_POS_X				(TABLE_POS_Y + 2)
#define MOD_ORIGIN			MOD_POS_X				(TABLE_POS_Y + 2)
#define PING_ORIGIN			PING_POS_X				(TABLE_POS_Y + 2)

#define PASSWORD_RECT		PASSWORD_ORIGIN			PASSWORD_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define MATCHTYPE_RECT		MATCHTYPE_ORIGIN		MATCHTYPE_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define AIMASSIST_RECT		AIMASSIST_ORIGIN		AIMASSIST_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define VOICECHAT_RECT		VOICECHAT_ORIGIN		VOICECHAT_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define SERVER_RECT			SERVER_ORIGIN			SERVER_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define MAP_RECT			MAP_ORIGIN				MAP_WIDTH			TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define PLAYERS_RECT		PLAYERS_ORIGIN			PLAYERS_WIDTH		TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define TYPE_RECT			TYPE_ORIGIN				TYPE_WIDTH			TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define MOD_RECT			MOD_ORIGIN				MOD_WIDTH			TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
#define PING_RECT			PING_ORIGIN				PING_WIDTH			TABLE_HEIGHT		HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP

#define PREPROC_COLUMN_BOX(pname, prect) PREPROC_COLUMN_BOX_RAW(pname, prect, 0 0 0 0)
#define PREPROC_COLUMN_BOX_RAW(pname, prect, pcolor) \
		itemDef \
		{ \
			name				pname \
			group				grpColumn \
			rect				prect 0 0 \
			origin				-2 -2 \
			style				WINDOW_STYLE_FILLED \
			border 				WINDOW_BORDER_FULL \
			backColor			pcolor \
			borderColor 		TAB_BORDER_COLOR \
			visible				1 \
			decoration			\
		}

		#define COLUMN_POS_Y		80

		PREPROC_COLUMN_BOX("passwordColumn", 		PASSWORD_POS_X		COLUMN_POS_Y			(PASSWORD_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("matchTypeColumn", 		MATCHTYPE_POS_X		COLUMN_POS_Y			(MATCHTYPE_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("aimAssistColumn", 		AIMASSIST_POS_X		COLUMN_POS_Y			(AIMASSIST_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("voiceChatColumn", 		VOICECHAT_POS_X		COLUMN_POS_Y			(VOICECHAT_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("serverColumn", 			SERVER_POS_X		COLUMN_POS_Y			(SERVER_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("mapColumn", 			MAP_POS_X			COLUMN_POS_Y			(MAP_WIDTH+2)			TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("playersColumn", 		PLAYERS_POS_X		COLUMN_POS_Y			(PLAYERS_WIDTH+2)		TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("typeColumn", 			TYPE_POS_X			COLUMN_POS_Y			(TYPE_WIDTH+2)			TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("modColumn", 			MOD_POS_X			COLUMN_POS_Y			(MOD_WIDTH+2)			TABLE_HEIGHT)
		PREPROC_COLUMN_BOX("pingColumn", 			PING_POS_X			COLUMN_POS_Y			(PING_WIDTH+2)			TABLE_HEIGHT)



		// Server list text
		itemDef
		{
			name					"serverlist"
			rect					TABLE_POS_X (TABLE_POS_Y + TAB_HEIGHT) (TABLE_WIDTH - 8) (TABLE_HEIGHT - 17) HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
			style					WINDOW_STYLE_FILLED
            borderSize 				1
            foreColor 				1 1 1 1
			outlinecolor 			OPTIONS_HEADING_JOIN_COLOR
			type					ITEM_TYPE_LISTBOX
			textFont				UI_FONT_NORMAL
			textScale				0.25
			visible					1
			feeder					FEEDER_SERVERS
			elementtype 			LISTBOX_TEXT
			elementWidth			126
			elementHeight			16
		//	numcols					xpos							xwidth					textlen			alignment
			columns 10				(PASSWORD_POS_X - 2)				PASSWORD_WIDTH			10				1
									(MATCHTYPE_POS_X - 2)			MATCHTYPE_WIDTH			10				1
									(AIMASSIST_POS_X - 2)			AIMASSIST_WIDTH			10				1
									(VOICECHAT_POS_X - 2)			VOICECHAT_WIDTH			10				1
									(SERVER_POS_X + 1)				SERVER_WIDTH			38				0
									(MAP_POS_X + 1)					MAP_WIDTH				25				0
									(PLAYERS_POS_X + 1)				PLAYERS_WIDTH			10				0
									(TYPE_POS_X + 1)				TYPE_WIDTH				22				0
									(MOD_POS_X + 1)					MOD_WIDTH				20				0
									(PING_POS_X + 1)				PING_WIDTH				20				0
			doubleClick
			{
				uiScript			"JoinServer";
			}
		}

		// Server list tabs
		#undef	TABLE_HEIGHT
		#define TABLE_HEIGHT		TAB_HEIGHT

		itemDef
		{
			name					"password"
			group					"grpTabs"
			rect					PASSWORD_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			visible					1
            mouseEnter
            {
            	show "message_sort";
            	setItemColor "passwordColumn" bordercolor 1 1 1 1;
            	play "mouse_over";
            }
            mouseExit
            {
            	hide "message_sort";
            	setItemColor "passwordColumn" bordercolor TAB_BORDER_COLOR;
            }
            action
            {
            	play "mouse_click";
            	uiScript "ServerSort" 0;
            	setItemColor "grpTabs" backColor TAB_BG_COLOR;
            	setItemColor "password" backColor 0.1 0.2 0.37 1;
            	setItemColor "grpColumn" backColor 0 0 0 0;
            	setItemColor "passwordColumn" backColor 0 0 0.4 0.15;
            }
		}
		itemDef
		{
			name					"passwordicon"
			rect					PASSWORD_ORIGIN 12 12 HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
			origin					8 2
			style					WINDOW_STYLE_SHADER
			background				"cardicon_locked"
			decoration
			visible					1
		}
		itemDef
		{
			name					"matchtype"
			group					"grpTabs"
			rect					MATCHTYPE_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			visible					1
            mouseEnter
            {
            	show "message_sort";
            	setItemColor "matchTypeColumn" bordercolor 1 1 1 1;
            	play "mouse_over";
            }
            mouseExit
            {
            	hide "message_sort";
            	setItemColor "matchTypeColumn" bordercolor 0.1 0.1 0.12 0.5;
            }
            action
            {
            	play "mouse_click";
            	uiScript "ServerSort" 1;
            	setItemColor "grpTabs" backColor TAB_BG_COLOR;
            	setItemColor "matchtype" backColor 0.1 0.2 0.37 1;
            	setItemColor "grpColumn" backColor 0 0 0 0;
            	setItemColor "matchTypeColumn" backColor 0 0 0.4 0.15;
            }
		}
		itemDef
		{
			name					"matchtypeicon"
			rect					MATCHTYPE_ORIGIN 12 12 HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
			origin					3 2
			style					WINDOW_STYLE_SHADER
			background				"server_hardware_header"
			decoration
			visible					1
		}
		itemDef
		{
			name					"aimassist"
			group					"grpTabs"
			rect					AIMASSIST_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			visible					1
            mouseEnter
            {
            	show "message_sort";
            	setItemColor "aimAssistColumn" bordercolor 1 1 1 1;
            	play "mouse_over";
            }
            mouseExit
            {
            	hide "message_sort";
            	setItemColor "aimAssistColumn" bordercolor 0.1 0.1 0.12 0.5;
            }
			action
			{
				play "mouse_click";
				uiScript "ServerSort" 2;
				setItemColor "grpTabs" backColor TAB_BG_COLOR;
				setItemColor "aimassist" backColor 0.1 0.2 0.37 1;
				setItemColor "grpColumn" backColor 0 0 0 0;
				setItemColor "aimAssistColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"aimassisticon"
			rect					AIMASSIST_ORIGIN 12 12 HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
			origin					3 2
			style					WINDOW_STYLE_SHADER
			background				"cardicon_headshot"
			decoration
			visible					1
		}
		itemDef
		{
			name					"voicechat"
			group					"grpTabs"
			rect					VOICECHAT_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			visible					1
            mouseEnter
            {
            	show "message_sort";
            	setItemColor "voiceChatColumn" bordercolor 1 1 1 1;
            	play "mouse_over";
            }
            mouseExit
            {
            	hide "message_sort";
            	setItemColor "voiceChatColumn" bordercolor 0.1 0.1 0.12 0.5;
            }
			action
			{
				play "mouse_click";
				uiScript "ServerSort" 3;
				setItemColor "grpTabs" backColor TAB_BG_COLOR;
				setItemColor "voicechat" backColor 0.1 0.2 0.37 1;
				setItemColor "grpColumn" backColor 0 0 0 0;
				setItemColor "voiceChatColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"voicechaticon"
			rect					VOICECHAT_ORIGIN 12 12 HORIZONTAL_ALIGN_SUBLEFT VERTICAL_ALIGN_TOP
			origin					4 2
			style					WINDOW_STYLE_SHADER
			background				"talkingicon"
			decoration
			visible					1
		}
		itemDef
		{
			name					"server"
			group					"grpTabs"
			rect					SERVER_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
            borderSize 				1
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MENU_SERVER_NAME"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort";
				setItemColor "serverColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort";
				setItemColor "serverColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 4;
				setItemColor 		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor 		"server" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor 		"serverColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"map"
			group					"grpTabs"
			rect					MAP_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MENU_MAP_NAME"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort";
				setItemColor "mapColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort";
				setItemColor "mapColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 5;
				setItemColor		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor 		"map" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor		"mapColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"players"
			group					"grpTabs"
			rect					PLAYERS_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MENU_NUMPLAYERS"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort";
				setItemColor "playersColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort";
				setItemColor "playersColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 6;
				setItemColor 		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor 		"players" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor 		"playersColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"type"
			group					"grpTabs"
			rect					TYPE_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MENU_GAME_TYPE"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort";
				setItemColor "typeColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort";
				setItemColor "typeColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 7;
				setItemColor		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor 		"type" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor		"typeColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"mod"
			group					"grpTabs"
			rect					MOD_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MPUI_MOD"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort"; 
				setItemColor "modColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort"; 
				setItemColor "modColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 8;
				setItemColor		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor		"mod" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor		"modColumn" backColor 0 0 0.4 0.15;
			}
		}
		itemDef
		{
			name					"ping"
			group					"grpTabs"
			rect					PING_RECT
			type					ITEM_TYPE_BUTTON
			style					WINDOW_STYLE_FILLED
			foreColor 				1 1 1 1
			backColor 				OPTIONS_HEADING_JOIN_COLOR
			textFont				UI_FONT_NORMAL
			textScale				0.25
			text					"@MENU_PING"
			visible					1
			TAB_LABEL_OFFSET
			mouseEnter 
			{ 
				show "message_sort"; 
				setItemColor "pingColumn" borderColor 1 1 1 1;
				play "mouse_over";
			}
			mouseExit 
			{ 
				hide "message_sort"; 
				setItemColor "pingColumn" borderColor TAB_BORDER_COLOR;
			}
			action
			{
				play				"mouse_click";
				uiScript			"ServerSort" 9;
				setItemColor		"grpTabs" backColor TAB_BG_COLOR;
				setItemColor		"ping" backColor 0.1 0.2 0.37 1;
				setItemColor 		"grpColumn" backColor 0 0 0 0;
				setItemColor		"pingColumn" backColor 0 0 0.4 0.15;
			}
		}