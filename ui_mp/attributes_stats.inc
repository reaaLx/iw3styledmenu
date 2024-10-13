        itemDef // ACCURACY
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 32 );
            exp rect Y ( 304 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // ACCURACY
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 32 );
            exp rect Y ( 304 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 22 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // DAMAGE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 32 );
            exp rect Y ( 324 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // DAMAGE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 32 );
            exp rect Y ( 324 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 23 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // RANGE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 32 );
            exp rect Y ( 344 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // RANGE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 32 );
            exp rect Y ( 344 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 24 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // FIRE RATE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 32 );
            exp rect Y ( 364 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // FIRE RATE
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 32 );
            exp rect Y ( 364 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 25 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // MOBILITY
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 32 );
            exp rect Y ( 384 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef // MOBILITY
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 32 );
            exp rect Y ( 384 );
            exp rect W ( ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "ui_selected_ref" ) , 26 ) / 100 ) * 120 )
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 3 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 3 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 3 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) < 0 ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 3 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 3 ) ) > 0 ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 4 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 4 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 4 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) < 0 ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 4 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 4 ) ) > 0 ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 5 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 5 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 5 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) < 0 ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 5 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 5 ) ) > 0 ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 6 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 1 1 1 0.3
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "gradient_fadein" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 6 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible 1                 
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 6 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) < 0 ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) , 6 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( stat( 202 ) != 0 ) && ( int( tablelookup( "mp/attributesTable.csv" , 1 , tablelookup( "mp/statsTable.csv" , 0 , stat( 201 ) , 4 ) + "_" + tablelookup( "mp/attachmentTable.csv" , 9 , stat( 202 ) , 4 ) , 6 ) ) > 0 ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( 326 );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 2 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 2 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( 326 );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) < 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 2 ) ) ) * 98 / 100 ) );
            exp rect Y ( 326 );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 2 ) ) > 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 3 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 3 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) < 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 3 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 26 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 3 ) ) > 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 4 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */
 
        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 4 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) < 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 4 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 46 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 4 ) ) > 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */
 
        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 5 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 5 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) < 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 5 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 66 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 5 ) ) > 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.25 0.3 0.35 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( 98 );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 6 ) ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */

        /*
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.4 0.15 0.15 1
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 6 ) ) ) * 98 / 100 + ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) ) * 98 / 100 ) ) );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) < 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        itemDef
        {
            rect 0 0 0 0 HORIZONTAL_ALIGN_LEFT VERTICAL_ALIGN_TOP
            style WINDOW_STYLE_SHADER
            borderSize 2
            foreColor 0.3 0.8 0.3 0.5
            borderColor 0.4 0.4 0.425 1
            textScale 0.55
            exp material ( "white" );
            exp rect X ( ( ( ( 0 + 220 - 222 ) + 100 ) + ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) , 6 ) ) ) * 98 / 100 ) );
            exp rect Y ( ( ( 320 + 86 ) ) );
            exp rect W ( ( ( int( tablelookup( "mp/attributestable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) ) * 98 / 100 ) );
            exp rect H ( ( 12 ) );
            visible when ( ( ( int( tablelookup( "mp/attributesTable.csv" , 1 , dvarstring( "ui_primary_highlighted" ) + "_" + dvarstring( "ui_attachment_highlighted" ) , 6 ) ) > 0 ) && dvarint( "ui_show_preview" ) ) )
            decoration                
        }
        */