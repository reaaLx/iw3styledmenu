#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#undef CHOICE_X_START
#define CHOICE_X_START				-218

#undef CHOICE_X_SPACING
#define CHOICE_X_SPACING			55

#undef CHOICE_Y_SPACING
#define CHOICE_Y_SPACING			55

#undef CHOICE_Y_START
#define CHOICE_Y_START				98

#define LOCAL_CARDICON( itemIndex, iconName, iconStat ) \
		itemDef \
		{ \
			name iconName \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 42 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style 3 \
			foreColor 1 1 1 1 \
			background "highlight_selected" \
			type 1 \
			textScale 0.55 \
			exp foreColor g ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
			exp foreColor b ( 0.45 + ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) && ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) ) \
			exp foreColor a ( ( getfocuseditemname( ) == iconName ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ); \
				if ( localvarstring( "ui_tempVar" ) != "" ) \
				{ \
					setPlayerData( iconNew , "localVarString" ( "ui_tempVar" ) , "false" ); \
				} \
			} \
			action \
			{ \
				if ( isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
				{ \
					play "mouse_click"; \
					setLocalVarString "ui_tempVar" ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ); \
					setPlayerData( "cardIcon" , "localVarString" ( "ui_tempVar" ) ); \
				} \
			} \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 42 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			foreColor 1 1 1 1 \
			textScale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) )  \
			exp material ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 1 ) ) \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 42 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			foreColor 0.25 1 0.45 1 \
			background "highlight_selected" \
			textScale 0.55 \
			exp foreColor a ( getplayerdata( iconNew , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) * ( ( sin( milliseconds( ) / 100 ) * 0.5 + 0.5 ) * 0.25 + 0.75 ) * 0.65 ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
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
			exp foreColor a ( getplayerdata( iconNew , tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) ) \
		} \
		itemDef \
		{ \
			rect ( CHOICE_X( itemIndex ) ) ( CHOICE_Y( itemIndex ) ) 42 42 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			foreColor 1 1 1 1 \
			background "cardicon_locked" \
			textScale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) != "" ) && !isitemunlocked( tablelookupbyrow( "mp/cardIconTable.csv" , iconStat + ( localvarint( "ui_pageIndex" ) * 48 ) , 0 ) ) ) \
		}