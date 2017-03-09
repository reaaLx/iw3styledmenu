#define CAC_STATNUM( statNum ) \
		setPlayerData( "customClasses" , statNum , "inUse" , "true" ); \
		setLocalVarInt "classIndex" ( statNum ); \
		open "menu_cac_assault"; \

#define CAC_STATNUM_HI( statNum ) \
		setLocalVarInt "classIndex" ( statNum ); \

#define CAC_LOCALVARSTRINGS \
		if ( !( tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) , 12 ) != "" || tablelookup( "mp/attachmentTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) , 12 ) != "" ) && ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_gl" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_grip" || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_shotgun" ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 ) == "specialty_null_heartbeat" ) \
		{ \
			setPlayerData ( "customClasses" , localVarInt ( "classIndex"), "perks" , 0 , "specialty_null"; \
		} \
		setLocalVarString loadoutPrimary ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
		setLocalVarString loadoutPrimaryAttachment ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) ); \
		setLocalVarString loadoutPrimaryAttachment2 ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutPrimaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString loadoutPrimaryAttachment2 ( "none" ); \
		} \
		setLocalVarString loadoutPrimaryCamo ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "camo" ) ); \
		setLocalVarString loadoutSecondaryCamo ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
		setLocalVarString loadoutSecondary ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
		setLocalVarString loadoutSecondaryAttachment ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
		setLocalVarString loadoutSecondaryAttachment2 ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
		if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
		{ \
			setLocalVarString loadoutSecondaryAttachment2 ( "none" ); \
		} \
		setLocalVarString loadoutSecondaryCamo ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "camo" ) ); \
		setLocalVarString loadoutEquipment ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 0 )  ); \
		setLocalVarString loadoutPerk1 ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) ); \
		setLocalVarString loadoutPerk2 ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 2 ) ); \
		setLocalVarString loadoutPerk3 ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 3 ) ); \
		setLocalVarString loadoutStreak1 ( getplayerdata( "killstreaks" , 0 ) ); \
		setLocalVarString loadoutStreak2 ( getplayerdata( "killstreaks" , 1 ) ); \
		setLocalVarString loadoutStreak3 ( getplayerdata( "killstreaks" , 2 ) ); \
		setLocalVarString loadoutDeathStreak ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 4 ) ); \
		setLocalVarString loadoutOffhandSecondary ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "specialGrenade" ) ); \
		setLocalVarString loadoutClassName ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "name" ) );

#define CAC_PRESTIGE_EXPAND	24 + ( int( 5 + min( 5 , getplayerdata( "prestige" ) / 2 + 0.5 ) ) ) * 20
	