
#include "ui_mp/navcontrols.inc"

#ifndef MAP_LIST
#error "MAP_LIST undefined"
#endif

#ifndef MAP_TABLE
#error "MAP_TABLE undefined"
#endif

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

#define MAP_INFO_X 324
#define MAP_INFO_Y 80

PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH2 (GAMEINFO_HEIGHT+GAMEINFO_HEIGHT2) HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 5, "white", 0 0 0 0.3, 0, 0, 0 0 0 0 )

PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 5 0, "white", 0.1 0.1 0.1 1, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) (-(GAMEINFO_WIDTH)) 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 5 0, "gradient_fadein", 0.9 0.95 1 0.4, 0, 0, 0 0 0 0 )

// ------------------------------------------------
// ------------------ map list --------------------
// ------------------------------------------------

#define LOCAL_MAP_SHOW( p_mapname, p_mapdesc, p_mapicon ) \
		setLocalVarString "ui_info_name" (p_mapname); \
		setLocalVarString "ui_info_desc" (p_mapdesc); \
		setLocalVarString "ui_info_icon" (p_mapicon); \

#define LOCAL_MAP_ACTION( p_maptext ) \
		play "mouse_click";	\
		setdvar ui_mapname p_maptext; \
		close "self";

#define LOCAL_MAP_SELECTION( itemNum, p_maptext, p_mapname, p_mapdesc, p_mapicon ) \
		CHOICE_BUTTON_FOCUS( itemNum, p_mapname, LOCAL_MAP_ACTION( p_maptext ), LOCAL_MAP_SHOW( p_mapname, p_mapdesc, p_mapicon ), leaveFocusArg )
MAP_LIST

UI_EDGE_REVERSE( (MAP_INFO_X) (MAP_INFO_Y), HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0, 0, 0.1 0.1 0.1 1 ) 
UI_EDGE_REVERSE( (MAP_INFO_X) (MAP_INFO_Y), HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0, 0, 0.9 0.95 1 0.4 )

PREPROC_TEXT_DRAW_ALIGNED_EXP( 328 82 275 16  HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 0, localvarstring( "ui_info_name" ), TEXTSIZE_SMALL, 0, 16, ITEM_ALIGN_LEFT, COLOR_TITLE )
PREPROC_SHADER_DRAW_ALIGNED(   (MAP_INFO_X) 100 275 174 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 0, localvarstring( "ui_info_icon" ), 1 1 1 1, 0, 0, 0 0 0 0 )
PREPROC_TEXT_DRAW_ALIGNED_EXP( (MAP_INFO_X) 282 275 100 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 0, localvarstring( "ui_info_desc" ), TEXTSIZE_SMALL, 0, 16, ITEM_ALIGN_LEFT, CHOICE_TEXTCOLOR )

PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH2 8 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 (194), "white", 0.1 0.1 0.1 1, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) ( - ( GAMEINFO_WIDTH2 ) ) 8 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 (194), "gradient_fadein",0.9 0.95 1 0.35, 0, 0, 0 0 0 0 )

PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH2 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 (300), "white", 0.1 0.1 0.1 1, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) ( - ( GAMEINFO_WIDTH2 ) ) 20 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 (300), "gradient_fadein",0.9 0.95 1 0.35, 0, 0, 0 0 0 0 )
		
PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH2 16 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 20, "gradient_top", 0 0 0 .75, 0, 0, 0 0 0 0 )
PREPROC_SHADER_DRAW_ALIGNED( (MAP_INFO_X) (MAP_INFO_Y) GAMEINFO_WIDTH2 16 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT, 0 (178), "gradient_bottom", 0 0 0 .75, 0, 0, 0 0 0 0 )
