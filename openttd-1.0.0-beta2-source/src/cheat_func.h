/* $Id: cheat_func.h 17248 2009-08-21 20:21:05Z rubidium $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file cheat_func.h Functions related to cheating. */

#ifndef CHEAT_FUNC_H
#define CHEAT_FUNC_H

#include "cheat_type.h"

extern Cheats _cheats;

void ShowCheatWindow();

/**
 * Return true if any cheat has been used, false otherwise
 * @return has a cheat been used?
 */
bool CheatHasBeenUsed();

#endif /* CHEAT_FUNC_H */
