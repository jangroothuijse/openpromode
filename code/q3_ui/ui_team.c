/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
//
// ui_team.c
//

#include "ui_local.h"


#define TEAMMAIN_FRAME	"menu/art/cut_frame"

#define ID_JOINRED		100
#define ID_JOINBLUE		101
#define ID_JOINGAME		102
#define ID_SPECTATE		103
#define ID_JOINGREEN	104
#define ID_JOINORANGE	105
#define ID_JOINYELLOW	106
#define ID_JOINWHITE	107


typedef struct
{
	menuframework_s	menu;
	menubitmap_s	frame;
	menutext_s		joinred;
	menutext_s		joinblue;
	menutext_s		joingreen;
	menutext_s		joinyellow;
	menutext_s		joinorange;
	menutext_s		joinwhite;
	menutext_s		joingame;
	menutext_s		spectate;
} teammain_t;

static teammain_t	s_teammain;

/*
===============
TeamMain_MenuEvent
===============
*/
static void TeamMain_MenuEvent( void* ptr, int event ) {
	if( event != QM_ACTIVATED ) {
		return;
	}

	switch( ((menucommon_s*)ptr)->id ) {
	case ID_JOINRED:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team red\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINBLUE:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team blue\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINGREEN:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team green\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINYELLOW:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team yellow\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINORANGE:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team orange\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINWHITE:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team white\n" );
		UI_ForceMenuOff();
		break;

	case ID_JOINGAME:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team free\n" );
		UI_ForceMenuOff();
		break;

	case ID_SPECTATE:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team spectator\n" );
		UI_ForceMenuOff();
		break;
	}
}


