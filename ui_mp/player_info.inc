#define PLAYERSTATS_WIDTH 		270

#define PLAYERSTATS_X			((-(PLAYERSTATS_WIDTH - RIGHTITEM_OFFSET))-80)
#define PLAYERSTATS_Y			12
#define FRAME_BG_COLOR			0.175 0.175 0.2 0.55

#define ORIGIN_PLAYERSTATS 			PLAYERSTATS_X PLAYERSTATS_Y
	
#define LABEL_ITEM_SPACING			18
#define SUB_LABEL_INDENT			16
	
#define LABEL_START_X				12
#define LABEL_START_Y				LABEL_ITEM_SPACING
#define ORIGIN_LABEL				LABEL_START_X LABEL_START_Y

#define LABEL_TEXTCOLOR				1 1 1 0.75
#define LABEL_TITLECOLOR			1 0.85 0.5 0.8

#define ORIGIN_LABEL_ITEM( itemNumber ) \
		LABEL_START_X (LABEL_START_Y+(LABEL_ITEM_SPACING*(itemNumber-1))) 

#define ORIGIN_SUB_LABEL_ITEM( itemNumber ) \
		(LABEL_START_X+SUB_LABEL_INDENT) (LABEL_START_Y+(LABEL_ITEM_SPACING*(itemNumber-1))) 
		
#define ORIGIN_DIVIDER( itemNumber ) \
		0 (LABEL_START_Y+(LABEL_ITEM_SPACING/2)+(LABEL_ITEM_SPACING*(itemNumber-1))) 

#define PREPROC_LABEL( itemNumber, ptext ) \
		PREPROC_LABEL_VIS( itemNumber, ptext, 1 )

#define PREPROC_LABEL_VIS( itemNumber, ptext, visArg ) \
		itemDef \
		{ \
			exp 			text ( ptext ) \
			rect			ORIGIN_LABEL_ITEM( itemNumber ) (PLAYERSTATS_WIDTH) LABEL_ITEM_SPACING RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
			origin			ORIGIN_PLAYERSTATS \
			textfont		UI_FONT_NORMAL \ 
			textstyle 		ITEM_TEXTSTYLE_SHADOWED \
			textscale		TEXTSIZE_SMALL \
			textalign		ITEM_ALIGN_MIDDLE_LEFT \
			forecolor		LABEL_TITLECOLOR \
			visible			visArg \
			decoration \
		}
	
#define PREPROC_DIVIDER( itemNumber ) \
		PREPROC_SHADER_DRAW_ALIGNED( ORIGIN_DIVIDER( itemNumber ) (PLAYERSTATS_WIDTH) 1 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "white", 1 1 1 0.1, 0, 0, 0 0 0 0 )

#define PREPROC_SUB_LABEL( itemNumber, ptext ) \
		PREPROC_SUB_LABEL_VIS( itemNumber, ptext, 1 )
	
#define PREPROC_SUB_LABEL_VIS( itemNumber, ptext, visArg ) \
		itemDef \
		{ \
			exp 			text ( ptext ) \
			rect			ORIGIN_SUB_LABEL_ITEM( itemNumber ) (PLAYERSTATS_WIDTH) LABEL_ITEM_SPACING RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
			origin			ORIGIN_PLAYERSTATS \
			textfont		UI_FONT_NORMAL \ 
			textstyle 		ITEM_TEXTSTYLE_SHADOWED \
			textscale		TEXTSIZE_SMALL \
			textalign		ITEM_ALIGN_MIDDLE_LEFT \
			forecolor		LABEL_TEXTCOLOR \
			visible			visArg \
			decoration \
		}
	
#define PREPROC_VALUE_TEXT( itemNumber, ptext, px_offset, pcolor ) \
		PREPROC_VALUE_TEXT_VIS( itemNumber, ptext, px_offset, pcolor, 1, ITEM_ALIGN_MIDDLE_RIGHT )

