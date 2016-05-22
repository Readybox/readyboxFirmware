/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#include "libs/Kernel.h"
#include "Panel.h"
#include "PanelScreen.h"
#include "LcdBase.h"
#include "AboutScreen.h"
#include "libs/utils.h"
#include <string>
#include "libs/SerialMessage.h"
#include "StreamOutput.h"


#include "version.h"

#include <string>
#include "UnloadFilamentScreen.h"
using namespace std;


void UnloadFilamentScreen::on_enter()
{
    THEPANEL->enter_menu_mode();
    THEPANEL->setup_menu(7);
    this->refresh_menu();
}

void UnloadFilamentScreen::on_refresh()
{
    if ( THEPANEL->menu_change() ) {
        this->refresh_menu();
    }
    if ( THEPANEL->click() ) {
        this->clicked_menu_entry(THEPANEL->get_menu_current_line());
    }
}

void UnloadFilamentScreen::display_menu_line(uint16_t line)
{
	// PLA, ABS, NINJA FLEX, HIPS, Nylon
	// 200  230  220         240   245
    switch ( line ) {
        case 0: THEPANEL->lcd->printf("Back"); break;
        case 1: THEPANEL->lcd->printf("200 C / PLA"); break;
        case 2: THEPANEL->lcd->printf("210 C "); break;
        case 3: THEPANEL->lcd->printf("220 C / Ninja Flex"); break;
        case 4: THEPANEL->lcd->printf("230 C / ABS"); break;
        case 5: THEPANEL->lcd->printf("240 C / HIPS, Nylon"); break;
        case 6: THEPANEL->lcd->printf("250 C "); break;
    }
}

void UnloadFilamentScreen::clicked_menu_entry(uint16_t line)
{
    switch ( line ) {
        case 0: THEPANEL->enter_screen(this->parent); break;
        case 1:
        {
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S200");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
        }
        case 2:
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S210");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
        case 3:
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S220");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
        case 4:
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S230");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
        case 5:
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S240");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
        case 6:
        	THEPANEL->enter_screen(this->parent);
        	send_command("M117 Unloading Filament");
        	send_command("M109 S250");
        	send_command("G92 E0");
        	send_command("G1 E-50 F1000");
        	send_command("G1 E-1000 F3000");
        	send_command("M117 Filament Unloaded.");
        	break;
    }
}



