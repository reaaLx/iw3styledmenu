
#include "ui_mp/navcontrols.inc"

//--- style override ---

#undef CHOICE_SIZE_Y
#define CHOICE_SIZE_Y			18
	
#undef CHOICE_Y_SPACING
#define CHOICE_Y_SPACING		20

#undef CHOICE_TEXTSIZE
#define CHOICE_TEXTSIZE			TEXTSIZE_SMALL

#undef CHOICE_TEXT_OFFSET_X
#define CHOICE_TEXT_OFFSET_X	-21

#undef ALT_HINT_X_OFFSET
#define ALT_HINT_X_OFFSET		-14

#undef HIGHLIGHT_COLOR
#define HIGHLIGHT_COLOR			0.9 0.95 1 0.25

#undef NEW_X_OFFSET			
#define NEW_X_OFFSET			(-(CHOICE_SIZE_X+4))

#undef NEW_Y_OFFSET			
#define NEW_Y_OFFSET			-3
//--- end style override ---

// ----------------------------map images------------------------------------
#define GAMEINFO_WIDTH			270
#define GAMEINFO_WIDTH2			275
#define GAMEINFO_HEIGHT			200
#define GAMEINFO_HEIGHT2		120
#define GAMEINFO_ORIGIN			4 -160

#define GAMETYPE_TABLE 			"mp/gametypesTable.csv"

#define GAME_INFO_X 324
#define GAME_INFO_Y 80

PREPROC_SHADER_DRAW_ALIGNED( (GAME_INFO_X) (GAME_INFO_Y) GAMEINFO_WIDTH2 GAMEINFO_HEIGHT HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 5, "white", 0 0 0 0.3, 0, 0, 0 0 0 0 )

PREPROC_SHADER_DRAW_ALIGNED( (GAME_INFO_X) (GAME_INFO_Y) GAMEINFO_WIDTH 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 5 0, "white", 0.1 0.1 0.1 1, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (GAME_INFO_X) (GAME_INFO_Y) (-(GAMEINFO_WIDTH)) 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 5 0, "gradient_fadein", 0.9 0.95 1 0.4, 0, 0, 0 0 0 0 )
//PREPROC_SHADER_DRAW_ALIGNED( GAMEINFO_ORIGIN -80 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_CENTER, (GAMEINFO_WIDTH-76) 0, "ui_perforation", 1 1 1 1, 0, 0, 0 0 0 0 )

// ------------------------------------------------
// -------------- gametype list -------------------
// ------------------------------------------------

#define LOCAL_GAMETYPE_SHOW( p_gametype ) \
		setLocalVarString "ui_info_name" ("@"+tablelookup("mp/gameTypesTable.csv",0,p_gametype,1)); \
		setLocalVarString "ui_info_desc" ("@"+tablelookup("mp/gameTypesTable.csv",0,p_gametype,2)); \

#define LOCAL_GAMETYPE_ACTION( p_gametype ) \
		setdvar ui_gametype p_gametype; \
		close "self"; \
	
#define LOCAL_GAMETYPE_NAME( p_gametype_name ) \
		"@" + tablelookup( "mp/gameTypesTable.csv" , 0 ,  p_gametype_name , 1 ) \
		
#define	LOCAL_GAMETYPE_SELECTION( itemIndex, p_gametype_name, p_gametype ) \
 		CHOICE_BUTTON_FOCUS_VIS( itemIndex, LOCAL_GAMETYPE_NAME( p_gametype_name ), LOCAL_GAMETYPE_ACTION( p_gametype ), LOCAL_GAMETYPE_SHOW( p_gametype ), ;, 1 ) \
		
		PREPROC_TEXT_DRAW_ALIGNED_EXP( (GAME_INFO_X) (GAME_INFO_Y) (255) 16  HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 4 18, localvarstring( "ui_info_name" ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, COLOR_TITLE )
		PREPROC_TEXT_DRAW_ALIGNED_EXP( (GAME_INFO_X) (GAME_INFO_Y) (262) 120 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 4 40, localvarstring( "ui_info_desc" ), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_LEFT, CHOICE_TEXTCOLOR autowrapped )

UI_EDGE_REVERSE( (GAME_INFO_X) (GAME_INFO_Y), HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0, 0, 0.1 0.1 0.1 1 ) 
UI_EDGE_REVERSE( (GAME_INFO_X) (GAME_INFO_Y), HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0, 0, 0.9 0.95 1 0.4 )

PREPROC_SHADER_DRAW_ALIGNED( (GAME_INFO_X) (GAME_INFO_Y)    GAMEINFO_WIDTH2   8 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 GAMEINFO_HEIGHT, "white", 0.1 0.1 0.1 1, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (GAME_INFO_X) (GAME_INFO_Y) (-(GAMEINFO_WIDTH2)) 8 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 GAMEINFO_HEIGHT, "gradient_fadein",0.9 0.95 1 0.35, 0, 0, 0 0 0 0 )