/*
===============
TeamMain_MenuInit
===============
*/
void TeamMain_MenuInit( void ) {
	int		y;
	int		gametype;
	char	info[MAX_INFO_STRING];

	memset( &s_teammain, 0, sizeof(s_teammain) );

	TeamMain_Cache();

	s_teammain.menu.wrapAround = qtrue;
	s_teammain.menu.fullscreen = qfalse;

	s_teammain.frame.generic.type   = MTYPE_BITMAP;
	s_teammain.frame.generic.flags	= QMF_INACTIVE;
	s_teammain.frame.generic.name   = TEAMMAIN_FRAME;
	s_teammain.frame.generic.x		= 142;
	s_teammain.frame.generic.y		= 118;
	s_teammain.frame.width			= 359;
	s_teammain.frame.height			= 256;

	y = 164;

	s_teammain.joinred.generic.type     = MTYPE_PTEXT;
	s_teammain.joinred.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joinred.generic.id       = ID_JOINRED;
	s_teammain.joinred.generic.callback = TeamMain_MenuEvent;
	s_teammain.joinred.generic.x        = 320;
	s_teammain.joinred.generic.y        = y;
	s_teammain.joinred.string           = "JOIN RED";
	s_teammain.joinred.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joinred.color            = colorRed;
	y += 20;

	s_teammain.joinblue.generic.type     = MTYPE_PTEXT;
	s_teammain.joinblue.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joinblue.generic.id       = ID_JOINBLUE;
	s_teammain.joinblue.generic.callback = TeamMain_MenuEvent;
	s_teammain.joinblue.generic.x        = 320;
	s_teammain.joinblue.generic.y        = y;
	s_teammain.joinblue.string           = "JOIN BLUE";
	s_teammain.joinblue.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joinblue.color            = colorRed;
	y += 20;

	s_teammain.joingreen.generic.type     = MTYPE_PTEXT;
	s_teammain.joingreen.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joingreen.generic.id       = ID_JOINGREEN;
	s_teammain.joingreen.generic.callback = TeamMain_MenuEvent;
	s_teammain.joingreen.generic.x        = 320;
	s_teammain.joingreen.generic.y        = y;
	s_teammain.joingreen.string           = "JOIN GREEN";
	s_teammain.joingreen.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joingreen.color            = colorGreen;
	y += 20;

	s_teammain.joinyellow.generic.type     = MTYPE_PTEXT;
	s_teammain.joinyellow.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joinyellow.generic.id       = ID_JOINYELLOW;
	s_teammain.joinyellow.generic.callback = TeamMain_MenuEvent;
	s_teammain.joinyellow.generic.x        = 320;
	s_teammain.joinyellow.generic.y        = y;
	s_teammain.joinyellow.string           = "JOIN YELLOW";
	s_teammain.joinyellow.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joinyellow.color            = colorYellow;
	y += 20;

	s_teammain.joinorange.generic.type     = MTYPE_PTEXT;
	s_teammain.joinorange.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joinorange.generic.id       = ID_JOINORANGE;
	s_teammain.joinorange.generic.callback = TeamMain_MenuEvent;
	s_teammain.joinorange.generic.x        = 320;
	s_teammain.joinorange.generic.y        = y;
	s_teammain.joinorange.string           = "JOIN ORANGE";
	s_teammain.joinorange.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joinorange.color            = colorOrange;
	y += 20;

	s_teammain.joinwhite.generic.type     = MTYPE_PTEXT;
	s_teammain.joinwhite.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joinwhite.generic.id       = ID_JOINWHITE;
	s_teammain.joinwhite.generic.callback = TeamMain_MenuEvent;
	s_teammain.joinwhite.generic.x        = 320;
	s_teammain.joinwhite.generic.y        = y;
	s_teammain.joinwhite.string           = "JOIN WHITE";
	s_teammain.joinwhite.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joinwhite.color            = colorWhite;
	y += 20;

	s_teammain.joingame.generic.type     = MTYPE_PTEXT;
	s_teammain.joingame.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.joingame.generic.id       = ID_JOINGAME;
	s_teammain.joingame.generic.callback = TeamMain_MenuEvent;
	s_teammain.joingame.generic.x        = 320;
	s_teammain.joingame.generic.y        = y;
	s_teammain.joingame.string           = "JOIN GAME";
	s_teammain.joingame.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.joingame.color            = colorRed;
	y += 20;

	s_teammain.spectate.generic.type     = MTYPE_PTEXT;
	s_teammain.spectate.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_teammain.spectate.generic.id       = ID_SPECTATE;
	s_teammain.spectate.generic.callback = TeamMain_MenuEvent;
	s_teammain.spectate.generic.x        = 320;
	s_teammain.spectate.generic.y        = y;
	s_teammain.spectate.string           = "SPECTATE";
	s_teammain.spectate.style            = UI_CENTER|UI_SMALLFONT;
	s_teammain.spectate.color            = colorRed;
	y += 20;

	trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);   
	gametype = atoi( Info_ValueForKey( info,"g_gametype" ) );
			      
	// set initial states
	switch( gametype ) {
	case GT_SINGLE_PLAYER:
	case GT_FFA:
	case GT_TOURNAMENT:
		s_teammain.joinred.generic.flags  |= QMF_GRAYED;
		s_teammain.joinblue.generic.flags |= QMF_GRAYED;
		s_teammain.joingreen.generic.flags |= QMF_GRAYED;
		s_teammain.joinyellow.generic.flags  |= QMF_GRAYED;
		s_teammain.joinorange.generic.flags |= QMF_GRAYED;
		s_teammain.joinwhite.generic.flags |= QMF_GRAYED;
		break;

	// Other multi team game modes should have their case here.
	case GT_MULTI_TEAM:
		s_teammain.joingame.generic.flags |= QMF_GRAYED;
		break;
	default:
	case GT_TEAM:
	case GT_CTF:
		s_teammain.joingame.generic.flags |= QMF_GRAYED;
		s_teammain.joingreen.generic.flags |= QMF_GRAYED;
		s_teammain.joinyellow.generic.flags  |= QMF_GRAYED;
		s_teammain.joinorange.generic.flags |= QMF_GRAYED;
		s_teammain.joinwhite.generic.flags |= QMF_GRAYED;
		break;
	}

	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.frame );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joinred );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joinblue );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joingreen );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joinyellow );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joinorange );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joinwhite );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.joingame );
	Menu_AddItem( &s_teammain.menu, (void*) &s_teammain.spectate );
}


/*
===============
TeamMain_Cache
===============
*/
void TeamMain_Cache( void ) {
	trap_R_RegisterShaderNoMip( TEAMMAIN_FRAME );
}


/*
===============
UI_TeamMainMenu
===============
*/
void UI_TeamMainMenu( void ) {
	TeamMain_MenuInit();
	UI_PushMenu ( &s_teammain.menu );
}
