/* $Id: command_func.h 17248 2009-08-21 20:21:05Z rubidium $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file command_func.h Functions related to commands. */

#ifndef COMMAND_FUNC_H
#define COMMAND_FUNC_H

#include "command_type.h"

/**
 * Checks if a command failes.
 *
 * As you see the parameter is not a command but the return value of a command,
 * the CommandCost class. This function checks if the command executed by
 * the CommandProc function failed and returns true if it does.
 *
 * @param cost The return value of a CommandProc call
 * @return true if the command failes
 * @see CmdSucceded
 */
static inline bool CmdFailed(CommandCost cost) { return cost.Failed(); }

/**
 * Checks if a command succeeded.
 *
 * As #CmdFailed this function checks if a command succeeded
 *
 * @param cost The return value of a CommandProc call
 * @return true if the command succeeded
 * @see CmdSucceeded
 */
static inline bool CmdSucceeded(CommandCost cost) { return cost.Succeeded(); }

/**
 * Define a default return value for a failed command.
 *
 * This variable contains a CommandCost object with is declared as "failed".
 * Other functions just need to return this error if there is an error,
 * which doesn't need to specific by a StringID.
 */
static const CommandCost CMD_ERROR = CommandCost(INVALID_STRING_ID);

/**
 * Returns from a function with a specific StringID as error.
 *
 * This macro is used to return from a function. The parameter contains the
 * StringID which will be returned.
 *
 * @param errcode The StringID to return
 */
#define return_cmd_error(errcode) return CommandCost(errcode);

/**
 * Execute a command
 */
CommandCost DoCommand(TileIndex tile, uint32 p1, uint32 p2, DoCommandFlag flags, uint32 cmd, const char *text = NULL);
CommandCost DoCommand(const CommandContainer *container, DoCommandFlag flags);

/**
 * Execute a network safe DoCommand function
 */
bool DoCommandP(TileIndex tile, uint32 p1, uint32 p2, uint32 cmd, CommandCallback *callback = NULL, const char *text = NULL, bool my_cmd = true);
bool DoCommandP(const CommandContainer *container, bool my_cmd = true);

#ifdef ENABLE_NETWORK

/**
 * Send a command over the network
 */
void NetworkSend_Command(TileIndex tile, uint32 p1, uint32 p2, uint32 cmd, CommandCallback *callback, const char *text);
#endif /* ENABLE_NETWORK */

extern Money _additional_cash_required;
extern StringID _error_message;

/**
 * Checks if a integer value belongs to a command.
 */
bool IsValidCommand(uint32 cmd);
/**
 * Returns the flags from a given command.
 */
byte GetCommandFlags(uint32 cmd);
/**
 * Returns the current money available which can be used for a command.
 */
Money GetAvailableMoneyForCommand();

/**
 * Extracts the DC flags needed for DoCommand from the flags returned by GetCommandFlags
 * @param cmd_flags Flags from GetCommandFlags
 * @return flags for DoCommand
 */
static inline DoCommandFlag CommandFlagsToDCFlags(uint cmd_flags)
{
	DoCommandFlag flags = DC_NONE;
	if (cmd_flags & CMD_NO_WATER) flags |= DC_NO_WATER;
	if (cmd_flags & CMD_AUTO) flags |= DC_AUTO;
	if (cmd_flags & CMD_ALL_TILES) flags |= DC_ALL_TILES;
	return flags;
}

#endif /* COMMAND_FUNC_H */
