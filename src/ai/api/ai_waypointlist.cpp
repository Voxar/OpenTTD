/* $Id: ai_waypointlist.cpp 17693 2009-10-04 17:16:41Z rubidium $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_waypointlist.cpp Implementation of AIWaypointList and friends. */

#include "ai_waypointlist.hpp"
#include "ai_vehicle.hpp"
#include "../../company_func.h"
#include "../../vehicle_base.h"
#include "../../waypoint_base.h"

AIWaypointList::AIWaypointList()
{
	const Waypoint *wp;
	FOR_ALL_WAYPOINTS(wp) {
		if (wp->facilities & FACIL_TRAIN && wp->owner == _current_company) this->AddItem(wp->index);
	}
}

AIWaypointList_Vehicle::AIWaypointList_Vehicle(VehicleID vehicle_id)
{
	if (!AIVehicle::IsValidVehicle(vehicle_id)) return;

	const Vehicle *v = ::Vehicle::Get(vehicle_id);

	for (const Order *o = v->GetFirstOrder(); o != NULL; o = o->next) {
		if (o->IsType(OT_GOTO_WAYPOINT)) this->AddItem(o->GetDestination());
	}
}