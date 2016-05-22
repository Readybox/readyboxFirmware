/*
 * LoadFilament.h
 *
 *  Created on: Apr 17, 2016
 *      Author: carson
 */

#ifndef SRC_MODULES_UTILS_PANEL_SCREENS_UNLOADFILAMENTSCREEN_H_
#define SRC_MODULES_UTILS_PANEL_SCREENS_UNLOADFILAMENTSCREEN_H_

#include "PanelScreen.h"

class UnloadFilamentScreen : public PanelScreen{
	public:

	    void on_refresh();
	    void on_enter();
	    void display_menu_line(uint16_t line);
	    void clicked_menu_entry(uint16_t line);
	    int idle_timeout_secs() { return 60; }
	};

#endif /* SRC_MODULES_UTILS_PANEL_SCREENS_LOADFILAMENTSCREEN_H_ */
