#define LOADOUT_WIDTH 			270

#define ORIGIN_LOADOUT			-350 4 //((-(LOADOUT_WIDTH - RIGHTITEM_OFFSET))-80) 4  


#define RATEBAR_FRAME_BORDER		0//WINDOW_BORDER_SUNKEN
#define RATEBAR_FRAME_BORDERSIZE	2
#define RATEBAR_FRAME_BORDERCOLOR	0.4 0.4 0.425 1

#define RATEBAR_BAR_SHADER			"gradient_fadein"
#define RATEBAR_BAR_COLOR			1 1 1 0.3

#define RATE_BAR_WIDTH				98
#define RATE_BAR_HEIGHT				12
	
#define VIS_WHEN_ATTACH_PLUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) )
#define VIS_WHEN_ATTACH_MINUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) ) 

#define VIS_WHEN_ATTACH_PLUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) && extraArg )
#define VIS_WHEN_ATTACH_MINUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) && extraArg ) 

#define VIS_WHEN_ONE_PRIME visible when( "specialty_twoprimaries" != tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON, 4 ) ) 
#define VIS_WHEN_TWO_PRIME visible when( "specialty_twoprimaries" == tablelookup( "mp/statstable.csv", 1, STAT_CAC_SPECIALTY_WEAPON , 4 ) ) 

/* ================================================================================= */
/* ================================ LOADOUT DISPLAY ================================ */
/* ================================================================================= */
// UI art: Julian version 2 - first pass

