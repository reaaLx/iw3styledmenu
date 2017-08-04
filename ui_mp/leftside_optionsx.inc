blurWorld		7.0

#undef BACK_OPEN
#define BACK_OPEN exec "wait";

#include "ui_mp/navcontrols.inc"

#undef ORIGIN_TITLE
#define ORIGIN_TITLE 64 0

CHOICE_MENU_TITLE( "@MENU_OPTIONS" )

#undef CHOICE_X_START
#define CHOICE_X_START		-324

#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN HORIZONTAL_ALIGN_CENTER

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN VERTICAL_ALIGN_TOP

CHOICE_BUTTON_VIS( 2, "@MENU_GRAPHICS", LOCAL_CLOSE_ALL open "options_graphics", when( ( !dvarint( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 2, "@MENU_GRAPHICS", when( ( dvarint( "sv_running" ) && dvarInt( "ui_allow_graphic_change" ) == 0 ) || dvarBool( "arcademode" ) ); )
CHOICE_BUTTON_VIS( 3, "@MENU_TEXTURE_SETTINGS", LOCAL_CLOSE_ALL open "options_graphics_texture", when( ( !dvarint( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 3, "@MENU_TEXTURE_SETTINGS", when( ( dvarint( "sv_running" ) && dvarInt( "ui_allow_graphic_change" ) == 0 ) || dvarBool( "arcademode" ) ); )
CHOICE_BUTTON( 4, "@MENU_SOUND", LOCAL_CLOSE_ALL open "pc_options_audio" )
CHOICE_BUTTON_VIS( 5, "@MENU_VOICECHAT", LOCAL_CLOSE_ALL open "options_voice", when( dvarint( "ui_multiplayer" ) ) )
CHOICE_DBUTTON_VIS( 5, "@MENU_VOICECHAT", when( !dvarint( "ui_multiplayer" ) ); )
CHOICE_BUTTON( 6, "@MENU_GAME_OPTIONS", LOCAL_CLOSE_ALL open "options_game" )

CHOICE_BUTTON_VIS( 7, "@MENU_MULTIPLAYER_OPTIONS", LOCAL_CLOSE_ALL open "options_multi", when( dvarint( "ui_multiplayer" ) ) )

CHOICE_BUTTON_VIS( 8, "@MENU_RESET_SYSTEM_DEFAULTS", LOCAL_CLOSE_ALL open "options_graphics_defaults", when( ( !dvarint( "sv_running" ) || dvarInt( "ui_allow_graphic_change" ) ) && dvarInt( "arcademode" ) == 0 ); )
CHOICE_DBUTTON_VIS( 8, "@MENU_RESET_SYSTEM_DEFAULTS", when( ( dvarint( "sv_running" ) && dvarInt("ui_allow_graphic_change") == 0 ) || dvarBool( "arcademode" ) ); )

// ---

#undef TEXTSIZE_BUTTON_PC
#define TEXTSIZE_BUTTON_PC	0.33

#undef CHOICE_SIZE_Y
#define CHOICE_SIZE_Y 		20

#undef	CHOICE_SIZE_X
#define CHOICE_SIZE_X		180

#undef  SECTION_X_OFFSET
#define SECTION_X_OFFSET 	60
// ---