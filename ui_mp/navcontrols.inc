#ifndef ALT_PANEL
#define ALT_PANEL		0
#endif

#ifdef	PC
	itemDef 	
	{ 
		style			3 
		rect			-120 -32 378 64 0 0 
		background		"white" 
		forecolor		0.9 0.9 0.95 0.175 
		visible			1
		decoration 	
	} 
	itemDef 	
	{ 
		style			3 
		rect			258 -32 16 -64 0 0 
		origin			0 0 
		background		"button_highlight_end" 
		forecolor		0.9 0.9 0.95 0.175 
		visible			1
		decoration	
	}
	itemDef		
	{
		style			3
		rect			56 448 528 40 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			1
		decoration	
	}
	itemDef		
	{
		style			3
		rect			584 448 16 64 0 0
		origin			0 0
		background		"button_highlight_end"
		forecolor		0.9 0.9 0.95 0.175
		visible			1
		decoration	
	}
	itemDef		
	{
		style			3
		rect			40 448 -16 64 0 0
		origin			0 0
		background		"button_highlight_end"
		forecolor		0.9 0.9 0.95 0.175
		visible			1
		decoration	
	}
	itemDef		
	{
		style			3
		rect			-120 464 160 32 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			1
		decoration	
	}
	itemDef		
	{
		style			3
		rect			600 464 160 32 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			1
		decoration	
	}
#endif

#ifndef PC
	itemDef 	
	{ 
		style			3 
		rect			-120 0 420 68 0 0 
		background		"white" 
		forecolor		0.9 0.9 0.95 0.175 
		visible			when( ENABLE_TITLE_BG )
		decoration 	
	} 
	itemDef 	
	{ 
		style			3 
		rect			300 0 16 -68 0 0 
		origin			0 0 
		background		"button_highlight_end" 
		forecolor		0.9 0.9 0.95 0.175 
		visible			when( ENABLE_TITLE_BG )
		decoration	
	}
	itemDef		
	{
		style			3
		rect			-120 414 1200 64 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			when( ENABLE_TITLE_BG && ALT_PANEL )
		decoration	
	}
	itemDef		
	{
		style			3
		rect			-120 416 420 64 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			when( ENABLE_TITLE_BG && ( ALT_PANEL == 0 ) )
		decoration	
	}
	itemDef		
	{
		style			3
		rect			300 416 16 64 0 0
		origin			0 0
		background		"button_highlight_end"
		forecolor		0.9 0.9 0.95 0.175
		visible			when( ENABLE_TITLE_BG && ( ALT_PANEL == 0 ) )
		decoration	
	}
	itemDef		
	{
		style			3
		rect			316 432 440 64 0 0
		background		"white"
		forecolor		0.9 0.9 0.95 0.175
		visible			when( ENABLE_TITLE_BG && ( ALT_PANEL == 0 ) )
		decoration	
	}
#endif
#ifdef PC

	#ifndef BACK_ENABLE
	#define BACK_ENABLE	1
	#endif

	#ifndef BACK_OPEN
	#define BACK_OPEN	open "main_text";
	#endif
	
	itemDef 
	{
		name			"back"
		text			"@MENU_BACK"
		type			1
		style			WINDOW_STYLE_FILLED
		textstyle		ITEM_TEXTSTYLE_SHADOWED
		rect			-250 10 40 20 HORIZONTAL_ALIGN_CENTER VERTICAL_ALIGN_BOTTOM
		textfont		UI_FONT_NORMAL
		textalign		ITEM_ALIGN_LEFT
		textscale		TEXTSIZE_SMALL
		textaligny		18
		visible			when( BACK_ENABLE )
		mouseEnter		{ play "mouse_over"; }
		action 
		{
			play "mouse_click";
			close "self";
			BACK_OPEN
		}	
	}
#endif // #ifdef PC