#define LOCAL_CAC_ACTION \
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
		setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) );

#define LOCAL_CAC_EQUIPMENT \
				if ( weaponStat != "specialty_bling" ) \
				{ \
					close self; \
				} \
				if ( 0 == 1 && weaponStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
				} \
				if ( 0 == 1 && weaponStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					; setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
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
				setLocalVarString "loadoutClassName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) );