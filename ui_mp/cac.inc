	#define UI_TABDEPTH( actionArg, textArg ) \
			if ( localvarint( "ui_tabDepth" ) == 0 ) \
			{ \
				setLocalVarString "ui_tab1Name" ( textArg ); \
			} \
			if ( localvarint( "ui_tabDepth" ) == 1 ) \
			{ \
				setLocalVarString "ui_tab2Name" ( textArg ); \
			} \
			if ( localvarint( "ui_tabDepth" ) == 2 ) \
			{ \
				setLocalVarString "ui_tab3Name" ( textArg ); \
			} \
			if ( localvarint( "ui_tabDepth" ) == 3 ) \
			{ \
				setLocalVarString "ui_tab4Name" ( textArg ); \
			} \
			if ( localvarint( "ui_tabDepth" ) == 4 ) \
			{ \
				setLocalVarString "ui_tab5Name" ( textArg ); \
			} \
			if ( localvarint( "ui_tabDepth" ) == 5 ) \
			{ \
				setLocalVarString "ui_tab6Name" ( textArg ); \
			} \
			actionArg \

			
	// cac selection button
	#define LOCAL_CAC_BUTTON( itemIndex, textArg, actionArg ) \
			CHOICE_BUTTON_FOCUS( itemIndex, textArg, setLocalVarInt "ui_tabDepth" 0 ;UI_TABDEPTH( actionArg, textArg ), setLocalVarFloat "ui_popupYPos"(getfocuseditemy());, ; )

	// primary weapons
	#define LOCAL_ITEM_PRIMARY( itemIndex, textArg, actionArg ) \
			CHOICE_BUTTON_FOCUS( itemIndex, textArg, UI_TABDEPTH( actionArg, textArg ), setLocalVarString "ui_info_name" (textArg);, leaveFocus )
	// extra 
	#define LOCAL_EXTRA_ACTION( weaponStat ) \
			play "mouse_click"; \
			LOCAL_CAC_ACTION \
			setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "specialGrenade" , weaponStat ); \
			close "popup_cac_extra";

	#define LOCAL_EXTRA_SHOW( weaponStat ) \
			setLocalVarString "ui_info_name" ("@"+tablelookup("mp/statsTable.csv",4,weaponStat,3)); \
			setLocalVarString "ui_info_desc" ("@"+tablelookup("mp/statstable.csv",4,weaponStat,7)); \
			setLocalVarString "ui_info_icon" (tablelookup("mp/statsTable.csv",4,weaponStat,6)); \

	#define REF_FLASH			"flash_grenade"
	#define REF_CONCUSSION		"concussion_grenade"
	#define REF_SMOKE			"smoke_grenade"

	#define LOCAL_EXTRA_ITEM( itemIndex, weaponStat ) \
			CHOICE_BUTTON_FOCUS( itemIndex, locstring("@MPUI_N_XN","@"+tablelookup("mp/statsTable.csv",4,weaponStat,3),int(tablelookup("mp/statsTable.csv",4,weaponStat,5))), LOCAL_EXTRA_ACTION( weaponStat ), LOCAL_EXTRA_SHOW( weaponStat ), leaveFocus )
	
	// equipment
	#define LOCAL_EQUIPMENT_ACTION( weaponStat ) \
			play "mouse_click"; \
			if ( weaponStat != "specialty_bling" ) \
			{ \
				close self; \
			} \
			if ( 0 == 1 && weaponStat != "specialty_bling" ) \
			{ \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
			} \
			if ( 0 == 1 && weaponStat == "specialty_onemanarmy" ) \
			{ \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 0 == 1 && weaponStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
			} \
			if ( 0 == 4 ) \
			{ \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , weaponStat ); \
			} \
			if ( 0 != 4 ) \
			{ \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , weaponStat ); \
			} \
			if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
			{ \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
			} \
			setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
			setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
			setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
			if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
			{ \
				setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
			} \
			setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
			setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
			setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
			setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
			setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
			if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
			{ \
				setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
			} \
			setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
			setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
			setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
			setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
			setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
			setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
			setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
			setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
			setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
			setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
			setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
			setPlayerData( "perkNew" , weaponStat , "false" ); \
			close "popup_cac_equipment";

	#define LOCAL_EQUIPMENT_FOCUS( weaponStat ) \
			setLocalVarString "ui_selected_ref" ( weaponStat ); \
			setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , weaponStat , 8 ) ); \
			setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ); \
			setLocalVarString "ui_challenge_state" ( 1 ); \
			if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_2" ) \
			{ \
				setLocalVarInt "ui_challenge_state" ( 2 ); \
			} \
			if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_3" ) \
			{ \
				setLocalVarInt "ui_challenge_state" ( 3 ); \
			} \
			if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_4" ) \
			{ \
				setLocalVarInt "ui_challenge_state" ( 4 ); \
			} \
			setLocalVarString "ui_challengeName" ( "@" + tablelookup( "mp/allChallengesTable.csv" , 0 , localvarstring( "ui_challenge_ref" ) , 1 ) ); \

	#define LOCAL_EQUIPMENT_NOFOCUS( weaponStat ) \
			setPlayerData( "perkNew" , weaponStat , "false" ); \
			setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , weaponStat , 8 ) ); \
			setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \

	#define LOCAL_EQUIPMENT_ITEM( itemIndex, weaponStat ) \
			CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,weaponStat,2), LOCAL_EQUIPMENT_ACTION( weaponStat ), LOCAL_EQUIPMENT_FOCUS( weaponStat ), LOCAL_EQUIPMENT_NOFOCUS( weaponStat ) )
	// perks 1
		#define LOCAL_PERK1_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				if ( perkStat != "specialty_bling" ) \
				{ \
					close "self"; \
				} \
				if ( 1 == 1 && perkStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
				} \
				if ( 1 == 1 && perkStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 1 == 1 && perkStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 1 == 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , perkStat ); \
				} \
				if ( 1 != 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 1 , perkStat ); \
				} \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				
		#define LOCAL_PERK1_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_2" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 2 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_3" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 3 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_4" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 4 ); \
				} \
				setLocalVarString "ui_challengeName" ( "@" + tablelookup( "mp/allChallengesTable.csv" , 0 , localvarstring( "ui_challenge_ref" ) , 1 ) ); \
		
		#define LOCAL_PERK1_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				
	#define LOCAL_PERK1_ITEM( itemIndex, perkStat ) \
			CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK1_ACTION( perkStat ), LOCAL_PERK1_FOCUS( perkStat ), LOCAL_PERK1_NOFOCUS( perkStat ) )
	// perks 2
		#define LOCAL_PERK2_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				if ( perkStat != "specialty_bling" ) \
				{ \
					close self; \
				} \
				if ( 2 == 1 && perkStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
				} \
				if ( 2 == 1 && perkStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 2 == 1 && perkStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 2 == 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , perkStat ); \
				} \
				if ( 2 != 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 2 , perkStat ); \
				} \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				
		#define LOCAL_PERK2_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_2" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 2 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_3" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 3 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_4" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 4 ); \
				} \
				setLocalVarString "ui_challengeName" ( "@" + tablelookup( "mp/allChallengesTable.csv" , 0 , localvarstring( "ui_challenge_ref" ) , 1 ) ); \
		
		#define LOCAL_PERK2_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				
	#define LOCAL_PERK2_ITEM( itemIndex, perkStat ) \
			CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK2_ACTION( perkStat ), LOCAL_PERK2_FOCUS( perkStat ), LOCAL_PERK2_NOFOCUS( perkStat ) )
	// perks 3
		#define LOCAL_PERK3_ACTION( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				if ( perkStat != "specialty_bling" ) \
				{ \
					close self; \
				} \
				if ( 3 == 1 && perkStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
				} \
				if ( 3 == 1 && perkStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ) ;; \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 3 == 1 && perkStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
					if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
					} \
					setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
					setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
					setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
					{ \
						setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
					} \
					setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
					setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
					setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
					setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
					setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
					setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
					setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
					setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
					setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
					setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
					setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				} \
				if ( 3 == 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , perkStat ); \
				} \
				if ( 3 != 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 3 , perkStat ); \
				} \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				
		#define LOCAL_PERK3_FOCUS( perkStat ) \
				setLocalVarString "ui_selected_ref" ( perkStat ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 4 ) ); \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_2" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 2 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_3" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 3 ); \
				} \
				if ( ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_upgrade_ref" ) , 3 ) ) == localvarstring( "ui_challenge_ref" ) + "_4" ) \
				{ \
					setLocalVarInt "ui_challenge_state" ( 4 ); \
				} \
				setLocalVarString "ui_challengeName" ( "@" + tablelookup( "mp/allChallengesTable.csv" , 0 , localvarstring( "ui_challenge_ref" ) , 1 ) ); \
		
		#define LOCAL_PERK3_NOFOCUS( perkStat ) \
				setPlayerData( "perkNew" , perkStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , perkStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				
		#define LOCAL_PERK3_ITEM( itemIndex, perkStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,perkStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,perkStat,8))*(9-2)))), LOCAL_PERK3_ACTION( perkStat ), LOCAL_PERK3_FOCUS( perkStat ), LOCAL_PERK3_NOFOCUS( perkStat ) )

	// PRIMARY WEAPONS
		#define LOCAL_WEAPON_ACTION( weaponStat ) \
				if ( localvarint( "ui_tabDepth" ) == 0 ) \
				{ \
					setLocalVarString "ui_tab1Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 1 ) \
				{ \
					setLocalVarString "ui_tab2Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 2 ) \
				{ \
					setLocalVarString "ui_tab3Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 3 ) \
				{ \
					setLocalVarString "ui_tab4Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 4 ) \
				{ \
					setLocalVarString "ui_tab5Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 5 ) \
				{ \
					setLocalVarString "ui_tab6Name" ( "@" + tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 3 ) ); \
				} \
				if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) != weaponStat ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , "none" ); \
				} \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "weapon" , weaponStat ); \
				setPlayerData( "weaponNew" , weaponStat , "false" ); \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				if ( 0 == 0 ) \
				{ \
					if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 11 ) != "" ) ) \
					{ \
						if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" ) \
						{ \
							open "popup_primary_attachments_bling"; \
						} \
						else \
						{ \
							open "popup_primary_attachments"; \
						} \
					} \
					else \
					{ \
						open "popup_cac_primary_camo"; \
					} \
				} \
				else \
				{ \
					if ( ( tablelookup( "mp/statsTable.csv" , 4 , weaponStat , 11 ) != "" ) ) \
					{ \
						if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" && isitemunlocked( "specialty_secondarybling" ) ) \
						{ \
							open "popup_secondary_attachments_bling"; \
						} \
						else \
						{ \
							open "popup_secondary_attachments"; \
						} \
					} \
					else \
					{ \
						close "popup_cac_weapon_primary"; \
						close "popup_primary_attachments" close "popup_secondary_attachments" close "popup_cac_weapon_secondary"; \
						close "popup_cac_handgun_secondary"; \
						close "popup_cac_machinePistols_secondary"; \
						close "popup_cac_assault_primary"; \
						close "popup_cac_SMG_primary"; \
						close "popup_cac_LMG_primary"; \
						close "popup_cac_sniper_primary"; \
						close "popup_cac_shotgun_primary"; \
						close "popup_cac_assault_secondary"; \
						close "popup_cac_SMG_secondary"; \
						close "popup_cac_LMG_secondary"; \
						close "popup_cac_sniper_secondary"; \
						close "popup_cac_shotgun_secondary"; \
						close "popup_cac_template"; \
						close "popup_cac_primary_camo"; \
						close "popup_cac_secondary_camo"; \
						close "popup_cac_bling"; \
						close "popup_cac_perk2"; \
						close "popup_cac_rocket_secondary"; \
						close "popup_primary_attachments_bling"; \
						close "popup_secondary_attachments_bling"; \
						close "popup_cac_other_primary"; \
					} \
				} \
				
		#define LOCAL_WEAPON_ITEM( itemIndex, weaponStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,weaponStat,3), LOCAL_WEAPON_ACTION( weaponStat ), setLocalVarString "ui_selected_ref" ( weaponStat );, setPlayerData( "weaponNew" , weaponStat , "false" ); )
// CAMOS
		#define LOCAL_CAMO_ACTION( camoStat ) \
				if ( localvarint( "ui_tabDepth" ) == 0 ) \
				{ \
					setLocalVarString "ui_tab1Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 1 ) \
				{ \
					setLocalVarString "ui_tab2Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 2 ) \
				{ \
					setLocalVarString "ui_tab3Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 3 ) \
				{ \
					setLocalVarString "ui_tab4Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 4 ) \
				{ \
					setLocalVarString "ui_tab5Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				if ( localvarint( "ui_tabDepth" ) == 5 ) \
				{ \
					setLocalVarString "ui_tab6Name" ( "@" + tablelookup( "mp/camoTable.csv" , 1 , camoStat , 2 ) ); \
				} \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , camoStat , "false" ); \
				; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , camoStat ); \
				if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , "specialty_null" ); \
				} \
				setLocalVarString "loadoutPrimary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "loadoutPrimaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutPrimaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutPrimaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setLocalVarString "loadoutSecondaryAttachment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
				setLocalVarString "loadoutSecondaryAttachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				} \
				setLocalVarString "loadoutSecondaryCamo" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
				setLocalVarString "loadoutEquipment" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) ); \
				setLocalVarString "loadoutPerk1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
				setLocalVarString "loadoutPerk2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
				setLocalVarString "loadoutPerk3" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
				setLocalVarString "loadoutStreak1" ( getplayerdata( "killstreaks" , 0 ) ); \
				setLocalVarString "loadoutStreak2" ( getplayerdata( "killstreaks" , 1 ) ); \
				setLocalVarString "loadoutStreak3" ( getplayerdata( "killstreaks" , 2 ) ); \
				setLocalVarString "loadoutDeathStreak" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
				setLocalVarString "loadoutOffhandSecondary" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) ); \
				close "popup_cac_weapon_primary"; \
				close "popup_primary_attachments" close "popup_secondary_attachments" close "popup_cac_weapon_secondary"; \
				close "popup_cac_handgun_secondary"; \
				close "popup_cac_machinePistols_secondary"; \
				close "popup_cac_assault_primary"; \
				close "popup_cac_SMG_primary"; \
				close "popup_cac_LMG_primary"; \
				close "popup_cac_sniper_primary"; \
				close "popup_cac_shotgun_primary"; \
				close "popup_cac_assault_secondary"; \
				close "popup_cac_SMG_secondary"; \
				close "popup_cac_LMG_secondary"; \
				close "popup_cac_sniper_secondary"; \
				close "popup_cac_shotgun_secondary"; \
				close "popup_cac_template"; \
				close "popup_cac_primary_camo"; \
				close "popup_cac_secondary_camo"; \
				close "popup_cac_bling"; \
				close "popup_cac_perk2"; \
				close "popup_cac_rocket_secondary"; \
				close "popup_primary_attachments_bling"; \
				close "popup_secondary_attachments_bling"; \
				close "popup_cac_other_primary"; \

		#define LOCAL_CAMO_FOCUS( camoStat ) \
				setLocalVarString "ui_selected_ref" ( camoStat ); \
				setLocalVarString "ui_weapon_ref" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setLocalVarString "ui_unlock_ref" ( localvarstring( "ui_weapon_ref" ) + " " + camoStat ); \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_unlock_ref" ) , 3 ) ); \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_2" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 2 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_3" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 3 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_4" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 4 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_5" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 5 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_6" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 6 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_7" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 7 ); \
				} \
				if ( ( localvarstring( "ui_challenge_ref" ) == "ch_expert_" + localvarstring( "ui_weapon_ref" ) + "_8" ) ) \
				{ \
					setLocalVarString "ui_challenge_ref" ( "ch_expert_" + localvarstring( "ui_weapon_ref" ) ); \
					setLocalVarInt "ui_challenge_state" ( 8 ); \
				} \
				
		#define LOCAL_CAMO_NOFOCUS( camoStat ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , camoStat , "false" ); \

		#define LOCAL_WEAPON_CAMO( itemIndex, camoStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/camoTable.csv",1,camoStat,2), LOCAL_CAMO_ACTION( camoStat ), LOCAL_CAMO_FOCUS( camoStat ), LOCAL_CAMO_NOFOCUS( camoStat ) )