#define PREPROC_VALUE_TEXT_LEFT_ALIGNED( itemNumber, ptext, px_offset, pcolor ) \
		PREPROC_VALUE_TEXT_VIS( itemNumber, ptext, px_offset, pcolor, 1, ITEM_ALIGN_MIDDLE_LEFT )
		
#define PREPROC_VALUE_TEXT_VIS( itemNumber, ptext, px_offset, pcolor, visArg, alignment ) \
		itemDef \
		{ \
			exp				text( ptext ) \
			type			ITEM_TYPE_TEXT \
			rect			ORIGIN_LABEL_ITEM( itemNumber ) (PLAYERSTATS_WIDTH) LABEL_ITEM_SPACING RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP \
			textstyle 		ITEM_TEXTSTYLE_SHADOWED \
			origin			ORIGIN_PLAYERSTATS \
			textfont		UI_FONT_NORMAL \ 
			textalignx		px_offset \
			textscale		TEXTSIZE_SMALL \
			forecolor		pcolor \
			textalign		alignment \
			visible			visArg \
			decoration 		\
		}
	
#define PREPROC_RANK_ICON( itemNumber, pshader, y_offset ) \
		PREPROC_RANK_ICON_VIS( itemNumber, pshader, y_offset, 1 )

#define PREPROC_RANK_ICON_VIS( itemNumber, pshader, y_offset, visArg ) \
		PREPROC_SHADER_DRAW_ALIGNED_VIS( (LABEL_START_X+PLAYERSTATS_WIDTH-80) (LABEL_START_Y+y_offset+(LABEL_ITEM_SPACING*(itemNumber-1))) 22 22 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, pshader, 1 1 1 1, 0, 0, 0 0 0 0, visArg )
	
	#define FRAME_HEIGHT	380

	// UI art
	PREPROC_SHADER_DRAW_ALIGNED( -4 12 (PLAYERSTATS_WIDTH+8) 364 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "white", FRAME_BG_COLOR, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -4 12 (PLAYERSTATS_WIDTH+8) 364 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "gradient_center", 0.3 0.3 0.325 0.8, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 FRAME_HEIGHT RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( (PLAYERSTATS_WIDTH+4) -4 20 FRAME_HEIGHT RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	
	PREPROC_SHADER_DRAW_ALIGNED( -4 -4 (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "white", 0.2 0.2 0.225 1, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -4 -4 (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -4 12 (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "gradient_top", 1 1 1 0.2, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( -4 (338+22) (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "white", 0.2 0.2 0.225 1, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -4 (338+22) (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "line_horizontal", 0.9 0.9 0.95 0.5, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -4 (322+22) (PLAYERSTATS_WIDTH+8) 16 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "gradient_bottom", 1 1 1 0.2, 0, 0, 0 0 0 0 )

#ifndef PC
	itemDef // player name with clan tag
	{
		rect			0 12 270 28 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			ORIGIN_PLAYERSTATS
		textfont		UI_FONT_NORMAL
		textstyle 		ITEM_TEXTSTYLE_SHADOWED
		textscale		TEXTSIZE_SMALL
		textalign		ITEM_ALIGN_MIDDLE_LEFT
		forecolor		LABEL_TITLECOLOR
		ownerdraw		UI_USERNAME
		visible			1
		decoration 
	}
#else
	itemDef 
	{
		rect			0 -7 270 20 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
		origin			ORIGIN_PLAYERSTATS
		textfont		UI_FONT_NORMAL
		textstyle 		ITEM_TEXTSTYLE_SHADOWED
		textscale		TEXTSIZE_SMALL
		textalign		ITEM_ALIGN_MIDDLE_CENTER
		exp				text( dvarString( "name" ) )
		visible			1
		decoration 
	}
#endif

	//PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 12 270 28 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "["+dvarString( clanName) +"]"+ dvarString( name ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_CENTER, 1 1 1 0.8 visible when( dvarString( clanName ) != "" ) )
	//PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 12 270 28 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, dvarString( name ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_CENTER, 1 1 1 0.8 visible when( dvarString( clanName ) == "" ) )
	
	PREPROC_LABEL( 1, locstring("@MPUI_RANK_PRE") + " " + locstring("@"+tablelookup("mp/ranktable.csv",0,levelforexperience(getplayerdata("experience")),5)) )				
	PREPROC_VALUE_TEXT( 1, locstring( "@MPUI_LEVEL_N", int(tablelookup("mp/ranktable.csv",0,getplayercardinfo(4,1,0),14))), -24, LABEL_TITLECOLOR )
	PREPROC_RANK_ICON( 1, tablelookup("mp/rankIconTable.csv",0,getplayercardinfo(4,1,0),(getplayercardinfo(5,1,0)+1)), -4 )
	PREPROC_SUB_LABEL( 2, locstring("@MPUI_XP_PRE") + " " + locstring(getplayerdata( "experience" )) )
	
	PREPROC_DIVIDER( 3 )

	/* display level */
	PREPROC_LABEL_VIS( 4, locstring("@MPUI_NEXT_RANK_PRE") + " " + locstring("@" + tablelookup( "mp/ranktable.csv" , 0 , levelforexperience( getplayerdata( "experience" ) ) + 1 , 5 )), when ( ( levelforexperience( getplayerdata( "experience" ) ) < int( tablelookup( "mp/rankTable.csv" , 0 , "maxrank" , 1 ) ) || getplayerdata( "prestige" ) < int( tablelookup( "mp/rankIconTable.csv" , 0 , "maxprestige" , 1 ) ) ) && ( getplayerdata( "prestige" ) < int( tablelookup( "mp/rankIconTable.csv" , 0 , "maxprestige" , 1 ) ) && levelforexperience( getplayerdata( "experience" ) ) == int( tablelookup( "mp/rankTable.csv" , 0 , "maxrank" , 1 ) ) ) == 0 ))
	PREPROC_LABEL_VIS( 4, locstring("@MPUI_NEXT_RANK_PRE") + " " + locstring("@MPUI_NONE"), when ( ( levelforexperience( getplayerdata( "experience" ) ) < int( tablelookup( "mp/rankTable.csv" , 0 , "maxrank" , 1 ) ) || getplayerdata( "prestige" ) < int( tablelookup( "mp/rankIconTable.csv" , 0 , "maxprestige" , 1 ) ) ) == 0 ))
	PREPROC_VALUE_TEXT_VIS( 4, locString( "@MPUI_LEVEL_N", int(tablelookup("mp/ranktable.csv",0,stat(252)+1,14)) ), -24, LABEL_TITLECOLOR, when(  ( levelforexperience( getplayerdata( "experience" ) ) < int( tablelookup( "mp/rankTable.csv" , 0 , "maxrank" , 1 ) ) || getplayerdata( "prestige" ) < int( tablelookup( "mp/rankIconTable.csv" , 0 , "maxprestige" , 1 ) ) ) && ( getplayerdata( "prestige" ) < int( tablelookup( "mp/rankIconTable.csv" , 0 , "maxprestige" , 1 ) ) && levelforexperience( getplayerdata( "experience" ) ) == int( tablelookup( "mp/rankTable.csv" , 0 , "maxrank" , 1 ) ) )  ), ITEM_ALIGN_MIDDLE_RIGHT )
	
	/* next rank icon */
	PREPROC_RANK_ICON_VIS( 4, tablelookup( "mp/rankIconTable.csv" , 0 , levelforexperience(getplayerdata("experience")),getplayerdata("prestige")+1), -4, when( 1 ) )
	PREPROC_SUB_LABEL_VIS( 5, "@MPUI_XP_REQUIRED_PRE", when( 1 ) )
	
	#define XP_BAR_START_Y 92

	// xp bar
	//PREPROC_SHADER_DRAW_ADV_VIS( (PLAYERSTATS_X+202), (XP_BAR_START_Y+13), levelforexperience(getplayerdata("experience")), 12, "white", 0.1 0.1 0.1 0.35, 1, 1, 1 1 1 0.2 rect 0 0 0 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, when( 1 ) )
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 200 (XP_BAR_START_Y) 60 14 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, ORIGIN_PLAYERSTATS, "white", 0.1 0.1 0.1 0.35, 1, 1, 1 1 1 0.2,  when( 1 ) )
	PREPROC_SHADER_DRAW_ADV_VIS( (PLAYERSTATS_X+202),(XP_BAR_START_Y+13),-58*(int(tablelookup("mp/rankTable.csv",0,levelforexperience(getplayerdata("experience")),2))-getplayerdata("experience"))/int(tablelookup("mp/rankTable.csv",0,levelforexperience(getplayerdata("experience")),3)), 12, "gradient_fadein", 1 0.9 0.5 0.6, 0, 1, 1 1 1 1 rect 0 0 0 0 RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP, when( CAN_RANK_UP ) )

	/* standard xp */
	PREPROC_VALUE_TEXT_VIS( 5, int(tablelookup("mp/rankTable.csv",0,levelforexperience(getplayerdata("experience")),7)-getplayerdata("experience")),-20, LABEL_TEXTCOLOR, when( 1 ), ITEM_ALIGN_MIDDLE_RIGHT )
		
	PREPROC_DIVIDER( 6 )	

	PREPROC_LABEL( 7, "@MPUI_SCORE_PRE" )	
	PREPROC_VALUE_TEXT( 7, getplayerdata( "score" ), -24, LABEL_TITLECOLOR )

	PREPROC_SUB_LABEL( 8, "@MPUI_WINS_PRE" )
	PREPROC_VALUE_TEXT( 8, getplayerdata( "wins" ), -24, LABEL_TEXTCOLOR )

	PREPROC_SUB_LABEL( 9, "@MPUI_LOSSES_PRE" )
	PREPROC_VALUE_TEXT( 9, getplayerdata( "losses" ),-24, LABEL_TEXTCOLOR )

	PREPROC_SUB_LABEL( 10, "@MPUI_TIES_PRE" )
	PREPROC_VALUE_TEXT( 10, getplayerdata( "ties" ), -24, LABEL_TEXTCOLOR )

	PREPROC_SUB_LABEL( 11,"@MPUI_WINSTREAK_PRE" )
	PREPROC_VALUE_TEXT( 11,getplayerdata( "winStreak" ), -24, LABEL_TEXTCOLOR )

	PREPROC_DIVIDER( 12 )	
	
	PREPROC_LABEL( 13, "@MPUI_KILLS_PRE")
	PREPROC_VALUE_TEXT( 13, getplayerdata( "kills" ), -24, LABEL_TITLECOLOR )
		
	PREPROC_SUB_LABEL( 14, "@MPUI_HEADSHOTS_PRE" )
	PREPROC_VALUE_TEXT( 14, getplayerdata( "headshots" ), -24, LABEL_TEXTCOLOR )
	
	PREPROC_SUB_LABEL( 15, "@MPUI_ASSISTS_PRE" )	
	PREPROC_VALUE_TEXT( 15, getplayerdata( "assists" ), -24, LABEL_TEXTCOLOR )
	
	PREPROC_SUB_LABEL( 16, "@MPUI_STREAK_PRE" )	
	PREPROC_VALUE_TEXT( 16, getplayerdata( "killStreak" ), -24, LABEL_TEXTCOLOR )
		
	PREPROC_DIVIDER( 17 )

	PREPROC_LABEL( 18, "@MPUI_DEATHS_PRE" )
	PREPROC_VALUE_TEXT( 18, getplayerdata( "deaths" ), -24, LABEL_TITLECOLOR )

	PREPROC_LABEL( 19, "@MPUI_TIME_PLAYED_PRE"  )	
	PREPROC_VALUE_TEXT( 19, secondsastime(getplayerdata("timePlayedAllies")+getplayerdata("timePlayedOpfor")+getplayerdata("timePlayedOther")), -24, LABEL_TITLECOLOR )
