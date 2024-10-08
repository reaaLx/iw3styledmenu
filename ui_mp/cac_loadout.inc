#define LOADOUT_WIDTH 			270

#define ORIGIN_LOADOUT			((-(LOADOUT_WIDTH - RIGHTITEM_OFFSET))-80) 4

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

	#define LOADOUT_ALIGN 	RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
	#define PERK_ALIGN		
	
	#define LOADOUT_PLATING( py, ph, vis_gradient_top, vis_gradient_bottom ) \
			LOADOUT_PLATING_RAW( ORIGIN_LOADOUT, 0, py, (LOADOUT_WIDTH+8), ph, LOADOUT_ALIGN, vis_gradient_top, vis_gradient_bottom )
		
	// background frame --------
	PREPROC_SHADER_DRAW_ALIGNED( -4 12 (LOADOUT_WIDTH+8) 376 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient_center", 0.3 0.3 0.325 0.6, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 398 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
//	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 342 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	PREPROC_SHADER_DRAW_ALIGNED( (LOADOUT_WIDTH+4) -4 20 398 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )
	
	// primary weapon camo
//	PREPROC_SHADER_DRAW_ALIGNED( -4 16 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/4)-4) 16 210 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/camoTable.csv" , 1 , localvarstring( "loadoutPrimaryCamo" ) , 4 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	//PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/2)-4) 16 100 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/camoTable.csv" , 1 , localvarstring( "loadoutPrimaryCamo" ) , 4 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
//	PREPROC_SHADER_DRAW_ALIGNED( ((((LOADOUT_WIDTH+8)/4)*3)-4) 16 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	
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
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 20 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , 3 ), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// primary weapon attachment name
//	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 74 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv", 9, STAT_CAC_PRIMARY_ATTACHMENT, 3), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )
	// primary weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 74 10 180 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 
	// primary weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 2 42 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmentTable.csv" , 4 , localvarstring( "loadoutPrimaryAttachment" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 	
	
	// second weapon name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (20+88) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutSecondary" ) , 3 ), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	
	// second weapon attachment name
//	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (74+88) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv", 9, STAT_CAC_SECONDARY_ATTACHMENT, 3), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )
	// second weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 74 (6+92) 180 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutSecondary" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1 VIS_WHEN_TWO_PRIME ) 
	PREPROC_SHADER_DRAW_ALIGNED( 74 (6+92) 180 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutSecondary" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1 VIS_WHEN_ONE_PRIME ) 
	// second weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 2 130 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmentTable.csv" , 4 , localvarstring( "loadoutSecondaryAttachment" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 	
	
// perk loadout info display =============
	
	#ifdef PC
		#define PERK_DESC_TEXTSIZE	0.25
	#else
		#define PERK_DESC_TEXTSIZE 	TEXTSIZE_SMALL
	#endif
	
	#define PERK_Y_OFFSET	206
	#define PERK_Y_SPACING	36

  // perk 1 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 34 (PERK_Y_OFFSET) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )

	// perk 1 icon
	/*normal*/	PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 PERK_Y_OFFSET 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) ) ) 
	/*pro*/		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 PERK_Y_OFFSET 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 8 ) ) && localvarstring( "loadoutPerk1" ) != "" ) ) 

	PREPROC_SHADER_DRAW_ALIGNED( -4 (PERK_Y_OFFSET+34) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 

	// perk 1 desc
	PREPROC_SHADER_DRAW_ALIGNED( 32 (PERK_Y_OFFSET+16) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 48 (PERK_Y_OFFSET+15) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk1" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		
	
  // perk 2 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 36 (PERK_Y_OFFSET+PERK_Y_SPACING) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	
	// perk 2 icon
	/*normal*/	PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (PERK_Y_OFFSET+PERK_Y_SPACING) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) ) )
	/*pro*/		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (PERK_Y_OFFSET+PERK_Y_SPACING) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 8 ) ) && localvarstring( "loadoutPerk2" ) != "" ) )
	
	PREPROC_SHADER_DRAW_ALIGNED( -4 (PERK_Y_OFFSET+PERK_Y_SPACING+34) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 

	// perk 2 desc
	PREPROC_SHADER_DRAW_ALIGNED( 32 (PERK_Y_OFFSET+PERK_Y_SPACING+16) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 48 (PERK_Y_OFFSET+PERK_Y_SPACING+15) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk2" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		
	
  // perk 3 name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 36 (PERK_Y_OFFSET+(PERK_Y_SPACING*2)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , int( 2 + ( isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) * ( 9 - 2 ) ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	
	// perk 3 icon
	/*normal*/	PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (PERK_Y_OFFSET+(PERK_Y_SPACING*2)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 3 ), 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) == "specialty_null" || !isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) ) )
	/*pro*/		PREPROC_SHADER_DRAW_ALIGNED_VIS( 0 (PERK_Y_OFFSET+(PERK_Y_SPACING*2)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 3 ) + "_upgrade", 1 1 1 0.65, 0, 1, 1 1 1 1, when ( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) != "specialty_null" && isitemunlocked( tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 8 ) ) && localvarstring( "loadoutPerk3" ) != "" ) )

	PREPROC_SHADER_DRAW_ALIGNED( -4 (PERK_Y_OFFSET+34+(PERK_Y_SPACING*2)) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 

	// perk 3 desc
	PREPROC_SHADER_DRAW_ALIGNED( 32 (PERK_Y_OFFSET+(PERK_Y_SPACING*2)+16) 14 14 LOADOUT_ALIGN, ORIGIN_LOADOUT, "ui_arrow_right", 1 1 1 0.4, 0, 1, 1 1 1 1) 
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 48 (PERK_Y_OFFSET+(PERK_Y_SPACING*2)+15) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutPerk3" ) , 4 ), PERK_DESC_TEXTSIZE, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )		

	// deathstreak icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 0 (PERK_Y_OFFSET-2+(PERK_Y_SPACING*3)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutDeathStreak" ) , 3 ), 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 
	// deathstreak name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 36 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutDeathStreak" ) , 2 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )

	PREPROC_SHADER_DRAW_ALIGNED( -4 (PERK_Y_OFFSET+64+(PERK_Y_SPACING*2)) (LOADOUT_WIDTH+8) 1 LOADOUT_ALIGN, ORIGIN_LOADOUT, "white", 1 1 1 0.1, 0, 1, 1 1 1 1) 

	// equipment icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 0 (PERK_Y_OFFSET-5+(PERK_Y_SPACING*4)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutEquipment" ) , 3 ), 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 
	// equipment name -------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 36 (PERK_Y_OFFSET+(PERK_Y_SPACING*4)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup( "mp/perkTable.csv" , 1 , localvarstring( "loadoutEquipment" ) , 2 ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )

	// extra icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 125 ( PERK_Y_OFFSET-2+(PERK_Y_SPACING*4)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 6 ), 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 	
	// extra names ------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 160 (PERK_Y_OFFSET+(PERK_Y_SPACING*4)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, locstring( "@MPUI_N_XN" , "@" + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 3 ) , int( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutOffhandSecondary" ) , 5 ) ) ), TEXTSIZE_SMALL, 0, -2, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
