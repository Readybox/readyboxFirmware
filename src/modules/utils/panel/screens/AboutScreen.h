/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H

#include "PanelScreen.h"

#include <string>

class AboutScreen : public PanelScreen {
    public:
        AboutScreen();
        void on_enter();
        void clicked_line(uint16_t line);
        void on_exit();
        void on_refresh();
        void on_main_loop();
        void display_menu_line(uint16_t line);
    private:
        bool done;
};

#endif
