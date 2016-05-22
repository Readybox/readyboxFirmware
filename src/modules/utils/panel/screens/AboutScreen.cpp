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
#include "MainMenuScreen.h"
#include "AboutScreen.h"
#include "libs/utils.h"
#include <string>
#include "libs/SerialMessage.h"
#include "StreamOutput.h"


#include "version.h"

using namespace std;

AboutScreen::AboutScreen()
{
	this->done = false;
}

// When entering this screen
void AboutScreen::on_enter()
{
    THEPANEL->lcd->clear();
    Version version;
    string date = version.get_build_date();
    date = date.substr(0, date.size()-8);

    THEPANEL->lcd->setCursor(7, 0); THEPANEL->lcd->printf("Readybox");

    THEPANEL->lcd->setCursor(0, 2); THEPANEL->lcd->printf("Version: 1.0");
    THEPANEL->lcd->setCursor(0, 4); THEPANEL->lcd->printf("Based on Smoothieware");

    THEPANEL->lcd->setCursor(0, 6);THEPANEL->lcd->printf("Build:%s", version.get_build());
    THEPANEL->lcd->setCursor(0, 7);THEPANEL->lcd->printf("Date: %s", date.c_str());
}



// When a line is clicked in the menu, act
void AboutScreen::clicked_line(uint16_t line)
{
    this->done = true;
}


void AboutScreen::on_refresh()
{
	if ( THEPANEL->click() ) {
		this->clicked_line(THEPANEL->get_menu_current_line());
	}
}
void AboutScreen::on_exit() {}
void AboutScreen::on_main_loop()
{
	if(this->done == true) {
		THEPANEL->enter_screen(this->parent);
		this->done = false;
		return;
	}
}
void AboutScreen::display_menu_line(uint16_t line) {}

