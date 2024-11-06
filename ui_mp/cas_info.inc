//		PREPROC_SHADER_DRAW_EXP_VIS( CHOICE_RECT( itemIndex ), "ks_button_selected_bar", 3, 0.8 0.6 0.1 1, when ( ( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) && 0 ) )

#define LOCAL_CAS_NAME( streakName ) \
		"@" + tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 2 )

#define FUNC_36 int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak1Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_selected_ref"), 4))
#define FUNC_37 int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_selected_ref"), 4))
#define FUNC_38 int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak3Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_selected_ref"), 4))

#define LOCAL_CAS_NAME2( streakName ) \
		locstring( "@MPUI_N_KILLS" , int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) )

		#define LOCAL_CAS_FOCUS( streakName ) \
                setLocalVarBool "ui_popupAButton" (1); \
                setLocalVarString "ui_selected_ref" (streakName); \
                setLocalVarString "ui_cas_hint" (""); \
                setLocalVarBool "ui_buttonFocused" (1); \
                if (localvarint("ui_numStreaks") == 3 ) \
                { \
                    setLocalVarString "ui_cas_hint" ("@MPUI_3_KILLSTREAKS_SELECTED"); \
                } \
                setLocalVarString "ui_conflicting_ref" (""); \
                if (!(localvarstring("ui_streak1Name") == streakName) && (isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && FUNC_36) \
                { \
                    setLocalVarString "ui_conflicting_ref" (localvarstring("ui_streak1Name")); \
                } \
                if (!(localvarstring("ui_streak2Name") == streakName) && (isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && FUNC_37) \
                { \
                    setLocalVarString "ui_conflicting_ref" (localvarstring("ui_streak2Name")); \
                } \
                if (!(localvarstring("ui_streak3Name") == streakName) && (isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && FUNC_38) \
                { \
                    setLocalVarString "ui_conflicting_ref" (localvarstring("ui_streak3Name")); \
                } \
                if (localvarint("ui_numStreaks") == 3) \
                { \
                    setLocalVarString "ui_conflicting_ref" (""); \
                } \
                if ((!(isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && !localvarint("ui_numTokens")) || ((isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && ((!(localvarstring("ui_streak1Name") == streakName || localvarstring("ui_streak2Name") == streakName || localvarstring("ui_streak3Name") == streakName) && (int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak1Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4)) || int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4)) || int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak3Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4)))) || (localvarint("ui_numStreaks") == 3 && !(localvarstring("ui_streak1Name") == streakName || localvarstring("ui_streak2Name") == streakName || localvarstring("ui_streak3Name") == streakName))))) \
                { \
                    setLocalVarBool "ui_popupAButton" (0); \
                } \

		#define LOCAL_CAS_ACTION( streakName ) \
                if ((localvarstring("ui_streak1Name") == streakName || localvarstring("ui_streak2Name") == streakName || localvarstring("ui_streak3Name") == streakName)) \
                { \
                    if (localvarstring("ui_streak1Name") == streakName) \
                    { \
                        setLocalVarString "ui_streak1Name" ("none"); \
                    } \
                    if (localvarstring("ui_streak2Name") == streakName) \
                    { \
                        setLocalVarString "ui_streak2Name" ("none"); \
                    } \
                    if (localvarstring("ui_streak3Name") == streakName) \
                    { \
                        setLocalVarString "ui_streak3Name" ("none"); \
                    } \
                    setLocalVarInt "ui_numStreaks" (localvarint("ui_numStreaks") - 1); \
                    play "mouse_click"; \
                } \
                else \
                { \
                    if ((isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName)) && localvarint("ui_numStreaks") < 3 && !(!(localvarstring("ui_streak1Name") == streakName || localvarstring("ui_streak2Name") == streakName || localvarstring("ui_streak3Name") == streakName) && (int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak1Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4)) || int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4)) || int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak3Name"), 4)) == int(tablelookup("mp/killstreakTable.csv", 1, streakName, 4))))) \
                    { \
                        if (localvarstring("ui_streak1Name") == "none") \
                        { \
                            setLocalVarString "ui_streak1Name" (streakName); \
                        } \
                        if (localvarstring("ui_streak2Name") == "none" && localvarstring("ui_streak1Name") != streakName) \
                        { \
                            setLocalVarString "ui_streak2Name" (streakName); \
                        } \
                        if (localvarstring("ui_streak3Name") == "none" && localvarstring("ui_streak1Name") != streakName && localvarstring("ui_streak2Name") != streakName) \
                        { \
                            setLocalVarString "ui_streak3Name" (streakName); \
                        } \
                        setLocalVarInt "ui_numStreaks" (localvarint("ui_numStreaks") + 1); \
                        play "mouse_click"; \
                    } \
                    else \
                    { \
                        if (!(isitemunlocked(streakName) && getplayerdata(killstreakUnlocked, streakName))) \
                        { \
                            open "popup_unlockconfirm"; \
                        } \
                    } \
                } \
                if (localvarstring("ui_streak1Name") == "none" || (int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) < int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak1Name"), 4)) && localvarstring("ui_streak2Name") != "none")) \
                { \
                    setLocalVarString "ui_tempStreak" (localvarstring("ui_streak1Name")); \
                    setLocalVarString "ui_streak1Name" (localvarstring("ui_streak2Name")); \
                    setLocalVarString "ui_streak2Name" (localvarstring("ui_tempStreak")); \
                } \
                if (localvarstring("ui_streak2Name") == "none" || (int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak3Name"), 4)) < int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) && localvarstring("ui_streak3Name") != "none")) \
                { \
                    setLocalVarString "ui_tempStreak" (localvarstring("ui_streak2Name")); \
                    setLocalVarString "ui_streak2Name" (localvarstring("ui_streak3Name")); \
                    setLocalVarString "ui_streak3Name" (localvarstring("ui_tempStreak")); \
                } \
                if (localvarstring("ui_streak1Name") == "none" || (int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak2Name"), 4)) < int(tablelookup("mp/killstreakTable.csv", 1, localvarstring("ui_streak1Name"), 4)) && localvarstring("ui_streak2Name") != "none")) \
                { \
                    setLocalVarString "ui_tempStreak" (localvarstring("ui_streak1Name")); \
                    setLocalVarString "ui_streak1Name" (localvarstring("ui_streak2Name")); \
                    setLocalVarString "ui_streak2Name" (localvarstring("ui_tempStreak")); \
                } \

