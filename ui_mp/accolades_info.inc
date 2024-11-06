#undef CHOICE_HORIZONTAL_ALIGN
#define CHOICE_HORIZONTAL_ALIGN 	2

#undef CHOICE_VERTICAL_ALIGN
#define CHOICE_VERTICAL_ALIGN 		1

#define POS_X 10
#define POS_Y 10

// rect ( -234.952 + 75 * CHOICE_COL( itemIndex ) ) ( 51.3 + 75 * CHOICE_ROW( itemIndex ) + CHOICE_SEP_TOTAL_SPACING( itemIndex ) ) 81.3 81.3 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN

#define CHOICE_ACCOLADE( posX, posY, accoladesName, accoladesIndex ) \
		itemDef \
		{ \
			name accoladesName \
			rect ( posX + POS_X ) ( posY + POS_Y ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			visible 1 \
			style WINDOW_STYLE_SHADER \
			forecolor 1 1 1 1 \
			background "highlight_selected" \
			type ITEM_TYPE_BUTTON \
			textScale 0.55 \
			exp forecolor g ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor b ( 0.45 + ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			exp forecolor a ( ( getfocuseditemname() == accoladesName ) * ( ( sin( milliseconds() / 150 ) * 0.5 + 0.5 ) * 0.5 + 0.5 ) ) \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) ) \
			onFocus \
			{ \
				play "mouse_over"; \
				setLocalVarInt "ui_highlightIndex" ( accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) ); \
			} \
			action \
			{ \
				play "mouse_click"; \
			} \
		} \
		itemDef \
		{ \
			rect ( posX + POS_X ) ( posY + POS_Y ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			background "award_locked" \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) == 0 ) \
		} \
		itemDef \
		{ \
			rect ( posX + POS_X ) ( posY + POS_Y ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			style 3 \
			forecolor 1 1 1 1 \
			textscale 0.55 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp material ( tablelookup( "mp/awardTable.csv" , 1 , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) , 2 ) ) \
		} \
		itemDef \
		{ \
			rect ( posX + POS_X ) ( posY + POS_Y ) 64 64 CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			decoration \
			visible 1 \
			forecolor 1 1 1 1 \
			textfont 3 \
			textalign 14 \
			textscale 0.375 \
			visible when ( ( tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) != "" ) && getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) > 0 ) \
			exp text ( locstring( "@MPUI_X_N" , getplayerdata( "awards" , tablelookupbyrow( "mp/awardTable.csv" , accoladesIndex + ( localvarint( "ui_pageIndex" ) * 18 ) , 1 ) ) ) ) \
		}