// ATTACHMENTS
		#define LOCAL_ATTACHMENT_NAME( attachmentStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)

		#define LOCAL_ATTACHMENT_ACTION( attachmentStat ) \
				if(localvarint("ui_tabDepth")==0) \
				{ \
					setLocalVarString"ui_tab1Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				if(localvarint("ui_tabDepth")==1) \
				{ \
					setLocalVarString"ui_tab2Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				if(localvarint("ui_tabDepth")==2) \
				{ \
					setLocalVarString"ui_tab3Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				if(localvarint("ui_tabDepth")==3) \
				{ \
					setLocalVarString"ui_tab4Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				if(localvarint("ui_tabDepth")==4) \
				{ \
					setLocalVarString"ui_tab5Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				if(localvarint("ui_tabDepth")==5) \
				{ \
					setLocalVarString"ui_tab6Name"("@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat),3)); \
				} \
				setLocalVarString"tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				if(menuisopen("popup_primary_attachments_bling")||menuisopen("popup_secondary_attachments_bling")) \
				{ \
					setLocalVarString"tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
					if((localvarstring("ui_attachment1")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)||localvarstring("ui_attachment2")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat))) \
					{ \
						setLocalVarInt"tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"none"); \
					} \
					else \
					{ \
						setLocalVarInt"tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)!="none"); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"localVarString"("tempName")); \
					} \
					setLocalVarString"ui_attachment1"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)); \
					setLocalVarString"ui_attachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)); \
					setLocalVarInt"ui_numAttachments"(0); \
					if(localvarstring("ui_attachment1")!="none") \
					{ \
						setLocalVarInt"ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					if(localvarstring("ui_attachment2")!="none") \
					{ \
						setLocalVarInt"ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					if(!(tablelookup("mp/attachmentTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0),12)!=""||tablelookup("mp/attachmentTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",0),12)!="")&&(getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_gl"||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_grip"||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_shotgun")||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_heartbeat") \
					{ \ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"perks",0,"specialty_null"); \
					} \
					setLocalVarString"loadoutPrimary"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
					setLocalVarString"loadoutPrimaryAttachment"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)); \
					setLocalVarString"loadoutPrimaryAttachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)); \
					if(localvarstring("loadoutPrimaryAttachment2")=="") \
					{ \
						setLocalVarString"loadoutPrimaryAttachment2"("none"); \
					} \
					setLocalVarString"loadoutPrimaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"camo")); \
					setLocalVarString"loadoutSecondaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"camo")); \
					setLocalVarString"loadoutSecondary"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon")); \
					setLocalVarString"loadoutSecondaryAttachment"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",0)); \
					setLocalVarString"loadoutSecondaryAttachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",1)); \
					if(localvarstring("loadoutSecondaryAttachment2")=="") \
					{ \
						setLocalVarString"loadoutSecondaryAttachment2"("none"); \
					} \
					setLocalVarString"loadoutSecondaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"camo")); \
					setLocalVarString"loadoutEquipment"(getplayerdata("customClasses",localvarint("classIndex"),"perks",0)); \
					setLocalVarString"loadoutPerk1"(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)); \
					setLocalVarString"loadoutPerk2"(getplayerdata("customClasses",localvarint("classIndex"),"perks",2)); \
					setLocalVarString"loadoutPerk3"(getplayerdata("customClasses",localvarint("classIndex"),"perks",3)); \
					setLocalVarString"loadoutStreak1"(getplayerdata("killstreaks",0)); \
					setLocalVarString"loadoutStreak2"(getplayerdata("killstreaks",1)); \
					setLocalVarString"loadoutStreak3"(getplayerdata("killstreaks",2)); \
					setLocalVarString"loadoutDeathStreak"(getplayerdata("customClasses",localvarint("classIndex"),"perks",4)); \
					setLocalVarString"loadoutOffhandSecondary"(getplayerdata("customClasses",localvarint("classIndex"),"specialGrenade")); \
					setLocalVarString"loadoutClassName"(getplayerdata("customClasses",localvarint("classIndex"),"name")); \
				} \
				else \
				{ \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling") \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling"&&getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)) \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					setLocalVarString"tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
					setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",0,"localVarString"("tempName")); \
					if(0==0) \
					{ \
						open"popup_cac_primary_camo"; \
					} \
					else \
					{ \
						close"popup_cac_weapon_primary"; \
						close"popup_primary_attachments"close"popup_secondary_attachments"close"popup_cac_weapon_secondary"; \
						close"popup_cac_handgun_secondary"; \
						close"popup_cac_machinePistols_secondary"; \
						close"popup_cac_assault_primary"; \
						close"popup_cac_SMG_primary"; \
						close"popup_cac_LMG_primary"; \
						close"popup_cac_sniper_primary"; \
						close"popup_cac_shotgun_primary"; \
						close"popup_cac_assault_secondary"; \
						close"popup_cac_SMG_secondary"; \
						close"popup_cac_LMG_secondary"; \
						close"popup_cac_sniper_secondary"; \
						close"popup_cac_shotgun_secondary"; \
						close"popup_cac_template"; \
						close"popup_cac_primary_camo"; \
						close"popup_cac_secondary_camo"; \
						close"popup_cac_bling"; \
						close"popup_cac_perk2"; \
						close"popup_cac_rocket_secondary"; \
						close"popup_primary_attachments_bling"; \
						close"popup_secondary_attachments_bling"; \
						close"popup_cac_other_primary"; \
					} \
					if(!(tablelookup("mp/attachmentTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0),12)!=""||tablelookup("mp/attachmentTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",0),12)!="")&&(getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_gl"||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_grip"||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_shotgun")||getplayerdata("customClasses",localvarint("classIndex"),"perks",0)=="specialty_null_heartbeat") \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"perks",0,"specialty_null"); \
					} \
					setLocalVarString"loadoutPrimary"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
					setLocalVarString"loadoutPrimaryAttachment"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)); \
					setLocalVarString"loadoutPrimaryAttachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)); \
					if(localvarstring("loadoutPrimaryAttachment2")=="") \
					{ \
						setLocalVarString"loadoutPrimaryAttachment2"("none"); \
					} \
					setLocalVarString"loadoutPrimaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"camo")); \
					setLocalVarString"loadoutSecondaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"camo")); \
					setLocalVarString"loadoutSecondary"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon")); \
					setLocalVarString"loadoutSecondaryAttachment"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",0)); \
					setLocalVarString"loadoutSecondaryAttachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"attachment",1)); \
					if(localvarstring("loadoutSecondaryAttachment2")=="") \
					{ \
						setLocalVarString"loadoutSecondaryAttachment2"("none"); \
					} \
					setLocalVarString"loadoutSecondaryCamo"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"camo")); \
					setLocalVarString"loadoutEquipment"(getplayerdata("customClasses",localvarint("classIndex"),"perks",0)); \
					setLocalVarString"loadoutPerk1"(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)); \
					setLocalVarString"loadoutPerk2"(getplayerdata("customClasses",localvarint("classIndex"),"perks",2)); \
					setLocalVarString"loadoutPerk3"(getplayerdata("customClasses",localvarint("classIndex"),"perks",3)); \
					setLocalVarString"loadoutStreak1"(getplayerdata("killstreaks",0)); \
					setLocalVarString"loadoutStreak2"(getplayerdata("killstreaks",1)); \
					setLocalVarString"loadoutStreak3"(getplayerdata("killstreaks",2)); \
					setLocalVarString"loadoutDeathStreak"(getplayerdata("customClasses",localvarint("classIndex"),"perks",4)); \
					setLocalVarString"loadoutOffhandSecondary"(getplayerdata("customClasses",localvarint("classIndex"),"specialGrenade")); \
					setLocalVarString"loadoutClassName"(getplayerdata("customClasses",localvarint("classIndex"),"name")); \
				}
				
		#define LOCAL_ATTACHMENT_FOCUS( attachmentStat ) \
				setLocalVarString"ui_selected_ref"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
				setLocalVarString"ui_weapon_ref"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				setLocalVarString"ui_unlock_ref"(localvarstring("ui_weapon_ref")+""+tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),attachmentStat)); \
				setLocalVarString"ui_challenge_ref"(tablelookup("mp/unlockTable.csv",0,localvarstring("ui_unlock_ref"),3)); \
				setLocalVarInt"ui_challenge_state"(1); \
				if((localvarstring("ui_challenge_ref")=="ch_marksman_"+localvarstring("ui_weapon_ref")+"_2")) \
				{ \
					setLocalVarString"ui_challenge_ref"("ch_marksman_"+localvarstring("ui_weapon_ref")); \
					setLocalVarInt"ui_challenge_state"(2); \
				} \
				if((localvarstring("ui_challenge_ref")=="ch_marksman_"+localvarstring("ui_weapon_ref")+"_3")) \
				{ \
					setLocalVarString"ui_challenge_ref"("ch_marksman_"+localvarstring("ui_weapon_ref")); \
					setLocalVarInt"ui_challenge_state"(3); \
				} \
				if((localvarstring("ui_challenge_ref")=="ch_marksman_"+localvarstring("ui_weapon_ref")+"_4")) \
				{ \
					setLocalVarString"ui_challenge_ref"("ch_marksman_"+localvarstring("ui_weapon_ref")); \
					setLocalVarInt"ui_challenge_state"(4); \
				} \
				if((localvarstring("ui_challenge_ref")=="ch_marksman_"+localvarstring("ui_weapon_ref")+"_5")) \
				{ \
					setLocalVarString"ui_challenge_ref"("ch_marksman_"+localvarstring("ui_weapon_ref")); \
					setLocalVarInt"ui_challenge_state"(5); \
				} \
				if((localvarstring("ui_challenge_ref")=="ch_marksman_"+localvarstring("ui_weapon_ref")+"_6")) \
				{ \
					setLocalVarString"ui_challenge_ref"("ch_marksman_"+localvarstring("ui_weapon_ref")); \
					setLocalVarInt"ui_challenge_state"(6); \
				} \
				
		#define LOCAL_ATTACHMENT_NOFOCUS \
				setLocalVarString"tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				if(localvarstring("ui_selected_ref")!="") \
				{ \
					setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				} \
		
		#define LOCAL_ATTACHMENT_ITEM( itemIndex, attachmentStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, LOCAL_ATTACHMENT_NAME( attachmentStat ), LOCAL_ATTACHMENT_ACTION( attachmentStat ), LOCAL_ATTACHMENT_FOCUS( attachmentStat ), LOCAL_ATTACHMENT_NOFOCUS )\
