#define POPUP_ITEM_HEIGHT	15
#define POPUP_ITEM_OFFSET	150

#undef CHOICE_HORIZONTAL_ALIGN

#define BACK_BUTTON_CLOSE \
		itemDef \
        { \
			type        ITEM_TYPE_BUTTON \
			rect        -600 -800 2000 2000 0 0 \
			text        "" \
			textfont    UI_FONT_NORMAL \
			visible     1 \
			action      \
            { \
                close "self"; 
            } \
		}

#define PREPROC_DVAR_POPUP_CHOICE_EX( pp_action, pp_origin, pp_string, pp_show, pp_extra ) \
		itemDef \
        { \
			exp text        ( pp_string ) \
			textScale 		TEXTSIZE_SMALL \
			textStyle 		ITEM_TEXTSTYLE_SHADOWED \
			rect 			pp_origin 110 POPUP_ITEM_HEIGHT CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			origin			0 4 \
			forecolor		MENU_FONT_COLOR \
			textAlign		ITEM_ALIGN_MIDDLE_CENTER \
			textAlignX		0 \
			textAlignY		0 \
			visible 		pp_show \
			pp_extra \
			leaveFocus \
			{ \
				play "mouse_submenu_over"; \
			} \
			action \
			{ \
				pp_action \
				play "mouse_click"; \
				close self; \
			} \
		}

#define PREPROC_POPUP_CHOICE( pp_update, pp_popupname, pp_offset, pp_height, pp_origin, pp_string, pp_setdvar, pp_show ) \
        itemDef \
        { \
            textscale 		TEXTSIZE_SMALL \
            textstyle 		ITEM_TEXTSTYLE_SHADOWED \
            rect 			pp_offset 110 pp_height 0 0 \
            origin			pp_origin \
            text 			pp_string \
            forecolor		MENU_FONT_COLOR \
            textalign		ITEM_ALIGN_RIGHT \
            textalignx		-101 \
            textaligny		-21 \
            visible 		pp_show; \
            leaveFocus \
            { \
                play "mouse_submenu_over"; \
            }\
            action 
            { \
                exec pp_setdvar; \
                play "mouse_click"; \
                pp_update \
                close GAME_OPTIONS_MENU_NAME"_"pp_popupname; \
            } \
        }

#define PREPROC_DVAR_POPUP2( pp_itemIndex, pp_name, pp_items, pp_dvar, pp_string1, pp_string2, pp_string3, pp_string4, pp_string5, pp_string6, pp_setdvar1, pp_setdvar2, pp_setdvar3, pp_setdvar4, pp_setdvar5, pp_setdvar6, pp_xOffset ) \
        menuDef	\
        { \
            name			GAME_OPTIONS_MENU_NAME"_"pp_name \
            visible			1 \
            fullscreen		0 \
            rect			0 0 640 480 0 0 \
            focusColor		COLOR_FOCUSED \
            style			WINDOW_STYLE_FILLED \
            popup \
            onOpen \
            { \
                focusFirst; \
                setfocusbydvar pp_dvar; \
            } \
            onESC \
            { \
                play "mouse_click"; \
                close GAME_OPTIONS_MENU_NAME"_"pp_name; \
            } \
            BACK_BUTTON_CLOSE \
            itemDef \
            { \
                style			WINDOW_STYLE_SHADER \
                rect			( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y( pp_itemIndex) -2 ) 110 ( 0 + ( POPUP_ITEM_HEIGHT * pp_items ) ) CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
                forecolor		0.2 0.2 0.22 1 \
                exp				material( "white" ) \
                border			1 \
                borderSize		2 \
                borderColor		0.4 0.4 0.42 1 \
                visible			1 \
                decoration \
            } \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar1, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 0 ) ), pp_string1, when ( pp_string1 != "" ), dvartest pp_dvar focusdvar { pp_setdvar1 } ) \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar2, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 1 ) ), pp_string2, when ( pp_string2 != "" ), dvartest pp_dvar focusdvar { pp_setdvar2 } ) \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar3, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 2 ) ), pp_string3, when ( pp_string3 != "" ), dvartest pp_dvar focusdvar { pp_setdvar3 } ) \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar4, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 3 ) ), pp_string4, when ( pp_string4 != "" ), dvartest pp_dvar focusdvar { pp_setdvar4 } ) \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar5, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 4 ) ), pp_string5, when ( pp_string5 != "" ), dvartest pp_dvar focusdvar { pp_setdvar5 } ) \
            PREPROC_DVAR_POPUP_CHOICE_EX( setdvar pp_dvar pp_setdvar6, ( CHOICE_X ( pp_itemIndex ) + pp_xOffset ) ( CHOICE_Y ( pp_itemIndex ) + ( POPUP_ITEM_HEIGHT * 5 ) ), pp_string6, when ( pp_string6 != "" ), dvartest pp_dvar focusdvar { pp_setdvar6 } ) \
        }