// CAC loadout main frame =================

	#define LOADOUT_ALIGN 	HORIZONTAL_ALIGN_RIGHT VERTICAL_ALIGN_TOP
	#define LOADOUT_ALIGN_V2 HORIZONTAL_ALIGN_DEFAULT VERTICAL_ALIGN_DEFAULT
	#define PERK_ALIGN		
	
	#define LOADOUT_PLATING( py, ph, vis_gradient_top, vis_gradient_bottom ) \
			LOADOUT_PLATING_RAW( ORIGIN_LOADOUT, 0, py, (LOADOUT_WIDTH+8), ph, LOADOUT_ALIGN, vis_gradient_top, vis_gradient_bottom )
		
	// background frame --------
	PREPROC_SHADER_DRAW_ALIGNED( -4 12 (LOADOUT_WIDTH+8) 376 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient_center", 0.3 0.3 0.325 0.6, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 398 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 342 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( (LOADOUT_WIDTH+4) -4 20 398 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	
	// primary weapon camo
	//PREPROC_SHADER_DRAW_ALIGNED( -4 16 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	
	/*
	might have to re-do this and have it sized accordingly 
	since its pretty much stretched :s
	this will do for now!!!
	*/

	PREPROC_SHADER_DRAW_ALIGNED( -4 16 278 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/camoTable.csv" , 1 , localvarstring( "loadoutPrimaryCamo" ) , 4 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	//PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/2)-4) 16 100 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/camoTable.csv" , 1 , localvarstring( "loadoutPrimaryCamo" ) , 4 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	//PREPROC_SHADER_DRAW_ALIGNED( ((((LOADOUT_WIDTH+8)/4)*3)-4) 16 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	
	/* top bar */ 			LOADOUT_PLATING( 4, 20, 0, 1 )
	/* bottom bar */		LOADOUT_PLATING( 386, 16, 1, 0 )
	/* weapon divider */ 	LOADOUT_PLATING( 104, 8, 1, 1 )
	/* perk plate */ 		LOADOUT_PLATING( 192, 16, 1, 1 )

	// perks //
	PREPROC_TEXT_DRAW_ALIGNED_EXP( -4 181 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@MPUI_PERKS_AND_INVENTORY", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_CENTER, CHOICE_TEXTCOLOR )
	
	// custom class name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( -4 -4 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_CENTER, CHOICE_TEXTCOLOR )

// attributes box ======================

#ifndef HIDE_WEAPON_ATTRIBUTE		

	#define INFO_BOX_ORIENT			0
	#define INFO_BOX_WIDTH			222
	#define INFO_BOX_HEIGHT			126
	#define INFO_BOX_X				(CHOICE_X_START+CHOICE_SIZE_X-INFO_BOX_WIDTH)

	#ifdef PC  
		#define INFO_BOX_Y				300
	#endif     

	#define INFO_TEXT				""
	#define INFO_TITLE				"@MENU_PRIMARY_ATTRIBUTES" //"Primary Attributes"
	#define INFO_TITLE_COLOR		CHOICE_TEXTCOLOR
	#include "ui_mp/info_box.inc"
	
	// meter bar unit dividers
	#define ATTRIBUTE_UNITS( px, py ) \
			PREPROC_SHADER_DRAW_ALIGNED( (px+(98/4)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 12, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 ) \
			PREPROC_SHADER_DRAW_ALIGNED( (px+(98/2)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 12, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 ) \
			PREPROC_SHADER_DRAW_ALIGNED( (px+((98/4)*3)) py 1 3 CHOICE_HORIZONTAL_ALIGN VERTICAL_ALIGN_TOP, 0 12, "line_vertical", 1 1 1 0.2, 0, 0, 0 0 0 0 )
		
	// weapon attribut meter bars
	#define ATTRIBUTE_BAR_FORMAT( px, py, pnum ) \
			ATTRIBUTE_UNITS( px, py )

	#define PREVIEW_VIS_CONDITION visible when( PREVIEW_VIS_CONDITION_RAW );
	#define PREVIEW_VIS_CONDITION_RAW dvarInt( ui_show_preview )

	#define ATTRIBUTE_BAR_FORMAT_PREVIEW( px, py, pnum ) \
			ATTRIBUTE_UNITS( px, py )\
		
#endif


	// weapon loadout info display ============
	
	// primary weapon name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 333 58 274 17 LOADOUT_ALIGN_V2, 0 0, "@"+tablelookup("mp/statsTable.csv",4,localvarstring("loadoutPrimary"),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
		
	// primary weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 333 78 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutPrimaryAttachment"),6), 1 1 1 1, 0, 1, 1 1 1 1) 	
	// primary weapon attachment 2 image
	PREPROC_SHADER_DRAW_ALIGNED( (333+40) 78 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutPrimaryAttachment2"),6), 1 1 1 1, 0, 1, 1 1 1 1) 	

	//primary weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 404 54 180 90 LOADOUT_ALIGN_V2, 0 0, tablelookup("mp/statsTable.csv",4,localvarstring("loadoutPrimary"),6), 1 1 1 1, 0, 1, 1 1 1 1) 

	// primary weapon attachment name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 333 113 274 20 LOADOUT_ALIGN_V2, 0 0, locstring("@"+tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutPrimaryAttachment"),3))+"/"+(locstring("@"+tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutPrimaryAttachment2"),3))), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )

	// second weapon name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 333 144 274 20 LOADOUT_ALIGN_V2, 0 0, "@"+tablelookup("mp/statsTable.csv",4,localvarstring("loadoutSecondary"),3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	
	// second weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 333 168 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutSecondaryAttachment"),6), 1 1 1 1, 0, 1, 1 1 1 1) 	

	// second weapon attachment name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 333 202 274 20 LOADOUT_ALIGN_V2, 0 0, "@"+tablelookup("mp/attachmentTable.csv",4,localvarstring("loadoutSecondaryAttachment"),3), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )
			
	// second weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 404 134 180 90 LOADOUT_ALIGN_V2, 0 0, tablelookup("mp/statsTable.csv",4,localvarstring("loadoutSecondary"),6), 1 1 1 1, 0, 1, 1 1 1 1 ) 
	
	#ifdef PC
		#define PERK_DESC_TEXTSIZE	0.25
	#else
		#define PERK_DESC_TEXTSIZE 	TEXTSIZE_SMALL
	#endif
	
	#define PERK_Y_OFFSET 206

	#define PERK_1_Y_NAME_OFFSET		246
	#define PERK_1_Y_ICON_OFFSET		246
	#define PERK_1_Y_ARROW_OFFSET		261
	#define PERK_1_Y_DESC_OFFSET		262
	#define PERK_1_Y_DIV_OFFSET			282

	#define PERK_2_Y_NAME_OFFSET		(PERK_1_Y_NAME_OFFSET + 40)
	#define PERK_2_Y_ICON_OFFSET		(PERK_1_Y_ICON_OFFSET + 40)
	#define PERK_2_Y_ARROW_OFFSET		(PERK_1_Y_ARROW_OFFSET + 40)
	#define PERK_2_Y_DESC_OFFSET		(PERK_1_Y_DESC_OFFSET + 40)
	#define PERK_2_Y_DIV_OFFSET			(PERK_1_Y_DIV_OFFSET + 40)
	
	#define PERK_3_Y_NAME_OFFSET		(PERK_2_Y_NAME_OFFSET + 40)
	#define PERK_3_Y_ICON_OFFSET		(PERK_2_Y_ICON_OFFSET + 40)
	#define PERK_3_Y_ARROW_OFFSET		(PERK_2_Y_ARROW_OFFSET + 40)
	#define PERK_3_Y_DESC_OFFSET		(PERK_2_Y_DESC_OFFSET + 40)
	#define PERK_3_Y_DIV_OFFSET			(PERK_2_Y_DIV_OFFSET + 40)

	#define DS_Y_NAME_OFFSET			(PERK_3_Y_NAME_OFFSET + 36)
	#define DS_Y_ICON_OFFSET			(PERK_3_Y_ICON_OFFSET + 36)
	#define DS_Y_ARROW_OFFSET			(PERK_3_Y_ARROW_OFFSET + 35)
	#define DS_Y_DESC_OFFSET			(PERK_3_Y_DESC_OFFSET + 36)
	#define DS_Y_DIV_OFFSET				(PERK_3_Y_DIV_OFFSET + 36)

	#define EQUIPMENT_Y_NAME_OFFSET		(DS_Y_NAME_OFFSET + 35)
	#define EQUIPMENT_Y_ICON_OFFSET		(DS_Y_ICON_OFFSET + 35)

	#define EXTRA_Y_NAME_OFFSET			(EQUIPMENT_Y_NAME_OFFSET)
	#define EXTRA_Y_ICON_OFFSET			(EQUIPMENT_Y_ICON_OFFSET)

	#define PERK_Y_SPACING	36

	// perk loadout info display =============

	//---------------//
	// PERK 1 LAYOUT //
	//---------------//
  	// perk 1 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 367 (PERK_1_Y_NAME_OFFSET) 240 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// perk 1 icon -------------
	//normal	
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_1_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) ) ) 
	//pro	
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_1_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) && localvarstring( "loadoutPerk1" ) != "" ) ) 
	// perk 1 desc -------------
	PREPROC_SHADER_DRAW_ALIGNED( 367 (PERK_1_Y_ARROW_OFFSET) 14 14 LOADOUT_ALIGN_V2, 0 0, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_1_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) ) )
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_1_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) , 9 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) ) )
	// perk 1 divider -------------
	PREPROC_SHADER_DRAW_ALIGNED( 328 (PERK_1_Y_DIV_OFFSET) 279 1 LOADOUT_ALIGN_V2, 0 0, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 
	//---------------//
	// PERK 2 LAYOUT //
	//---------------//
	// perk 2 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 367 (PERK_2_Y_NAME_OFFSET) 240 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// perk 2 icon -------------
	//normal	
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_2_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) ) )
	//pro		
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_2_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) && localvarstring( "loadoutPerk2" ) != "" ) )
	// perk 2 desc -------------
	PREPROC_SHADER_DRAW_ALIGNED( 367 (PERK_2_Y_ARROW_OFFSET) 14 14 LOADOUT_ALIGN_V2, 0 0, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_2_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) ) )
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_2_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) , 9 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) ) )
	// perk 2 divider -------------
	PREPROC_SHADER_DRAW_ALIGNED( 328 (PERK_2_Y_DIV_OFFSET) 279 1 LOADOUT_ALIGN_V2, 0 0, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 
	//---------------//
	// PERK 3 LAYOUT //
	//---------------//
	// perk 3 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 367 (PERK_3_Y_NAME_OFFSET) 240 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// perk 3 icon -------------
	//normal	
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_3_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) ) )
	//pro		
	PREPROC_SHADER_DRAW_ALIGNED_VIS( 333 (PERK_3_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) && localvarstring( "loadoutPerk3" ) != "" ) )
	// perk 3 desc -------------
	PREPROC_SHADER_DRAW_ALIGNED( 367 (PERK_3_Y_ARROW_OFFSET) 14 14 LOADOUT_ALIGN_V2, 0 0, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_3_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) ) )
	PREPROC_TEXT_DRAW_ALIGNED_EXP_VIS( 382 (PERK_3_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) , 9 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) ) )
	// perk 3 divider -------------
	PREPROC_SHADER_DRAW_ALIGNED( 328 (PERK_3_Y_DIV_OFFSET) 279 1 LOADOUT_ALIGN_V2, 0 0, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 

	// deathstreak name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 367 (DS_Y_NAME_OFFSET) 240 20 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutDeathStreak" ) , 2 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// deathstreak icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 333 (DS_Y_ICON_OFFSET) 32 32 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutDeathStreak" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1 visible when( 1 ) ) 
	// deathstreak desc ------------
	PREPROC_SHADER_DRAW_ALIGNED( 367 (DS_Y_ARROW_OFFSET) 14 14 LOADOUT_ALIGN_V2, 0 0, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 382 (DS_Y_DESC_OFFSET) 225 14 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutDeathStreak" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR)
	// deathstreak divider -------------
	PREPROC_SHADER_DRAW_ALIGNED( 328 (DS_Y_DIV_OFFSET) 279 1 LOADOUT_ALIGN_V2, 0 0, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 
	
	// equipment name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 367 (EQUIPMENT_Y_NAME_OFFSET) 100 20 LOADOUT_ALIGN_V2, 0 0, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutEquipment" ) , 2 ), 0.2333, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// equipment icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 333 (EQUIPMENT_Y_ICON_OFFSET) 22 22 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutEquipment" ) , 3 ), 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 
	// extra names ------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( (367 + EXTRA_Y_NAME_OFFSET - 255 ) (EXTRA_Y_NAME_OFFSET) 98 20 LOADOUT_ALIGN_V2, 0 0, locstring( "@MPUI_N_XN" , "@" + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 3 ) , int( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 5 ) ) ), 0.2333, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// extra icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( (333 + EXTRA_Y_NAME_OFFSET - 255 ) (EXTRA_Y_ICON_OFFSET) 22 22 LOADOUT_ALIGN_V2, 0 0, tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 	
	/*