#define CAS_STRNAME_CHECK( streakName ) \
		localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName \

#define KS_TABLE( streakName ) \
        tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) \

#define CAS_KS_CHECK( streakName ) \
		int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) \


#define PREPROC_CAS_TEXT_DRAW( itemIndex, ptext, visArg ) \
		itemDef \
		{ \
			rect			( CHOICE_X( itemIndex ) + 250 ) ( CHOICE_Y( itemIndex ) + 2 ) (40) (18) CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			textstyle		ITEM_TEXTSTYLE_SHADOWED \
			textalign		4 \
			textscale		0.333 \
			textaligny		2 \
			forecolor		CHOICE_TEXTCOLOR \
			exp text		( ptext ) \
			visible			visArg \
			decoration 		\
		}

#define KS_SIZE_X 20
#define KS_SIZE_Y 20

#define CHECK_BOX_SHADER_DRAW( itemIndex, materialArg, colorArg, visArg ) \
		itemDef \
		{ \
			style			WINDOW_STYLE_SHADER \
			rect			( CHOICE_X( itemIndex ) + 225 ) ( CHOICE_Y( itemIndex ) + 1 ) (KS_SIZE_X) (KS_SIZE_Y) CHOICE_HORIZONTAL_ALIGN CHOICE_VERTICAL_ALIGN \
			forecolor		colorArg \
			exp				material ( materialArg ) \
			visible			visArg \
			decoration 		\
		}

#define LOCAL_CAS_FOCUS2( streakName ) \
		if ( ( !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) && ( int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak1Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak2Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) || int( tablelookup( "mp/killstreakTable.csv" , 1 , localvarstring( "ui_streak3Name" ) , 4 ) ) == int( tablelookup( "mp/killstreakTable.csv" , 1 , streakName , 4 ) ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( localvarstring( "ui_streak1Name" ) == streakName || localvarstring( "ui_streak2Name" ) == streakName || localvarstring( "ui_streak3Name" ) == streakName ) ) ) \
		{ \
			setLocalVarBool "ui_popupAButton" ( 0 ); \
		} \

#define CHOICE_BUTTON_KILLSTREAK( itemIndex, streakName ) \
		CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, LOCAL_CAS_NAME( streakName ), LOCAL_CAS_ACTION( streakName ), LOCAL_CAS_FOCUS( streakName ), ;, 1, disabled when ( ( !( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) && !localvarint( "ui_numTokens" ) ) || ( ( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) && ( ( !( CAS_STRNAME_CHECK( streakName ) ) && (CAS_KS_CHECK( streakName ) ) ) || ( localvarint( "ui_numStreaks" ) == 3 && !( CAS_STRNAME_CHECK( streakName ) ) ) ) ) ) ) \
		/* kill requirement count */ \
		PREPROC_CAS_TEXT_DRAW( itemIndex, LOCAL_CAS_NAME2( streakName ), when ( !( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) ) ) \
		/* check boxes */ \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_bg", 		0.6 0.55 0.55 0.5,	when ( !( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_locked", 	1 1 1 0.25, 		when ( !( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) && !localvarint( "ui_numTokens" ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_locked", 	0.55 0.93 0.56 1,	when ( !( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) && localvarint( "ui_numTokens" ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_bg", 		0 0 0 1,			when ( !( CAS_STRNAME_CHECK( streakName ) ) && ( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_bg", 		0 0 0 1,			when ( ( CAS_STRNAME_CHECK( streakName ) ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_fg", 		1 1 1 1,			when ( ( CAS_STRNAME_CHECK( streakName ) ) ) ) \
		CHECK_BOX_SHADER_DRAW( itemIndex, "ks_button_check_x", 			1 1 1 0.65,			when ( ( !( CAS_STRNAME_CHECK( streakName ) ) && ( CAS_KS_CHECK( streakName ) ) && ( isitemunlocked( streakName ) && getplayerdata( killstreakUnlocked , streakName ) ) && ( localvarint( "ui_numStreaks" ) != 3 ) ) ) )