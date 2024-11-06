#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#undef CHOICE_X_START
#define CHOICE_X_START				-265

#undef CHOICE_X_SPACING
#define CHOICE_X_SPACING			185

#undef CHOICE_Y_SPACING
#define CHOICE_Y_SPACING			38

#undef CHOICE_Y_START
#define CHOICE_Y_START				98

#define LOCAL_CARDTITLE( itemIndex, cardName, cardStat ) \
		itemDef \
		{ \
			name cardName \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 160 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 3 \
			foreColor 1 1 1 1 \
			background "highlight_selected" \
			type 1 \
			textScale 0.55 \
			exp foreColor g ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) ) \
			exp foreColor b ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) ) \
			exp foreColor a ( ( getfocuseditemname( ) == cardName ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ); \
				if ( localvarstring( "ui_tempVar" ) != "" ) \
				{ \
					setPlayerData( titleNew , "localVarString" ( "ui_tempVar" ) , "false" ); \
				} \
			} \
			action \
			{ \
				if ( isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
				{ \
					play "mouse_click"; \
					setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ); \
					setPlayerData( cardTitle , "localVarString" ( "ui_tempVar" ) ); \
				} \
			} \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 160 32 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			foreColor 1 1 1 1 \
			backColor 1 1 1 1 \
			textFont 3 \
			textAlign 5 \
			textAlignY 8 \
			textStyle 8 \
			textScale 0.375 \
			exp foreColor a ( ( 1 * !( getfocuseditemname( ) == cardName ) ) + ( ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.25 + 0.75 ) * ( getfocuseditemname( ) == cardName ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) && isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
			exp text ( "@" + tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 1 ) ) \
			exp material ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 2 ) ) \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 160 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			foreColor 0.25 1 0.45 1 \
			background "highlight_selected" \
			textScale 0.55 \
			exp foreColor a ( getplayerdata( titleNew , tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) * 0.65 ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 40 20 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			foreColor 1 1 1 1 \
			background "specialty_new_bg" \
			textScale 0.55 \
			exp foreColor a ( getplayerdata( titleNew , tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 160 32 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 1 \
			foreColor 1 1 1 1 \
			backColor 1 1 1 1 \
			background "cardtitle_locked" \
			textFont 3 \
			textAlign 5 \
			textAlignY 8 \
			textScale 0.375 \
			visible when ( ( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) != "" ) && !isitemunlocked( tablelookupbyrow( "mp/cardTitleTable.csv" , cardStat + ( localvarint( "ui_pageIndex" ) * 27 ) , 0 ) ) ) \
		}